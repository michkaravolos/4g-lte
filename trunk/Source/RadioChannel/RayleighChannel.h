/**
 * @file    RayleighChannel.h
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
       * Generates the channel matrix.
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

