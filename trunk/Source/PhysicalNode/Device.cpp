/**
 * @file    Device.cpp
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

#include "Device.h"

#include "SystemParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
Device::Device()
{
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------

PhysicalNode::
Device::~Device()
{
   if (antenna_ != 0 )
   {
      delete antenna_;
      antenna_ = 0;
   }
   
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
Device::setParameters()
{
}

//------------------------------------------------------------------------------

void
PhysicalNode::
Device::initialize()
{
   //antenna_ = new Antenna();  
}

//------------------------------------------------------------------------------

/*double
PhysicalNode::
Device::getGain( double theta )
{
   //return antenna_->getGain( theta );  
}*/


// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





