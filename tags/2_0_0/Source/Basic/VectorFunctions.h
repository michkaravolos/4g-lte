/**
 * @file    VectorFunctions.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _VectorFunctions_h_
#define _VectorFunctions_h_

#include <itpp/itbase.h>

using namespace itpp;
using namespace std;

namespace Basic
{

/**
 * VectorFunctions Class.
 * Detailed description.
 */
class VectorFunctions
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      VectorFunctions();
      
      /**
       * Destructor.
       * Detailed description.
       */	
      virtual ~VectorFunctions();
      
      /**
       * Interface.
       * Detailed description.
       */
      void normalize( cvec& sequence, bool average );
      
      /**
       * Interface.
       * Detailed description.
       */
      void normalize( vec& sequence, bool average );
      
      /**
       * Interface.
       * Detailed description.
       */
      void normalize( Array<cvec>& matrix, bool average );
      
      /**
       * Interface.
       * Detailed description.
       */
      void setZerosArray( Array<vec>& sequence, int cols );
      
      /**
       * Interface.
       * Detailed description.
       */
      void setZerosArray( Array<cvec>& sequence, int cols );
      
      /**
       * Interface.
       * Detailed description.
       */
      void transposeArray( Array<vec>& input, Array<vec>& output );
      
      /**
       * Interface.
       * Detailed description.
       */
      void transposeArray( Array<cvec>& input, Array<cvec>& output );
      
      /**
       * Interface.
       * Detailed description.
       */
      void printEnergy( cvec& sequence );
      
      /**
       * Interface.
       * Detailed description.
       */
      void printEnergy( Array<cvec>& matrix );
      
      /**
       * Interface.
       * Detailed description.
       */
      void generateAbsolute( cvec& input, vec& output );
      
      /**
       * Interface.
       * Detailed description.
       */
      void generateSquare( cvec& input, vec& output );

             
   protected:
    
   
   private:
   

};

};

#endif

