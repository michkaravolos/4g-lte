/**
 * @file    SchedulerParameters.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _SchedulerParameters_h_
#define _SchedulerParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * SchedulerParameters Class. 
 * Detailed Description.
 */
class SchedulerParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~SchedulerParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static SchedulerParameters* getInstance();

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
       * Member
       * Detailed description
       */
      int numberUsersPerSlot;
      
      /**
       * Member
       * Detailed description
       */
      int schedulingAlgorithm;
      
      /**
       * Member
       * Detailed description
       */
      bool sameUserAtSlots;
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      SchedulerParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static SchedulerParameters* instance_; 
      
};

};

#endif
