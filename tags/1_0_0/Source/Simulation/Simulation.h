/**
 * @file    Simulation.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Define os parametros de simulacao e inicializa as demais classes relacionadas a simulacao
       * 
       */	
      Simulation();

      /**
       * Destructor.
       * Detailed description.
       */	
      virtual ~Simulation();
      
      /**
       * Resgata os parametros de simulacao setados em SimulationParameters.dat
       * e define o numero de simulacoes.
       */
      void setParameters();
      
      /**
       * Cada função realiza um teste específico
       * 
       */
      void testChannel();
      void testLosses();
      void testPathLoss();
      void testLink();
      void testResults();
      void testFrequencyPlanning();
      void testFading();
      
      /**
       * Inicializa as classes da simulacao resgatando as situações de cada classes
       * geralmente iniciando novamente
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void initializeDrop();
      
      /**
       * Calcula o ruído acrescido de interferencia, aloca os recursos e transmite
       * um certo números de vezes setados em SimulationParameters.dat StepsPerDrop.
       */
      void runDrop();
      
      /**
       * Inicia outra rodada
       * 
       */
      void runSimulation();
      
     /**
       * Finaliza a rodada limpando todos os dados
       * 
       */
      void finalizeDrop();
      
      /**
       * Inicializa e finaliza a simulacao
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

