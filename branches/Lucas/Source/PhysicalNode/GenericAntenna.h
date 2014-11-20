/**
 * @file    GenericAntenna.h
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

#ifndef _GenericAntenna_h_
#define _GenericAntenna_h_

#include "Antenna.h"

using namespace std;

namespace PhysicalNode
{

/**
 * GenericAntenna Class.
 * Detailed description.
 */
class GenericAntenna : public Antenna
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      GenericAntenna();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~GenericAntenna();
      
      /**
       * Defines theta3dB_ and minimumGaindB_.
       * 
       */
      void setParameters();
      
      /**
       * Returns Gain of the generic Antenna.
       *
       */
      double getGain( double theta );
      
      /**
       * Returns Gain of the generic Antenna in dB.
       * 
       */
      double getGain_dB( double theta );

             
   protected:
      
      /**
       * 3dB Angle.
       * 
       */
      double theta3dB_;
      
      /**
       * Minimum gain of the antenna in dB.
       * 
       */
      double minimumGaindB_;
   
   
   private:
   

};

};

#endif

