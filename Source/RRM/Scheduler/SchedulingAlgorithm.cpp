/**
 * @file    SchedulingAlgorithm.cpp
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

#include "SchedulingAlgorithm.h"

#include "SchedulerParameters.h"
#include "SystemParameters.h"
#include "SimulationEnvironment.h"
#include "Results.h"
#include "Link.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

Scheduler::
SchedulingAlgorithm::SchedulingAlgorithm()
{
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------

Scheduler::
SchedulingAlgorithm::~SchedulingAlgorithm()
{
   int s1 = usersPRBs_.size();
   int s2 = 0;
   int s3 = 0;
   for( int i = 0; i < s1; ++i )
   {
      s1 = usersPRBs_( i ).size();
      for( int j = 0; j < s2; ++j )
      {
         s2 = usersPRBs_( i )( j ).size();
         for( int k = 0; k < s3; ++k )
         {
            usersPRBs_( i )( j ).clear();
         }
      }
      usersPRBs_( i ).set_size( 0 );
      
   }
   usersPRBs_.set_size( 0 );
};

// *****************************************************************************
// Interface
// *****************************************************************************

void
Scheduler::
SchedulingAlgorithm::setParameters()
{
   Parameters::SchedulerParameters* schp = 
      Parameters::SchedulerParameters::getInstance(); 
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   
   numberUsersPerSlot_ = schp->numberUsersPerSlot;
   sameUserAtSlots_ = schp->sameUserAtSlots;
   
   numberAntennas_ = sysp->numberTransmitAntennas;
 
}

// -----------------------------------------------------------------------------

void
Scheduler::
SchedulingAlgorithm::initialize()
{
   linkAdaptation_ = LinkAdaptation::LinkAdaptation::getInstance();
   timeManager_ =  TimeManager::TimeManager::getInstance();
   usersPRBs_.set_size( 0 );
   totalSINR_ = 0.0;

}

// -----------------------------------------------------------------------------

void
Scheduler::
SchedulingAlgorithm::schedule( const ivec& users, PhysicalLayer::PhysicalLayer* pl, int Direction)
{
   if( users.size() == 0 )
   {
      return;
   }
   
   SimulationEnvironment::SimulationEnvironment* se = 
      SimulationEnvironment::SimulationEnvironment::getInstance();
   
   //Results::Results* r = Results::Results::getInstance();
   
   PhysicalNode::User* user;
   PhysicalLayer::PhysicalResourceBlock* prb;
 
  
   int slots = pl->getNumberSlots();
   int prbs = pl->getNumberPRBsPerSlot();
   int index = 0;
   int antenna = 0;
   int usersSize = 0 ;
   j1[0]=0;
   double maxMetric = 1e-300;
   double metric = 0.0;
  

   
   int antenaIds[numberAntennas_];
   
   timeSchedule( users, schedulerUsers_ );
  
   usersSize = schedulerUsers_.size();
   
   usersPRBs_.set_size( usersSize );
   for( int i = 0; i < usersPRBs_.size(); ++i )
   {
      usersPRBs_( i ).set_size( slots );   
   }
   
   if( sameUserAtSlots_ )
   { 
      for( int i = 0; i < prbs; ++i )
      {
         prb = pl->getSubframe()->getSlot( 0 )->getPRB( i );     
         for( int k = 0; k < numberAntennas_; ++k )
         {
            for( int l = 0; l < usersSize; ++l )
            {
               user = se->getUser( schedulerUsers_( l ) );
               metric = this->calculateFrequencyMetric( 
                  user->getAverageCQI( prb->getSCFrequencies(), k ), 
                  static_cast< double >( user->getRawBits() ) 
                     /* timeManager_->getCurrentTime()*/ );
               if( metric > maxMetric )
               {
                  maxMetric = metric;
                  index = l; 
                  antenna = k;           
               }       
            }
            antenaIds[k] = index;
            maxMetric = 1e-300;
         }
         
         for( int k = 0; k < numberAntennas_; ++k )
         {
            user = se->getUser( schedulerUsers_(  antenaIds[k] ) );
            metric = this->calculateSpaceMetric( 
               user->getAverageCQI( prb->getSCFrequencies(), k ), 
               static_cast< double >( user->getRawBits() ) 
                  /* timeManager_->getCurrentTime()*/ );
            if( metric > maxMetric )
            {
               maxMetric = metric;
               index = antenaIds[k]; 
               antenna = k;           
            }   
         }
         maxMetric = 1e-300;
         
         for( int j = 0; j < slots; ++j )
         {
            prb = pl->getSubframe()->getSlot( j )->getPRB( i );
            prb->setUser( schedulerUsers_( index ), antenna );        
            usersPRBs_( index )( j ).push_back( prb );         
         }
       //ind[j1[0]]=index;
	// j1[0]++;
