/**
 * @file    Position.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
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

#include "Position.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

Basic::
Position::Position()
{
   position_ = complex<double> ( 0, 0 );
};

// -----------------------------------------------------------------------------

Basic::
Position::Position( double x, double y )
{
   position_ = complex<double>( x, y);
};

// -----------------------------------------------------------------------------

Basic::
Position::~Position()
{
};

// -----------------------------------------------------------------------------


// *****************************************************************************
// Interface
// *****************************************************************************


double
Basic::
Position::x()
{
   return real( position_ );
};

// -----------------------------------------------------------------------------

double
Basic::
Position::y()
{
   return imag( position_ );
};

// -----------------------------------------------------------------------------

void
Basic::
Position::x( double x_arg )
{
   double y = imag( position_ );
   position_ = complex<double>( x_arg, y );
};

// -----------------------------------------------------------------------------

void
Basic::
Position::y( double y_arg )
{
   double x = real( position_ );
   position_ = complex<double>( x, y_arg );
};

// -----------------------------------------------------------------------------

void
Basic::
Position::xy( double x, double y )
{
   position_ = complex<double>( x, y );
};

// -----------------------------------------------------------------------------

double
Basic::
Position::arg()
{
   return std::arg( position_ );
};

// -----------------------------------------------------------------------------

double
Basic::
Position::abs()
{
   return std::abs( position_ );
};

//------------------------------------------------------------------------------

Basic::Position
Basic::
Position::operator+( Position p ) const
{
   double x = real( position_ );
   double y = imag( position_ );
   x += p.x();
   y += p.y();
   
   return Position( x, y );
}

//------------------------------------------------------------------------------
/*
std::ostream& 
Basic::operator << ( ostream& os, Basic::Position p ) 
{
   return os << "( " << p.x() << ", " << p.y() << " ) ";
}*/

//------------------------------------------------------------------------------


// *****************************************************************************
// Operators
// *****************************************************************************



// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





