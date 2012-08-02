/**
 * @file    LinkAdaptation.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include "LinkAdaptation.h"

#include "Results.h"
#include "LinkAdaptationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

LinkAdaptation::LinkAdaptation* 
   LinkAdaptation::LinkAdaptation::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

LinkAdaptation::
LinkAdaptation::LinkAdaptation()
{
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

LinkAdaptation::
LinkAdaptation::~LinkAdaptation()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

LinkAdaptation::LinkAdaptation* 
LinkAdaptation::
LinkAdaptation::getInstance()
{
   if ( !instance_)
   {
      instance_ = new LinkAdaptation();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
LinkAdaptation::
LinkAdaptation::setParameters()
{
   Parameters::LinkAdaptationParameters* la = 
      Parameters::LinkAdaptationParameters::getInstance();
   
   
   
   numberMCSs_ = 3;
   BERt_ = 1e-6;
   
   codingRate_ = la->codingRate;
   
   // pages 14, 37, 39, 47 of WINNER document. Use only MCS 3 e 4 from document.
   betas_.set_size( numberMCSs_ );
   MCSThresholds_.set_size( numberMCSs_ );
   
   betas_( 0 ) = la->beta0;
   betas_( 1 ) = la->beta1;
   betas_( 2 ) = la->beta2;
   //MCSThresholds_( 0 ) = pow( 10.0, -0.75 / 10 );
   //MCSThresholds_( 1 ) = pow( 10.0, 4.1 / 10 );
   MCSThresholds_( 0 ) = pow( 10.0, la->MCSThreshold0 / 10 );
   //cout << MCSThresholds_( 0 ) << endl;
   MCSThresholds_( 1 ) = pow( 10.0, la->MCSThreshold1 / 10 );
   //cout << MCSThresholds_( 1 ) << endl;
   MCSThresholds_( 2 ) = pow( 10.0, la->MCSThreshold2 / 10 );
}

//------------------------------------------------------------------------------

void
LinkAdaptation::
LinkAdaptation::initialize()
{

   
}

//------------------------------------------------------------------------------

void
LinkAdaptation::
LinkAdaptation::clear()
{
   //betas_.set_size( 0 );
   //MCSThresholds_.set_size( 0 );
}

//------------------------------------------------------------------------------

void
LinkAdaptation::
LinkAdaptation::chooseMCS( vec sinrs, double& sinr, int& MCS, int& rawBits,
   double& effectiveBits )
{
   //Results::Results* r = Results::Results::getInstance();
   double BER = 0.0;
   bool isOK = true;
   MCS = 0;
   double sinr1 = 0.000001;
   double sinr2 = 0.000001;
   while( isOK )
   {
      sinr2 = sinr1;
      sinr1 = mapSINRs( sinrs, MCS );
      BER = getBER( sinr1, MCS );
      isOK = isBERvalid( BER );
      if( isOK )
      {
         MCS++;
      }
      else
      {
         MCS--;
         sinr1 = sinr2;
      }
      if( MCS == numberMCSs_ )
      {
         isOK = false;
         MCS--;
      }
      
   }
   sinr = sinr1;
   setBits( MCS, rawBits, effectiveBits );  
}

//------------------------------------------------------------------------------

bool
LinkAdaptation::
LinkAdaptation::checkMCS( vec sinrs, int MCS )
{
   
   bool isOK = true;
   if( MCS == -1 )
   {
      isOK = false;
   }
   else
   {
      double BER = 0.0;
      double sinr = 0.0;
      sinr = mapSINRs( sinrs, MCS );
      BER = getBER( sinr, MCS );
      isOK = isBERvalid( BER );
   }
   //Results::Results* r = Results::Results::getInstance();
   
   
   return isOK; 
}

//------------------------------------------------------------------------------

double
LinkAdaptation::
LinkAdaptation::mapSINRs( const vec& sinrs, const int MCS )
{
   double sinr = 0.0;
   int size = sinrs.size();
   double sum = 0.0;
   for( int i = 0; i < size; ++i )
   {
       sum += exp( -1 * sinrs( i ) / betas_( MCS ) ) ;
   } 
   
   sinr = -1 * betas_( MCS ) * log( sum / size );
   return sinr;
}

//------------------------------------------------------------------------------

double
LinkAdaptation::
LinkAdaptation::getBER( const double sinr, const int MCS )
{
   if( sinr < MCSThresholds_( MCS ) )
   {
      return 1;
   }
   else
   {
      return 1e-7;
   }

}

//------------------------------------------------------------------------------

bool
LinkAdaptation::
LinkAdaptation::isBERvalid( const double BER )
{
   bool ok = true;
   if( BER > BERt_ )
   {
      ok = false;
   }
   return ok;
}

//------------------------------------------------------------------------------

void
LinkAdaptation::
LinkAdaptation::setBits( const int MCS, int& rawBits, double& effectiveBits )
{
   switch( MCS )
   {
      case -1:
      
      rawBits = 0;
      break;
      
      case 0:
         
      rawBits = 2;
      break;
      
      case 1:
         
      rawBits = 4;
      break;
      
      case 2:
         
      rawBits = 6;
      break;
      
      default:
         
      rawBits = 0;
      break;
         
   }
      
   effectiveBits = rawBits * 0.33333;
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
