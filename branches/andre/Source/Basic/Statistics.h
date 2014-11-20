/**
 * @file    Statistics.h
 * Name:    3G LTE Statistics Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
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
 *
 * @author_2  Luiz Gustavo da Silva Carvalho
 * @author_3  Marcos Samuel Santos Ouriques  
 * Date:      09/01/2012 (Month/Day/Year)
 * 
 * This file is also a part of the undergraduate final project, under the supervision 
 * of Andre Noll Barreto.
 */



#ifndef _Statistics_h_
#define _Statistics_h_

#include <itpp/itbase.h>
#include <queue>

using namespace itpp;
using namespace std;

/**
 * Namespace. 
 * Detailed Description.
 */
namespace Basic
{

/**
 * Statistics Class. 
 * Detailed Description.
 */
class Statistics
{
   public:
           
      /**
       * Constructor.
       * Left empty.
       */
      Statistics();     
      
      /**
       * Destructor.
       * Left empty.
       */
      ~Statistics();
      
      /**
       * Method.
       * Detailed description.
       */
      double calculateOutage( priority_queue< double, 
                              vector<double>, 
                              greater<double> > queue
                               );
      
      /**
       * Method.
       * Detailed description.
       */
      double calculateMean( vec sequence );
      
      /**
       * Method.
       * Detailed description.
       */
      double calculateStandardDeviation( vec sequence );
      
      /**
       * Method.
       * Detailed description.
       */
      double calculateMeanEnergy( vec sequence );
         
      
   private:
       
        
};

};

#endif
