/**
 * @file    Subcarrier.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Subcarrier_h_
#define _Subcarrier_h_

#include <itpp/itbase.h>
#include "ResourceElement.h"

using namespace itpp;
using namespace std;

namespace PhysicalLayer
{

/**
 * Subcarrier Class.
 * Detailed description.
 */
class Subcarrier
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Subcarrier( double frequency );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Subcarrier();

      /**
       * Interface.
       * Detailed description.
       */   
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void initialize( double frequency );
      
      /**
       * Member
       * Detailed description
       */
      int getRawBits();
      
      /**
       * Member
       * Detailed description
       */
      double getEffectiveBits();
      
      /**
       * Member
       * Detailed description
       */
      double getFrequency();
      
      /**
       * Member
       * Detailed description
       */
      int getNumberREs();
      
      /**
       * Member
       * Detailed description
       */
      ResourceElement* getRE( int index );

             
   protected:
      
      /**
       * Member
       * Detailed description
       */
      int numberResourceElements_;
      
      /**
       * Member
       * Detailed description
       */
      Array<ResourceElement*> resourceElements_;
      
      /**
       * Member
       * Detailed description
       */
      double frequency_;
   
     /**
       * Member
       * Detailed description
       */
     int SoundingSlots_;
     /**
       * Member
       * Detailed description
       */
     int Direction_;
     
     
   private:
   

};

};

inline
int
PhysicalLayer::
Subcarrier::getRawBits()
{
   int r = 0;
   int size = resourceElements_.size();
   
   for( int i = 0; i < size; ++i )
   {
      r += resourceElements_(i)->getRawBits(); 
   }
   
   return r;
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
Subcarrier::getEffectiveBits()
{
   double e = 0.0;
   int size = resourceElements_.size();
   
   for( int i = 0; i < size; ++i )
   {
      e += resourceElements_(i)->getEffectiveBits(); 
   }
   
   return e;
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
Subcarrier::getFrequency()
{
   return frequency_;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
Subcarrier::getNumberREs()
{
   return resourceElements_.size();
};

// -----------------------------------------------------------------------------


inline
PhysicalLayer::ResourceElement*
PhysicalLayer::
Subcarrier::getRE( int index )
{
   ResourceElement* re = 0;
   if ( index < resourceElements_.size() )
   {
      re = resourceElements_( index );
   }
   else
   {
      it_error( "Subcarrier: Index out of range" );
   }  
   
   return re;
};

// -----------------------------------------------------------------------------

#endif

