/**
 * @file    ChannelParameters.cpp
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

#include "ChannelParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::ChannelParameters* 
   Parameters::ChannelParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
ChannelParameters::ChannelParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
ChannelParameters::~ChannelParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::ChannelParameters* 
Parameters::
ChannelParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new ChannelParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
ChannelParameters::setParameters()
{
   shadowingMean = 0;
   shadowingSD = 8; // pow( 10, 8 / 10 );
   userSpeed = 3 / 3.6; // ms/s; 
   shouldReadFile = false;
   ChannelFileName = "./../SmallScaleFading.it";
   profile = COST259_TUx;
   channelTime = 2000;
   fileName_ = string("../Parameters/ChannelParameters.dat");
   timeStep = 0.0;
   frequencyStep = 0.0;
   
}

//------------------------------------------------------------------------------

void
Parameters::
ChannelParameters::readFile()
{
   File f;
   f.read( fileName_, "shadowingMean", shadowingMean );
   f.read( fileName_, "shadowingSD", shadowingSD );
   f.read( fileName_, "userSpeed", userSpeed );
   f.read( fileName_, "channelTime", channelTime );
   f.read( fileName_, "timeStep", timeStep );
   f.read( fileName_, "frequencyStep", frequencyStep );
//cout<<userSpeed<<"\n";
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