vec frequencies;
         frequencies.set_size( prb->getNumberSubcarriers() );
         frequencies = prb->getSCFrequencies();
	 
         /*for( int ii = 0; ii < frequencies.size(); ++ii )
         {cout<<frequencies[ii]<<"\n";
            //r->storeSINR( user->getSINR( frequencies( ii ), antenna ), frequencies( ii ) );
         }
         cout<<"USER\n";*/
      }
 
   vec scfreqs;
   vec frequencies;
   int usersSize = schedulerUsers_.size();
   int nprbs = 0;
     Link::Link* link_;
      link_ = Link::Link::getInstance();
   int freqSize = 0;
   int oldSize = 0;
   scfreqs.set_size( 0 );
   bool calc=false;
   if(Direction==1){
   for( int i = 0; i < usersSize; ++i )
   {
      user = se->getUser( schedulerUsers_( i ) );
      int EnodeID = user->getENodeBId();
      nprbs = usersPRBs_( i )( 0 ).size();
      if( nprbs != 0 )
      {
         for( int j = 0; j < nprbs; ++j )
         {        
            prb = usersPRBs_( i )( 0 ).at( j );
            freqSize = prb->getNumberSubcarriers();
            oldSize = frequencies.size();
            scfreqs.set_size( freqSize );
            scfreqs = prb->getSCFrequencies();
            frequencies.set_size( oldSize + 1, true );
            frequencies.ins( oldSize, scfreqs );
	    if(i==usersSize-1 && j==nprbs-1){calc=true;}
	   link_->calculateSINR1(schedulerUsers_(i), schedulerUsers_, scfreqs, calc);
	 }
      }
      
      frequencies.set_size( 0 );
      scfreqs.set_size( 0 );
   }
   }
      configurePRBs( pl );
   }
   
   else
   {
      for( int i = 0; i < slots; ++i )
      {
         for( int j = 0; j < prbs; ++j )
         {
            prb = pl->getSubframe()->getSlot( i )->getPRB( j );
            
            for( int k = 0; k < numberAntennas_; ++k )
            {
               for( int l = 0; l < usersSize; ++l )
               {
                  user = se->getUser( schedulerUsers_( l ) );
                  metric = this->calculateFrequencyMetric( 
                     user->getAverageCQI( prb->getSCFrequencies(), k ), 
                     static_cast< double >( user->getRawBits() ) 
                        /* timeManager_->getCurrentTime()*/ );
                  if( metric > maxMetric )
                  {
                     maxMetric = metric;
                     index = l; 
                     antenna = k;           
                  }       
               }
               antenaIds[k] = index;
               maxMetric = 1e-300;
            }
            
            for( int k = 0; k < numberAntennas_; ++k )
            {
               user = se->getUser( schedulerUsers_(  antenaIds[k] ) );
               metric = this->calculateSpaceMetric( 
                  user->getAverageCQI( prb->getSCFrequencies(), k ), 
                  static_cast< double >( user->getRawBits() ) 
                     /* timeManager_->getCurrentTime() */ );
               if( metric > maxMetric )
               {
                  maxMetric = metric;
                  index = antenaIds[k]; 
                  antenna = k;           
               }   
            }
            maxMetric = 1e-300;
            prb = pl->getSubframe()->getSlot( i )->getPRB( j );        
            prb->setUser( schedulerUsers_( index ), antenna );            
            usersPRBs_( index )( i ).push_back( prb );
         }
      }
      configurePRBsPerSlot( pl );
   }
     
      
   schedulerUsers_.clear();  
   for( int i = 0; i < usersPRBs_.size(); ++i )
   {
      for( int j = 0; j < usersPRBs_( i ).size(); ++j )
      {
         usersPRBs_( i )( j ).clear();
      }
      usersPRBs_( i ).set_size( 0 );
   }
   
   usersPRBs_.set_size( 0 );

}

// -----------------------------------------------------------------------------

