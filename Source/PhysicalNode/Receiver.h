/**
 * @file    Receiver.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/21/2008
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

#ifndef _Reciever_h_
#define _Reciever_h_

#include "Antenna.h"
#include "Device.h"

using namespace std;

namespace PhysicalNode
{

/**
 * Receiver Class.
 * Detailed description.
 */
class Receiver : public Device
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Receiver(int orientation);
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Receiver();
      
      /**
       * Defines totalPower_.
       * 
       */
      void setParameters();
      
      /**
       * Initializes antenna_.
       * If Direction_ ==0, antenna_ = Antenna.
       * Else, antenna_ = GenericAntenna.
       */
      void initialize();
      
      /**
       * 
       */
      virtual double getGain( double theta );
      /**
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
       * Trouxe de Transmitter para que Receiver também tenha Potencia Total.
       */
      double totalPower_;
      
      

   
   
   private:
   


};

};

inline
double
PhysicalNode::
Receiver::getPower()
{
   return totalPower_;
};

#endif

