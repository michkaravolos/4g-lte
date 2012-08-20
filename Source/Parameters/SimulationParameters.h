/**
 * @file    SimulationParameters.h
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

#ifndef _SimulationParameters_h_
#define _SimulationParameters_h_

#include "Parameters.h"

using namespace std;

namespace Parameters
{

/**
 * SimulationParameters Class. 
 * Detailed Description.
 */
class SimulationParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~SimulationParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static SimulationParameters* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void readFile();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void update();
      
      /**
       * Member.
       * Simulation time, in seconds..
       */
      int StepsPerDrop; 
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs;       
      
      /**
       * Member.
       * Left empty.
       */      
      int numberUsers;
      
      /**
       * Member.
       * Left empty.
       */      
      double temperature;
      
      /**
       * Member.
       * Left empty.
       */      
      int DropsPerSimulation;
      
      /**
       * Member.
       * Left empty.
       */      
      int initialUsers;
      
      /**
       * Member.
       * Left empty.
       */      
      int finalUsers;
      
      /**
       * Member.
       * Left empty.
       */      
      int userStep;
       /**
       * Member.
       * Left empty.
       */   
      int Direction;
      
       /**
       * Member.
       * Left empty.
       */   
      double SoundingInterval;
      
       /**
       * Member.
       * Left empty.
       */   
      double SoundingLimit;
      
       /**
       * Member.
       * Left empty.
       */   
      double InterLimit;
      
      
    
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      SimulationParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static SimulationParameters* instance_;    

};

};

#endif

