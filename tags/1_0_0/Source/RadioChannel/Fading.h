/**
 * @file    Fading.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Fading_h_
#define _Fading_h_

#include <itpp/itbase.h>

using namespace std;
using namespace itpp;

using namespace std;

namespace RadioChannel
{

/**
 * Fading Class.
 * Detailed description.
 */
class Fading
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Fading();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Fading();
      
      /**
       * Define os parâmetros
       * 
       */
      void setParameters();
             
   protected:
   
   
   private:
   

};

};

#endif

