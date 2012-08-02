/**
 * @file    MobilityParameters.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _MobilityParameters_h_
#define _MobilityParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * MobilityParameters Class. 
 * Detailed Description.
 */
class MobilityParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~MobilityParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static MobilityParameters* getInstance();

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
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      MobilityParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static MobilityParameters* instance_;          
};

};

#endif
