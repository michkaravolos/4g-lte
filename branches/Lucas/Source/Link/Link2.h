/**
 * @file    Link.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Link_h_
#define _Link_h_

#include <itpp/itbase.h>
#include "PhysicalNode.h"
#include "RadioChannel.h"
#include "SimulationEnvironment.h"

using namespace itpp;
using namespace std;

/**
 * Link Namespace. 
 * Detailed Description.
 */
namespace Link
{

/**
 * Link Class. 
 * Detailed Description.
 */
class Link
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Link();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static Link* getInstance();
      
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
      void createLinks();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getLoss( int i );
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getTotalFading( int eNodeBId, 
                             int userId,
                             double time,
                             double frequency,
                             int antenna );
      
      /**
       * Interface.
       * Detailed description. 
       */
      void calculateCQI();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void calculateSINR();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void calculateSINRs();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double calculateSINRPerUser( int userId,
                                   int eNodeBId,
                                   double frequency,
                                   int antenna );
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Link();
      
      /**
       * Member.
       * Left empty.
       */      
      static Link* instance_;    
      
      /**
       * Member.
       * Left empty.
       */      
      int numberUsers_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs_;
      
      /**
       * Member.
       * Left empty.
       */      
      ivec userId_;
      
      /**
       * Member.
       * Left empty.
       */      
      ivec eNodeBId_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec losses_;   
      
      /**
       * Member.
       * Left empty.
       */      
      RadioChannel::RadioChannel* radioChannel_;
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      /**
       * Member.
       * Left empty.
       */      
      double noiseFigure_;
      
      /**
       * Member.
       * Left empty.
       */      
      double boltzmannConstant_;
      
      /**
       * Member.
       * Left empty.
       */      
      double bandwidth_;
      
      /**
       * Member.
       * Left empty.
       */      
      double temperature_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberAntennas_;
      
      
      
      
      
              
};

};

#endif
