/**
 * @file    RandomAlgorithm.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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
       * Calculates the metric in time domain.
       * 
       */   
      virtual double calculateTimeMetric( double averageCQI, 
                                          double throughput   ) ;
      
      /**
       * Calculates the metric in frequency domain.
       * 
       */   
      virtual double calculateFrequencyMetric( double averageCQI, 
                                               double throughput   );
      
      /**
       * Calculates the metric in space domain.
       * 
       */   
      virtual double calculateSpaceMetric( double averageCQI, 
                                           double throughput   );

};

};

#endif

