/**
 * @file    SimulationEnvironment.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
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

#include "SimulationEnvironment.h"

#include "SimulationParameters.h"
#include "Results.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

SimulationEnvironment::SimulationEnvironment* 
   SimulationEnvironment::SimulationEnvironment::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

SimulationEnvironment::
SimulationEnvironment::SimulationEnvironment()
{
   name_ = "Simulation Environment: ";
   setParameters();
   //initialize();
   
}

//------------------------------------------------------------------------------

SimulationEnvironment::
SimulationEnvironment::~SimulationEnvironment()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

SimulationEnvironment::SimulationEnvironment* 
SimulationEnvironment::
SimulationEnvironment::getInstance()
{
   if ( !instance_)
   {
      instance_ = new SimulationEnvironment();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
SimulationEnvironment::
SimulationEnvironment::initialize()
{    
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   numberUsers_ = sp->numberUsers;
   mobility_ = Mobility::Mobility::getInstance();
   userIdCounter_ = 0;
   eNodeBIdCounter_ = 0;
   
   createUsers();
   createENodeBs();
  
}

//------------------------------------------------------------------------------

void
SimulationEnvironment::
SimulationEnvironment::setParameters()
{  
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   
   numberUsers_ = sp->numberUsers;
   numberENodeBs_ = sp->numberENodeBs; 
}

//------------------------------------------------------------------------------

void
SimulationEnvironment::
SimulationEnvironment::clear()
{
   PhysicalNode::User* u;
   PhysicalNode::ENodeB* e;
   
   for( int i = 0; i < numberUsers_; ++i )
   {
      u = getUser( i );
      delete u;
      /*if (users_( i ) != 0 )
      {
         delete users_( i );
         users_( i ) = 0;
      }*/
      //users_( i ) = 0;
   }
   users_.set_size( 0 );
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      e = getENodeB( i );
      delete e;
      /*if (eNodeBs_( i ) != 0 )
      {
         delete eNodeBs_( i );
         eNodeBs_( i ) = 0;
      }*/
      //eNodeBs_( i ) = 0;
   }
   eNodeBs_.set_size( 0 );
}

//------------------------------------------------------------------------------

void
SimulationEnvironment::
SimulationEnvironment::createUsers()
{   
   //Results::Results* r = Results::Results::getInstance();
   int sector = 0;
   int site = 0;
   Basic::Position p( 0.0, 0.0 );
   
   users_.set_size( numberUsers_ );
   for( int i = 0; i < numberUsers_; ++i )
   {
      
      mobility_->generatePosition( p, site, sector );
  
      users_( i ) = new PhysicalNode::User( p, site, sector, userIdCounter_ );
      
      //r->storeDistance( p.abs() );

      userIdCounter_++;     
   } 
}

//------------------------------------------------------------------------------

void
SimulationEnvironment::
SimulationEnvironment::createENodeBs()
{
   eNodeBs_.set_size( numberENodeBs_ );
   int nSites = 19;
   for( int i = 0; i < nSites; ++i )
   {
      Basic::Position p( 0.0, 0.0 );
      mobility_->generatePosition( p, i );     
      for( int j = 0; j < 3; ++j )
      {
         eNodeBs_( 3 * i + j ) = new PhysicalNode::ENodeB( p, eNodeBIdCounter_ );
         eNodeBIdCounter_++;
      }
      
   } 
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
