/**
 * @file    Subframe.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Subframe_h_
#define _Subframe_h_

#include <itpp/itbase.h>

#include "Slot.h"

using namespace std;
using namespace itpp;

namespace PhysicalLayer
{

/**
 * Subframe Class.
 * Detailed description.
 */
class Subframe
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Subframe();
      
      /**
       * Constructor.
       * Detailed description.
       */   
      Subframe( const vec PRBFrequencies );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Subframe();

      /**
       * Interface.
       * Detailed description.
       */   
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void initialize( const vec PRBFrequencies );
      
      /**
       * Interface.
       * Detailed description.
       */   
      Slot* getSlot( const int index );
      
      /**
       * Interface.
       * Detailed description.
       */   
      int getNumberSlots();

             
   protected:
      
      /**
       * Member
       * Detailed description
       */
      Array<Slot*> slots_;
      
      /**
       * Member
       * Detailed description
       */
      int numberSlotsPerRSubframe_;
   
   
   private:
   

};

};

inline
PhysicalLayer::Slot*
PhysicalLayer::
Subframe::getSlot( int index )
{
   Slot* s;
   if ( index < numberSlotsPerRSubframe_ )
   {
      s = slots_( index );
   }
   else
   {
      it_error( "Subframe: Index out of range" );
   }  
   return s; 
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
Subframe::getNumberSlots()
{
   return slots_.size();  
};

// -----------------------------------------------------------------------------

#endif

