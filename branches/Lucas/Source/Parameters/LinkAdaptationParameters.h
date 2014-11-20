/**
 * @file    LinkAdaptationParameters.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    05/09/2008
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

#ifndef _LinkAdaptationParameters_h_
#define _LinkAdaptationParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * LinkAdaptationParameters Class. 
 * Detailed Description.
 */
class LinkAdaptationParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~LinkAdaptationParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static LinkAdaptationParameters* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void readFile();
      
      /**
       * Member
       * Detailed description
       */
      double beta0;
      
      /**
       * Member
       * Detailed description
       */
      double beta1;
      
      /**
       * Member
       * Detailed description
       */
      double beta2;
      
      /**
       * Member
       * Detailed description
       */
      double MCSThreshold0;
      
      /**
       * Member
       * Detailed description
       */
      double MCSThreshold1;
      
      /**
       * Member
       * Detailed description
       */
      double MCSThreshold2;
      
      /**
       * Member
       * Detailed description
       */
      double BERt;
      
      /**
       * Member
       * Detailed description
       */
      double codingRate;
      
      /**
       * Member
       * Detailed description
       */
      int numberMCSs;

      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      LinkAdaptationParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static LinkAdaptationParameters* instance_; 
      
};

};

#endif
