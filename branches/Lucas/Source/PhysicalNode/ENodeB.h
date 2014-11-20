/**
 * @file    ENodeB.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
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

#ifndef _ENodeB_h_
#define _ENodeB_h_

#include "PhysicalNode.h"
#include "PhysicalLayer.h"
#include "SchedulingAlgorithm.h"
#include "Transmitter.h"
#include "SystemParameters.h"

using namespace std;

namespace PhysicalNode
{

/**
 * ENodeB Class.
 * Detailed description.
 */
class ENodeB : public PhysicalNode
{
   public:
      
      

      /**
       * Constructor.
       * Creates a generic ENodeB.
       */   
      ENodeB();
      
      /**
       * Defines the position and the ID of ENodeB.
       */   
      ENodeB( Basic::Position p, int id);
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~ENodeB();
      
      /**
       * Defines reuse_.
       * 
       */
      void setParameters();
      
      /**
       * Initializes the ENodeB.
       * Defining reuse_, device_ (Direction_ ==0, device_ = Transmitter, else, Receiver).
       * Defining site_, sector_, rawBits_, effectiveBits_.
       */
      void initialize();
      
      /**
       * Returns antenna gain.
       * 
       */
      double getGain( const double theta );
            
      /**
       * Calls setPhysicalLayer from PhysicalLayer.
       * 
       */
      void setPhysicalLayer( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Calls addUser from User.
       * 
       */
      void addUser( int userId );
      
      /**
       * Return number of links.
       * 
       */
      int getNumberLinks();
      
      /**
       * Schedule Users.
       * 
       */
      void scheduleUsers(int Direction);
      
      /**
       * Set Schedulling Algorithm.
       * 
       */
      void setSchedulingAlgorithm( Scheduler::SchedulingAlgorithm* sa );
      
      /**
       * The trasmition consists in defining rawBits_ and effectiveBits_.
       * 
       */
      void transmit();
      
      /**
       * Returns the number of Physical Resource Blocks.
       * 
       */
      int getNumberPRBs();
      
      /**
       * Returns the number of Slots.
       * 
       */
      int getNumberSlots();
      
      /**
       * Returns the ID of the scheduled user defined by the parameters.
       */
      int getScheduledUserId( int slot , int prb );
      
      /**
       * Returns the Transmited power.
       * 
       */
      double getTransmittedPower( double Frequency );
      
      /**
       * Returns a frequency.
       * 
       */
      double getFrequency( int slot , int prb );
      
      /**
       * Return the User frequencies.
       * 
       */
      void informUserFrequencies();
      
      /**
       * 
       */
      PhysicalLayer::PhysicalLayer* getPhysicalLayer();
      
      /**
       * Returns the number of users on the ENodeB.
       * 
       */
      int getNumberLinkedUsers();
      
      /**
       * Returns the ID of the linked user.
       * 
       */
      int getLinkedUserId( int index );
      //ivec linkedUsers_;
      /**
       * Inteiro para capturar o reuso
       * 
       */
      int reuse_;
        
   protected:
      
      /**
       * Pointer to physicalLayer
       * 
       */
      PhysicalLayer::PhysicalLayer* physicalLayer_;
      
      /**
       * Vector with linked users.
       * 
       */
      ivec linkedUsers_;
      
      /**
       * Pointer to schedulingAlgorithm
       * 
       */
      Scheduler::SchedulingAlgorithm* schedulingAlgorithm_;
 
   private:

};

};

inline
double
PhysicalNode::
ENodeB::getGain( const double theta )
{
   return device_->getGain( theta );  
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::setPhysicalLayer( PhysicalLayer::PhysicalLayer* pl )
{
   physicalLayer_ = pl;
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::addUser( int userId )
{
   int s = linkedUsers_.size();
   linkedUsers_.set_size( s + 1, true );
   linkedUsers_( s ) = userId;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberLinks()
{
   return linkedUsers_.size();
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::setSchedulingAlgorithm( Scheduler::SchedulingAlgorithm* sa )
{
   schedulingAlgorithm_ = sa;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberPRBs()
{
   return physicalLayer_->getNumberPRBsPerSlot();
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberSlots()
{
   return physicalLayer_->getNumberSlots();
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getScheduledUserId( int slot , int prb )
{
   return physicalLayer_->getUserId( slot, prb );
}

//------------------------------------------------------------------------------

inline
double
PhysicalNode::
ENodeB::getFrequency( int slot , int prb )
{
   return physicalLayer_->getFrequency( slot, prb );
}

//------------------------------------------------------------------------------

inline
PhysicalLayer::PhysicalLayer*
PhysicalNode::
ENodeB::getPhysicalLayer()
{
   return physicalLayer_;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberLinkedUsers()
{
   return linkedUsers_.size();;
}

//------------------------------------------------------------------------------


inline
int
PhysicalNode::
ENodeB::getLinkedUserId( int index )
{
   int i = -1;
   
   if( index < linkedUsers_.size() && index > -1 )
   {
      i = linkedUsers_( index );
   }
   else
   {
      it_error("ENodeB: index out of range.");
   }
   
   return i;
}

//------------------------------------------------------------------------------


#endif

