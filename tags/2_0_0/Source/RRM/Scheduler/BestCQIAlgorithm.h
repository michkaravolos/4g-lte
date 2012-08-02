/**
 * @file    BestCQIAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _BestCQIAlgorithm_h_
#define _BestCQIAlgorithm_h_

#include "SchedulingAlgorithm.h"

using namespace std;
using namespace itpp;

namespace Scheduler
{

/**
 * BestCQIAlgorithm Class.
 * Detailed description.
 */
class BestCQIAlgorithm : public SchedulingAlgorithm
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      BestCQIAlgorithm();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~BestCQIAlgorithm();
      
             
   protected:
      
      /**
       * Calcula a metrico no dominio do tempo
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
       * Calcula a métrica espacial
       * 
       */   
      virtual double calculateSpaceMetric( double averageCQI, 
                                           double throughput );
};

};

#endif