void
Scheduler::
SchedulingAlgorithm::timeSchedule( const ivec& users, ivec& scheduledUsers )
{
   SimulationEnvironment::SimulationEnvironment* se = 
      SimulationEnvironment::SimulationEnvironment::getInstance();
 
   PhysicalNode::User* user;
   
   ivec u;
   u.set_size( users.size() );
   u = users;
   int size = u.size();
   double metric = 0.0;
   double maxMetric = 1e-300;
   int index = -1;
   
   if( users.size() <= numberUsersPerSlot_ )
   {
      scheduledUsers.set_size( users.size() );
      scheduledUsers = users;
   }
   else
   {
      scheduledUsers.set_size( numberUsersPerSlot_ );
      
      for( int i = 0; i < numberUsersPerSlot_; ++i )
      {
         for( int j = 0; j < size; ++j )
         {
            user = se->getUser( u( j ) );
            metric = calculateTimeMetric( 
               user->getAverageCQI(), 
               static_cast< double >( user->getRawBits() ) 
                  /* timeManager_->getCurrentTime()*/ );
            if( metric > maxMetric )
            {
               maxMetric = metric;
               index = j;
            }          
         }        
         maxMetric = 1e-300;
         scheduledUsers( i ) = u( index );
	 //cout<<scheduledUsers(i)<<"\n\n\n\n";
         u.del( index );
         size--;
         
      } 
   }


}

// -----------------------------------------------------------------------------

void
Scheduler::
SchedulingAlgorithm::configurePRBs( PhysicalLayer::PhysicalLayer* pl )
{
   SimulationEnvironment::SimulationEnvironment* se = 
      SimulationEnvironment::SimulationEnvironment::getInstance();
   
   Results::Results* r = Results::Results::getInstance();
   
   PhysicalLayer::PhysicalResourceBlock* prb;  
   PhysicalNode::User* user;
   
   vec frequencies;
   vec cqis;
   vec sinrs;
   vec scfreqs;
   
   int usersSize = schedulerUsers_.size();
   int nslots = 0;
   int nprbs = 0;
   
   int freqSize = 0;
   int oldSize = 0;
    Link::Link* link_;
      link_ = Link::Link::getInstance();
   double sinr = 0.0;  
   int MCS = -1;
   int rawBits = 0;
   double effectiveBits = 0.0;
   
   frequencies.set_size( 0 );
   cqis.set_size( 0 );
   sinrs.set_size( 0 );
   scfreqs.set_size( 0 );
   
   for( int i = 0; i < usersSize; ++i )
   {
      user = se->getUser( schedulerUsers_( i ) );
      int EnodeID = user->getENodeBId();
           //cout<<schedulerUsers_(i)<<" da EnodeB: "<<EnodeID<<"\n";
      nslots = usersPRBs_( 0 ).size();
      nprbs = usersPRBs_( i )( 0 ).size();
      if( nprbs != 0 )
      {
         for( int j = 0; j < nprbs; ++j )
         {        
            prb = usersPRBs_( i )( 0 ).at( j );
            freqSize = prb->getNumberSubcarriers();
            oldSize = frequencies.size();
            scfreqs.set_size( freqSize );
            scfreqs = prb->getSCFrequencies();
            frequencies.set_size( oldSize + 1, true );
            cqis.set_size( oldSize + 1, true );
            sinrs.set_size( oldSize + 1, true );
            frequencies.ins( oldSize, scfreqs );
            for( int freq = 0; freq < freqSize; ++freq )
            {//cout<<scfreqs(freq)<<"\n";
               cqis.ins( cqis.size() - 1, 
                  user->reportCQI( scfreqs( freq ), prb->getUserAntenna() ) );
               sinrs.ins( sinrs.size() - 1, 
                  user->getSINR( scfreqs( freq ), prb->getUserAntenna() ) );
	       
               r->storeSINR( user->getSINR( scfreqs( freq ), prb->getUserAntenna() ) );
               r->storeDistance( user->getPosition().abs() );
            }
            cqis.del( cqis.size() - 1 );
            sinrs.del( sinrs.size() - 1 );      
            frequencies.del( frequencies.size() - 1 );          
         }
         linkAdaptation_->chooseMCS( cqis, sinr, MCS, rawBits, effectiveBits );   
                  
         for( int j = 0; j < nslots; ++j )
         {
            for( int k = 0; k < nprbs; ++k )
            {
               prb = usersPRBs_( i )( j ).at( k );
               
               if( linkAdaptation_->checkMCS( sinrs, MCS )  )
               {
                  prb->setBits( rawBits, effectiveBits );                  
                  r->storeSuccess();
               }
               else if( MCS != -1 )
               {
                  prb->setBits( 0, 0 );
                  r->storeFailure();
               }   
               r->storeMCS( MCS ); 
            }
         }
      }
      frequencies.set_size( 0 );
      scfreqs.set_size( 0 );
      cqis.set_size( 0 );
      sinrs.set_size( 0 );
      sinr = 0.0;  
      MCS = -1;
      rawBits = 0;
      effectiveBits = 0.0;     
   }   
}

