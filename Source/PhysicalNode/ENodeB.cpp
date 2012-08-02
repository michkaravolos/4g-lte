/**
 * @file    ENodeB.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 


// *****************************************************************************
// Includes
// *****************************************************************************

#include "ENodeB.h"

#include "User.h"
#include "SimulationEnvironment.h"
#include "SimulationParameters.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
ENodeB::ENodeB()
{
   
};

// -----------------------------------------------------------------------------

PhysicalNode::
ENodeB::ENodeB( Basic::Position p, int id )
{
   position_ = p;
   id_ = id;
   initialize();
};

// -----------------------------------------------------------------------------

PhysicalNode::
ENodeB::~ENodeB()
{
   if (physicalLayer_ != 0 )
   {
      delete physicalLayer_;
      physicalLayer_ = 0;
   }
   if (schedulingAlgorithm_ != 0 )
   {
      delete schedulingAlgorithm_;
      schedulingAlgorithm_ = 0;
   }
   //delete device_;
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
ENodeB::initialize()
{
   int orientation = static_cast<int> ( id_ % 3 );

   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

int Direction_ = sp->Direction;

if(Direction_ ==0){
   if( orientation > 0 || orientation < 3 )
   {
      device_ = new Transmitter( orientation );
   }
   else
   {
      it_error("e-NodeB: Wrong orientation");
   }
 }
else{
   if( orientation > 0 || orientation < 3 )
   {
       device_ = new Receiver(orientation);// É receptor, mas a antena eh igual a de transmissão.
   }
   else
   {
      it_error("e-NodeB: Wrong orientation");
   }
        
}
   linkedUsers_.set_size( 0 );
   
   site_ = static_cast<int>( id_ / 3 );
   sector_ = orientation;
   rawBits_ = 1;
   effectiveBits_ = 1.0;
};

// -----------------------------------------------------------------------------

void
PhysicalNode::
ENodeB::setParameters()
{
   
   
};

// -----------------------------------------------------------------------------

void
PhysicalNode::
ENodeB::scheduleUsers(int Direction)
{
   //if( id_ == 0 )
   //{
      //cout << linkedUsers_ << endl;
   //}
   physicalLayer_->clearUsers(); //Limpa cada PRB, de cada Slot, de cada Subframe, de cada EnodeB
   //cout << "ScheduleUsers" << endl;
   schedulingAlgorithm_->schedule( linkedUsers_, physicalLayer_,Direction );
   
   
};

// -----------------------------------------------------------------------------

void
PhysicalNode::
ENodeB::transmit()
{
   SimulationEnvironment::SimulationEnvironment* se =
      SimulationEnvironment::SimulationEnvironment::getInstance();
    
   User* user;
   
   int slots = physicalLayer_->getNumberSlots();
   int prbs = physicalLayer_->getNumberPRBsPerSlot();
   int rawBits = 0;
   double effectiveBits = 0;
   int userId = -1;
   
   for( int i = 0; i < slots; ++i )
      {
         for( int j = 0; j < prbs; ++j )
         {
            if( id_ == 0 )
            {
               //cout << physicalLayer_->getUserId( i, j ) << endl;
            }
            userId = physicalLayer_->getUserId( i, j );
            if( userId != -1 )
            {
               user = se->getUser( userId );
               rawBits = physicalLayer_->getRawBits( i, j );
               effectiveBits = physicalLayer_->getEffectiveBits( i, j );        
               user->setBits( rawBits, effectiveBits );
               rawBits_ += rawBits;
               effectiveBits_ += effectiveBits;
            }
            
         }
      }
};

// -----------------------------------------------------------------------------

void
PhysicalNode::
ENodeB::informUserFrequencies()
{
   SimulationEnvironment::SimulationEnvironment* se =
      SimulationEnvironment::SimulationEnvironment::getInstance();
   
   User* user;
   
   int size = linkedUsers_.size();
   
   for( int i = 0; i < size; ++i )
   {
      user = static_cast<User*>( se->getUser( linkedUsers_( i ) ) );
      user->setFrequencies( physicalLayer_->getSCFrequencies() );
   }
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
ENodeB::getTransmittedPower( double Frequency )
{

   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

int Direction_ = sp->Direction;

   Transmitter* t = static_cast<Transmitter*>( device_ );
   Receiver* r = static_cast<Receiver*>( device_ );

   double p = 0.0;
   int size = physicalLayer_->getNumberSCFrequencies();
   for( int i = 0; i < size; ++i )
   {
      //p = physicalLayer_->getSCFrequency( i );
      if( Frequency == physicalLayer_->getSCFrequency( i ) )
      {
if(Direction_ == 0){
         p = t->getPower() / size;
}
else{
       p = r->getPower() / size;
}
         break;
      }
      else
      {
         p = 0.0;
      }
   }
   return p;
}

//------------------------------------------------------------------------------


// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





