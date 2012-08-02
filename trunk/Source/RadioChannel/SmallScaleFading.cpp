/**
 * @file    SmallScaleFading.cpp
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

#include "SmallScaleFading.h"
#include "FrequencySelectiveChannel.h"
#include "VectorFunctions.h"
#include "SimulationParameters.h"
#include "SystemParameters.h"
#include "ChannelParameters.h"
#include "File.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

RadioChannel::
SmallScaleFading::SmallScaleFading()
{
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------

RadioChannel::
SmallScaleFading::~SmallScaleFading()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
RadioChannel::
SmallScaleFading::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   
   Parameters::ChannelParameters* cp = 
      Parameters::ChannelParameters::getInstance();
   
   numberUsers_ = sp->numberUsers;
   numberENodeBs_ = sp->numberENodeBs / 3;
   simulationTime_ = 1; 
   
   bandWidth_ = sysp->systemBandwidth;
   bandWidthSubcarrier_ = sysp->subcarrierBandwidth; 
   carrierFrequency_ = sysp->centralFrequency;
   numberAntennas_ = sysp->numberTransmitAntennas; 
   
   userSpeed_ = cp->userSpeed; 
   channelProfile_ = cp->profile;
   totalTime_ = cp->channelTime;
}

//------------------------------------------------------------------------------

void
RadioChannel::
SmallScaleFading::initialize()
{  
   //numberFrequencies_ = 2048;
   
   maximumDopplerShift_ = userSpeed_ * carrierFrequency_ / 3e8;
   
   totalTime_ = 1000; //numberUsers_* numberENodeBs_ * simulationTime_ * numberAntennas_;
   
   timeStep_ = 0.0;
   frequencyStep_ = 0.0;
   channel_.set_size( 0 );
   fading_.set_size( 0 );
   
}

//------------------------------------------------------------------------------

void
RadioChannel::
SmallScaleFading::createChannel()
{
   FrequencySelectiveChannel ch;
   ch.generateChannel( channel_ , bandWidth_, maximumDopplerShift_, 
      totalTime_, bandWidthSubcarrier_, timeStep_, frequencyStep_, 
      channelProfile_ );
   
}

//------------------------------------------------------------------------------

void
RadioChannel::
SmallScaleFading::generateFading( Array<vec>& fading )
{
   Basic::VectorFunctions vf;
   
   createChannel();
   int rows = channel_.size();
   int cols = channel_( 0 ).size();
   
   fading.set_size( rows );
   vf.setZerosArray( fading, cols );
   
   for( int i = 0; i < rows; ++i)
   {
      vf.generateSquare( channel_( i ) , fading( i ) );
   }
   
}

//------------------------------------------------------------------------------

double
RadioChannel::
SmallScaleFading::getTimeStep()
{
   return timeStep_;
   
}

//------------------------------------------------------------------------------

double
RadioChannel::
SmallScaleFading::getFrequencyStep()
{
   return frequencyStep_;  
}

//------------------------------------------------------------------------------

void
RadioChannel::
SmallScaleFading::saveFadingArray()
{
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





