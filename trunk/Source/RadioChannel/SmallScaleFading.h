/**
 * @file    SmallScaleFading.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _SmallScaleFading_h_
#define _SmallScaleFading_h_

#include "Fading.h"
#include <itpp/comm/channel.h>

using namespace std;
using namespace itpp;

namespace RadioChannel
{

/**
 * SmallScaleFading Class.
 * Detailed description.
 */
class SmallScaleFading : public Fading
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      SmallScaleFading();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~SmallScaleFading();
      
      /**
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa os parâmetros
       * 
       */
      void initialize();
      
      /**
       * Cria o canal
       *  
       */
      void createChannel();
      
      /**
       * Gera o fading
       * 
       */
      void generateFading( Array<vec>& fading );
      
      /**
       * Retorna o timestep
       * 
       */
      double getTimeStep();
      
      /**
       * Retorna o frequencystep
       * 
       */
      double getFrequencyStep(); 
      
      /**
       * Salva a matriz de fading de pequena escala
       * 
       */
      void saveFadingArray(); 
      
      

             
   protected:
      
      /**
       * Member.
       * Left empty.
       */      
      Array<cvec> channel_;
      
      /**
       * Member.
       * Left empty.
       */      
      Array<vec> fading_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberUsers_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs_;
      
      /**
       * Member.
       * Left empty.
       */      
      double totalTime_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberFrequencies_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberAntennas_;
      
      /**
       * Member.
       * User speed.
       */
      CHANNEL_PROFILE channelProfile_;
      
      /**
       * Member.
       * System Bandwidth.
       */
      double bandWidth_;
      
      /**
       * Member.
       * User speed.
       */
      double userSpeed_;
      
      /**
       * Member.
       * Carrier frequency;.
       */
      double carrierFrequency_;
         
      /**
       * Member.
       * Maximum Doppler Shift. 3 km/h. Carrier frequency = 2 GHz..
       */
      double maximumDopplerShift_;
      
      /**
       * Member.
       * Simulation time, in seconds..
       */
      double simulationTime_; 
      
      /**
       * Member.
       * Subcarrier bandwidth.
       */
      double bandWidthSubcarrier_;
      
      /**
       * Member.
       * Subcarrier bandwidth.
       */
      double timeStep_;
      
      /**
       * Member.
       * Subcarrier bandwidth.
       */
      double frequencyStep_;
   
   
   private:
   

};

};

#endif

