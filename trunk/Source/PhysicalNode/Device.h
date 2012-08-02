/**
 * @file    Device.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Device_h_
#define _Device_h_

#include "Antenna.h"
#include "GenericAntenna.h"

using namespace std;

namespace PhysicalNode
{

/**
 * Device Class.
 * Detailed description.
 */
class Device
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Device();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Device();
      
      /**
       * Define os parâmetros do dispositivo
       * 
       */
      virtual void setParameters();
      
      /**
       * Inicializa o dispositivo
       * 
       */
      virtual void initialize();
      
      /**
       * Evoca a interface de antenna
       * 
       */
      virtual double getGain( double theta )= 0;
      
             
   protected:
           
      /**
       * Member
       * Detailed description
       */
      Antenna* antenna_;
      /**
       * Orientação
       * Trouxe de Transmitter para que Reciever também tenha orientation. Mas só faz sentido na eNodeB.
       */
      int orientation_;

      
      
      
   private:
   

};

};

#endif

