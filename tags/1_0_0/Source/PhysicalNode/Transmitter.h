/**
 * @file    Transmitter.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Transmitter_h_
#define _Transmitter_h_

#include "Antenna.h"
#include "GenericAntenna.h"
#include "Device.h"

using namespace std;

namespace PhysicalNode
{

/**
 * Transmitter Class.
 * Detailed description.
 */
class Transmitter : public Device
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Transmitter( int orientation );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Transmitter();
      
      /**
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa o transmissor
       * 
       */
      void initialize();
      
      /**
       * Retorna o ganho
       * 
       */
      double getGain( double theta );
      
      /**
       * Evoca getPower
       * 
       */
      double getPower();
      
             
   protected:
      

      /**
       * Potencia Toral
       * 
       */
      double totalPower_;
      

   private:
      
      /**
       * Member
       * Detailed description
       */
      //Antenna* antenna_;
   

};

};

inline
double
PhysicalNode::
Transmitter::getPower()
{
   return totalPower_;
};

//------------------------------------------------------------------------------

#endif

