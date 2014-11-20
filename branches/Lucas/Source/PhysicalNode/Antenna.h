/**
 * @file    Antenna.h
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
       * Returns gain.
       * Whereas this antenna is an isotropic antenna, it returns 1.
       */
      virtual double getGain( double theta );
      
      /**
       * Returns gain in dB.
       * Whereas this antenna is an isotropic antenna, it returns 0.
       */
      virtual double getGain_dB( double theta );

             
   protected:
   
   
   private:
   

};

};

#endif

