/**
 * @file    SimulationParameters.cpp
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

#include "SimulationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::SimulationParameters* 
   Parameters::SimulationParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************
/**
       * Inicializa os parametros e depois os lê do arquivo SimulationParameters.dat
       * 
       */
Parameters::
SimulationParameters::SimulationParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
SimulationParameters::~SimulationParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************
/**
       * Chama o constructor
       * 
       */
Parameters::SimulationParameters* 
Parameters::
SimulationParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new SimulationParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------
/**
       * Inicia os parametros
       * 
       */
void
Parameters::
SimulationParameters::setParameters()
{
    StepsPerDrop = 100; // [subframes]
    numberENodeBs = 57; // 19 x 3
    numberUsers = 1000; 
    temperature = 300;
    fileName_ = string( "../Parameters/SimulationParameters.dat" );
    DropsPerSimulation = 10;
    initialUsers = 10;
    finalUsers = 20;
    userStep = 5;
    Direction = 0;
    SoundingInterval = 0.05;
    SoundingLimit=100;
    InterLimit=100;
    
}

//------------------------------------------------------------------------------
/**
       * Lê os parâmetros do arquivo SimulationParameters.dat
       * 
       */
void
Parameters::
SimulationParameters::readFile()
{
   File f;
   f.read( fileName_, "StepsPerDrop", StepsPerDrop );
   f.read( fileName_, "numberENodeBs", numberENodeBs );
   f.read( fileName_, "numberUsers", numberUsers );
   f.read( fileName_, "temperature", temperature );
   f.read( fileName_, "DropsPerSimulation", DropsPerSimulation );
   f.read( fileName_, "initialUsers", initialUsers );
   f.read( fileName_, "finalUsers", finalUsers );
   f.read( fileName_, "userStep", userStep );
   f.read( fileName_, "SoundingLimit", SoundingLimit );
   f.read( fileName_, "InterLimit", InterLimit );   
   f.read( fileName_, "SoundingInterval", SoundingInterval );
   f.read( fileName_, "Direction", Direction );
   numberUsers = initialUsers;

}

//------------------------------------------------------------------------------
/**
       * Atualiza o número atual de usuários no sistema
       * 
       */
void
Parameters::
SimulationParameters::update()
{
   numberUsers += userStep;
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
