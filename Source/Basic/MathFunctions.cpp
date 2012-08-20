/**
 * @file    MathFunctions.cpp
 * Name:    3G LTE MathFunctions Simulator
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

#include "MathFunctions.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

Basic::
MathFunctions::MathFunctions()
{
}

//------------------------------------------------------------------------------

Basic::
MathFunctions::~MathFunctions()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

void 
Basic::
MathFunctions::setPowerOf2( int& N )
{
   double log2N_d = log10( N ) / log10( 2 ); 
   int log2N_i = static_cast<int>( log2N_d );
   double temp = static_cast<double>( log2N_i );
   if( log2N_d - temp > 1e-7 )
   {
      temp +=1;
   }
   
   N = static_cast<int>( pow( 2.0, temp ) );
}

// -----------------------------------------------------------------------------

double 
Basic::
MathFunctions::calculateDistance( Position p1, Position p2 )
{
   return sqrt( ( p2.x() - p1.x() ) * ( p2.x() - p1.x() ) +
                ( p2.y() - p1.y() ) * ( p2.y() - p1.y() ) 
                  );
   
}

// -----------------------------------------------------------------------------

double 
Basic::
MathFunctions::calculateAngle( Position p1, Position p2 )
{
   complex<double> c2 = complex<double>( p2.x(), p2.y() );
   complex<double> c1 = complex<double>( p1.x(), p1.y() );
   return arg( c2 - c1 );
   
}

// -----------------------------------------------------------------------------




// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
