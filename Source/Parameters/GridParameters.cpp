/**
 * @file    GridParameters.cpp
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

#include "GridParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::GridParameters* 
   Parameters::GridParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
GridParameters::GridParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
GridParameters::~GridParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::GridParameters* 
Parameters::
GridParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new GridParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
GridParameters::setParameters()
{
    interSiteDistance = 500; // [m]
    minimumDistance = 35; // [m]
    fileName_ = string("../Parameters/GridParameters.dat");
}

//------------------------------------------------------------------------------

void
Parameters::
GridParameters::readFile()
{
   File f;
   f.read( fileName_, "interSiteDistance", interSiteDistance );
   f.read( fileName_, "minimumDistance", minimumDistance );
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
