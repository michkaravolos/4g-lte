/**
 * @file    RandomAlgorithm.cpp
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

#include "RandomAlgorithm.h"

#include "SchedulerParameters.h"
#include "SimulationEnvironment.h"
#include "Results.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

Scheduler::
RandomAlgorithm::RandomAlgorithm()
{
};

// -----------------------------------------------------------------------------

Scheduler::
RandomAlgorithm::~RandomAlgorithm()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

double
Scheduler::
RandomAlgorithm::calculateTimeMetric( double averageCQI, double throughput )
{
   Uniform_RNG gen;
   return gen();
};


// -----------------------------------------------------------------------------

double
Scheduler::
RandomAlgorithm::calculateFrequencyMetric( double averageCQI, double throughput )
{
   Uniform_RNG gen;
   return gen();
};


// -----------------------------------------------------------------------------

double
Scheduler::
RandomAlgorithm::calculateSpaceMetric( double averageCQI, double throughput )
{
   Uniform_RNG gen;
   return gen();
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





