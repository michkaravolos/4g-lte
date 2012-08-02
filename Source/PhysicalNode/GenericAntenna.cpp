/**
 * @file    GenericAntenna.cpp
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

#include <itpp/itbase.h>

#include "GenericAntenna.h"

#include "AntennaParameters.h"

using namespace itpp;

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
GenericAntenna::GenericAntenna()
{
   setParameters();
};

// -----------------------------------------------------------------------------

PhysicalNode::
GenericAntenna::~GenericAntenna()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
GenericAntenna::setParameters()
{
   Parameters::AntennaParameters* ap = 
      Parameters::AntennaParameters::getInstance();
   theta3dB_ = ap->theta3dB;
   minimumGaindB_ = ap->minimumGaindB;  
};

// -----------------------------------------------------------------------------      
      
double
PhysicalNode::
GenericAntenna::getGain( double theta )
{
   return pow( 10, getGain_dB( theta ) / 10 );
   
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
GenericAntenna::getGain_dB( double theta )
{
   complex<double> c = complex<double>( cos(theta), sin(theta) );
   theta = arg( c );
   
   double gain = 12 * pow( theta / theta3dB_, 2 );
   if( gain > minimumGaindB_ )
   {
      return -1 * minimumGaindB_;
   }
   else
   {
      return -1 * gain;
   }
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





