/**
 * @file    GenericAntenna.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Evoca getGain
       *
       */
      double getGain( double theta );
      
      /**
       * Evoca getGain_dB
       * 
       */
      double getGain_dB( double theta );

             
   protected:
      
      /**
       * Angulo de 3dB
       * 
       */
      double theta3dB_;
      
      /**
       * Mínimo ganho da antena
       * 
       */
      double minimumGaindB_;
   
   
   private:
   

};

};

#endif

