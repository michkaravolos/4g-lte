/**
 * @file    Channel.h
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
       * Left empty.
       */	
      Channel();

      /**
       * Destructor.
       * Left empty.
       */	
      virtual ~Channel();

   protected:

   private:

};

};

#endif 

