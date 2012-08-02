/**
 * @file    VectorFunctions.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 


// *****************************************************************************
// Includes
// *****************************************************************************

#include "VectorFunctions.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

// *****************************************************************************
// Constructors
// *****************************************************************************

Basic::
VectorFunctions::VectorFunctions()
{
};

// -----------------------------------------------------------------------------

Basic::
VectorFunctions::~VectorFunctions()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

void 
Basic::
VectorFunctions::normalize( cvec& sequence, bool average )
{
   int N = sequence.size();
   double total = 0.0;
   
   for( int i = 0; i < N; ++i )
   {     
      total += abs( sequence( i ) ) * abs( sequence( i ) );
   }
   
   if ( average )
   {
      total /= N;   
   }
   
   total = sqrt( total );
   
   for( int i = 0; i < N; ++i )
   {     
      sequence( i ) /= total;    
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::normalize( vec& sequence, bool average )
{
   int N = sequence.size();
   double total = 0.0;
   
   for( int i = 0; i < N; ++i )
   {     
      total += sequence( i ) * sequence( i );
   }
   
   if ( average )
   {
      total /= N;   
   }
   
   total = sqrt( total );
   
   for( int i = 0; i < N; ++i )
   {     
      sequence( i ) /= total;    
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::normalize( Array<cvec>& matrix, bool average)
{
   int rows = matrix.size();
   int cols= matrix(0).size();
   double total = 0.0;
   
   for( int i = 0; i < rows; ++i )
   {
      for( int j = 0; j < cols; ++j)
      {
         total += abs( matrix( i )( j ) ) * abs( matrix( i )( j ) );
      }
   }
   
   if ( average )
   {
   total /= rows;   
   }
   total = sqrt( total );
   
   for( int i = 0; i < rows; ++i )
   {
      for( int j = 0; j < cols; ++j)
      {     
      matrix( i )( j ) /= total;    
      }
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::setZerosArray( Array<vec>& sequence, int cols )
{
   int rows = sequence.size();
   for( int i = 0; i < rows; ++i )
   {
      sequence( i ).set_size( cols );
      sequence( i ).zeros();
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::setZerosArray( Array<cvec>& sequence, int cols )
{
   int rows = sequence.size();
   for( int i = 0; i < rows; ++i )
   {
      sequence( i ).set_size( cols );
      sequence( i ).zeros();
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::transposeArray( Array<vec>& input, Array<vec>& output )
{
   int cols = input( 0 ).size();
   int rows = input.size();
   
   output.set_size( cols );
   
   for( int i = 0; i < cols; ++i )
   {
      output( i ).set_size( rows );
      for( int j = 0; j < rows; ++j)
      {
         output( i )( j ) = input( j )( i );
      }
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::transposeArray( Array<cvec>& input, Array<cvec>& output )
{
   int cols = input( 0 ).size();
   int rows = input.size();
   
   output.set_size( cols );
   
   for( int i = 0; i < cols; ++i )
   {
      output( i ).set_size( rows );
      for( int j = 0; j < rows; ++j)
      {
         output( i )( j ) = input( j )( i );
      }
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::printEnergy( cvec& sequence )
{
   int N = sequence.size();
   double total = 0.0;
   for(int i = 0; i < N; ++i)
   {
      total += abs ( sequence( i ) )* abs( sequence( i ) );
   }
   cout << "Energy: " << total << endl;
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::printEnergy( Array<cvec>& matrix )
{
   int rows = matrix.size();
   int cols= matrix(0).size();
   double total = 0.0;
   
   for( int i = 0; i < rows; ++i )
   {
      for( int j = 0; j < cols; ++j)
      {
         total += abs( matrix( i )( j ) ) * abs( matrix( i )( j ) );
      }
   }
   cout << "Energy: " << total << endl;
   
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::generateAbsolute( cvec& input, vec& output )
{
   int N = input.size();
   output.set_size( N );
   
   for( int i = 0; i < N; ++i )
   {     
      complex<double> c = input( i );
      double d =  abs( c ); 
      output( i ) = d;
   }
}

// -----------------------------------------------------------------------------

void 
Basic::
VectorFunctions::generateSquare( cvec& input, vec& output )
{
   int N = input.size();
   output.set_size( N );
   
   for( int i = 0; i < N; ++i )
   {     
      complex<double> c = input( i );
      double d =  abs( c ) * abs( c ); 
      output( i ) = d;
   }
}



// *****************************************************************************
// Operators
// *****************************************************************************


// *****************************************************************************
// Protected Methods
// *****************************************************************************



// *****************************************************************************
// Private Methods
// *****************************************************************************





