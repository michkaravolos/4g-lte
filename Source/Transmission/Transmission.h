/**
 * @file    Transmission.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/29/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Transmission_h_
#define _Transmission_h_

#include "SimulationEnvironment.h"

using namespace itpp;
using namespace std;

/**
 * Transmission Namespace. 
 * Detailed Description.
 */
namespace Transmission
{

/**
 * Transmission Class. 
 * Detailed Description.
 */
class Transmission
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Transmission();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static Transmission* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void clear();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void transmit();
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Transmission();
      
      /**
       * Member.
       * Left empty.
       */      
      static Transmission* instance_;  
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      /**
       * Member.
       * Left empty.
       */      
      string name_;    
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs_; 
};

};

#endif
