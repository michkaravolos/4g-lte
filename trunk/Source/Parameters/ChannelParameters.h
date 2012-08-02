/**
 * @file    ChannelParameters.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _ChannelParameters_h_
#define _ChannelParameters_h_

#include <itpp/itbase.h>
#include <itpp/comm/channel.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * ChannelParameters Class. 
 * Detailed Description.
 */
class ChannelParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~ChannelParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static ChannelParameters* getInstance();

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
      double shadowingMean;
      
      /**
       * Member.
       * Left empty.
       */      
      double shadowingSD;
      
      /**
       * Member.
       * User speed.
       */
      double userSpeed;
      
      /**
       * Member.
       * User speed.
       */
      CHANNEL_PROFILE profile;
      
      /**
       * Member.
       * User speed.
       */
      int channelTime;
      
      /**
       * Member.
       * User speed.
       */
      double timeStep;
      
      /**
       * Member.
       * User speed.
       */
      double frequencyStep;
      
      /**
       * Member.
       * Left empty.
       */
      bool shouldReadFile;
      
      /**
       * Member.
       * Left empty.
       */
      char* ChannelFileName;
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      ChannelParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static ChannelParameters* instance_;
      
      
};

};

#endif
