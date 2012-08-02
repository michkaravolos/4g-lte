/**
 * @file    LargeScaleFading.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Calcula o fading em dB
       * 
       */   
      double generateFading_dB( double distance );
      
      /**
       * Calcula a perda de caminho em dB
       * 
       */   
      double generatePathLoss_dB( double distance );
      
      /**
       * Calcula o sombreamento em dB
       * 
       */   
      double generateShadowing_dB();
      
      /**
       * Calcula o fading
       * 
       */   
      double generateFading( double distance );
      
      /**
       * Calcula a perda de caminho
       * 
       */   
      double generatePathLoss( double distance );
      
      /**
       * Calcula o sombreamento
       * 
       */   
      double generateShadowing();
      
      /**
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa LargeScaleFading
       * 
       */
      void initialize();

             
   protected:
      
      /**
       * Média
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

