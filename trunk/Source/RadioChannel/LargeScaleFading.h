/**
 * @file    LargeScaleFading.h
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

#ifndef _LargeScaleFading_h_
#define _LargeScaleFading_h_

#include "Fading.h"

using namespace std;
using namespace itpp;

namespace RadioChannel
{

/**
 * LargeScaleFading Class.
 * Detailed description.
 */
class LargeScaleFading : public Fading
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      LargeScaleFading();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~LargeScaleFading();
      
      /**
       * Calculates the fading in dB.
       */   
      double generateFading_dB( double distance );
      
      /**
       * Calculates the Path Loss in dB.
       */   
      double generatePathLoss_dB( double distance );
      
      /**
       * Calculates the Shadowing in dB.
       */   
      double generateShadowing_dB();
      
      /**
       * Calculates the fading.
       */   
      double generateFading( double distance );
      
      /**
       * Calculates the Path Loss.
       */   
      double generatePathLoss( double distance );
      
      /**
       * Calculates the Shadowing.
       */   
      double generateShadowing();
      
      /**
       * Defines mean_, sd_.
       */
      void setParameters();
      
      /**
       * Initializes Normal_RNG n, LargeScaleFading.
       * 
       */
      void initialize();

             
   protected:
      
      /**
       * Mean.
       * 
       */      
      double mean_;
      
      /**
       * Member.
       * Left empty.
       */      
      double sd_;
      
      /**
       * Member.
       * Left empty.
       */ 
      Normal_RNG n;
   
   
   private:
   

};

};

#endif

