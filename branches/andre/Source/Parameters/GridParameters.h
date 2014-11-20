/**
 * @file    GridParameters.h
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

#ifndef _GridParameters_h_
#define _GridParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * GridParameters Class. 
 * Detailed Description.
 */
class GridParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~GridParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static GridParameters* getInstance();

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
       * Member.
       * Left empty.
       */      
      double interSiteDistance;  
      
      /**
       * Member.
       * Left empty.
       */      
      double minimumDistance;  
     
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      GridParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static GridParameters* instance_;   
      
      
      
};

};

#endif
