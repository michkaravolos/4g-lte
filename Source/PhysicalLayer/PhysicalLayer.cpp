/**
 * @file    PhysicalLayer.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/28/2008
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

#include "PhysicalLayer.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
PhysicalLayer::PhysicalLayer()
{
};

// -----------------------------------------------------------------------------

PhysicalLayer::
PhysicalLayer::PhysicalLayer( const vec PRBFrequencies, const vec SCFrequencies )
{
   initialize( PRBFrequencies );
   frequencies_.set_size( PRBFrequencies.size() );
   frequencies_ = PRBFrequencies;
   SCfrequencies_.set_size( SCFrequencies.size() );
   SCfrequencies_ = SCFrequencies;
   //cout << SCfrequencies_ << endl;
};

// -----------------------------------------------------------------------------

PhysicalLayer::
PhysicalLayer::~PhysicalLayer()
{
   //delete subframe_;
   if (subframe_ != 0 )
   {
      delete subframe_;
      subframe_ = 0;
   }
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
PhysicalLayer::initialize( const vec PRBFrequencies )
{
   subframe_ = new Subframe( PRBFrequencies );

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





