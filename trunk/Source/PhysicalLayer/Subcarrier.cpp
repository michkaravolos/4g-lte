/**
 * @file    Subcarrier.cpp
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

#include "Subcarrier.h"

#include "PhysicalLayerParameters.h"
#include "SimulationParameters.h"
// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
Subcarrier::Subcarrier( const double frequency )
{
   setParameters();
   initialize( frequency );
};

// -----------------------------------------------------------------------------

PhysicalLayer::
Subcarrier::~Subcarrier()
{
   int size = resourceElements_.size();
   
   for( int i = 0; i < size; ++i )
   {
      //delete resourceElements_( i ); 
      if (resourceElements_( i ) != 0 )
      {
         delete resourceElements_( i );
         resourceElements_( i ) = 0;
      }
   }
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
Subcarrier::setParameters()
{
   Parameters::PhysicalLayerParameters* plp = 
      Parameters::PhysicalLayerParameters::getInstance();
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   numberResourceElements_ = plp->numberREPerSC;
   SoundingSlots_=plp->SoundingSlots;
   Direction_=sp->Direction;
   if(Direction_==1){ numberResourceElements_-=SoundingSlots_;}
   //cout<<numberResourceElements_<<"\n";

}

// -----------------------------------------------------------------------------

void
PhysicalLayer::
Subcarrier::initialize( const double frequency )
{
   resourceElements_.set_size( numberResourceElements_ );
   for( int i = 0; i < numberResourceElements_; ++i )
   {
      resourceElements_( i ) = new ResourceElement();
   }
   
   frequency_ = frequency;

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





