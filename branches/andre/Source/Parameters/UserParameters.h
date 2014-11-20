/**
 * @file    UserParameters.h
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

#ifndef _UserParameters_h_
#define _UserParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * UserParameters Class. 
 * Detailed Description.
 */
class UserParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~UserParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static UserParameters* getInstance();

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
      double noiseFigure;
      
            
      /**
       * Member.
       * Left empty.
       */      
      int CQIUpdatePeriod;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberCQIBits;
      
      /**
       * Member.
       * Left empty.
       */      
      double maxSINRConsidered;
      
       /**
       * Member.
       * Left empty.
       */      
      double minSINRConsidered;
      
      /**
       * Member.
       * Left empty.
       */      
      double CQISD;
      
      /**
       * Member.
       * Left empty.
       */      
      int CQIReportDelay;
      
      
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      UserParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static UserParameters* instance_; 
      
      
};

};

#endif
