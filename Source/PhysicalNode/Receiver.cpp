/**
 * @file    Receiver.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/21/2008
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

#include "Receiver.h"

#include "SystemParameters.h"
#include "SimulationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
Receiver::Receiver(int orientation)
{
   // 
   orientation_ = orientation;
   initialize();
   setParameters();
};

// -----------------------------------------------------------------------------

PhysicalNode::
Receiver::~Receiver()
{
   //delete antenna_;
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
Receiver::setParameters()
{
   Parameters::SystemParameters* sp = 
      Parameters::SystemParameters::getInstance();
   totalPower_ = sp->totalPower;
}

//------------------------------------------------------------------------------

void
PhysicalNode::
Receiver::initialize()
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
Receiver::getGain( double theta )
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





