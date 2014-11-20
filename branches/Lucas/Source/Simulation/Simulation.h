/**
 * @file    Simulation.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
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

#ifndef _Simulation_h_
#define _Simulation_h_

#include <itpp/itbase.h>

#include "Statistics.h"
#include "RadioChannel.h"
#include "SimulationEnvironment.h"
#include "Link.h"
#include "FrequencyPlanning.h"
#include "Scheduler.h"
#include "Transmission.h"
#include "Results.h"
#include "TimeManager.h"
#include "LinkAdaptation.h"
#include "Grid.h"
#include "Mobility.h"


using namespace itpp;
using namespace std;

/**
 * Simulation Namespace. 
 * Detailed Description.
 */
namespace Simulation
{
   
/**
 * Simulation Class.
 * Detailed description.
 */
class Simulation
{
   public:
   
      /**
       * Calls setParameters and initialize.
       */	
      Simulation();

      /**
       * Destructor.
       * Detailed description.
       */	
      virtual ~Simulation();
      
      /**
       * Retrieves the parameters of simulation setled on SimulationParameters.dat and define the number of simulations.
       * Initializes simulationDrops_, numberSimulations_ and Direction_.
       */
      void setParameters();
      
       /**
       * Tests the Channel.
       */
      void testChannel();
      /**
       * 
       * Tests the losses.
       */
      void testLosses();
      /**
       * Tests path Losses.
       * 
       */
      void testPathLoss();
      /**
       * Tests the links
       * 
       */
      void testLink();
      /**
       * Shows the results of raw and efective rate.
       */
      void testResults();
      /**
       * Shows the total of links of ENodeBs, that are 57.
       */
      void testFrequencyPlanning();
      /**
       * Tests the fading.
       * 
       */
      void testFading();
      
      /**
       * Run all getInstances.
       * Which sets results_, grid_, mobility_, timeManager_, radioChannel_, simulationEnvironment_, link_, frequencyPlanning_, scheduler_, linkAdaptation_, transmission_.
       * Calls radioChannel_->generateSmallScaleFading.
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void initializeDrop();
      
      /**
       * Calculates the SINR, alklocates the resources and transmits, as settled on SimulationParameters.dat.
       */
      void runDrop();
      
      /**
       * Begin other Simulation round.
       * 
       */
      void runSimulation();
      
     /**
       * Finishes the round cleaning all data.
       */
      void finalizeDrop();
      
      /**
       * Starts and finishes the simulation.
       * 
       */
      void runCampaign();
     
      
   protected:
      
      /**
       * Member.
       * Left empty.
       */      
      Grid::Grid* grid_;
      
      /**
       * Member.
       * Left empty.
       */      
      Mobility::Mobility* mobility_;
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      /**
       * Member.
       * Left empty.
       */      
      RadioChannel::RadioChannel* radioChannel_;
      
      /**
       * Member.
       * Left empty.
       */      
      Link::Link* link_;
      
      /**
       * Member.
       * Left empty.
       */      
      LinkAdaptation::LinkAdaptation* linkAdaptation_;
      
      /**
       * Member.
       * Left empty.
       */      
      FrequencyPlanning::FrequencyPlanning* frequencyPlanning_;
      
      /**
       * Member.
       * Left empty.
       */      
      Scheduler::Scheduler* scheduler_;
      
      /**
       * Member.
       * Left empty.
       */      
      Transmission::Transmission* transmission_;
      
      /**
       * Member.
       * Left empty.
       */      
      Results::Results* results_;
      
      /**
       * Member.
       * Left empty.
       */      
      TimeManager::TimeManager* timeManager_;
      
      /**
       * Member.
       * Left empty.
       */      
      int simulationDrops_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberSimulations_;
      int Direction_;
   
   
   private:


};

};

#endif

