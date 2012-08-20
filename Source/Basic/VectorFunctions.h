/**
 * @file    VectorFunctions.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
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
       * Left empty.
       */   
      VectorFunctions();
      
      /**
       * Destructor.
       * Left empty.
       */	
      virtual ~VectorFunctions();
      
      /**
       * Interface.
       * @param average If TRUE, normalizes by the average value of the sequence.
       * Normalizes the complex sequence.
       */
      void normalize( cvec& sequence, bool average );
      
      /**
       * Interface.
       * @param average If TRUE, normalizes by the average value of the sequence.
       * Normalizes the sequence.
       */
      void normalize( vec& sequence, bool average );
      
      /**
       * Interface.
       * Normalizes the matrix.
       */
      void normalize( Array<cvec>& matrix, bool average );
      
      /**
       * Interface.
       * @param cols Defines the size of each row of sequence.
       * Sets zeros on each col of each row of sequence.
       */
      void setZerosArray( Array<vec>& sequence, int cols );
      
      /**
       * Interface.
       * @param cols Defines the size of each row of sequence.
       * Sets zeros on each col of each row of complex sequence.
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
       * @param input Complex vector.
       * @param output Vector of square value of each row of input.
       */
      void generateSquare( cvec& input, vec& output );

             
   protected:
    
   
   private:
   

};

};

#endif

