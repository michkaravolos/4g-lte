/**
 * @file    RadioChannel.cpp
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

#include "RadioChannel.h"
#include "VectorFunctions.h"
#include "MathFunctions.h"
#include "SimulationParameters.h"
#include "SystemParameters.h"
#include "ChannelParameters.h"
#include "File.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

RadioChannel::RadioChannel* 
   RadioChannel::RadioChannel::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

RadioChannel::
RadioChannel::RadioChannel()
{
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

RadioChannel::
RadioChannel::~RadioChannel()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

RadioChannel::RadioChannel* 
RadioChannel::
RadioChannel::getInstance()
{
   if ( !instance_)
   {
      instance_ = new RadioChannel();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   Parameters::ChannelParameters* cp = 
      Parameters::ChannelParameters::getInstance();
   
   numberUsers_ = sp->numberUsers;
   numberENodeBs_ = sp->numberENodeBs;  
   shouldReadFile_ = cp->shouldReadFile;
   fileName_ = cp->ChannelFileName;
   frequencyStep_ = cp->frequencyStep;
   timeStep_ = cp->timeStep; 
   numberTransmitAntennas_ = sysp->numberTransmitAntennas;

}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::initialize()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   numberUsers_ = sp->numberUsers;
   largeScaleMatrix_.set_size( numberUsers_, numberENodeBs_ ); 
   largeScaleMatrix_.zeros();
   usersSmallScaleMatrixIndex_ = new int**[ numberUsers_ ];
   for( int i = 0; i < numberUsers_; ++i )
   { 
      usersSmallScaleMatrixIndex_[ i ] = new int*[ numberENodeBs_ ];
      for( int j = 0; j < numberENodeBs_; ++j )
      { 
         usersSmallScaleMatrixIndex_[ i ][ j ] = new int[ numberTransmitAntennas_ ];       
      }
   }
   
   simulationEnvironment_ = SimulationEnvironment::
      SimulationEnvironment::getInstance();
}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::clear()
{
   largeScaleMatrix_.set_size( 0, 0 );
   //smallScaleArray_.set_size( 0 );
   //usersSmallScaleMatrixIndex_.set_size( 0, 0);
   for( int i = 0; i < numberUsers_; ++i )
   {
      for( int j = 0; j < numberENodeBs_; ++j )
      {
         if( usersSmallScaleMatrixIndex_[ i ][ j ] != 0 )
         {
            delete[] usersSmallScaleMatrixIndex_[ i ][ j ];
            usersSmallScaleMatrixIndex_[ i ][ j ] = 0;
         }
         
         /*for( int k = k; k < numberTransmitAntennas_; ++k )
         {
            delete[] usersSmallScaleMatrixIndex_[i][j][k];
         }*/
      }
      if( usersSmallScaleMatrixIndex_[ i ] != 0 )
      {
         delete[] usersSmallScaleMatrixIndex_[i];
         usersSmallScaleMatrixIndex_[i] = 0;
      }
      //delete[] usersSmallScaleMatrixIndex_[i];
   }
}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::generateLargeScaleFading()
{
   PhysicalNode::PhysicalNode* node1;
   PhysicalNode::PhysicalNode* node2;
   Basic::MathFunctions mf;
   double distance = 0.0;
   for( int i = 0; i < numberUsers_; ++i )
   {
      node1 = simulationEnvironment_->getUser( i );
      for( int j = 0; j < numberENodeBs_; ++j )
      {        
         node2 = simulationEnvironment_->getENodeB( j );
         distance = mf.calculateDistance( node1->getPosition() , node2->getPosition() );
         double l = largeScaleFading_.generateFading( distance );
         largeScaleMatrix_( i , j ) =  l;             
      }
   }
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getLargeScaleFading( PhysicalNode::PhysicalNode* user,
   PhysicalNode::PhysicalNode* eNodeB )
{
   return largeScaleMatrix_( user->getId(), eNodeB->getId() ); 
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getLargeScaleFading_dB( PhysicalNode::PhysicalNode* user,
   PhysicalNode::PhysicalNode* eNodeB )
{
   return 10 * log10 ( getLargeScaleFading( user, eNodeB ) );  
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getLargeScaleFading( int userId, int eNodeBId )
{
   return largeScaleMatrix_( userId, eNodeBId ); 
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getLargeScaleFading_dB( int userId, int eNodeBId )
{
   return 10 * log10 ( getLargeScaleFading( userId, eNodeBId ) );  
}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::generateSmallScaleFading()
{
    Parameters::File f;
    if( shouldReadFile_ )
    {
       f.readChannel( fileName_, smallScaleArray_, timeStep_, 
          frequencyStep_ );
    }
    else
    {
       smallScaleFading_.generateFading( smallScaleArray_ );  
       timeStep_ = smallScaleFading_.getTimeStep();
       frequencyStep_ = smallScaleFading_.getFrequencyStep();
       f.saveChannel(fileName_, smallScaleArray_, timeStep_, 
          frequencyStep_); 
    }
}

//------------------------------------------------------------------------------

void
RadioChannel::
RadioChannel::generateSmallScaleFadingIndexes()
{  
    int timeSize = smallScaleArray_.size();
    I_Uniform_RNG gen(0, timeSize -1 );
    
    for( int i = 0; i < numberUsers_; ++i )
    {
       for( int j = 0; j < numberENodeBs_; ++j )
       {
          for( int k = 0; k < numberTransmitAntennas_; ++k )
          {  
             usersSmallScaleMatrixIndex_[ i ][ j ][ k ]  = gen();   
          }
       }
    } 
   
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getFading( PhysicalNode::PhysicalNode* user, 
 PhysicalNode::PhysicalNode* eNodeB, double time, double frequency, int antenna )
{
   int row = user->getId();
   int col = eNodeB->getId();
   return getFading( row, col, time, frequency, antenna );
}

//------------------------------------------------------------------------------

double
RadioChannel::
RadioChannel::getFading( int userId, int eNodeBId, double time, 
   double frequency, int antenna )
{
   if( userId > numberUsers_ )
   {
       it_error("userId out of range");
   }
   if( eNodeBId > numberENodeBs_ )
   {
       it_error("eNodeBid out of range");
   }
   if( antenna > numberTransmitAntennas_ )
   {
       it_error("antenna out of range");
   }
    
   // TODO: Create method to associate user index to a matrix index;
   int row = userId;
   int col = eNodeBId;
   
   int tindex1 = usersSmallScaleMatrixIndex_[ row ][ col ][ antenna ];
   int tindex2 = 0;
   double tindex_d = static_cast< double >( tindex1 );
   
   double findex_d = frequency / frequencyStep_;
   int findex1 = static_cast< int >( findex_d );
   int findex2 = 0;
   
   double small = 0.0;
   double large = 0.0;
   
   // for linear interpolation
   double y1 = 0.0;
   double y2 = 0.0;
   
   tindex_d += ( time / timeStep_ );
   tindex1 = static_cast< int >( tindex_d );
     
   while( tindex1 >= smallScaleArray_.size() )
   {
      tindex1 -= smallScaleArray_.size();
      tindex_d -= smallScaleArray_.size();
   }
   
   while( findex1 >= smallScaleArray_( 0 ).size() )
   {
      findex1 -= smallScaleArray_( 0 ).size();
      findex_d -= smallScaleArray_( 0 ).size();
   }
   
   tindex2 = tindex1 + 1;
   findex2 = findex1 + 1;
   
   while( tindex2 >= smallScaleArray_.size() )
   {
      tindex2 -= smallScaleArray_.size();
   }
   
   while( findex2 >= smallScaleArray_( 0 ).size() )
   {
      findex2 -= smallScaleArray_( 0 ).size();
   }
   
   if( tindex1 < 0 || tindex1 >= smallScaleArray_.size() || 
       tindex2 < 0 || tindex2 >= smallScaleArray_.size() )
   {
      it_error("Time out of range");    
   }
   
   if( findex1 < 0 || findex1 >= smallScaleArray_( 0 ).size() ||
       findex2 < 0 || findex2 >= smallScaleArray_( 0 ).size() )
   {
      it_error("Frequency out of range");
   }
   
   y1 = smallScaleArray_( tindex1 )( findex1 ) 
        + ( findex_d - findex1 ) 
        * ( smallScaleArray_( tindex1 )( findex2 ) 
            - smallScaleArray_( tindex1 )( findex1 ) 
           );
   y2 = smallScaleArray_( tindex2 )( findex1 ) 
        + ( findex_d - findex1 ) 
        * ( smallScaleArray_( tindex2 )( findex2 ) 
            - smallScaleArray_( tindex2 )( findex1 ) 
           );
   
   small = y1 + ( y2 - y1 ) * ( tindex_d - tindex1 );
   
   //cout << "size1: " << smallScaleArray_.size() << endl;
   //cout << "size2: " << smallScaleArray_(0).size() << endl;
   large = largeScaleMatrix_( row, col );
   //double small = smallScaleArray_( timeIndex )( frequencyIndex );
   
   return large * small;
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
