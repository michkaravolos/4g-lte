/**
 * @file    main.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008 (Month/Day/Year)
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

#include "Simulation.h"
/**
       * Creates an instance si and starts the simulation by runCampaing
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
