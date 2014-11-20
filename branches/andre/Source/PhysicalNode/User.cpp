/**
 * @file    Sector.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/06/2008
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

#include "User.h"

#include "SystemParameters.h"
#include "VectorFunctions.h"
#include "UserParameters.h"
#include "SimulationParameters.h"
#include "Transmitter.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

PhysicalNode::
User::User()
{
};

// -----------------------------------------------------------------------------

PhysicalNode::
User::User( Basic::Position p, int site, int sector, int id )
{
   position_ = p;
   sector_ = sector;
   site_ = site;
   id_ = id;
   setParameters();
   initialize();
   
};

// -----------------------------------------------------------------------------

PhysicalNode::
User::~User()
{
   //delete device_;
   //delete device_;
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
PhysicalNode::
User::initialize()
{ 
}

// -----------------------------------------------------------------------------

void
PhysicalNode::
User::setParameters()
{
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   Parameters::UserParameters* up = 
      Parameters::UserParameters::getInstance();
   Basic::VectorFunctions vf;

   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();

   int orientation = 1;

   int Direction_=sp->Direction;

   if(Direction_ == 0){
      device_ = new Receiver(orientation);} //Não faz sentido orientation, por isso ponho 1. Se por 0, provoca erro.
   else{
      device_ = new Transmitter(orientation);
   }

   rawBits_ = 1;
   effectiveBits_ = 1;
   CQI_.set_size( sysp->numberTransmitAntennas );
   CQIUpdatePeriod_ = up->CQIUpdatePeriod;
   numberCQIBits_ = up->numberCQIBits;
   maxSINRConsidered_ = up->maxSINRConsidered;
   minSINRConsidered_ = up->minSINRConsidered;
   CQIUpdateCounter_ = up->CQIUpdatePeriod;
   CQISD_ = up->CQISD;
   reuse_=sysp->reuse;
   for( int i = 0; i < CQI_.size(); ++i )
   {
      CQI_( i ).set_size( up->CQIReportDelay + 1 );
      vf.setZerosArray( CQI_( i ) , 0 );
   }
   
   SINR_.set_size( sysp->numberTransmitAntennas );
   
   vf.setZerosArray( SINR_ , 0 );
   //SINR_.set_size( 0 );
   
}

// -----------------------------------------------------------------------------

double
PhysicalNode::
User::getGain( double theta )
{
   return device_->getGain( theta );  
}

//------------------------------------------------------------------------------

void
PhysicalNode::
User::updateCQI()
{
   int antennas = CQI_.size();
   int delay = CQI_( 0 ).size();
   int size = CQI_( 0 )( delay - 1 ).size();
   Normal_RNG gen( 0 , CQISD_ * CQISD_ );
   //int nfreq = CQI_( 0 ).size();
   
   for( int i = 0; i < antennas; ++i )
   {
      for( int j = 0; j < delay - 1; ++j )
      {
         CQI_( i )( j ) = CQI_( i )( j + 1 );
      }
   }
   
   for( int i = 0; i < antennas; ++i )
   {
      for( int j = 0; j < size; ++j )
      {
         if( SINR_( i )( j )  == 0 )
         {
            it_error( "SINR equals to zero." );
         }
         if( CQIUpdateCounter_ == CQIUpdatePeriod_ )
         {
            double cqi = SINR_( i )( j ) * pow( 10.0, gen() / 10 );
            adjustCQI( cqi );
            CQI_( i )( delay - 1 )( j ) = cqi;
            CQIUpdateCounter_ = 0;
         }
         else
         {
            CQIUpdateCounter_++;
         }       
      }
   }
}

//------------------------------------------------------------------------------

void
PhysicalNode::
User::adjustCQI( double& CQI )
{
   double cqi = 10 * log10( CQI );
   double cqiMin = 0.0;
   double step = ( maxSINRConsidered_ - minSINRConsidered_ ) 
      / pow( 2.0 , numberCQIBits_ );
   if( cqi < minSINRConsidered_ )
   {
      cqi = minSINRConsidered_;
   }
   if( cqi > maxSINRConsidered_ )
   {
      cqi = maxSINRConsidered_;
   }
   
   cqiMin = minSINRConsidered_ + 
      static_cast< int >( ( cqi - minSINRConsidered_) / step ) 
      * step;
   
   if( cqi - cqiMin > cqiMin + step - cqi )
   {
      CQI = pow( 10, ( cqiMin + step ) / 10.0 );
   }
   else
   {
      CQI = pow( 10, cqiMin / 10.0 ); 
   }
   
}

//------------------------------------------------------------------------------

double
PhysicalNode::
User::reportCQI( double frequency, int antenna )
{
   int index = -1;
   int size = frequencies_.size();
   
   int bindex;
   int findex;


switch(reuse_)
   {
   case 0:
  	 bindex=0;
  	 findex=size;
  	 break;

   case 1:
  	 switch(eNodeBSector_)
  	 {
  	 case 0:
  	   bindex=0;
  	   findex=size/3;
  	   break;

  	 case 1:
  	   bindex=size/3;
  	   findex=(size/3)*2;
  	   break;

  	 case 2:
  	   bindex=(size/3)*2;
  	   findex=size;
  	   break;
  	 }

  	 break;
   }
   
   for( int i = bindex; i < findex; ++i )
   {
      if( frequency == frequencies_( i ) )
      {
         index = i;
      }
   }
   
   if( index == -1 )
   {
      it_error("User CQI report: index out of range.");
   }
   
   return CQI_( antenna )( 0 )( index );
}

//------------------------------------------------------------------------------

void
PhysicalNode::
User::storeSINR( double sinr, double frequency, int antenna)
{
   int index = -1;
   int size = frequencies_.size();
   //double f = 0.0;
   index = static_cast<int> ( frequency / 15e3 );
   //cout << frequencies_ << endl;
   /*for( int i = 0; i < size; ++i )
   {
      if( frequency == frequencies_( i ) )
      {
         index = i;
         break;
      }
   }*/
  
   switch(reuse_)
   {
   case 0:
	   
  	 break;

   case 1:

	switch(eNodeBSector_)
  	 {
  	 case 0:
  		index = index;
  	   break;

  	 case 1:
  		 index = index - size/3;
  	  	   break;

  	 case 2:
  		index = index - 2*(size/3);
  	   break;

  	 }
  	 break;
   }
    
   
   if( index == -1 )
   {
      it_error("User CQI report: index out of range.");
   }
  // cout<<index<<" "<<frequency<<endl;
   SINR_( antenna )( index ) = sinr;
   //cout << sinr << ", ";
   
    
}

