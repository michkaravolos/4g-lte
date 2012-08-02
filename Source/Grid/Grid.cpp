/**
 * @file    Grid.cpp
 * Name:    3G LTE Grid Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include <itpp/itbase.h>

#include "Grid.h"

#include "GridParameters.h"
#include "SimulationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Grid::Grid* 
   Grid::Grid::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Grid::
Grid::Grid()
{
   name_ = "Grid: ";
   
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

Grid::
Grid::~Grid()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Grid::Grid* 
Grid::
Grid::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Grid();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Grid::
Grid::initialize()
{
   numberSites_ = static_cast<int>( numberENodeBs_ / 3 );
   siteIndex_ = 0;
   triangleIndex_ = 0;
}

//------------------------------------------------------------------------------

void
Grid::
Grid::clear()
{
}

//------------------------------------------------------------------------------

void
Grid::
Grid::setParameters()
{   
   Parameters::GridParameters* grid = Parameters::GridParameters::getInstance();
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   numberENodeBs_ = sp->numberENodeBs;
   
   interSiteDistance_ = grid->interSiteDistance;
   minimumDistance_ = grid->minimumDistance;
}

//------------------------------------------------------------------------------

void
Grid::
Grid::generateUserPosition( Basic::Position& p, int& site, int& sector )
{
   double xMax = interSiteDistance_ / 2;  
   int i = triangleIndex_;
   
   p.xy( 0.0, 0.0 );

   while( p.abs() < minimumDistance_ )
   {
      generatePositionInsideTriangle( p, xMax );
   } 
   
   generatePositionInsideHexagon( p, i );  
   
   sector = getSector( p ); 
   
   site = 0; //siteIndex_;
   
   generateAbsolutePosition( p, site );
   
   updateIndexes();
  
  
   
}

//------------------------------------------------------------------------------

void
Grid::
Grid::generatePositionInsideTriangle( Basic::Position& p, double xMax )
{
   Uniform_RNG gen( 0 , 1 );
   complex<double> c;
   double x = gen() * xMax; // random number between 0 and x_max;
   double yAllowed = x / sqrt( 3.0 );
   double yMax = xMax / sqrt( 3.0 );
   double y = 2 * gen() * yMax - yMax; // random number between -y_max and y_max
   
   while( sqrt( pow( y, 2.0 ) ) > yAllowed )
   {
      x = gen() * xMax;
      y = 2 * gen() * yMax - yMax;
      yAllowed = x / sqrt( 3.0 );
   }
   
   
   p.xy( x, y );   
   
   
}

//------------------------------------------------------------------------------

void
Grid::
Grid::generatePositionInsideHexagon( Basic::Position& p, int index )
{
   complex<double> c1 = complex<double>( 0 , 0 );
   complex<double> c2 = complex<double>( p.x() , p.y() );
   
   c1 = std::complex<double>( cos( pi/3 ), sin( pi/3 ) );
   c1 = pow( c1, index );
   
   p.xy( real( c1 * c2 ), imag( c1 * c2 ) );  
   
   
}

//------------------------------------------------------------------------------

int
Grid::
Grid::getSector( Basic::Position& p )
{
   int sector = 0;
   if( p.arg() >= pi / 3  && p.arg() <  pi )
   {
      sector = 1;
   }
   else if( p.arg() >= -1 * pi && p.arg() < -1 * pi / 3 )
   {
      sector = 2;
   }
   return sector;
}

//------------------------------------------------------------------------------

void
Grid::
Grid::generateAbsolutePosition( Basic::Position& p, int site )
{
   Basic::Position node;
   generateENodeBPosition( node, site );
   p = p + node;
}

//------------------------------------------------------------------------------

void
Grid::
Grid::updateIndexes()
{
   triangleIndex_++;
   siteIndex_++;
   if( triangleIndex_ == 6 )
   {
      triangleIndex_ = 0;
   }
   
   if( siteIndex_ ==  numberSites_ )
   {
      siteIndex_ = 0;
   }
}

//------------------------------------------------------------------------------

void
Grid::
Grid::generateENodeBPosition( Basic::Position& p, int& index )
{
   
   int i = index - 1;
   p = Basic::Position( 0, 0 );
   complex<double> c1 = complex<double>( 0 , 0 );
   complex<double> c2 = complex<double>( 0 , 0 );
   
   if( i >= 0 && i < 6 )
   {
      c1 = complex<double>( cos( pi / 3 ), sin( pi / 3 ) );
      c1 = pow( c1, i );
      c2 =  complex<double>( interSiteDistance_, 0 );  
   }
   else if( i > 5 && i < 18 && i % 2 == 0 )
   {
      c1 = complex<double>( cos( pi/6 ), sin( pi/6 ) );
      c1 = pow( c1, i - 6 );
      c2 =  complex<double>( 2 * interSiteDistance_, 0 );
   }
   else if( i > 5 && i < 18 && i % 2 == 1 )
   {
      c1 = complex<double>( cos( pi/6 ), sin( pi/6 ) );
      c1 = pow( c1, i - 6 );
      c2 =  complex<double>( sqrt( 3.0 ) * interSiteDistance_, 0 );
   }
   else
   {
      
   }
   
   p = Basic::Position( real( c1 * c2 ), imag( c1 * c2 ) );
   
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************

