/**
 * @file    ProportionalFairAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _ProportionalFairAlgorithm_h_
#define _ProportionalFairAlgorithm_h_

#include "SchedulingAlgorithm.h"

using namespace std;
using namespace itpp;

namespace Scheduler
{

/**
 * ProportionalFairAlgorithm Class.
 * Detailed description.
 */
class ProportionalFairAlgorithm : public SchedulingAlgorithm
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      ProportionalFairAlgorithm();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~ProportionalFairAlgorithm();

      
   protected:
      
      /**
       * Calcula a metrica no dominio do tempo
       * 
       */   
      virtual double calculateTimeMetric( double averageCQI, 
                                          double throughput ) ;
      
      /**
       * Calcula a metrica no dominio da frequencia
       * 
       */   
      virtual double calculateFrequencyMetric( double averageCQI, 
                                               double throughput );
      
      /**
       * Calcula a metrica espacial
       * 
       */   
      virtual double calculateSpaceMetric( double averageCQI, 
                                           double throughput );


};

};

#endif

