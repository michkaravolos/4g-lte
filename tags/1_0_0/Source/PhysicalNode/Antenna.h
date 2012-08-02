/**
 * @file    Antenna.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Antenna_h_
#define _Antenna_h_

using namespace std;

namespace PhysicalNode
{

/**
 * Antenna Class.
 * Detailed description.
 */
class Antenna
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Antenna();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Antenna();
      
      /**
       * Retorna o ganho
       *
       */
      virtual double getGain( double theta );
      
      /**
       * Retorna o ganho em dB
       * 
       */
      virtual double getGain_dB( double theta );

             
   protected:
   
   
   private:
   

};

};

#endif

