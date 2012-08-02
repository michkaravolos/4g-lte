/**
 * @file    Scheduler.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Scheduler_h_
#define _Scheduler_h_

#include "SimulationEnvironment.h"

using namespace itpp;
using namespace std;

/**
 * Scheduler Namespace. 
 * Detailed Description.
 */
namespace Scheduler
{

/**
 * Scheduler Class. 
 * Detailed Description.
 */
class Scheduler
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Scheduler();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static Scheduler* getInstance();

      /**
       * Define os parametros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa a alocação
       * 
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void clear();
      
      /**
       * Define o algoritmo de alocação de recursos
       * 
       */
      void setSchedulingAlgorithm();
      
      /**
       * Realiza a alocação de recursos para as EnodeBs
       * 
       */
      void schedule(int Direction);
      
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Scheduler();
      
      /**
       * Member.
       * Left empty.
       */      
      static Scheduler* instance_;    
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
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
      int schedulingAlgorithm_; 
      
      /**
       * Member.
       * Left empty.
       */  
      bool sameUserAtSlots_;
};

};

#endif
