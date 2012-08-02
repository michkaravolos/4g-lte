/**
 * @file    Mobility.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Mobility_h_
#define _Mobility_h_

#include <itpp/itbase.h>

#include "Position.h"
#include "Grid.h"

using namespace itpp;
using namespace std;

/**
 * Mobility Namespace. 
 * Detailed Description.
 */
namespace Mobility
{

/**
 * Mobility Class. 
 * Detailed Description.
 */
class Mobility
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Mobility();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static Mobility* getInstance();

      /**
       * Interface.
       * Detailed description. 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void initialize();
      
      /**
       * Interface.
       * Detailed description.
       */
      void clear();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void generatePosition( Basic::Position& p,
                             int& site, 
                             int& sector );
      
      /**
       * Interface.
       * Detailed description. 
       */
      void generatePosition( Basic::Position& p,
                             int& index );
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Mobility();
      
      /**
       * Member.
       * Left empty.
       */      
      static Mobility* instance_;        
      
      /**
       * Member.
       * Left empty.
       */      
      Grid::Grid* grid_;
};

};

#endif
