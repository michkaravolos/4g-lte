/**
 * @file    UserParameters.cpp
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

#include "UserParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::UserParameters* 
   Parameters::UserParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
UserParameters::UserParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------

Parameters::
UserParameters::~UserParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

Parameters::UserParameters* 
Parameters::
UserParameters::getInstance()
{
   if ( !instance_ )
   {
      instance_ = new UserParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
Parameters::
UserParameters::setParameters()
{
   noiseFigure = pow( 10, 0.9 ); // 9 dB
   CQIReportDelay = 4; // [subframes]
   CQIUpdatePeriod = 10; // [subframes]
   numberCQIBits = 4;
   maxSINRConsidered = 30.0;
   minSINRConsidered = -10.0;
   CQISD = 1.0;
   fileName_ = string("../Parameters/UserParameters.dat");
}

//------------------------------------------------------------------------------

void
Parameters::
UserParameters::readFile()
{
   File f;
   f.read( fileName_, "noiseFigure", noiseFigure );
   f.read( fileName_, "CQIUpdatePeriod", CQIUpdatePeriod );
   f.read( fileName_, "numberCQIBits", numberCQIBits );
   f.read( fileName_, "maxSINRConsidered", maxSINRConsidered );
   f.read( fileName_, "minSINRConsidered", minSINRConsidered );
   f.read( fileName_, "CQIReportDelay", CQIReportDelay );
   f.read( fileName_, "CQISD", CQISD );
   //cout << "Noise figure: " << noiseFigure << endl;
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
