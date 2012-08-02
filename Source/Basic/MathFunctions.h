/**
 * @file    MathFunctions.h
 * Name:    3G LTE Statistics Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _MathFunctions_h_
#define _MathFunctions_h_

#include <itpp/itbase.h>

#include "Position.h"

using namespace itpp;
using namespace std;

/**
 * Basic Namespace. 
 * Detailed Description.
 */
namespace Basic
{

/**
 * MathFunctions Class. 
 * Detailed Description.
 */
class MathFunctions
{
   public:
           
      /**
       * Constructor.
       * Left empty.
       */
      MathFunctions();
      
      /**
       * Destructor.
       * Left empty.
       */
      ~MathFunctions();
          
      /**
       * Interface.
       * Detailed description.
       */
      void setPowerOf2( int& N );
       
      /**
       * Interface.
       * Detailed description.
       */
      double calculateDistance( Position p1, Position p2 );
      
      /**
       * Interface.
       * Detailed description.
       */
      double calculateAngle( Position p1, Position p2 );
         
      
   private:        
};

};

#endif
