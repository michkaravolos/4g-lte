/**
 * @file    Fading.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
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
       * Left empty.
       */   
      Fading();
      
      /**
       * Destructor.
       * Left empty.
       */   
      virtual ~Fading();
      
      /**
       * Left empty.
       * 
       */
      void setParameters();
             
   protected:
   
   
   private:
   

};

};

#endif

