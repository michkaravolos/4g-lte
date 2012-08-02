/**
 * @file    Frame.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Detailed description.
       */   
      Frame();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Frame();

      /**
       * Interface.
       * Detailed description.
       */   
      void interface();

             
   protected:
   
   
   private:
   

};

};

#endif

