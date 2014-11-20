/**
 * @file    SystemParameters.h
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

#ifndef _SystemParameters_h_
#define _SystemParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * SystemParameters Class. 
 * Detailed Description.
 */
class SystemParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~SystemParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static SystemParameters* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void readFile();
      
      /**
       * Member.
       * System Bandwidth.
       */
      double systemBandwidth;
      
      /**
       * Member.
       * Carrier frequency;.
       */
      double centralFrequency;
      
      /**
       * Member.
       * Subcarrier bandwidth.
       */
      double subcarrierBandwidth;
      
      /**
       * Member.
       * Subcarrier bandwidth.
       */
      double totalPower;

      /**
       * Member.
       * Left empty.
       */      
      int numberTransmitAntennas;
       /**
       * Member.
       * Left empty.
       */ 
      
      int reuse;

      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      SystemParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static SystemParameters* instance_;          
};

};

#endif
