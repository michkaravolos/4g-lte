/**
 * @file    ClarkeChannel.h
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

#ifndef _CLARKE_CHANNEL_H_
#define _CLARKE_CHANNEL_H_

#include <itpp/itbase.h>

#include "Channel.h"

using namespace itpp;
using namespace std;

namespace RadioChannel
{
   
/**
 * ClarkeChannel Class.
 * Detailed description.
 */
class ClarkeChannel : public Channel
{
   public:
   
      /**
       * Generates the complex vector.
       */    
      cvec generateComplexVector( int N, double fm );
      
      /**
       * Generates the absolute vector.
       */  
      vec generateAbsoluteVector( int N, double fm );
      
      
      /**
       * Calculates the spectrum.
       */
      double calculateSpectrum( double f, double fc, double fm );
      
   protected:
   
      /**
       * Method.
       * Detailed description.
       * @return description.
       * @param f description.
       * @param fc description.
       * @param fm description.
       */  
      

   private:


};

};

#endif
