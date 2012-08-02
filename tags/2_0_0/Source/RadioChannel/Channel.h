/**
 * @file    Channel.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Channel_h_
#define _Channel_h_

#include <itpp/itbase.h>

#include "VectorFunctions.h"
#include "MathFunctions.h"

using namespace itpp;
using namespace std;

namespace RadioChannel
{

/**
 * Channel Class.
 * Detailed description.
 */
class Channel
{
   public:
   
      /**
       * Constrcutor.
       * Detailed description.
       */	
      Channel();

      /**
       * Destructor.
       * Detailed description.
       */	
      virtual ~Channel();

   protected:

   private:

};

};

#endif 

