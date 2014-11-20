/**
 * @file    FrequencyPlanning.h
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
       * Initializes numberENodeBs_, systemBandwitdh_, subcarrierBandwitdh_, centralFrequency_, reuse_, numberSCperPRB_. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Initializes simulationEnvironment_, numberSubcarriers_, numberPRBs_, each subcarrierFrequencies_ and each PRBFrequencies_.
       */
      void initialize();
      
      /**
       * Interface.
       * Clears frequencies_, subcarrierFrequencies_, PRBFrequencies_.
       */
      void clear();
      
      /**
       * Interface.
       * Allocate Frquencies determinated by the parameter reuse_.
       * reuse_ = 0: All the frequencies are used in all sectors of cell.
       * reuse_ = 1: The available frequencies are divided between the 3 sectors, each one of them with on
       * band of frequencies. The layout of reuse is the same in all the cells.
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
        /**
       * Member.
       * Left empty.
       */ 
       int reuse_;
};

};

#endif
