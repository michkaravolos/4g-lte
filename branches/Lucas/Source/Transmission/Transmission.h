/**
 * @file    Transmission.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/29/2008
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
       * Initialize numberENodeBs_ from simulation parameters.
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void initialize();
      
      /**
       * Interface.
       * Left empty. 
       */
      void clear();
      
      /**
       * Interface.
       * Call transmit of every eNodeB. 
       */
      void transmit();
      
   private:
      
      /**
       * Constructor.
       * Initialize name_.
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
       * The title of Transmission instance.
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
