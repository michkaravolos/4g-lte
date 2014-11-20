/**
 * @file    PhysicalLayerParameters.h
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

#ifndef _PhysicalLayerParameters_h_
#define _PhysicalLayerParameters_h_

#include <itpp/itbase.h>

#include "Parameters.h"

using namespace itpp;
using namespace std;

namespace Parameters
{

/**
 * PhysicalLayerParameters Class. 
 * Detailed Description.
 */
class PhysicalLayerParameters : public Parameters
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~PhysicalLayerParameters();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static PhysicalLayerParameters* getInstance();

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
       * Member
       * Detailed description
       */
      int numberREPerSC;
      
      /**
       * Member
       * Detailed description
       */
      int numberSCPerPRB;
      
      /**
       * Member
       * Detailed description
       */
      double slotTimeLength;
      
      /**
       * Member
       * Detailed description
       */
      int numberSlotsPerRSubframe;
      
      /**
       * Member
       * Detailed description
       */
      int numberSubframesPerFrame;
     
         /**
       * Member.
       * Left empty.
       */   
      int SoundingSlots;
   
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      PhysicalLayerParameters();
      
      /**
       * Member.
       * Left empty.
       */      
      static PhysicalLayerParameters* instance_; 
      
      
      
};

};

#endif
