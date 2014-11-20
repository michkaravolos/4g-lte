/**
 * @file    Parameters.h
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

#ifndef _Parameters_h_
#define _Parameters_h_

#include "File.h"

#include <string>

using namespace std;

/**
 * Parameters Namespace. 
 * Detailed Description.
 */
namespace Parameters
{

/**
 * Parameters Class.
 * Detailed description.
 */
class Parameters
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Parameters();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Parameters();

      /**
       * Interface.
       * Detailed description.
       */   
      void interface();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void readFile();

             
   protected:
      
      /**
       * Member.
       * Left empty.
       */      
      string fileName_; 
   
   
   private:
   

};

};

#endif

