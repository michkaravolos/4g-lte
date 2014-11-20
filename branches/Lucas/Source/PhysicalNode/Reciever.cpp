/**
 * @file    Reciever.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/21/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 


// *****************************************************************************
// Includes
// *****************************************************************************

#include "Reciever.h"

#include "SystemParameters.h"
#include "SimulationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
Reciever::Reciever(int orientation)
{
   // 
   orientation_ = orientation;
   initialize();
   setParameters();
};

// -----------------------------------------------------------------------------

PhysicalNode::
Reciever::~Reciever()
{
   //delete antenna_;
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
Reciever::setParameters()
{
   Parameters::SystemParameters* sp = 
      Parameters::SystemParameters::getInstance();
   totalPower_ = sp->totalPower;
}

//------------------------------------------------------------------------------

void
PhysicalNode::
Reciever::initialize()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

int Direction_ = sp->Direction;

if(Direction_ ==0){
   antenna_ = new Antenna(); //Antena de recepcao.
}
else
{
   antenna_ = new GenericAntenna(); //Semelhante à antena de transmissão, mas é para RECEPÇÃO NO UPLINK (ENODEB).
}

}

//-----------------------------------------------------------------------------

double
PhysicalNode::
Reciever::getGain( double theta )
{
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





