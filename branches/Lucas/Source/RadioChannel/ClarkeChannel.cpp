/**
 * @file    ClarkeChannel.cpp
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

#include "ClarkeChannel.h"
#include <itpp/comm/channel.h>
#include <itpp/signal/transforms.h>

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

// *****************************************************************************
// Constructors
// *****************************************************************************

// *****************************************************************************
// Operators
// *****************************************************************************


// *****************************************************************************
// Interface
// *****************************************************************************

cvec
RadioChannel::
ClarkeChannel::generateComplexVector( int N, double fm )
{
   int M;
   Basic::MathFunctions mf;
   Basic::VectorFunctions vf;
   mf.setPowerOf2( N );
   M = N / 2; 
   
   double df;
   double fi;
      
   Independent_Fading_Generator generator;
      
   cvec posValues( M + 1 );
   cvec negValues( M - 1 );
   cvec phaseValues( N );
   cvec quadValues( N );
   cvec phaseTime( N );
   cvec quadTime( N ); 
   cvec timeComplex( N );
   
   df = fm  / M;
   
   generator.generate( M + 1, posValues );
   
   for( int i = 0; i < M - 1 ; ++i )
   {
      negValues( i ) = conj( posValues( i + 1 ) );
   }
   
   
   for( int i = 0; i < M - 1; ++i )
   {
      fi = ( i + 1 ) * df;
      posValues( i + 1 ) *= sqrt( calculateSpectrum( fi, 0.0, fm ) );  
      negValues( i ) *= sqrt( calculateSpectrum( fi, 0.0, fm ) );    
   }
   posValues( 0 ) *= sqrt( calculateSpectrum( 0.0, 0.0, fm ) );
   posValues( M ) *= sqrt( calculateSpectrum( fm, 0.0, fm ) );
   
   
   for( int i = 0; i < M + 1; ++i )
   {
      phaseValues( i ) = real( posValues( i ) );
      quadValues( i ) = imag( posValues( i ) );
   }
   
   
   for( int i = 0; i < M - 1; ++i )
   {
      phaseValues( i + M + 1 ) = real( negValues( M - 2 - i ) );   
      quadValues( i + M + 1 ) = imag( negValues( M - 2 - i ) );
   }
   quadValues( 0 ) = 0.0;
   quadValues( M ) = 0.0;
      
   
   ifft( phaseValues, phaseTime );
   ifft( quadValues, quadTime );
   
   
   for( int i = 0; i < N; ++i )
   {     
      timeComplex( i ) = complex<double>( real( phaseTime( i ) ), 
         imag( quadTime( i ) ) );
   }
   
   
   vf.normalize( timeComplex, true );
   
   return timeComplex;

}

// -----------------------------------------------------------------------------

vec
RadioChannel::
ClarkeChannel::generateAbsoluteVector( int N, double fm )
{
   vec timeEnvelope;
   cvec timeComplex = generateComplexVector( N, fm );
   Basic::VectorFunctions vf;
   vf.generateAbsolute( timeComplex, timeEnvelope );
   
   //Basic::VectorFunctions::getInstance()->
      //normalize( timeEnvelope, true );
   
   return timeEnvelope;
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

double
RadioChannel::
ClarkeChannel::
calculateSpectrum( double f, double fc, double fm )
{
   f = sqrt( f * f );
   fc = sqrt( fc * fc );
   fm = sqrt( fm * fm );
   
   if( f < fc + fm)
   {
      double s = 1.5 / ( pi * fm * sqrt( 1 - pow( ( f - fc ) / fm, 2) ) );
      return s;
   }
   else if( f - fc - fm < 1e-7 )
   {
      double temp1, temp2, f1, a, b, y;
      f1 = 0.999999 * f;
      temp1 = ( f1 - fc ) / fm;
      temp2 = temp1;
      temp1 = pow( temp1, 2);
      temp1 = pow( 1 - temp1, -1.5 );
      a = temp2 * temp1 * 1.5 / ( pi * fm * fm ); 
      y = calculateSpectrum( f1, fc, fm );
      b = y - a * f1;
      
      return a * f + b;
   }
   
   return 0.0;
}

// *****************************************************************************
// Private Methods
// *****************************************************************************




