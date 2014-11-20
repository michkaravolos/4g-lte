/**
 * @file    SchedulerParameters.cpp
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

#include "SchedulerParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::SchedulerParameters* 
   Parameters::SchedulerParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
SchedulerParameters::SchedulerParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
SchedulerParameters::~SchedulerParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::SchedulerParameters* 
Parameters::
SchedulerParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new SchedulerParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
SchedulerParameters::setParameters()
{
   numberUsersPerSlot = 10;
   sameUserAtSlots = true;
   schedulingAlgorithm = 0;
   fileName_ = string( "../Parameters/SchedulerParameters.dat" );
}

//------------------------------------------------------------------------------

void
Parameters::
SchedulerParameters::readFile()
{
   File f;
   f.read( fileName_, "numberUsersPerSlot", numberUsersPerSlot );
   f.read( fileName_, "schedulingAlgorithm", schedulingAlgorithm );


}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
