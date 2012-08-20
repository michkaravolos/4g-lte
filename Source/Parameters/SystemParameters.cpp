/**
 * @file    SystemParameters.cpp
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

#include "SystemParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::SystemParameters* 
   Parameters::SystemParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
SystemParameters::SystemParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
SystemParameters::~SystemParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::SystemParameters* 
Parameters::
SystemParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new SystemParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
SystemParameters::setParameters()
{
   systemBandwidth = 10e6;
   centralFrequency = 2e9;
   subcarrierBandwidth = 15e3;
   totalPower = 39.810; // 46dBm;
   numberTransmitAntennas = 4;
   fileName_ = string( "../Parameters/SystemParameters.dat" );
   reuse=0;
}

//------------------------------------------------------------------------------

void
Parameters::
SystemParameters::readFile()
{
   File f;
   f.read( fileName_, "systemBandwidth", systemBandwidth );
   f.read( fileName_, "centralFrequency", centralFrequency );
   f.read( fileName_, "subcarrierBandwidth", subcarrierBandwidth );
   f.read( fileName_, "totalPower", totalPower );
   f.read( fileName_, "numberTransmitAntennas", numberTransmitAntennas );
   f.read( fileName_, "reuse", reuse );
   
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
