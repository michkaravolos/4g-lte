/**
 * @file    FrequencySelectiveChannel.h
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

#ifndef _FREQUENCY_SELECTIVE_CHANNEL_H_
#define _FREQUENCY_SELECTIVE_CHANNEL_H_

#include <itpp/itbase.h>
#include <itpp/comm/channel.h>

#include "ClarkeChannel.h"

using namespace itpp;
using namespace std;

namespace RadioChannel
{

/**
 * FrequencySelectiveChannel Class.
 *
 */
class FrequencySelectiveChannel : public Channel
{
   public:
   
      /**
       * Creates the selective channel on the frequency.
       */            
      void generateChannel( Array<cvec>& Channel,
                                    const double BW, 
                                    const double fm,
                                    const double simulationTime, 
                                    const double BW_subcarrier,
                                    double& timeStep,
                                    double& frequencyStep,
                                    CHANNEL_PROFILE profile);
      
      
      
      



   protected:

   private:

 
};

};

#endif
