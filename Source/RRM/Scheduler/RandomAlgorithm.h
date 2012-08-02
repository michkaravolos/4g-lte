/**
 * @file    RandomAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _RandomAlgorithm_h_
#define _RandomAlgorithm_h_

#include "SchedulingAlgorithm.h"

using namespace std;
using namespace itpp;

namespace Scheduler
{

/**
 * RandomAlgorithm Class.
 * Detailed description.
 */
class RandomAlgorithm : public SchedulingAlgorithm
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      RandomAlgorithm();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~RandomAlgorithm();
             
   protected:
      
      /**
       * Calcula a metrica no dominio do tempo
       * 
       */   
      virtual double calculateTimeMetric( double averageCQI, 
                                          double throughput   ) ;
      
      /**
       * Calcula a metrica no dominio da frequencia
       * 
       */   
      virtual double calculateFrequencyMetric( double averageCQI, 
                                               double throughput   );
      
      /**
       * Calcula a metrica espacial
       * 
       */   
      virtual double calculateSpaceMetric( double averageCQI, 
                                           double throughput   );

};

};

#endif

