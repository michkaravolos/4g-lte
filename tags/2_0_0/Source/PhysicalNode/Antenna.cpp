/**
 * @file    Antenna.cpp
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

#include "Antenna.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************
/**
       * Constructor.
       *
       */ 
PhysicalNode::
Antenna::Antenna()
{
};

// -----------------------------------------------------------------------------
/**
       * Destructor.
       *
       */
PhysicalNode::
Antenna::~Antenna()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

double
PhysicalNode::
Antenna::getGain( double theta )
{
   return 1.0;
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
Antenna::getGain_dB( double theta )
{
   return 0.0;
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





