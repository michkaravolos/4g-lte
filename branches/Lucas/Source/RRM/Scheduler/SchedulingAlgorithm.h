/**
 * @file    SchedulingAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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
       * Calls setParameters and initialize.
       */   
      SchedulingAlgorithm();
      
      /**
       * Destructor.
       * Clears usersPRBs_.
       */   
      virtual ~SchedulingAlgorithm();

      /**
       * Defines numberUsersPerSlot_, sameUserAtSlots_, numberAntennas_.
       */   
      virtual void setParameters();
      
      /**
       * Initializes linkAdaptation_, timeManager_, usersPRBs_ and totalSINR_.
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
       * Allocates resources per user.
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
       * Configures the Physical Resource Blocks.
       */  
      virtual void configurePRBs( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Configures the PRBs per slot.
       * 
       */  
      virtual void configurePRBsPerSlot( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Calculates the metric in time domain.
       */   
      virtual double calculateTimeMetric( double averageCQI, 
                                          double throughput ) = 0;
      
      /**
       * Calculates the metric in frequency domain.
       * 
       */   
      virtual double calculateFrequencyMetric( double averageCQI, 
                                               double throughput ) = 0;
      
      /**
       * Calculates the metric in space domain.
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
       * Allocate time.
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

