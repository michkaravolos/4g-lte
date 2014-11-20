/**
 * @file    AntennaParameters.cpp
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

#include "AntennaParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::AntennaParameters* 
   Parameters::AntennaParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
AntennaParameters::AntennaParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
AntennaParameters::~AntennaParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::AntennaParameters* 
Parameters::
AntennaParameters::getInstance()
{
   if ( !instance_ )
   {
      instance_ = new AntennaParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
AntennaParameters::setParameters()
{
   theta3dB = 70 * pi / 180; //70 * pi / 180;
   minimumGaindB = 20;
   fileName_ = string("../Parameters/AntennaParameters.dat");
}

//------------------------------------------------------------------------------

void
Parameters::
AntennaParameters::readFile()
{
   File f;
   f.read( fileName_, "theta3dB", theta3dB );
   f.read( fileName_, "minimumGaindB", minimumGaindB );
   ///cout << "Reading File:" << endl;
   //cout << theta3dB << endl;
   //cout << minimumGaindB << endl;
   //theta3dB = 70 * pi / 180;
   //minimumGaindB = 20;
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
