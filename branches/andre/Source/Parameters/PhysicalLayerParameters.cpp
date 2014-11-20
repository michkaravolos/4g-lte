/**
 * @file    PhysicalLayerParameters.cpp
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

#include "PhysicalLayerParameters.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::PhysicalLayerParameters* 
   Parameters::PhysicalLayerParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
PhysicalLayerParameters::PhysicalLayerParameters()
{
   setParameters();
   
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
PhysicalLayerParameters::~PhysicalLayerParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::PhysicalLayerParameters* 
Parameters::
PhysicalLayerParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new PhysicalLayerParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
PhysicalLayerParameters::setParameters()
{
    numberREPerSC = 7;
    numberSCPerPRB = 12;
    slotTimeLength = 5e-4;
    numberSlotsPerRSubframe = 2;
    numberSubframesPerFrame = 10;
    fileName_ = string( "../Parameters/PhysicalLayerParameters.dat" );
    SoundingSlots= 1;
}

//------------------------------------------------------------------------------

void
Parameters::
PhysicalLayerParameters::readFile()
{
   File f;
   f.read( fileName_, "numberREPerSC", numberREPerSC);
   f.read( fileName_, "numberSCPerPRB", numberSCPerPRB );
   f.read( fileName_, "slotTimeLength", slotTimeLength );
   f.read( fileName_, "numberSlotsPerRSubframe", numberSlotsPerRSubframe );
   f.read( fileName_, "numberSubframesPerFrame", numberSubframesPerFrame );
   f.read( fileName_, "SoundingSlots", SoundingSlots );
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
