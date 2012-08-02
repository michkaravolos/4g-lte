/**
 * @file    receiver.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/21/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Reciever_h_
#define _Reciever_h_

#include "Antenna.h"
#include "Device.h"

using namespace std;

namespace PhysicalNode
{

/**
 * receiver Class.
 * Detailed description.
 */
class receiver : public Device
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      receiver(int orientation);
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~receiver();
      
      /**
       * Define os parametros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa o receiver
       * 
       */
      void initialize();
      
      /**
       * Evoca getGain
       * 
       */
      virtual double getGain( double theta );
      /**
       * Evoca getPower
       * 
       */
      double getPower();

                   
   protected:
    
      /**
       * Member
       * Detailed description
       */
      //Antenna* antenna_;
      
      
      /**
       * Potencia Toral
       * Trouxe de Transmitter para que receiver também tenha Potencia Total.
       */
      double totalPower_;
      
      

   
   
   private:
   


};

};

inline
double
PhysicalNode::
receiver::getPower()
{
   return totalPower_;
};

#endif

