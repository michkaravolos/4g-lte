/**
 * @file    PhysicalLayer.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/28/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _PhysicalLayer_h_
#define _PhysicalLayer_h_

#include <itpp/itbase.h>

#include "Subframe.h"

using namespace std;
using namespace itpp;

/**
 * PhysicalLayer Namespace. 
 * Detailed Description.
 */
namespace PhysicalLayer
{

/**
 * PhysicalLayer Class.
 * Detailed description.
 */
class PhysicalLayer
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      PhysicalLayer();
      
      /**
       * Constructor.
       * Detailed description.
       */   
      PhysicalLayer( const vec PRBFrequencies, const vec SCFrequencies );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~PhysicalLayer();

      /**
       * Interface.
       * Detailed description.
       */   
      void initialize( const vec PRBFrequencies );
      
      /**
       * Interface.
       * Detailed description.
       */  
      Subframe getSubframeAsObject();
      
      /**
       * Interface.
       * Detailed description.
       */  
      int getNumberPRBsPerSlot();
      
      /**
       * Interface.
       * Detailed description.
       */  
      int getNumberSlots();
      
      /**
       * Interface.
       * Detailed description.
       */  
      PhysicalResourceBlock* getPRB( const int slot, 
                                     const int prb );
      
      /**
       * Interface.
       * Detailed description.
       */  
      void setUser( const int slot, 
                    const int prb, 
                    const int userId );
      
      /**
       * Interface.
       * Detailed description.
       */  
      int getUserId( const int slot, 
                     const int prb );
      
      /**
       * Interface.
       * Detailed description.
       */  
      double getFrequency( const int slot, 
                           const int prb );
      
      /**
       * Member
       * Detailed description
       */
      int getRawBits( const int slot, 
                         const int prb );
      /**
       * Member
       * Detailed description
       */
      double getEffectiveBits( const int slot, 
                               const int prb );
      
      /**
       * Member
       * Detailed description
       */
      void clearUsers();
      
      /**
       * Member
       * Detailed description
       */
      int getNumberFrequencies();
      
      /**
       * Member
       * Detailed description
       */
      int getNumberSCFrequencies();
      
      /**
       * Member
       * Detailed description
       */
      double getFrequency( int index );
      
      /**
       * Member
       * Detailed description
       */
      double getSCFrequency( int index );
      
      /**
       * Member
       * Detailed description
       */
      vec getFrequencies();
      
      /**
       * Member
       * Detailed description
       */
      vec getSCFrequencies();
      
      /**
       * Member
       * Detailed description
       */
      Subframe* getSubframe();
                  
   protected:
      
      /**
       * Member.
       * Left empty.
       */      
      Subframe* subframe_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec frequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec SCfrequencies_;
   
   
   private:
   

};

};

inline
PhysicalLayer::Subframe
PhysicalLayer::
PhysicalLayer::getSubframeAsObject()
{
   return *subframe_;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getNumberPRBsPerSlot()
{
   return ( subframe_->getSlot( 0 ) )->getNumberPRBs();
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getNumberSlots()
{
   return subframe_->getNumberSlots();
};

// -----------------------------------------------------------------------------

inline
PhysicalLayer::PhysicalResourceBlock*
PhysicalLayer::
PhysicalLayer::getPRB( const int slot, const int prb )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   
   return p;
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
PhysicalLayer::setUser( int slot, int prb, int userId )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   p->setUser( userId, 0 );
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getUserId( const int slot, const int prb )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   
   return p->getUserId();
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalLayer::getFrequency( const int slot, const int prb )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   
   return p->getFrequency();
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getRawBits( const int slot, const int prb )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   
   return p->getRawBits();
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalLayer::getEffectiveBits( const int slot, const int prb )
{
   Slot* s = subframe_->getSlot( slot );
   PhysicalResourceBlock* p = s->getPRB( prb );
   
   return p->getEffectiveBits();
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
PhysicalLayer::clearUsers()
{
   int ns = subframe_->getNumberSlots();
   for( int i = 0; i < ns; ++i )
   {
      Slot* s = subframe_->getSlot( i );
      int nprbs = s->getNumberPRBs();
      for( int j = 0; j < nprbs; ++j )
      {
         PhysicalResourceBlock* prb = s->getPRB( j );
         prb->clearUser();
      }
   }
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getNumberFrequencies()
{
   return frequencies_.size();
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalLayer::getNumberSCFrequencies()
{
   return SCfrequencies_.size();
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalLayer::getFrequency( int index )
{
   double f = -1.0;
   if( index < frequencies_.size() )
   {
      f = frequencies_( index );
   }
   else
   {
      it_error("Physical Layer: index out of range.");
   }
   
   return f;
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalLayer::getSCFrequency( int index )
{
   double f = -1.0;
   if( index < SCfrequencies_.size() )
   {
      f = SCfrequencies_( index );
   }
   else
   {
      it_error("Physical Layer: index out of range.");
   }
   
   return f;
};

// -----------------------------------------------------------------------------

inline
vec
PhysicalLayer::
PhysicalLayer::getFrequencies()
{
   return frequencies_;
};

// -----------------------------------------------------------------------------

inline
vec
PhysicalLayer::
PhysicalLayer::getSCFrequencies()
{
   return SCfrequencies_;
};

// -----------------------------------------------------------------------------

inline
PhysicalLayer::Subframe*
PhysicalLayer::
PhysicalLayer::getSubframe()
{
   return subframe_;
};

// -----------------------------------------------------------------------------

#endif

