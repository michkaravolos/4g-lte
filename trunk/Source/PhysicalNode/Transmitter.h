/**
 * @file    Transmitter.h
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
       * Defines totalPower_.
       * 
       */
      void setParameters();
      
      /**
       * Inicializes Direction_ and antenna_.
       * If Direction_ ==0, antenna_ = GenericAntenna.
       * Else, antenna_ = Antenna.
       */
      void initialize();
      
      /**
       * Returns Gain.
       * 
       */
      double getGain( double theta );
      
      /**
       * Returns totalPower_.
       * 
       */
      double getPower();
      
             
   protected:
      

      /**
       * Total Power of the transmitter.
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

