/**
 * @file    AntennaParameters.h
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

#ifndef _AntennaParameters_h_
#define _AntennaParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * AntennaParameters Class. 
 * Detailed Description.
 */
class AntennaParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~AntennaParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static AntennaParameters* getInstance();

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
       * Member
       * Detailed description
       */
      double theta3dB;
      
      /**
       * Member
       * Detailed description
       */
      double minimumGaindB;
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      AntennaParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static AntennaParameters* instance_; 
      
      
};

};

#endif
