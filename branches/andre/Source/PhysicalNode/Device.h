/**
 * @file    Device.h
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
       * Calls setParameters and initialize.
       */   
      Device();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Device();
      
      /**
       * Left white.
       * 
       */
      virtual void setParameters();
      
      /**
       * Left white.
       * 
       */
      virtual void initialize();
      
      /**
       * Detailed description.
       */
      virtual double getGain( double theta )= 0;
      
             
   protected:
           
      /**
       * Member
       * Detailed description
       */
      Antenna* antenna_;
      /**
       * Orientation.
       * It came from Transmitter so that Receiver has an orienation too.
       */
      int orientation_;

      
      
      
   private:
   

};

};

#endif

