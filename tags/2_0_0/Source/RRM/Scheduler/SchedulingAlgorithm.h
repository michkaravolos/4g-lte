/**
 * @file    SchedulingAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _SchedulingAlgorithm_h_
#define _SchedulingAlgorithm_h_

#include <itpp/itbase.h>

#include <vector>

#include "Slot.h"
#include "PhysicalLayer.h"
#include "LinkAdaptation.h"
#include "PhysicalResourceBlock.h"
#include "TimeManager.h"



using namespace std;
using namespace itpp;

namespace Scheduler
{

/**
 * SchedulingAlgorithm Class.
 * Detailed description.
 */
class SchedulingAlgorithm
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      SchedulingAlgorithm();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~SchedulingAlgorithm();

      /**
       * Define os parametros
       * 
       */   
      virtual void setParameters();
      
      /**
       * Inicializa os parametros
       *
       */   
      virtual void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */   
      //virtual void frequencySchedule();
      
      /**
       * Interface.
       * Detailed description.
       */   
      //virtual void antennaSchedule();
      
      /**
       * Realiza a alocação de recursos por usuário
       * 
       */  
      virtual void schedule( const ivec& users, 
                     PhysicalLayer::PhysicalLayer* pl, int Direction);
      /**
       * Member.
       * Left empty.
       */      
      ivec schedulerUsers_;
      
      /**
       * Member.
       * Left empty.
       */   
      int schedulerUsers_R (int index1);
      
      /**
       * Member.
       * Left empty.
       */ 
      int j1_R ();
      
      /**
       * Member.
       * Left empty.
       */ 
      
      int index_R (int j11);
      
      int ind[200];
   
      int j1[1];
     
      


             
   protected:
     
      
      /**
       * Configura os Physical Resource Blocks
       * 
       */  
      virtual void configurePRBs( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Configura os PRBs por slot
       * 
       */  
      virtual void configurePRBsPerSlot( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Calcula a metrica no dominio do tempo
       * 
       */   
      virtual double calculateTimeMetric( double averageCQI, 
                                          double throughput ) = 0;
      
      /**
       * Calcula a metrica no dominio da frequencia
       * 
       */   
      virtual double calculateFrequencyMetric( double averageCQI, 
                                               double throughput ) = 0;
      
      /**
       * Calcula a metrica espacial
       * 
       */   
      virtual double calculateSpaceMetric( double averageCQI, 
                                           double throughput  ) = 0;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberUsersPerSlot_;   
      
       /**
       * Member.
       * Left empty.
       */      
      int numberAntennas_;   
      
      /**
       * Member.
       * Left empty.
       */      
      bool sameUserAtSlots_;
      
      
        
      /**
       * Aloca o tempo
       * 
       */  
      virtual void timeSchedule( const ivec& users, ivec& scheduledUsers );
      
      /**
       * Member.
       * Left empty.
       */      
      LinkAdaptation::LinkAdaptation* linkAdaptation_;
      
      
      
      /**
       * Member.
       * Left empty.
       */      
      Array< vec > usersFrequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      Array< Array< vector< PhysicalLayer::PhysicalResourceBlock* > > > usersPRBs_;   
      
      /**
       * Member.
       * Left empty.
       */      
      TimeManager::TimeManager* timeManager_;
   
   private:
   
      int counter;
      
      double totalSINR_;

};

};

#endif

