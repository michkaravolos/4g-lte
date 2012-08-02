/**
 * @file    main.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008 (Month/Day/Year)
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */                                                                

// *****************************************************************************
// Includes
// *****************************************************************************

#include "Simulation.h"
/**
       * Cria o objeto si e inicia a simulacao por runCampaign
       * 
       */

using namespace std;

int 
main()
{
   Simulation::Simulation si;
   si.runCampaign();
   return 1;
}
