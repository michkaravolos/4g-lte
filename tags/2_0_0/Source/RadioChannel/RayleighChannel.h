/**
 * @file    RayleighChannel.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _RAYLEIGH_CHANNEL_H_
#define _RAYLEIGH_CHANNEL_H_

#include <itpp/itbase.h>

#include "Channel.h"

using namespace itpp;
using namespace std;

namespace RadioChannel
{
   
/**
 * RayleighChannel Class.
 * Detailed description.
 */
class RayleighChannel : public Channel
{
   public:
   
      /**
       * Constrcutor.
       * Detailed description.
       */   
      RayleighChannel();

      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~RayleighChannel();
      
      /**
       * Method.
       * Gera a matriz do canal
       * @return description.
       * @param rows description.
       * @param cols description;
       */
      cmat generateChannelMatrix( int rows, int cols );

   protected:

   private:

 
};

};

#endif /* _RAYLEIGH_CHANNEL_H_ */

