/**
 * @file    BestCQIAlgorithm.cpp
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

#include "BestCQIAlgorithm.h"

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
BestCQIAlgorithm::BestCQIAlgorithm()
{
};

// -----------------------------------------------------------------------------

Scheduler::
BestCQIAlgorithm::~BestCQIAlgorithm()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************

double
Scheduler::
BestCQIAlgorithm::calculateTimeMetric( double averageCQI, double throughput )
{
   return log10( 1 + averageCQI ) / log10( 2.0 );
};


// -----------------------------------------------------------------------------

double
Scheduler::
BestCQIAlgorithm::calculateFrequencyMetric( double averageCQI, 
                                            double throughput )
{
   return log10( 1 + averageCQI ) / log10( 2.0 );
};


// -----------------------------------------------------------------------------

double
Scheduler::
BestCQIAlgorithm::calculateSpaceMetric( double averageCQI, double throughput )
{
   return log10( 1 + averageCQI ) / log10( 2.0 );
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





