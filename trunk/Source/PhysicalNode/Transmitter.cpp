/**
 * @file    Transmitter.cpp
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

#include "Transmitter.h"

#include "SystemParameters.h"
#include "SimulationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
Transmitter::Transmitter( int orientation )
{
   orientation_ = orientation;
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------

PhysicalNode::
Transmitter::~Transmitter()
{
  //delete antenna_;
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
Transmitter::setParameters()
{
   Parameters::SystemParameters* sp = 
      Parameters::SystemParameters::getInstance();
   totalPower_ = sp->totalPower; 
}

//------------------------------------------------------------------------------

void
PhysicalNode::
Transmitter::initialize()
{
Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

int Direction_ = sp->Direction;

if(Direction_ ==0){
   antenna_ = new GenericAntenna();
}
else{
   antenna_ = new Antenna();
}

}

//------------------------------------------------------------------------------

double
PhysicalNode::
Transmitter::getGain( double theta )
{
   //if( orientation_ == 2)
   //{
      //int i = 1;
   //}

   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

   int Direction_ = sp->Direction;

   if(Direction_ == 0){
       theta -= orientation_ * 2 * pi / 3;
       double g = antenna_->getGain( theta );  
       return g;
}
   else{
       return antenna_->getGain( theta );
   }

}



// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





