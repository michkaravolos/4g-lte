/**
 * @file    Slot.cpp
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

#include "Slot.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
Slot::Slot()
{
};

// -----------------------------------------------------------------------------

PhysicalLayer::
Slot::Slot( vec PRBFrequencies )
{
   initialize( PRBFrequencies );
};

// -----------------------------------------------------------------------------

PhysicalLayer::
Slot::~Slot()
{
   int size = PRBs_.size();
   for( int i = 0; i < size; ++i )
   {
      //delete PRBs_( i );
      if (PRBs_( i ) != 0 )
      {
         delete PRBs_( i );
         PRBs_( i ) = 0;
      }
   }
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
Slot::initialize( const vec PRBFrequencies )
{
   int size = PRBFrequencies.size();
   PRBs_.set_size( size );
   for( int i = 0; i < size; ++i )
   {
      PRBs_( i ) = new PhysicalResourceBlock( PRBFrequencies( i ) );
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





