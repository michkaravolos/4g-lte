/**
 * @file    SmallScaleFading.h
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
       * Defines numberUsers_, numberENodeBs_, simulationTime_, bandWidth_, bandWidthSubcarrier_, carrierFrequency_, numberAntennas_, 
       userSpeed_, channelProfile_, totalTime_.
       * 
       */
      void setParameters();
      
      /**
       * Initializes maximumDopplerShift_, totalTime_, timeStep_, frequencyStep_, channel_, fading_.
       * 
       */
      void initialize();
      
      /**
       * Creates the channel.
       *  
       */
      void createChannel();
      
      /**
       * Generates Fading.
       * 
       */
      void generateFading( Array<vec>& fading );
      
      /**
       * Returns timestep.
       * 
       */
      double getTimeStep();
      
      /**
       * Returns frequencystep.
       * 
       */
      double getFrequencyStep(); 
      
      /**
       * Saves the Small Scaling Fading.
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

