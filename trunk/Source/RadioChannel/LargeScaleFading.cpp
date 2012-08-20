/**
 * @file    LargeScaleFading.cpp
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


// *****************************************************************************
// Includes
// *****************************************************************************

#include "LargeScaleFading.h"

#include "ChannelParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

RadioChannel::
LargeScaleFading::LargeScaleFading()
{
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------

RadioChannel::
LargeScaleFading::~LargeScaleFading()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
RadioChannel::
LargeScaleFading::setParameters()
{
   Parameters::ChannelParameters* cp = 
      Parameters::ChannelParameters::getInstance();
   
   mean_ = cp->shadowingMean;
   sd_ = cp->shadowingSD;
}

//------------------------------------------------------------------------------

void
RadioChannel::
LargeScaleFading::initialize()
{
   n = Normal_RNG( mean_ , sd_ * sd_ );
}

//------------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generateFading_dB( double distance )
{
   return - 1 * generatePathLoss_dB( distance ) - generateShadowing_dB();
};

// -----------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generatePathLoss_dB( double distance )
{
   if( distance != 0 )
   {
      return 128.1 + 37.6 * log10( distance / 1000 );
   }
   else
   {
      return -300;
   }
};

// -----------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generateShadowing_dB()
{
   return n();
};

// -----------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generateFading( double distance )
{
   return pow( 10, generateFading_dB( distance ) / 10 );
};

// -----------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generatePathLoss( double distance )
{
   return pow( 10, generatePathLoss_dB( distance ) / 10 );
};

// -----------------------------------------------------------------------------

double
RadioChannel::
LargeScaleFading::generateShadowing()
{
   
   return pow( 10 , generateShadowing_dB() / 10 );
};

// -----------------------------------------------------------------------------

// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





