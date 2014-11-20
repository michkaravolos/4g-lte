/**
 * @file    Results.h
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

#ifndef _Results_h_
#define _Results_h_

#include <itpp/itbase.h>

#include <string>
#include <queue>

using namespace itpp;
using namespace std;

namespace Results
{

/**
 * Results Class. 
 * Detailed Description.
 */
class Results
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Results();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static Results* getInstance();

      /**
       * Defines numberSimulations_, numberDrops_, MCSHistogramPerDrop_, MCSPercentage_, CQIReportDelay_, dropResultsFile_, simulationResultsFile_, initialUsers_, finalUsers_, userStep_.
       * 
       */
      void setParameters();
      
      /**
       * 
       * 
       */
      void clear();
      
      /**
       * Initializes the vectors of SINR.
       */
      void initialize();
      
      /**
       * Initializes variables of DROPS
       */
      void initializeDrop();
      
       /**
       * Initializes the variables of Simulation.
       */
      void initializeSimulation();
      
      /**
       * Add ID for each user.
       */
      void addUserId( int userId );
      
      /**
       * Returns the number of users.
       */
      int getNumberUsers();
      
      /**
       * Returns the id of the user.
       */
      int getUserId( int index );
      
      /**
       * Finishes Drops.
       */
      void finalizeDrop();
      
      /**
       * Finishes the simulation.
       */
      void finalizeSimulation();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getAverageUserRawRate();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getAverageUserEffectiveRate();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getAverageSINR();
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getAverageSINR_dB();
      
      /**
       * Saves MCS used by each transmission.
       */
      void storeMCS( int MCS );
      
      /**
       * Returns the MCS for a defined transmission.
       */
      int getMCSHistogram( int MCS );
      
      /**
       * Interface.
       * Detailed description. 
       */
      double getMCSPercentage( int MCS );
      
    /**
       * Displays Results.
       */
      void displayResults();
      
      /**
       * Saves the results of DROPs in DropSimulationResults.dat
       */
      void saveDropResults();
      
      /**
       * Saves the data of the simulation in SimulationResults.dat
       */
      void saveSimulationResults();
      
      /**
       * Increases the success per DROP variable.
       */
      void storeSuccess();
      
      /**
       * Increases the failure per DROP variable.
       */
      void storeFailure();
      
      /**
       * Returns percentage of success.
       */
      double getPercentageSuccess();
      
      /**
       * Returns percentage of failure.
       * 
       */
      double getPercentageFailure();
      
      /**
       * Saves the histogram of SINR.
       * 
       */
      void storeSINR( const double sinr );
      
      /**
       * Saves the histogram of distance.
       */
      void storeDistance( const double distance );
      
      /**
       * Saves the SINR related with relation to frequency.
       */
      void storeSINR( const double sinr,
                      const double frequency );
      
     /**
       * Saves the probability functions with relation to SINR.
       */
      void saveSINRCDF();
      
      /**
       * Performs calculations of average, variance and standard deviation of probability functions in relation to SINR
       * 
       */
      void saveDistanceCDF();
        /**
       * Interface.
       * Detailed description.
       */
      void generateCDFEffectiveUserRate();
       /**
       * Interface.
       * Detailed description.
       */
       void creategraph();
         
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Results();
      
      /**
       * Member.
       * Left empty.
       */      
      static Results* instance_;
      
      /**
       * Member.
       * Left empty.
       */      
      char* dropResultsFile_;
      
      /**
       * Member.
       * Left empty.
       */      
      char* simulationResultsFile_;
      
      /**
       * Member.
       * Left empty.
       */      
      ivec userIds_;
      
      /**
       * Member.
       * Left empty.
       */      
      ivec eNodeBIds_;
      
      /**
       * Member.
       * Left empty.
       */      
      int totalRawBitsPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double totalEffectiveBitsPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      int eNodeBRawBitsPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double eNodeBEffectiveBitsPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double eNodeBRawRate_;
      
      /**
       * Member.
       * Left empty.
       */      
      double eNodeBEffectiveRate_;
      
      /**
       * Member.
       * Left empty.
       */      
      double simlationRawRate_;
      
      /**
       * Member.
       * Left empty.
       */      
      double simlationEffectiveRate_;
      
      /**
       * Member.
       * Left empty.
       */      
      double updateTime_;
      
      /**
       * Member.
       * Left empty.
       */      
      double averageSINR_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberSINR_;
      
      /**
       * Member.
       * Left empty.
       */      
      ivec MCSHistogramPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      vec MCSPercentage_;
      
      /**
       * Member.
       * Left empty.
       */      
      int totalMCSsPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      int MCSNotUsedPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double percentageMCSNotUsed_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberSimulations_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberDrops_;
      
      /**
       * Member.
       * Left empty.
       */      
      int simulationIndex_;
      
      /**
       * Member.
       * Left empty.
       */      
      int dropIndex_;
      
      /**
       * Member.
       * Left empty.
       */      
      unsigned int successPerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double percentageSuccess_;
      
      /**
       * Member.
       * Left empty.
       */      
      unsigned int failurePerDrop_;
      
      /**
       * Member.
       * Left empty.
       */      
      double percentageFailure_;
      
      /**
       * Member.
       * Left empty.
       */      
      int CQIReportDelay_;
      
      /**
       * Member..
       * Detailed description. 
       */
      ivec sinrHistogram_;
      
      /**
       * Member..
       * Detailed description. 
       */
      ivec distanceHistogram_;
      
      /**
       * Member..
       * Detailed description. 
       */
      double oldTime_;
      
      /**
       * Member..
       * Detailed description. 
       */
      int initialUsers_;
      
      /**
       * Member..
       * Detailed description. 
       */
      int finalUsers_;
      
      /**
       * Member..
       * Detailed description. 
       */
      int userStep_;
      
      /**
       * Member..
       * Detailed description. 
       */
      int numberUsers_;
     
      /**
       * Member..
       * Detailed description. 
       */
      int Direction_;
       /**
     * Member..
     * Detailed description.
     * Modified by Luiz Gustavo Carvalho and Marcos Samuel Ouriques
     */
    vec  cdfEffectiveUserRateX_;
    /**
     * Member..
     * Detailed description.
     * Modified by Luiz Gustavo Carvalho and Marcos Samuel Ouriques
     */
    vec  cdfEffectiveUserRateY_;

   
};

};

