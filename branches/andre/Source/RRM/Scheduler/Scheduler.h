/**
 * @file    Scheduler.h
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
       * Initialize parameters numberENodeBs_ and schedulingAlgorithm_.
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
       * Left empty.
       */
      void clear();
      
      /**
       * Defines the resource alocation algorithm according to schedulingAlgorithm_.
       */
      void setSchedulingAlgorithm();
      
      /**
       * Allocation of resources to ENodeBs.
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
       * Defined in SchedulerParameters.
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
