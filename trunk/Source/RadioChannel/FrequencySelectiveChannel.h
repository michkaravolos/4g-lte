/**
 * @file    FrequencySelectiveChannel.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Cria o canal seletivo em frequência
       * 
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
