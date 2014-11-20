/**
 * @file    ResourceElement.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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

#include "ResourceElement.h"

//#include "PhysicalLayerParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
ResourceElement::ResourceElement()
{
   setParameters();
};

// -----------------------------------------------------------------------------

PhysicalLayer::
ResourceElement::~ResourceElement()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
ResourceElement::setParameters()
{
   //Parameters::PhysicalLayerParameters* plp = 
      //Parameters::PhysicalLayerParameters::getInstance();
   
   rawBits_ = 0; //plp->numberRawBitsPerRE;
   effectiveBits_ = 0; //plp->numberEffectiveBitsPerRE;

}

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





