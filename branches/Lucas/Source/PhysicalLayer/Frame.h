/**
 * @file    Frame.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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

#ifndef _Frame_h_
#define _Frame_h_

#include <itpp/itbase.h>

using namespace std;
using namespace itpp;

namespace PhysicalLayer
{

/**
 * Frame Class.
 * Detailed description.
 */
class Frame
{
   public:

      /**
       * Constructor.
       * Left empty.
       */   
      Frame();
      
      /**
       * Destructor.
       * Left empty.
       */   
      virtual ~Frame();

      /**
       * Interface.
       * Left empty.
       */   
      void interface();

             
   protected:
   
   
   private:
   

};

};

#endif

