/**
 * @file    RadioChannel.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa o canal de rádio
       * 
       */
      void initialize();
      
      /**
       * Limpa a matriz de índices do fading de pequena escala
       * 
       */
      void clear();
      
      /**
       * Gera o fading de larga escala
       * 
       */
      void generateLargeScaleFading();
      
      /**
       * Gera o fading de pequena escala
       * 
       */
      void generateSmallScaleFading();
      
      /**
       * Gera os índices do fading de pequena escala
       * 
       */
      void generateSmallScaleFadingIndexes();
      
      /**
       * Retorna o fading de larga escala entre o usuário e a EnodeB
       * 
       */
      double getLargeScaleFading( PhysicalNode::PhysicalNode* user,
                                  PhysicalNode::PhysicalNode* eNodeB );
      
     /**
       * Retorna o fading de larga escala entre o usuário e a EnodeB em dB
       * 
       */
      double getLargeScaleFading_dB( PhysicalNode::PhysicalNode* user,
                                     PhysicalNode::PhysicalNode* eNodeB );
      
     /**
       * Retorna o fading de larga escala entre o usuário e a EnodeB
       * 
       */
      double getLargeScaleFading( int userId,
                                  int eNodeBId );
      
      /**
       * Retorna o fading de larga escala entre o usuário e a EnodeB em dB
       * 
       */
      double getLargeScaleFading_dB( int userId,
                                     int eNodeBId);
      
      /**
       *Retorna o fading naquele instante naquela frequência
       *
       */
      double getFading( PhysicalNode::PhysicalNode* user,
                        PhysicalNode::PhysicalNode* eNodeB,
                        double time,
                        double frequency,
                        int antenna );
      
      /**
       *Retorna o fading naquele instante naquela frequência
       *
       */
      double getFading( int userId,
                        int eNodeBId,
                        double time,
                        double frequency,
                        int antenna );
      
      /**
       * Retorna o timestep
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

