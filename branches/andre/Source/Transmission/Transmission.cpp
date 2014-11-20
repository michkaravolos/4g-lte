/**
 * @file    Transmission.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/29/2008
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

#include "Transmission.h"

#include "SimulationParameters.h"
#include "ENodeB.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Transmission::Transmission* 
   Transmission::Transmission::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Transmission::
Transmission::Transmission()
{
   name_ = "Transmission: ";
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

Transmission::
Transmission::~Transmission()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Transmission::Transmission* 
Transmission::
Transmission::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Transmission();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Transmission::
Transmission::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   numberENodeBs_ = sp->numberENodeBs;
   
}

//------------------------------------------------------------------------------

void
Transmission::
Transmission::initialize()
{
   simulationEnvironment_ = SimulationEnvironment::
      SimulationEnvironment::getInstance();
}

//------------------------------------------------------------------------------

void
Transmission::
Transmission::clear()
{
}

//------------------------------------------------------------------------------

void
Transmission::
Transmission::transmit()
{
   PhysicalNode::ENodeB* e;
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      e = simulationEnvironment_->getENodeB( i );
      e->transmit();
   }
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
