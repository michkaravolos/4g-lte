/**
 * @file    FrequencySelectiveChannel.cpp
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

#include <itpp/signal/transforms.h>

#include "File.h"

#include "FrequencySelectiveChannel.h"


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

void
RadioChannel::
FrequencySelectiveChannel::generateChannel( Array<cvec>& Channel, 
   double BW, double fm, double simulationTime, double BW_subcarrier, 
      double& timeStep, double& frequencyStep, CHANNEL_PROFILE profile )
{
   Basic::VectorFunctions vf;
   Basic::MathFunctions mf;
    
   int numberFrequencySamples;
   int numberTimeSamples;
   double dTime;
   double dFrequency;
   
   numberFrequencySamples = static_cast<int>( BW / BW_subcarrier);  
   numberTimeSamples = static_cast<int>( 2 * simulationTime * fm ) + 1; 
   
   dTime = 1 / ( 2 * fm );
   dFrequency = 1 / ( BW );  
  
   mf.setPowerOf2( numberTimeSamples );
   mf.setPowerOf2( numberFrequencySamples );
   
   timeStep = dTime;
   frequencyStep = BW / numberFrequencySamples;
   
   int taps; // Number of channel taps. TU 20 tap channel.
   
   ClarkeChannel cc;
   
   Array<cvec> ht( numberFrequencySamples );
   Array<cvec> Ht( numberTimeSamples );
   Array<cvec> h;
   
   vec powerdB;
   vec power;
   vec delay;
   
   Parameters::File f;    
   
   Channel.set_size( numberTimeSamples );
   
   vf.setZerosArray( ht, numberTimeSamples );
   vf.setZerosArray( Ht, numberFrequencySamples );
   vf.setZerosArray( Channel, numberFrequencySamples );
   
   Channel_Specification cs( profile );
   cs.get_channel_profile( powerdB, delay );
   
   // Adjusting matrix sizes
   taps = cs.taps();
   power.set_size( taps );
   h.set_size( taps );
     
   for( int i = 0; i < taps; ++i)
   {
      h( i ) = cc.generateComplexVector( numberTimeSamples, fm );
      power( i ) = pow( 10, powerdB( i ) / 20 );
      for( int j = 0; j < numberTimeSamples; ++j )
      {
         h( i )( j ) *= power( i );
      }
   } 
   
      
   for( int i = 0; i < taps; ++i )
   {
      int s;
      double tmed;
      s = static_cast<int>( delay( i ) / dFrequency );
      tmed = static_cast<double>( s ) * dFrequency + 0.5 * dFrequency;
      
      if( s >= ht.size() )
      {
         //cout << "Warning" << endl;
         it_info("Wrong matrix index");  
         break;
      }
      else
      {
         if( delay( i ) <= tmed )
         {
           ht( s ) = h( i );
         }
         else
         {
            ht( s + 1 ) = h( i );
         } 
      }
   }
   
   vf.transposeArray( ht, Ht );
   vf.normalize( Ht, true );
   
   //printEnergy( Ht );
   
   for( int i = 0; i < numberTimeSamples; ++i )
   {
      fft( Ht( i ), Channel( i ) );
      //vf->generateSquare( Hf( i ), Channel( i) );
   } 
}

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************




