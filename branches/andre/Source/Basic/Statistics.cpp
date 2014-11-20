/**
 * @file    Statistics.cpp
 * Name:    3G LTE Statistics Simulator
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

#include "Statistics.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

// *****************************************************************************
// Constructors
// *****************************************************************************

Basic::
Statistics::Statistics()
{
}

//------------------------------------------------------------------------------

Basic::
Statistics::~Statistics()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

double 
Basic::
Statistics::calculateOutage( priority_queue< double, vector<double>, 
   greater<double> > queue )
{
   int N = queue.size();
   double n = 0.0;
   int i = 0;
   double c;
   while ( n < 0.10 )
   {
      c = queue.top();
      queue.pop();
      ++i;
      n = (double) i / N;
   }
   while( queue.size() != 0 )
   {
      n += queue.top();
      queue.pop();
   }
   
   return c;     
   //return n / N;
}

// -----------------------------------------------------------------------------

double
Basic::
Statistics::calculateMean( vec sequence )
{
   int N = sequence.size();
   double mean = 0.0;
   
   for( int i = 0; i < N; ++i)
   {
      mean += sequence( i );   
   }
   
   mean /= N;
   
   return mean;
}

// -----------------------------------------------------------------------------

double
Basic::
Statistics::calculateMeanEnergy( vec sequence )
{
   int N = sequence.size();
   double mean = 0.0;
   
   for( int i = 0; i < N; ++i)
   {
      mean += sequence( i ) * sequence( i );   
   }
   
   mean /= N;
   
   return mean;
}


// -----------------------------------------------------------------------------

double
Basic::
Statistics::calculateStandardDeviation( vec sequence )
{
   int N = sequence.size();
   double mean = calculateMean( sequence );
   double variance = 0.0;
   double sd;
   
   for( int i = 0; i < N; ++i)
   {
      variance += ( sequence( i ) - mean ) * ( sequence( i ) - mean );
   }
   
   variance /= N;
   
   sd = sqrt( variance );
   
   return sd;
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
