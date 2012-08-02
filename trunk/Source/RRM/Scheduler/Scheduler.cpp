/**
 * @file    Scheduler.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include "Scheduler.h"

#include "SchedulerParameters.h"
#include "SimulationParameters.h"
#include "RandomAlgorithm.h"
#include "BestCQIAlgorithm.h"
#include "ProportionalFairAlgorithm.h"
#include "ENodeB.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Scheduler::Scheduler* 
   Scheduler::Scheduler::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Scheduler::
Scheduler::Scheduler()
{
   name_ = "Scheduler: ";
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

Scheduler::
Scheduler::~Scheduler()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Scheduler::Scheduler* 
Scheduler::
Scheduler::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Scheduler();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Scheduler::
Scheduler::setParameters()
{
   //cout << name_ 
        //<< "Start reading parameters" 
        //<< endl;
   
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   Parameters::SchedulerParameters* schp = 
      Parameters::SchedulerParameters::getInstance();
   
   numberENodeBs_ = sp->numberENodeBs;
   schedulingAlgorithm_ = schp->schedulingAlgorithm;
   
   
   //cout << name_ 
        //<< "Finished reading parameters" 
        //<< endl;
}

//------------------------------------------------------------------------------

void
Scheduler::
Scheduler::initialize()
{
   simulationEnvironment_ = SimulationEnvironment::
      SimulationEnvironment::getInstance();
}

//------------------------------------------------------------------------------

void
Scheduler::
Scheduler::clear()
{
}

//------------------------------------------------------------------------------

void
Scheduler::
Scheduler::setSchedulingAlgorithm()
{
   PhysicalNode::ENodeB* e;
   SchedulingAlgorithm* sa;
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      e = simulationEnvironment_->getENodeB( i );
      switch( schedulingAlgorithm_ )
      {
         case 0:
            sa = new RandomAlgorithm();
            break;
            
         case 1:
            sa = new BestCQIAlgorithm();
            break;
         
         case 2:
            sa = new ProportionalFairAlgorithm();
            break;
            
         default:
            sa = new ProportionalFairAlgorithm();       
      }   
      e->setSchedulingAlgorithm( sa );
   }
   
}

//------------------------------------------------------------------------------

void
Scheduler::
Scheduler::schedule(int Direction)
{
   PhysicalNode::ENodeB* e;
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      e = simulationEnvironment_->getENodeB( i );
      e->scheduleUsers(Direction);
   }
   
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
