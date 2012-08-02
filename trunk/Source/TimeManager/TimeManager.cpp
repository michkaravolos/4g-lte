/**
 * @file    TimeManager.cpp
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

#include "TimeManager.h"

#include "SimulationParameters.h"
#include "PhysicalLayerParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

TimeManager::TimeManager* 
   TimeManager::TimeManager::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

TimeManager::
TimeManager::TimeManager()
{
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

TimeManager::
TimeManager::~TimeManager()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

TimeManager::TimeManager* 
TimeManager::
TimeManager::getInstance()
{
   if ( !instance_ )
   {
      instance_ = new TimeManager();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
TimeManager::
TimeManager::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   Parameters::PhysicalLayerParameters* plp = 
      Parameters::PhysicalLayerParameters::getInstance();
   
   totalSteps_ = sp->StepsPerDrop;
   timeStep_ = plp->slotTimeLength * plp->numberSlotsPerRSubframe;
}

//------------------------------------------------------------------------------


void
TimeManager::
TimeManager::initialize()
{
   currentStep_ = 0;
   currentTime_ = 0.0;
   currentResolutionStep_ = 0;
   totalTime_ = totalSteps_ * timeStep_;
   resolutionStepHasChanged_ = true;
}

//------------------------------------------------------------------------------

void
TimeManager::
TimeManager::clear()
{
   
}
//------------------------------------------------------------------------------

void
TimeManager::
TimeManager::update()
{
   currentTime_ += timeStep_;
   currentStep_++;
   int c = static_cast<int>( currentTime_ / timeResolution_ );
      
   if( c > currentResolutionStep_ )
   {
       resolutionStepHasChanged_ = true;
   }
   else
   {
      resolutionStepHasChanged_ = false;
   }
   
   currentResolutionStep_ = c;
};

// -----------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