//------------------------------------------------------------------------------

double
PhysicalNode::
User::getSINR( double frequency, int antenna )
{
   int index = -1;
   int size = frequencies_.size();
   
   int bindex;
   int findex;

   
   switch(reuse_)
      {
      case 0:
     	 bindex=0;
     	 findex=size;
     	 break;

      case 1:
     	 switch(eNodeBSector_)
     	 {
     	 case 0:
     	   bindex=0;
     	   findex=size/3;
     	   break;

     	 case 1:
     	   bindex=size/3;
     	   findex=(size/3)*2;
     	   break;

     	 case 2:
     	   bindex=(size/3)*2;
     	   findex=size;
     	   break;
     	 }

     	 break;
      }
   for( int i = bindex; i < findex; ++i )
      {
      if( frequency == frequencies_( i ) )
      {
         index = i;
      }
   }
   
   if( index == -1 )
   {
      it_error("User SINR: index out of range.");
   }
   
   return SINR_( antenna )( index );
}


//------------------------------------------------------------------------------

double
PhysicalNode::
User::getAverageSINR()
{
   int size = SINR_.size();
   double asinr = 0.0;
   for( int i = 0; i < size; ++i )
   {
      asinr += getAverageSINR( i );
   }
   return asinr / size;
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
User::getAverageSINR( int antenna )
{
   int size = SINR_( antenna ).size();
   int s = 0;
   double asinr = 0.0;
   for( int i = 0; i < size; ++i )
   {
      if ( SINR_( antenna )( i ) != 0.0 )
      {
         asinr += SINR_( antenna )( i );
         s++;
      }
      else
      {
         it_error("SINR = 0");
      }
      
   }
   //cout << SINR_ << endl ;
   //cout << SINR_ << endl;
   return asinr / s;
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
User::getAverageCQI( int antenna )
{
   int size = CQI_( antenna )( 0 ).size();
   int s = 0;
   double cqi = 0.0;
   for( int i = 0; i < size; ++i )
   {
      if ( CQI_( antenna )( 0 )( i ) != 0.0 )
      {
         cqi += CQI_( antenna )( 0 )( i );
         s++;
      }
      else
      {
         it_error("CQI = 0");
      }
      
   }
   //cout << SINR_ << endl;
   return cqi / s;
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
User::getAverageCQI()
{
   int size = CQI_.size();
   double cqi = 0.0;
   for( int i = 0; i < size; ++i )
   {
      cqi += getAverageCQI( i );     
   }
   //cout << SINR_ << endl;
   return cqi / size;
};

// -----------------------------------------------------------------------------

double
PhysicalNode::
User::getAverageCQI( vec frequencies, int antenna )
{
   int freqSize = frequencies.size();
   int size = frequencies_.size();
   int s = 0;
   double cqi = 0.0;
   int bindex0;
   int findex0;
   int bindex1;
   int findex1;

switch(reuse_)
   {
   case 0:
  	  bindex0=0;
  	  findex0=freqSize;
  	  bindex1=0;
  	  findex1=size;
  	 break;

   case 1:
	   switch(eNodeBSector_)
	   	 {
     case 0:
  	   bindex0=0;
  	   findex0=freqSize/3;
       bindex1=0;
       findex1=size/3;
  	   break;

     case 1:
  	   bindex0=freqSize/3;
  	   findex0=(freqSize/3)*2;
       bindex1=size/3;
       findex1=(size/3)*2;
  	   break;

     case 2:
  	   bindex0=(freqSize/3)*2;
  	   findex0=freqSize;
       bindex1=(size/3)*2;
       findex1=size;
  	   break;

  	 }
   }
   
   for( int i =bindex0; i < findex0; ++i )
    {
      for( int j = bindex1; j < findex1; ++j)
      {
         if( frequencies( i )  == frequencies_( j ) )
         {
            if ( CQI_( antenna )( 0 )( j ) != 0.0 )
            {
               cqi += CQI_( antenna )( 0 )( j );
               s++;
            }
            else
            {
               it_error( "CQI = 0" );
            }
         }
      }
     }
      
      
      
   
   //cout << SINR_ << endl;
   return cqi / s;
};

// -----------------------------------------------------------------------------

void
PhysicalNode::
User::setFrequencies( vec frequencies )
{
   int size = frequencies.size();
   
   frequencies_.set_size( size );
   frequencies_ = frequencies;
   int slots = 0;
   int antennas = CQI_.size();
   int bindex; // Modified by Igor Abrahão
   int findex;// Modified by Igor Abrahão
   int aux;

   switch(reuse_)
      {
      case 0:
     	 bindex=0;
     	 findex=size;
     	 break;

      case 1:
     	 switch(eNodeBSector_)
     	 {
     	 case 0:
     	   bindex=0;
     	   findex=size/3;
     	   break;

     	 case 1:
     	   bindex=size/3;
     	   findex=(size/3)*2;
     	   break;

     	 case 2:
     	   bindex=(size/3)*2;
     	   findex=size;
     	   break;
     	 }

     	 break;
      }

    for( int i = 0; i < antennas; ++i )
   {
      slots = CQI_( i ).size();
      for( int j = 0; j < slots; ++j )
      {
	aux=findex - bindex;
    	  
         CQI_( i )( j ).set_size( aux  );
         for( int k = 0; k < aux; ++k )
         {
            CQI_( i )( j )( k ) = 0.00001;
         }
      }
     
      SINR_( i ).set_size( aux);
   }
   
};

//------------------------------------------------------------------------------

double
PhysicalNode::
User::getFrequency( int index )
{
   double f = -1.0;
   if( index < frequencies_.size()  )
   {
      f = frequencies_( index );
   }
   else
   {
      it_error("User: index out of range.");
   }
   return f;
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





