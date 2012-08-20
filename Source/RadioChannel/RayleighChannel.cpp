/**
 * @file    RayleighChannel.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
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

#include "RayleighChannel.h"
#include <itpp/comm/channel.h>

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

// *****************************************************************************
// Constructors
// *****************************************************************************

RadioChannel::
RayleighChannel::RayleighChannel()
{
};

// -----------------------------------------------------------------------------

RadioChannel::
RayleighChannel::~RayleighChannel()
{
};

// *****************************************************************************
// Operators
// *****************************************************************************


// *****************************************************************************
// Interface
// *****************************************************************************

cmat 
RadioChannel::
RayleighChannel::generateChannelMatrix( int rows, int cols )
{
   cmat H( rows, cols );
   Independent_Fading_Generator generator;
   cvec value;
   
   generator.init();
  
   for( int i = 0; i < rows; ++i )
   {
      for( int j = 0; j < cols; ++j )
      {
         value.clear();
         generator.generate( 1, value );
         H( i, j ) = value[0];
      }
   }

   return H;
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************


// *****************************************************************************
// Private Methods
// *****************************************************************************




