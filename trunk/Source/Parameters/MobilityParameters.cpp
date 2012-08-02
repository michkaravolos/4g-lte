/**
 * @file    MobilityParameters.cpp
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

#include "MobilityParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::MobilityParameters* 
   Parameters::MobilityParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
MobilityParameters::MobilityParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
MobilityParameters::~MobilityParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::MobilityParameters* 
Parameters::
MobilityParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new MobilityParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
MobilityParameters::setParameters()
{
   fileName_ = string( "../Parameters/MobilityParameters.h" );
}

//------------------------------------------------------------------------------

void
Parameters::
MobilityParameters::readFile()
{

}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
