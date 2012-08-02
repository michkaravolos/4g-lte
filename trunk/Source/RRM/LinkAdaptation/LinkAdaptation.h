/**
 * @file    LinkAdaptation.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _LinkAdaptation_h_
#define _LinkAdaptation_h_

#include <itpp/itbase.h>

#include "User.h"
#include "PhysicalResourceBlock.h"

using namespace itpp;
using namespace std;

/**
 * LinkAdaptation Namespace. 
 * Detailed Description.
 */
namespace LinkAdaptation
{

enum MCS_e
{
   MCS1,
   MCS2,
   MCS3,
   MCS4,
   MCS5,
   MCS6,
   MCS7,
   MCS8,
   MCS9  
};
   
/**
 * LinkAdaptation Class. 
 * Detailed Description.
 */
class LinkAdaptation
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~LinkAdaptation();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static LinkAdaptation* getInstance();

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
      double mapSINRs( const vec& sinrs, 
                       const int MCS );
      
      /**
       * Interface.
       * Detailed description. 
       */
      void chooseMCS( vec sinrs,
                      double& sinr,
                      int& MCS,
                      int& rawBits,
                      double& effectiveBits );

      /**
       * Interface.
       * Detailed description. 
       */
      double getBER( const double sinr,
                     const int MCS );
      
      /**
       * Interface.
       * Detailed description. 
       */
      bool isBERvalid( const double BER );
      
      /**
       * Interface.
       * Detailed description. 
       */
      void setBits( const int MCS,
                    int& rawBits,
                    double& effectiveBits );
      
      /**
       * Interface.
       * Detailed description. 
       */
      bool checkMCS( vec sinrs,
                     int MCS );

      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      LinkAdaptation();
      
      /**
       * Member.
       * Left empty.
       */      
      static LinkAdaptation* instance_;  
      
      /**
       * Member.
       * Left empty.
       */      
      vec betas_;  
      
      /**
       * Member.
       * Left empty.
       */      
      vec MCSThresholds_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberMCSs_;  
      
      /**
       * Member.
       * Left empty.
       */      
      double BERt_;  
      
      /**
       * Member.
       * Left empty.
       */      
      double codingRate_; 

      
};

};

#endif
