/**
 * @file    FrequencyPlanning.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _FrequencyPlanning_h_
#define _FrequencyPlanning_h_

#include <itpp/itbase.h>

#include "SimulationEnvironment.h"

using namespace itpp;
using namespace std;

/**
 * FrequencyPlanning Namespace. 
 * Detailed Description.
 */
namespace FrequencyPlanning
{

/**
 * FrequencyPlanning Class. 
 * Detailed Description.
 */
class FrequencyPlanning
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~FrequencyPlanning();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static FrequencyPlanning* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void clear();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void allocateFrequencies();
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      FrequencyPlanning();
      
      /**
       * Member.
       * Left empty.
       */      
      static FrequencyPlanning* instance_;      
      
      /**
       * Member.
       * Left empty.
       */      
      string name_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs_;  
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      /**
       * Member.
       * Left empty.
       */      
      double systemBandwitdh_;
      
      /**
       * Member.
       * Left empty.
       */      
      double subcarrierBandwitdh_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberSubcarriers_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberSCperPRB_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberPRBs_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec frequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec subcarrierFrequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec PRBFrequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      double centralFrequency_;
};

};

#endif