inline
void
Results::
Results::addUserId( int userId )
{
   int s = userIds_.size();
   userIds_.set_size( s + 1, true );
   userIds_( s ) = userId;
}

//------------------------------------------------------------------------------

inline
int
Results::
Results::getNumberUsers()
{
   return userIds_.size();
}

//------------------------------------------------------------------------------

inline
int
Results::
Results::getUserId( int index )
{
   int i = -1;
   if( index < userIds_.size() )
   {
      i = userIds_( index );
   }
   else
   {
      it_error("Results: index out of range");
   }
   return i;
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getAverageUserRawRate()
{
   
   //cout << "R: "<< TotalRawBits_ << endl;
   return static_cast<double>( totalRawBitsPerDrop_ ) 
      / static_cast<double>( userIds_.size() ) 
      / updateTime_;
      
      
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getAverageUserEffectiveRate()
{
   //cout << "E: "<< TotalEffectiveBits_ << endl;
   return static_cast<double>( totalEffectiveBitsPerDrop_ ) 
      / static_cast<double>( userIds_.size() )
      / updateTime_;
      
      
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getAverageSINR()
{
   //cout <<"qwe"<<averageSINR_ / 40 << endl;
   //cout << "number: "<< numberSINR_;
   return averageSINR_ / numberSINR_;
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getAverageSINR_dB()
{
   
   return 10 * log10( getAverageSINR() );
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getMCSPercentage( int MCS )
{ 
   return 100 * static_cast<double> ( getMCSHistogram( MCS ) ) / 
      static_cast<double>( totalMCSsPerDrop_ );
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getPercentageSuccess()
{ 
   return 100.0 * static_cast<double>( successPerDrop_ )
          / static_cast<double>( successPerDrop_ + failurePerDrop_ );
}

//------------------------------------------------------------------------------

inline
double
Results::
Results::getPercentageFailure()
{ 
   return 100.0 - getPercentageSuccess();
}

//------------------------------------------------------------------------------



#endif
