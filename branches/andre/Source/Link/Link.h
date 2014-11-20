/**
 * @file    Link.h
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


#ifndef _Link_h_
#define _Link_h_

#include <itpp/itbase.h>
#include "PhysicalNode.h"
#include "RadioChannel.h"
#include "SimulationEnvironment.h"
#include "SchedulingAlgorithm.h"
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
       * Set these Parameters:
       * numberUsers_, numberENodeBs_ and temperature from simulation parameters.
       * noiseFigure_ from uplink parameters.
       * boltzmannConstant_ (1.3806503e-23).
       * bandwidth_, numberAntennas_ and reuse_ from system parameters.
       */
      void setParameters();
      
      /**
       * Initialize these parameters:
       * numberUsers_, losses_, userId_, eNodeBId_, InterLimit_ and SoundingLimit_ from simulation parameters.
       * 
       */
      void initialize();
      
      /**
       * Interface.
       * Sets size 0 to userId_, eNodeBId_ and losses.
       */
      void clear();
      
      /**
       * Initialize links.
       * 
       */
      void createLinks();
      
      /**
       * Return Losses.
       * 
       */
      double getLoss( int i );
      
      /**
       * Calculates the total fading between an ENodeB and an user with the parameteres.
       * 
       */
      double getTotalFading( int eNodeBId, 
                             int userId,
                             double time,
                             double frequency,
                             int antenna );
      
      /**
       * Calculates CQI.
       * 
       */
      void calculateCQI();
      
      /**
       * Calls calculateSINRs e calculateCQI
       * 
       */
      void calculateSINR();
       /**
       * Calls calculateSINRs e calculateCQI
       * 
       */
      void calculateSINR1(int index, ivec& SchedulerUsers_, vec frequencies, bool calc);
      
      /**
       * Calculates the SINRs of users.
       */
      void calculateSINRs1(int scheduleduser, ivec& SchedulerUsers_, vec frequencies, bool calc);
      
      /**
       * Calculate the SINR for each user.
       */
      double calculateSINRPerUser1( int userId,
                                   int eNodeBId,
                                   double frequency,
                                   int antenna,
				   double InterSINR);
      /**
       * Interface.
       * Detailed description. 
       */
      void calculateSINRs();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void calculateSINRSounding(ivec& SchedulerUsers_);
      /**
       * Interface.
       * Detailed description. 
       */
      double calculateSINRPerUser( int userId,
                                   int eNodeBId,
                                   double frequency,
                                   int antenna );
      
      /**
       * Calculate the fading between the user that are producing interference and the ENodeB.
       */
      
      double CalculateInterFading(int userId, 
				  int eNodeBId, 
				  double frequency, 
                                  int antenna);
      
      Scheduler::SchedulingAlgorithm* sche;
      PhysicalLayer::PhysicalResourceBlock* prb;
      vec frequencies;
       
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Link();
      
      /**
       * Member.
       * Calls setParameters.
       */      
      static Link* instance_;    
      
      /**
       * Member.
       * The number of Users.
       */      
      int numberUsers_;
      
      /**
       * Member.
       * The number of ENodeBs.
       */      
      int numberENodeBs_;
      
      /**
       * Member.
       * Vector of users.
       */      
      ivec userId_;
      
      /**
       * Member.
       * Vector of eNodeBs.
       */      
      ivec eNodeBId_;
      
      /**
       * Member.
       * Vector of losses.
       */      
      vec losses_;   
      
      /**
       * Member.
       * Bind the Link to the radioChannel of the simulation.
       */      
      RadioChannel::RadioChannel* radioChannel_;
      
      /**
       * Member.
       * Bind the Link to the Simulation Envirioment.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      /**
       * Member.
       * Left empty.
       */      
      double noiseFigure_;
      
      /**
       * Member.
       * Equals to 1.3806503e-23
       */      
      double boltzmannConstant_;
      
      /**
       * Member.
       * Left empty.
       */      
      double bandwidth_;
      
      /**
       * Member.
       * Given in Kelvin.
       */      
      double temperature_;
      
      /**
       * Member.
       * May not being used.
       */      
      int numberAntennas_;
      /**
       * Member.
       * Left empty.
       */      
      double SoundingInterval_;
      /**
       * Member.
       * Left empty.
       */      
      int reuse_;
       /**
       * Member.
       * Left empty.
       */      
      int SoundingLimit_;
       /**
       * Member.
       * Left empty.
       */      
      int InterLimit_;
      
      
      
      
      
              
};

};

#endif
