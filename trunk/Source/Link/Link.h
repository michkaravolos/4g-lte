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
       * Define os parametros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa o link
       * 
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void clear();
      
      /**
       * Inicializa os links
       * 
       */
      void createLinks();
      
      /**
       * Retorna as perdas
       * 
       */
      double getLoss( int i );
      
      /**
       * Calcula o fading total entre uma EnodeB e um usuario naquele tempo, naquela frequencia e com aquela antena
       * 
       */
      double getTotalFading( int eNodeBId, 
                             int userId,
                             double time,
                             double frequency,
                             int antenna );
      
      /**
       * Calcula o CQI
       * 
       */
      void calculateCQI();
      
      /**
       * Evoca calculateSINRs e calculateCQI
       * 
       */
      void calculateSINR();
       /**
       * Evoca calculateSINRs e calculateCQI
       * 
       */
      void calculateSINR1(int index, ivec& SchedulerUsers_, vec frequencies, bool calc);
      
      /**
       * Calcula as SINRs do usuarios
       * 
       */
      void calculateSINRs1(int scheduleduser, ivec& SchedulerUsers_, vec frequencies, bool calc);
      
      /**
       * Calcula a SINR para cada usuario
       * 
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
       * Calcula o Fading entre o Usuario interferente e a ENodeB do usuario em questao
       * . 
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
      /**
       * Member.
       * Left empty.
       */      
      double SoundingInterval_;
      /**
       * Member.
       * Left empty.
       */      
      int WaySimulation_;
      
      
      
      
      
              
};

};

#endif