// -----------------------------------------------------------------------------

void
Scheduler::
SchedulingAlgorithm::configurePRBsPerSlot( PhysicalLayer::PhysicalLayer* pl )
{
   SimulationEnvironment::SimulationEnvironment* se = 
      SimulationEnvironment::SimulationEnvironment::getInstance();
   
   
   Results::Results* r = Results::Results::getInstance();
   
   PhysicalLayer::PhysicalResourceBlock* prb;  
   PhysicalNode::User* user;
   
   vec frequencies;
   vec cqis;
   vec sinrs;
   vec scfreqs;
   
   int usersSize = schedulerUsers_.size();
   int nslots = 0;
   int nprbs = 0;
   
   int freqSize = 0;
   int oldSize = 0;
   
   double sinr = 0.0;  
   int MCS = -1;
   int rawBits = 0;
   double effectiveBits = 0.0;
   
   frequencies.set_size( 0 );
   
   
   for( int i = 0; i < usersSize; ++i )
   {
      user = se->getUser( schedulerUsers_( i ) );
      nslots = usersPRBs_( i ).size();
      for( int j = 0; j < nslots; ++j )
      {   
         nprbs = usersPRBs_( i )( j ).size();
         if( nprbs != 0 )
         {
            for( int k = 0; k < nprbs; ++k )
            {        
               prb = usersPRBs_( i )( j ).at( k );
               freqSize = prb->getNumberSubcarriers();
               oldSize = frequencies.size();
               scfreqs.set_size( freqSize );
               scfreqs = prb->getSCFrequencies();
               
               frequencies.set_size( oldSize + 1, true );
               cqis.set_size( oldSize + 1, true );
               sinrs.set_size( oldSize + 1, true );
               frequencies.ins( oldSize, scfreqs );
               for( int freq = 0; freq < freqSize; ++freq )
               {
                  cqis.ins( cqis.size() - 1, 
                     user->reportCQI( scfreqs( freq ), prb->getUserAntenna() ) );
                  sinrs.ins( sinrs.size() - 1, 
                     user->getSINR( scfreqs( freq ), prb->getUserAntenna() ) );
                  //r->storeSINR( user->getSINR( scfreqs( freq ), prb->getUserAntenna() ) );
                  //r->storeDistance( user->getPosition().abs() );
               }
               cqis.del( cqis.size() - 1 );
               sinrs.del( sinrs.size() - 1 );      
               frequencies.del( frequencies.size() - 1 );          
            }
            linkAdaptation_->chooseMCS( cqis, sinr, MCS, rawBits, effectiveBits );   
            
            
            for( int k = 0; k < nprbs; ++k )
            {
               prb = usersPRBs_( i )( j ).at( k );
               
               if( linkAdaptation_->checkMCS( sinrs, MCS )  )
               {
                  prb->setBits( rawBits, effectiveBits );                  
                  r->storeSuccess();
               }
               else if( MCS != -1 )
               {
                  prb->setBits( 0, 0 );
                  r->storeFailure();
               }   
               r->storeMCS( MCS ); 
            }
               
         } // if    
      }  //slots
      cqis.set_size( 0 );
      sinrs.set_size( 0 );
      sinr = 0.0;  
      MCS = -1;
      rawBits = 0;
      effectiveBits = 0.0;     
   }   // users
}
int Scheduler::
SchedulingAlgorithm::j1_R(){

    return j1[0];
}
int Scheduler::
SchedulingAlgorithm::index_R(int j11){
  if(j11>j1[0]){cout<<"Valor Maluco\n";}
  else
    return ind[j11] ;
}
int Scheduler::
SchedulingAlgorithm::schedulerUsers_R(int index1){
  //if(index1>j1[0]){cout<<"Valor Maluco\n";}
  //else
    return schedulerUsers_(index1);
}
  
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





