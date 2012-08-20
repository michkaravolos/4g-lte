/**
 * @file    Subframe.cpp
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

#include "Subframe.h"

#include "PhysicalLayerParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
Subframe::Subframe()
{
   //setParameters();
   //initialize();
};

// -----------------------------------------------------------------------------

PhysicalLayer::
Subframe::Subframe( vec PRBFrequencies )
{
   setParameters();
   initialize( PRBFrequencies );
};

// -----------------------------------------------------------------------------

PhysicalLayer::
Subframe::~Subframe()
{
   int size = slots_.size();
   //Slot* s;
   for( int i = 0; i < size; ++i )
   {
      //s = slots_( i );
      if (slots_( i ) != 0 )
      {
         delete slots_( i );
         slots_( i ) = 0;
      }
   }
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
Subframe::setParameters()
{
   Parameters::PhysicalLayerParameters* plp = 
      Parameters::PhysicalLayerParameters::getInstance();
   
   numberSlotsPerRSubframe_ = plp->numberSlotsPerRSubframe;
}

// -----------------------------------------------------------------------------

void
PhysicalLayer::
Subframe::initialize( const vec PRBFrequencies )
{
   slots_.set_size( numberSlotsPerRSubframe_ );
   for( int i = 0; i < numberSlotsPerRSubframe_; ++i )
   {
      slots_( i ) = new Slot( PRBFrequencies );
   }

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





