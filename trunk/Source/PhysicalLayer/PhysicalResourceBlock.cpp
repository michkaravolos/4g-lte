/**
 * @file    PhysicalResourceBlock.cpp
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

#include "PhysicalResourceBlock.h"

#include "PhysicalLayerParameters.h"
#include "SystemParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalLayer::
PhysicalResourceBlock::PhysicalResourceBlock( const double frequency )
{
   setParameters();
   initialize( frequency );
};

// -----------------------------------------------------------------------------

PhysicalLayer::
PhysicalResourceBlock::~PhysicalResourceBlock()
{
   int size = subcarriers_.size();
   for( int i = 0; i < size; ++i )
   {
      //delete subcarriers_( i );  
      if (subcarriers_( i ) != 0 )
      {
         delete subcarriers_( i );
         subcarriers_( i ) = 0;
      }
   }
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalLayer::
PhysicalResourceBlock::setParameters()
{
   Parameters::PhysicalLayerParameters* plp = 
      Parameters::PhysicalLayerParameters::getInstance();
   
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   
   numberSubcarriers_ = plp->numberSCPerPRB;
   subcarrierFrequency_ = sysp->subcarrierBandwidth;

}

// -----------------------------------------------------------------------------

void
PhysicalLayer::
PhysicalResourceBlock::initialize( const double frequency )
{
   initialFrequency_ = frequency;
   
   subcarriers_.set_size( numberSubcarriers_ );
   for( int i = 0; i < numberSubcarriers_; ++i )
   {
      subcarriers_( i ) = 
         new Subcarrier( initialFrequency_ + i * subcarrierFrequency_ );
   }
   
   userId_ = -1;
}

// -----------------------------------------------------------------------------

void
PhysicalLayer::
PhysicalResourceBlock::setBits( const int rawBits, const double effectiveBits )
{
   int size = subcarriers_.size();
   int size1 = 0;
   for( int i = 0; i < size; ++i )
   {
      size1 = subcarriers_( i )->getNumberREs();
      
      for( int j = 0; j < size1; ++j )
      {
         subcarriers_( i )->getRE( j )->setRawBits( rawBits ); 
         subcarriers_( i )->getRE( j )->setEffectiveBits( effectiveBits ); 
      }
      //subcarriers_( i )->setRawBits( rawBits ); 
      //subcarriers_( i )->setEffectiveBits( rawBits ); 
   }
   
};

// -----------------------------------------------------------------------------

vec
PhysicalLayer::
PhysicalResourceBlock::getSCFrequencies()
{
   vec scfreq;
   int size = subcarriers_.size();
   scfreq.set_size( size );
   for( int i = 0; i < size; ++i )
   {
      scfreq( i ) = subcarriers_( i )->getFrequency();
   }
   
   return scfreq;
   
};

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





