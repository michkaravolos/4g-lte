/**
 * @file    Slot.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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

#ifndef _Slot_h_
#define _Slot_h_

#include <itpp/itbase.h>

#include "PhysicalResourceBlock.h"

using namespace std;
using namespace itpp;

namespace PhysicalLayer
{

/**
 * Slot Class.
 * Detailed description.
 */
class Slot
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Slot();
      
      /**
       * Constructor.
       * Detailed description.
       */   
      Slot( vec PRBFrequecies );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Slot();

      /**
       * Interface.
       * Detailed description.
       */   
      void initialize( const vec PRBFrequencies );
      
      /**
       * Interface.
       * Detailed description.
       */  
      PhysicalResourceBlock* getPRB( const double Frequency );
      
      /**
       * Interface.
       * Detailed description.
       */  
      PhysicalResourceBlock* getPRB( const int index );
      
      /**
       * Interface.
       * Detailed description.
       */  
      int getNumberPRBs();
      
      
           
   protected:
      
      /**
       * Member.
       * Left empty.
       */      
      Array<PhysicalResourceBlock*> PRBs_;
   
   
   private:
   

};

};

inline
PhysicalLayer::PhysicalResourceBlock*
PhysicalLayer::
Slot::getPRB( double Frequency )
{
   int size = PRBs_.size();
   int index = -1;
   for( int i = 0; i < size; ++i )
   {
      if( Frequency == PRBs_( i )->getFrequency() )
      {
         index = i;
         break;
      }
   }
   
   if( index != -1 )
   {
      return getPRB( index );
   }
   else
   {
      it_error("Slot: Frequency does not exist.");
   }
};

// -----------------------------------------------------------------------------

inline
PhysicalLayer::PhysicalResourceBlock*
PhysicalLayer::
Slot::getPRB( int index )
{
   PhysicalResourceBlock* prb;
   if ( index < PRBs_.size() )
   {
      prb = PRBs_( index );
   }
   else
   {
      it_error("Slot: Index out of range");
   }  
   
   return prb;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
Slot::getNumberPRBs()
{
   return PRBs_.size();  
};

// -----------------------------------------------------------------------------

#endif

