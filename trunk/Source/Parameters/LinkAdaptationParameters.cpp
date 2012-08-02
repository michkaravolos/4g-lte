/**
 * @file    LinkAdaptationParameters.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    05/09/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include "LinkAdaptationParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Parameters::LinkAdaptationParameters* 
   Parameters::LinkAdaptationParameters::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************
/**
       * Inicia as variáveis e lê as variáveis do arquivo LinkAdaptationParameters.dat
       * 
       */
Parameters::
LinkAdaptationParameters::LinkAdaptationParameters()
{
   setParameters();
   readFile();
}

//------------------------------------------------------------------------------
/**
       * Destructor
       * 
       */
Parameters::
LinkAdaptationParameters::~LinkAdaptationParameters()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************
/**
       * Chama o constructor
       * 
       */
Parameters::LinkAdaptationParameters* 
Parameters::
LinkAdaptationParameters::getInstance()
{
   if ( !instance_)
   {
      instance_ = new LinkAdaptationParameters();
   }
   return instance_;
}

//------------------------------------------------------------------------------
/**
       * Inicia as variáveis
       * 
       */
void
Parameters::
LinkAdaptationParameters::setParameters()
{
   numberMCSs = 3;
   beta0 = 1.513;
   beta1 = 3.620;
   beta2 = 3.620;
   codingRate = 1 / 3;
   MCSThreshold0 = 0.0; // dB
   MCSThreshold1 = 5.0; // dB
   MCSThreshold2 = 13.0; // dB
   BERt = 1e-6;
   fileName_ = string( "../Parameters/LinkAdaptationParameters.dat" );
}

//------------------------------------------------------------------------------
/**
       * Lê os parâmetros do arquivo LinkAdaptationParameters.dat
       * 
       */
void
Parameters::
LinkAdaptationParameters::readFile()
{
   File f;
   f.read( fileName_, "numberMCSs", numberMCSs );
   f.read( fileName_, "beta0", beta0 );
   f.read( fileName_, "beta1", beta1 );
   f.read( fileName_, "beta2", beta2 );
   f.read( fileName_, "MCSThreshold0", MCSThreshold0 );
   f.read( fileName_, "MCSThreshold1", MCSThreshold1 );
   f.read( fileName_, "MCSThreshold2", MCSThreshold2 );
   f.read( fileName_, "BERt", BERt );
   f.read( fileName_, "codingRate", codingRate );
}

//------------------------------------------------------------------------------

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
