/**
 * @file    Link.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 * 
 * @author_2  Luiz Gustavo da Silva Carvalho
 * @author_3  Marcos Samuel Santos Ouriques  
 * Date:      09/01/2012 (Month/Day/Year)
 * 
 * This file is also a part of the undergraduate final project, under the supervision 
 * of Andre Noll Barreto.
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
#include "SchedulingAlgorithm.h"

#include "SchedulerParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Link::Link* 
   Link::Link::instance_ = 0;
double time1[1]={0};

      int control=0;
      int index1=0;
      int timesounding[2]={0.0};
     
      int control2=0;
      int flag=0;
      int control3,control4;
      
      
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
   reuse_=sysp->reuse;
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
      control3=0;
      control4=0;
      InterLimit_=sp->InterLimit;
      SoundingLimit_=sp->SoundingLimit;
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
   
   for( int i = 0; i < numberUsers_; ++i )               //Total number of users
   {
      max = -1e300;                                      //Defines a maximum number.
      user = simulationEnvironment_->getUser( i );       //Catchs an user with SimulationEnvironment->GetUser.
      
      p2 = user->getPosition();                          //Creates an position inside the GRID to this user.
      
      for( int j = 0; j < numberENodeBs_; ++j )          //Total number of ENodeBs
      {   
         eNodeB = simulationEnvironment_->getENodeB( j );//Creates an ENodeB from SimulationEnvironment->GetENodeB.
         
         p1 = eNodeB->getPosition();                     //Creates an position to this ENodeB inside the GRID.
         arg = mf.calculateAngle( p1, p2 );              //Calculates the angle between ENodeB and the user.
         gainTX = eNodeB->getGain( arg );                //Analyse the gain to the TX angle.
         gainRX = user->getGain( pi + arg );             //Analyse the gain to the RX angle.
         
         fading = gainTX * gainRX * 
            radioChannel_->getLargeScaleFading( user, eNodeB );//Creates LargeScaleFading to this User-ENodeB pair.
         
         if( fading > max )
         {
            max = fading;                                 //If fading is greater than the maximum number, now the fading is the max.
            id = eNodeB->getId();                         //It takes the ID of the maximum fading.
         }        
      }
      losses_( i ) = max;                                 //Keep the max on the losses_ vector.
      id = 3 * user->getSite() + user->getSector();
      eNodeB = simulationEnvironment_->getENodeB( id ); 
      user->setENodeBId( id );
       user->setENodeBSector(eNodeB->getSector());
      
      if( id >= 0 && id < 3 )
      {
         r->addUserId( i );                               //If the ID become between 0 and 3, it adds the index i with the ID of the created user.
      }
      
      eNodeB->addUser( user->getId() );                   //Adds the user on the defined eNodeB.
      
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
Link::calculateSINR1(int index, ivec& schedulerUsers_, vec frequencies, bool calc)
{
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
       Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
      timesounding[1]=toc();
      if((timesounding[1]-timesounding[0])>= sp->SoundingInterval && tm->getCurrentStep()!=0)
      {
	calculateSINRSounding(schedulerUsers_); 
	timesounding[0]=timesounding[1];
      }
      
  if ( tm->hasResolutionStepChanged() )
   {
        calculateSINRs1(index, schedulerUsers_,frequencies, calc); 
   }
   
   calculateCQI();
}
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
Link::calculateSINRs1(int scheduleduser, ivec& schedulerUsers_, vec frequencies, bool calc)
{
   //Results::Results* r = Results::Results::getInstance();
   
   double sinr = 0.0;
   double intersinr =0.0;
   PhysicalNode::ENodeB* eNodeB;
   PhysicalNode::User* user;
   PhysicalNode::User* user2;
    SimulationEnvironment::SimulationEnvironment* se = 
      SimulationEnvironment::SimulationEnvironment::getInstance();
   double temp =0.0;
   int UserID[10000];
   int ENodeBID[10000];
   int freq[10000];
   int usersSize = schedulerUsers_.size();
   int lastUser = schedulerUsers_(usersSize-1);
   int freqsize= frequencies.size();
   //cout<<freqsize<<"\n";
   int equalfreq=0;
   int temp2;
   // cout<<toc()<<"\n";
   //cout<<index1<<" "<<control<<"\n";
   user = se->getUser( scheduleduser);
	  int enodeid=user->getENodeBId();
   control++;
   if(control<=usersSize || scheduleduser==lastUser ){
         user = se->getUser( scheduleduser);
	  int enodeid=user->getENodeBId();
	  int soma=index1+freqsize;
	  int jj=0;
	 for(int j=index1;j<soma;j++){UserID[j]=scheduleduser;ENodeBID[j]=enodeid;freq[j]=frequencies[jj];temp2=j;jj++;
	   index1=temp2;//cout<<UserID[j]<<" "<<ENodeBID[j]<<" "<<freq[j]<<"\n";
	}
	 //cout<<index1<<" "<<freq[index1]<<" "<<UserID[index1]<<" "<<ENodeBID[index1]<<"\n";
}
else{control=0;}
if(calc==true){
  for(int i=0;i<=index1;i++)
	{//cout<<UserID[i]<<" "<<ENodeBID[i]<<" "<<freq[i]<<"\n";
	   for(int p=0;p<=index1;p++)
	      {
		if(freq[i]==freq[p] && ENodeBID[i]!=ENodeBID[p]){
		  for( int k2 = 0; k2 < numberAntennas_; ++k2 ){
		    intersinr=CalculateInterFading(UserID[p],ENodeBID[i],freq[i],k2);
		    sinr = calculateSINRPerUser1( UserID[i], ENodeBID[i], freq[i], k2, temp);//Apenas pega o tempo para o interfading
		    temp+=intersinr;//cout<<temp<<" "<<freq[i]<<" "<<ENodeBID[i]<<" "<<ENodeBID[p]<<"\n";
		                                               }
		                                            }
		   
		temp=0;
	      }
	     for( int k2 = 0; k2 < numberAntennas_; ++k2 ){
		   sinr = calculateSINRPerUser1( UserID[i], ENodeBID[i], freq[i], k2, temp);
		   if(control3<=InterLimit_){
		    user->storeSINR( sinr, freq[i], k2);
		   control3++;}
		                                                } 
	}
	index1=0;
}
}
void
Link::
Link::calculateSINRs()
{
   Results::Results* r = Results::Results::getInstance();
   
   double sinr = 0.0;
   PhysicalNode::ENodeB* eNodeB;
   PhysicalNode::User* user;
   
   int nfreq = 0;
   double freq = 0.0;
   int eid = -1;
   int findex;
   int bindex;
   for( int i = 0; i < numberUsers_; ++i )
   {
      user = simulationEnvironment_->getUser( i );  
      nfreq = user->getNumberFrequencies();
      eid = user->getENodeBId();
      eNodeB = simulationEnvironment_->getENodeB( eid );  
           switch(reuse_)
         {
         case 0:
        	 bindex=0;
        	 findex=nfreq;
        	 break;

         case 1:
        	 switch(eNodeB->getSector())
        	 {
        	 case 0:
        	   bindex=0;
        	   findex=nfreq/3;
        	   break;

        	 case 1:
        	   bindex=nfreq/3;
        	   findex=(nfreq/3)*2;
        	   break;

        	 case 2:
        	   bindex=(nfreq/3)*2;
        	   findex=nfreq;
        	   break;
        	 }

        	 break;
	 }
       for( int j = bindex; j < findex; ++j )
      {

       freq = user->getFrequency( j );

         for( int k = 0; k < numberAntennas_; ++k )
         {
        	 sinr = calculateSINRPerUser( i, eid, freq, k);
        	   user->storeSINR( sinr, freq, k);
                   r->storeSINR( sinr, freq );
        	   //r->storeSINR( sinr );
            
         }
      }
   }
}

void
Link::
Link::calculateSINRSounding(ivec& schedulerUsers_)
{
   //Results::Results* r = Results::Results::getInstance();   
    Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
      SoundingInterval_= sp->SoundingInterval;
     int NumberUserSounding= int(SoundingInterval_/0.01);
   double sinr = 0.0;
   PhysicalNode::ENodeB* eNodeB;
   PhysicalNode::User* user;
   int nfreq = 0;
   double freq = 0.0;
   int eid = -1;
   int usersSize = schedulerUsers_.size();
   int findex;
   int bindex;
   for(int i=0;i<usersSize/NumberUserSounding;i++){
   
   if(i+control2>=usersSize-1){control2=0;return;}
      user = simulationEnvironment_->getUser( i+control2 );  
      nfreq = user->getNumberFrequencies();
      eid = user->getENodeBId();
      eNodeB = simulationEnvironment_->getENodeB( eid ); 
        switch(reuse_)
         {
         case 0:
        	 bindex=0;
        	 findex=nfreq;
        	 break;

         case 1:
        	 switch(eNodeB->getSector())
        	 {
        	 case 0:
        	   bindex=0;
        	   findex=nfreq/3;
        	   break;

        	 case 1:
        	   bindex=nfreq/3;
        	   findex=(nfreq/3)*2;
        	   break;

        	 case 2:
        	   bindex=(nfreq/3)*2;
        	   findex=nfreq;
        	   break;
        	 }

        	 break;
	 }
      for( int j = bindex; j < findex; ++j )
      {

       freq = user->getFrequency( j );

         for( int k = 0; k < numberAntennas_; ++k )
         {
        	 sinr = calculateSINRPerUser( i, eid, freq, k);
		 if(control4<=SoundingLimit_){
        	   user->storeSINR( sinr, freq, k); control4++;
		   
		}
                   //r->storeSINR( sinr );
            
         }
      }
  
   }
   control2+=usersSize/NumberUserSounding;
}
//------------------------------------------------------------------------------

double
Link::
Link::calculateSINRPerUser1( int userId, int eNodeBId, double frequency, 
   int antenna, double InterSINR )
{
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   PhysicalNode::User* user;
   PhysicalNode::ENodeB* eNodeB;
   int eId = -1;
   double time1[1]={0};
   double sinr = 0.0;
   double prx = 0.0;
   double time = 0.0;
   double fading = 0.0;
   double interFading = 0.0;
   double inter = 0.0;
   double noise = boltzmannConstant_ * noiseFigure_ * bandwidth_ * temperature_; //Creates a Gaussian User.
   I_Uniform_RNG gen( 0, numberAntennas_ - 1 );                                  //Takes an aleatory antenna.
   
   eNodeB = simulationEnvironment_->getENodeB( eNodeBId );                       //Returns the ENodeB from CalculateSINRs
   
   user = simulationEnvironment_->getUser( userId );                             //Returns the User from CalculateSINRs
   
   time = tm->getCurrentTime();
   time1[0]=time;
   fading = getTotalFading( eNodeBId, userId, time, frequency, antenna );
   prx = eNodeB->getTransmittedPower( frequency ) * fading;
   if ( prx == 0.0 )
   {
      it_error("Recieved power = 0");
   }
   
   if ( prx < 0.0 )
   {
      it_error("Recieved power < 0");
   }
   sinr = prx / ( InterSINR + noise ); 
   return sinr;
}

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
   double noise = boltzmannConstant_ * noiseFigure_ * bandwidth_ * temperature_;
   I_Uniform_RNG gen( 0, numberAntennas_ - 1 );
   
   eNodeB = simulationEnvironment_->getENodeB( eNodeBId );
   
   user = simulationEnvironment_->getUser( userId );
   
   time = tm->getCurrentTime();
   
   fading = getTotalFading( eNodeBId, userId, time, frequency, antenna );
   prx = eNodeB->getTransmittedPower( frequency ) * fading;
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
      eNodeB = simulationEnvironment_->getENodeB( i );
      eId = eNodeB->getId();
      interFading = getTotalFading( eId, userId, time, frequency, gen() );
      
      if( eId == eNodeBId )
      {
         interFading = 0;    
      }
      
      inter += eNodeB->getTransmittedPower( frequency ) * interFading;

   }
   
   if ( inter < 0.0 )
   {
      it_error("Recieved power < 0");
   }
   sinr = prx / ( inter + noise ); 
   return sinr;
}

double
Link::
Link::CalculateInterFading( int userId, int eNodeBId, double frequency, 
   int antenna )
{
 
double sinr = 0.0;
PhysicalNode::User* user;
   PhysicalNode::ENodeB* eNodeB;
   double intersinr = 0.0;
   double prx = 0.0;
   double time = 0.0;
   double interFading = 0.0;
   double inter = 0.0;
   eNodeB = simulationEnvironment_->getENodeB( eNodeBId );
   //cout<<"Chegou aqui \n"<<userId<<" "<<eNodeBId<<" "<<frequency<<" "<<antenna<<"\n";
    interFading = getTotalFading( eNodeBId, userId, time1[0], frequency, antenna);
    //cout<<"Chegou aqui2 \n"<<interFading<<"\n";  
    intersinr = eNodeB->getTransmittedPower( frequency ) * interFading;
      //cout<<intersinr<<"\n";

   if ( intersinr < 0.0 )
   {
      it_error("Recieved power < 0");
   }
  return intersinr; 
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

