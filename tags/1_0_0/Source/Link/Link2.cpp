/**
 * @file    Link.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include "Link.h"
#include "SimulationParameters.h"
#include "UserParameters.h"
#include "PhysicalLayerParameters.h"
#include "SystemParameters.h"
#include "User.h"
#include "ENodeB.h"
#include "MathFunctions.h"
#include "TimeManager.h"
#include "Results.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Link::Link* 
   Link::Link::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Link::
Link::Link()
{
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

Link::
Link::~Link()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Link::Link* 
Link::
Link::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Link();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Link::
Link::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   //Parameters::PhysicalLayerParameters* plp = 
      //Parameters::PhysicalLayerParameters::getInstance();
   Parameters::UserParameters* up = 
      Parameters::UserParameters::getInstance();
   numberUsers_ = sp->numberUsers;
   numberENodeBs_ = sp->numberENodeBs;
   noiseFigure_ = up->noiseFigure;
   boltzmannConstant_ = 1.3806503e-23;
   bandwidth_ = sysp->subcarrierBandwidth;
   temperature_ = sp->temperature;
   numberAntennas_ = sysp->numberTransmitAntennas;
}

//------------------------------------------------------------------------------

void
Link::
Link::initialize()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   numberUsers_ = sp->numberUsers;
   losses_.set_size( numberUsers_ );
   losses_.zeros();
   userId_.set_size( numberUsers_ );
   userId_.zeros();
   eNodeBId_.set_size( numberUsers_ );
   eNodeBId_.zeros();
   radioChannel_ = RadioChannel::RadioChannel::getInstance();
   simulationEnvironment_ = SimulationEnvironment::
      SimulationEnvironment::getInstance();
}

//------------------------------------------------------------------------------

void
Link::
Link::clear()
{
   userId_.set_size( 0 );
   eNodeBId_.set_size( 0 );
   losses_.set_size( 0 );
}

//------------------------------------------------------------------------------

void
Link::
Link::createLinks()
{
   Results::Results* r = Results::Results::getInstance();
   PhysicalNode::User* user;
   PhysicalNode::ENodeB* eNodeB;
   Basic::Position p1;
   Basic::Position p2;
   Basic::MathFunctions mf;
   double arg = 0.0;
   double gainTX = 0.0;
   double gainRX = 0.0;
   double fading = 0.0;
   double max = -1e300;
   int id = 0;
   
   for( int i = 0; i < numberUsers_; ++i )//Numero total de usuarios
   {
      max = -1e300; //Define um numero maximo
      user = simulationEnvironment_->getUser( i );//Pega um usuario de SimulationEnvironment->GetUser
      
      p2 = user->getPosition();//Gera uma posição dentro do GRID para esse usuario
      
      for( int j = 0; j < numberENodeBs_; ++j )//Numero total de ENodeBs
      {   
         eNodeB = simulationEnvironment_->getENodeB( j );  //Gera uma ENodeB de SimulationEnvironment-GetENodeB
         
         p1 = eNodeB->getPosition();//Gera uma poição para essa ENodeB dentro do GRID
         arg = mf.calculateAngle( p1, p2 );//Calcula o angulo entre essa ENodeB e do usuário
         gainTX = eNodeB->getGain( arg );//Analisa o Ganho para esse angulo de TX
         gainRX = user->getGain( pi + arg );//Analisa o Ganho para esse angulo de RX
         
         fading = gainTX * gainRX * 
            radioChannel_->getLargeScaleFading( user, eNodeB );//Gera um LargeScaleFading para esse par User-ENodeB
         
         if( fading > max )
         {
            max = fading;//Se o fading for maior que o numero maximo esse maximo agora é esse fading
            id = eNodeB->getId();//Pega-se o ID dessa ENodeB de fading maximo
         }        
      }
      losses_( i ) = max;//Guarda esse max nesse vetor perdas
      id = 3 * user->getSite() + user->getSector();//?
      eNodeB = simulationEnvironment_->getENodeB( id ); 
      user->setENodeBId( id );
      
      if( id >= 0 && id < 3 )
      {
         r->addUserId( i );//Se o id ficar entre zero e tres ele adiciona o index i como ID do user criado
      }
      
      eNodeB->addUser( user->getId() );//Adiciona o Usuario naquela ENodeB
      
   }
}

//------------------------------------------------------------------------------

double
Link::
Link::getLoss( int i )
{
   return losses_( i );
}

//------------------------------------------------------------------------------

void
Link::
Link::calculateSINR()
{
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   if ( tm->hasResolutionStepChanged() )
   {
      calculateSINRs();   
   }
   
   calculateCQI();
}

//------------------------------------------------------------------------------

void
Link::
Link::calculateCQI()
{
   PhysicalNode::User* user;
   
   for( int i = 0; i < numberUsers_; ++i )
   {
      user = simulationEnvironment_->getUser( i );
      //user->clearCQI();
      user->updateCQI();
   }
}

//------------------------------------------------------------------------------

void
Link::
Link::calculateSINRs()
{
   //Results::Results* r = Results::Results::getInstance();
   
   double sinr = 0.0;
   PhysicalNode::ENodeB* eNodeB;
   PhysicalNode::User* user;
   
   int nfreq = 0;
   int nfreq2 = 0;
   double freq = 0.0;
   int eid = -1;
   
   for( int i = 0; i < numberUsers_; ++i )
   {
      user = simulationEnvironment_->getUser( i );  //Pega um usuario
      nfreq = user->getNumberFrequencies();//Pega o numero de frequencias alocadas para esse user
      eid = user->getENodeBId();//Pega o ID da EnodeB daquele usuario
      eNodeB = simulationEnvironment_->getENodeB( eid ); //Pega os parametros dessa ENodeB
      for( int j = 0; j < nfreq; ++j )
      {
         freq = user->getFrequency( j ); //Pega cada frequencia  alocada para esse user
	 
         for( int k = 0; k < numberAntennas_; ++k )//Pega cada antena
         {
            sinr = calculateSINRPerUser( i, eid, freq, k );//Calcula a SINR para aquele usuario nessa frequencia com essa antena
            user->storeSINR( sinr, freq, k );//Salva essa SINR
            //r->storeSINR( sinr, freq );    
         }
      }
   }
}

//------------------------------------------------------------------------------

double
Link::
Link::calculateSINRPerUser( int userId, int eNodeBId, double frequency, 
   int antenna )
{
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   PhysicalNode::User* user;
   PhysicalNode::ENodeB* eNodeB;
   int eId = -1;
   double sinr = 0.0;
   double prx = 0.0;
   double time = 0.0;
   double fading = 0.0;
   double interFading = 0.0;
   double inter = 0.0;
   double noise = boltzmannConstant_ * noiseFigure_ * bandwidth_ * temperature_; //Gera um ruído Gaussiano
   I_Uniform_RNG gen( 0, numberAntennas_ - 1 );//Pega uma antena aleatoriamente
   
   eNodeB = simulationEnvironment_->getENodeB( eNodeBId );//Retoma o ENodeB de CalculateSINRs
   
   user = simulationEnvironment_->getUser( userId );//Retoma o User de CalculateSINRs
   
   time = tm->getCurrentTime();//?
   
   fading = getTotalFading( eNodeBId, userId, time, frequency, antenna );//Pega o fading total Small+Large
   prx = eNodeB->getTransmittedPower( frequency ) * fading;//Pega a potencia de recepçao já multiplicada pelo fading
   if ( prx == 0.0 )
   {
      it_error("Recieved power = 0");
   }
   
   if ( prx < 0.0 )
   {
      it_error("Recieved power < 0");
   }
   
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      eNodeB = simulationEnvironment_->getENodeB( i );//Pega os parametros de cada EnodeB
      eId = eNodeB->getId();//Pega o ID dessa EnodeB
      interFading = getTotalFading( eId, userId, time, frequency, gen() );//Pega o fading inter ENodeBs para uma antena aleatória
      
      if( eId == eNodeBId )
      {
         interFading = 0;    //Se for a mesma ENodeB o interFading zera
      }
      
      inter += eNodeB->getTransmittedPower( frequency ) * interFading;//Calcula o interfading total de todas as ENodeBs para aquele usuario

   }
   
   if ( inter < 0.0 )
   {
      it_error("Recieved power < 0");
   }
   sinr = prx / ( inter + noise ); //SINR é o resultado da potencia recebida dividida pela soma do interfading mais o ruido gaussiano
   return sinr;
}

//------------------------------------------------------------------------------

double
Link::
Link::getTotalFading( int eNodeBId, int userId, double time, double frequency, 
 int antenna )
{
   Basic::MathFunctions mf;
   PhysicalNode::User* user;
   PhysicalNode::ENodeB* eNodeB;
   Basic::Position p1;
   Basic::Position p2;
   double arg = 0.0;
   double gainTX = 0.0;
   double gainRX = 0.0;
   double fading = 0.0;

   
   eNodeB = simulationEnvironment_->getENodeB( eNodeBId );
   
   user = simulationEnvironment_->getUser( userId );
   
   // Refactor
   p2 = user->getPosition();
   p1 = eNodeB->getPosition();
   arg = mf.calculateAngle( p1, p2 );
   gainTX = eNodeB->getGain( arg );
   gainRX = user->getGain( pi + arg );
   
   fading = gainTX * gainRX * 
      radioChannel_->getFading( userId, eNodeBId, time , frequency, antenna );
   
   return fading;
   
   
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************

