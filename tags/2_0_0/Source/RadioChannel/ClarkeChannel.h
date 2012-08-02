/**
 * @file    ClarkeChannel.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Gera vetor complexo
       * 
       */    
      cvec generateComplexVector( int N, double fm );
      
      /**
       * Gera vetor abosuto
       * 
       */  
      vec generateAbsoluteVector( int N, double fm );
      
      
      /**
       * Calcula o espectro
       * 
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
