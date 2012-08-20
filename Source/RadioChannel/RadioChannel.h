/**
 * @file    RadioChannel.h
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

#ifndef _RadioChannel_h_
#define _RadioChannel_h_

#include <itpp/itbase.h>

#include "PhysicalNode.h"
#include "LargeScaleFading.h"
#include "SmallScaleFading.h"
#include "SimulationEnvironment.h"

using namespace itpp;
using namespace std;

/**
 * RadioChannel Namespace. 
 * Detailed Description.
 */
namespace RadioChannel
{

/**
 * RadioChannel Class. 
 * Detailed Description.
 */
class RadioChannel
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~RadioChannel();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static RadioChannel* getInstance();
      
      /**
       * Defines numberUsers_, numberENodeBs_, shouldReadFile_, fileName_, frequencyStep_, timeStep_, numberTransmitAntennas_.
       * 
       */
      void setParameters();
      
      /**
       * Initializes the radio channel.
       * Defines largeScaleMatrix_, usersSmallScaleMatrixIndex_, 
       */
      void initialize();
      
      /**
       * Clears usersSmallScaleMatrixIndex_.
       * 
       */
      void clear();
      
      /**
       * Generates largeScaleMatrix_.
       * 
       */
      void generateLargeScaleFading();
      
      /**
       * Generates smallScaleFading_.
       * 
       */
      void generateSmallScaleFading();
      
      /**
       * Generates usersSmallScaleMatrixIndex_.
       * 
       */
      void generateSmallScaleFadingIndexes();
      
      /**
       * Returns the large scale fading between user and eNodeB.
       */
      double getLargeScaleFading( PhysicalNode::PhysicalNode* user,
                                  PhysicalNode::PhysicalNode* eNodeB );
      
     /**
       * Returns the large scale fading between user and eNodeB in dB.
       * 
       */
      double getLargeScaleFading_dB( PhysicalNode::PhysicalNode* user,
                                     PhysicalNode::PhysicalNode* eNodeB );
      
     /**
       * Returns the large scale fading between user and eNodeB.
       * 
       */
      double getLargeScaleFading( int userId,
                                  int eNodeBId );
      
      /**
       * Returns the large scale fading between user and eNodeB in dB.
       * 
       */
      double getLargeScaleFading_dB( int userId,
                                     int eNodeBId);
      
      /**
       * Returns the fading on the specific moment on the specific frequency.
       */
      double getFading( PhysicalNode::PhysicalNode* user,
                        PhysicalNode::PhysicalNode* eNodeB,
                        double time,
                        double frequency,
                        int antenna );
      
      /**
       * Returns the fading on the specific moment on the specific frequency.
       *
       */
      double getFading( int userId,
                        int eNodeBId,
                        double time,
                        double frequency,
                        int antenna );
      
      /**
       * Returns the timestep.
       * 
       */
      double getTimeStep();
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      RadioChannel();
      
      /**
       * Member.
       * Left empty.
       */      
      static RadioChannel* instance_;
      
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
      int numberTransmitAntennas_;
      
      /**
       * Member.
       * Left empty.
       */      
      bool shouldReadFile_;
      
      /**
       * Member.
       * Left empty.
       */      
      char* fileName_;
      
      /**
       * Member.
       * Left empty.
       */      
      double timeStep_;
      
      /**
       * Member.
       * Left empty.
       */      
      double frequencyStep_;
      
      /**
       * Member.
       * Left empty.
       */   
      LargeScaleFading largeScaleFading_;
      
      /**
       * Member.
       * Left empty.
       */   
      SmallScaleFading smallScaleFading_;
      
      /**
       * Member.
       * Left empty.
       */      
      mat largeScaleMatrix_;
      
      /**
       * Member.
       * Left empty.
       */      
      Array<vec> smallScaleArray_;
      
      /**
       * Member.
       * Left empty.
       */      
      int*** usersSmallScaleMatrixIndex_;
      
      /**
       * Member.
       * Left empty.
       */      
      SimulationEnvironment::SimulationEnvironment* simulationEnvironment_;
      
      
      
      
};

};

inline
double
RadioChannel::
RadioChannel::getTimeStep()
{
   return timeStep_;
};

// -----------------------------------------------------------------------------

#endif

