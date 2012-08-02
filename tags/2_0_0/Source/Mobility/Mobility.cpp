/**
 * @file    Mobility.cpp
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

#include "Mobility.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Mobility::Mobility* 
   Mobility::Mobility::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Mobility::
Mobility::Mobility()
{
   setParameters();
}

//------------------------------------------------------------------------------

Mobility::
Mobility::~Mobility()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Mobility::Mobility* 
Mobility::
Mobility::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Mobility();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Mobility::
Mobility::setParameters()
{
   grid_ = Grid::Grid::getInstance();
}

//------------------------------------------------------------------------------

void
Mobility::
Mobility::initialize()
{
}


//------------------------------------------------------------------------------

void
Mobility::
Mobility::clear()
{
}

//------------------------------------------------------------------------------

void
Mobility::
Mobility::generatePosition( Basic::Position& p, int& site, int& sector )
{
   grid_->generateUserPosition( p, site, sector );
}

//------------------------------------------------------------------------------

void
Mobility::
Mobility::generatePosition( Basic::Position& p, int& index )
{ 
   grid_->generateENodeBPosition( p, index );
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
