/**
 * @file    TimeManager.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _TimeManager_h_
#define _TimeManager_h_

#include <itpp/itbase.h>

using namespace itpp;
using namespace std;

/**
 * TimeManager Namespace. 
 * Detailed Description.
 */
namespace TimeManager
{

/**
 * TimeManager Class. 
 * Detailed Description.
 */
class TimeManager
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      virtual ~TimeManager();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static TimeManager* getInstance();

      /**
       * Define os Parâmetros
       *  
       */
      void setParameters();
      
      /**
       * Inicializa o TimeManager
       * 
       */
      void initialize();
      
      /**
       * Interface.
       *  
       */
      void clear();
      
      /**
       * Retorna o pacote atual
       * 
       */
      int getCurrentStep();
      
       /**
       * Retorna a resolução corrente do pacote
       * 
       */
      int getCurrentResolutionStep();
      
      /**
       * Retorna o tempo atual
       * 
       */
      double getCurrentTime();
      
      /**
       * Retorna o tempo do pacote
       * 
       */
      double getTimeStep();
      
      /**
       * Interface.
       * Detailed description. 
       */
      void update();
      
      /**
       * Define a resolução do tempo
       * 
       */
      void setTimeResolution( const double timeStep );
      
      /**
       * Valida o tempo
       * 
       */
      bool validateTime();
      
      /**
       * Verifica se a resolução do tempo mudou
       * 
       */
      bool hasResolutionStepChanged();
     
       
      
   private:
       TimeManager();
      
      /**
       * Constructor.
       * Left empty.
       */
     
      
      /**
       * Member.
       * Left empty.
       */      
      static TimeManager* instance_;          
      
      /**
       * Member.
       * Left empty.
       */      
      int currentStep_;   
      
      /**
       * Member.
       * Left empty.
       */      
      double currentTime_;   
      
      /**
       * Member.
       * Left empty.
       */      
      int currentResolutionStep_;
      
      /**
       * Member.
       * Left empty.
       */      
      int totalSteps_;   
      
      /**
       * Member.
       * Left empty.
       */      
      double totalTime_;   
      
      /**
       * Member.
       * Left empty.
       */      
      double timeStep_;   
      
      /**
       * Member.
       * Left empty.
       */      
      double timeResolution_; // time for channel change
      
      /**
       * Member.
       * Left empty.
       */      
      bool resolutionStepHasChanged_;   
};

};

inline
double
TimeManager::
TimeManager::getTimeStep()
{
   return timeStep_;
};

// -----------------------------------------------------------------------------

inline
double
TimeManager::
TimeManager::getCurrentTime()
{
   return currentTime_;
};

// -----------------------------------------------------------------------------

inline
int
TimeManager::
TimeManager::getCurrentStep()
{
   return currentStep_;
};

// -----------------------------------------------------------------------------

inline
bool
TimeManager::
TimeManager::validateTime()
{
   return currentStep_ < totalSteps_;
};

// -----------------------------------------------------------------------------

inline
void
TimeManager::
TimeManager::setTimeResolution( const double timeResolution )
{
   timeResolution_ = timeResolution;
};

// -----------------------------------------------------------------------------

inline
int
TimeManager::
TimeManager::getCurrentResolutionStep()
{
   return currentResolutionStep_;
};

// -----------------------------------------------------------------------------

inline
bool
TimeManager::
TimeManager::hasResolutionStepChanged()
{
   return resolutionStepHasChanged_;
};

// -----------------------------------------------------------------------------


#endif
