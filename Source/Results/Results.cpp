/**
 * @file    Results.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */

// *****************************************************************************
// Includes
// *****************************************************************************

#include <iostream>

#include "Results.h"

#include "User.h"
#include "SimulationEnvironment.h"
#include "TimeManager.h"
#include "SimulationParameters.h"
#include "LinkAdaptationParameters.h"
#include "UserParameters.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

Results::Results* 
   Results::Results::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************
/**
       * Inicia os parametros
       * 
       */
Results::
Results::Results()
{
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------
/**
       * Destructor
       * 
       */
Results::
Results::~Results()
{
}

// *****************************************************************************
// Interfaces
// *****************************************************************************
/**
       * Chama o constructor
       * 
       */
Results::Results* 
Results::
Results::getInstance()
{
   if ( !instance_)
   {
      instance_ = new Results();
   }
   return instance_;
}

//------------------------------------------------------------------------------
/**
       * Inicializa os parametros
       * 
       */
void
Results::
Results::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   Parameters::LinkAdaptationParameters* la = 
      Parameters::LinkAdaptationParameters::getInstance();
   Parameters::UserParameters* up = 
      Parameters::UserParameters::getInstance();
   
   numberSimulations_ = static_cast<int>( ( sp->finalUsers - sp->initialUsers ) 
      / sp->userStep ) + 1;
   numberDrops_ = sp->DropsPerSimulation;
   MCSHistogramPerDrop_.set_size( la->numberMCSs );
   MCSPercentage_.set_size( la->numberMCSs );
   CQIReportDelay_ = up->CQIReportDelay;
   dropResultsFile_ = "../Results/DropResults.dat";
   simulationResultsFile_ = "../Results/SimulationResults.dat";
   
   initialUsers_ = sp->initialUsers;
   finalUsers_ = sp->finalUsers;
   userStep_ = sp->userStep;
   
   
   
   oldTime_ = 0.0;
}

//------------------------------------------------------------------------------
/**
       * Inicializa os vetores de SINR
       * 
       */
void
Results::
Results::initialize()
{
   numberUsers_ = initialUsers_;
   simulationIndex_ = 0;
   dropIndex_ = 0;
   sinrHistogram_.set_size( 10000 );
   sinrHistogram_.zeros();
   distanceHistogram_.set_size( 10000 );
   distanceHistogram_.zeros();
   tic();
   ofstream file;
   file.open( dropResultsFile_ ); 
   file.close();
   file.open( simulationResultsFile_ ); 
   file.close(); 
   file.open( "../Results/SINR3d.dat" ); 
   file.close();
   file.open( "../Results/SimulationValues.dat" ); 
   file.close(); 
   file.open("../Results/TransmissionRate.dat");
   file.close();
    Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
       Direction_=sp->Direction;
}

//------------------------------------------------------------------------------
/**
       * Inicializa variáveis dos DROPS
       * 
       */
void
Results::
Results::initializeDrop()
{
   userIds_.set_size( 0 );
   totalRawBitsPerDrop_ = 0;
   totalEffectiveBitsPerDrop_ = 0.0;
   averageSINR_ = 0.0;
   numberSINR_ = 0;  
   
   MCSHistogramPerDrop_.zeros();
   totalMCSsPerDrop_ = 0;
   MCSNotUsedPerDrop_ = 0;
   successPerDrop_ = 0;
   failurePerDrop_ = 0;
   eNodeBIds_.set_size( 3 );
   eNodeBIds_( 0 ) = 0;
   eNodeBIds_( 1 ) = 1;
   eNodeBIds_( 2 ) = 2;
   
   eNodeBRawBitsPerDrop_ = 0;
   eNodeBEffectiveBitsPerDrop_ = 0.0;
   
   
}

//------------------------------------------------------------------------------
/**
       * Inicializa as variáveis da Simulacao
       * 
       */
void
Results::
Results::initializeSimulation()
{
   simlationRawRate_ = 0.0;
   simlationEffectiveRate_ = 0.0;
   
   MCSPercentage_.zeros();
   percentageMCSNotUsed_ = 0.0;
   percentageSuccess_ = 0.0;
   percentageFailure_ = 0.0;
   
   eNodeBRawRate_ = 0.0;
   eNodeBEffectiveRate_ = 0.0;
   cdfEffectiveUserRateX_.set_size(numberUsers_);
   cdfEffectiveUserRateX_.zeros();
   cdfEffectiveUserRateY_.set_size(numberUsers_);
   cdfEffectiveUserRateY_.zeros();
}

//------------------------------------------------------------------------------

void
Results::
Results::clear()
{
   
}

//------------------------------------------------------------------------------
/**
       * Finaliza os Drops
       * 
       */
void
Results::
Results::finalizeDrop()
{
   PhysicalNode::User* u;
   PhysicalNode::ENodeB* e;
   SimulationEnvironment::SimulationEnvironment* se =
      SimulationEnvironment::SimulationEnvironment::getInstance();
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   int s = userIds_.size();
   int us=0;
   for( int i = 0; i < s; ++i )
   {
      u = se->getUser( userIds_( i ) );
      totalRawBitsPerDrop_ += u->getRawBits();
      totalEffectiveBitsPerDrop_ += u->getEffectiveBits();
      if(u->getEffectiveBits()>1){
	if(u->getEffectiveBits()/(updateTime_) > 10000000){cdfEffectiveUserRateX_(us)=10000000;}
      if(u->getEffectiveBits()/(updateTime_) <= 10000000){cdfEffectiveUserRateX_(us) = u->getEffectiveBits()/(updateTime_);}
      //cout<<u->getEffectiveBits()<<" "<<updateTime_<<endl;
	us++;
                                 }
      
   }
   
   s = eNodeBIds_.size();
   
   for( int i = 0; i < s; ++i )
   {
      e = se->getENodeB( eNodeBIds_( i ) );
      eNodeBRawBitsPerDrop_ += e->getRawBits();
      eNodeBEffectiveBitsPerDrop_ += e->getEffectiveBits();
   }
   updateTime_ = tm->getCurrentTime() - CQIReportDelay_ * tm->getTimeStep();
   
   saveDropResults();
   
   simlationRawRate_ += getAverageUserRawRate();
   simlationEffectiveRate_ += getAverageUserEffectiveRate();
   eNodeBRawRate_ += static_cast< double >( 
      eNodeBRawBitsPerDrop_ ) / updateTime_ / eNodeBIds_.size();
   eNodeBEffectiveRate_ += static_cast< double >( 
      eNodeBEffectiveBitsPerDrop_ ) / updateTime_ / eNodeBIds_.size();
   
   for( int i = 0; i < MCSHistogramPerDrop_.size(); ++i )
   {
      MCSPercentage_( i ) += getMCSPercentage( i );
   }
   percentageMCSNotUsed_ += getMCSPercentage( -1 );
   percentageSuccess_ += getPercentageSuccess();
   percentageFailure_ += getPercentageFailure();
   
   dropIndex_++;
}

//------------------------------------------------------------------------------
/**
       * Salva os resultados dos DROPS no arquivo DropSimulationResults.dat
       * 
       */
void
Results::
Results::saveDropResults()
{
   ofstream file;
   file.open( dropResultsFile_, ios::out | ios::app );
   if(Direction_==0){file << "Downlink" << endl;}
   if(Direction_==1){file << "Uplink" << endl;}
   
   file << "Simulation:" 
        << simulationIndex_ << endl;
   file << "   Drop: " 
        << dropIndex_ << endl;
   file << "      User average raw data rate: " 
        << getAverageUserRawRate() << endl; 
   file << "      User average effective data rate: " 
        << getAverageUserEffectiveRate() << endl; 
   
   file << "      eNode B average raw throughput: " 
        << static_cast< double >( eNodeBRawBitsPerDrop_ ) 
        / updateTime_ / eNodeBIds_.size() << endl; 
   file << "      eNode B average effective throughput: " 
        << static_cast< double >( eNodeBEffectiveBitsPerDrop_ ) 
        / updateTime_ / eNodeBIds_.size() << endl;
        
   for( int i = -1; i < MCSHistogramPerDrop_.size(); ++i )
   {
      file << "      Percentage of MCS " << i << " : " 
           << getMCSPercentage( i ) << endl; 
   }
   file << "      Percentage of successful transmissions: "
        << getPercentageSuccess() << endl;
   file << "      Percentage of failed transmissions: " 
        << getPercentageFailure() << endl;
   file.close();
}

//------------------------------------------------------------------------------
/**
       * Salva os dados da Simulacao no arquivo SimulationResults.dat
       * 
       */
void
Results::
Results::saveSimulationResults()
{
   ofstream file;
   file.open( simulationResultsFile_, ios::out | ios::app );
   if(Direction_==0){file << "Downlink" << endl;}
   if(Direction_==1){file << "Uplink" << endl;}
   file << "Simulation:" 
        << simulationIndex_ << endl;

   file << "   Number of users: " << numberUsers_ << endl;
   file << "   User average raw data rate: " 
        << simlationRawRate_ / numberDrops_ << endl; 
   file << "   User average effective data rate: " 
        << simlationEffectiveRate_ / numberDrops_ << endl;
   
      file << "   eNode B average raw throughput: " 
        << eNodeBRawRate_ / numberDrops_ << endl; 
   file << "   eNode B average effective throughput: " 
        << eNodeBEffectiveRate_ / numberDrops_ << endl;
   
   file << "   Percentage of MCS " << -1 << " : " 
        << percentageMCSNotUsed_ / numberDrops_ << endl; 
   for( int i = 0; i < MCSHistogramPerDrop_.size(); ++i )
   {
      file << "   Percentage of MCS " << i << " : " 
           << MCSPercentage_( i ) / numberDrops_ << endl; 
   }
   file << "   Percentage of successful transmissions: "
        << percentageSuccess_ / numberDrops_ << endl;
   file << "   Percentage of failed transmissions: " 
        << percentageFailure_ / numberDrops_ << endl;
   file.close();
   
   
   
   file.open( "../Results/SimulationValues.dat", ios::out | ios::app );
   
   file << numberUsers_ << "   "
        << simlationRawRate_ / numberDrops_ / 1e3 << "   "
        << simlationEffectiveRate_ / numberDrops_ / 1e3 << "   "
        << eNodeBRawRate_ / numberDrops_ / 1e3 << "   "
        << eNodeBEffectiveRate_ / numberDrops_ / 1e3 << "   "
        << percentageMCSNotUsed_ / numberDrops_ << "   ";
   for( int i = 0; i < MCSHistogramPerDrop_.size(); ++i )
   {
      file << MCSPercentage_( i ) / numberDrops_ << "   ";
   }
   
   file << percentageSuccess_ / numberDrops_ << "   ";
   file << percentageFailure_ / numberDrops_ << "   ";
   file << endl;
   file.close();
   
}

//------------------------------------------------------------------------------
/**
       * Finaliza a Simulacao
       * 
       */
void
Results::
Results::finalizeSimulation()
{
   dropIndex_ = 0;
   generateCDFEffectiveUserRate();
   creategraph();
   saveSimulationResults();
   numberUsers_ += userStep_;
   simulationIndex_++;
   
}

//------------------------------------------------------------------------------
/**
       * Salva o MCS usado para cada transmissao
       * 
       */
void
Results::
Results::storeMCS( int MCS )
{
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   if( tm->getCurrentStep() >= CQIReportDelay_ )
   {
      if( MCS == -1 )
      {
         MCSNotUsedPerDrop_++;
      }
      else
      {
         MCSHistogramPerDrop_( MCS ) += 1;        
      }
      totalMCSsPerDrop_++;
   }
   
}

//------------------------------------------------------------------------------
/**
       * Retorna o MCS utilizado para uma transmissao qualquer definida.
       * 
       */
int
Results::
Results::getMCSHistogram( int MCS )
{
   int mcs = 0;
   
   if( MCS < MCSHistogramPerDrop_.size() )
   {
      if( MCS == -1 )
      {
         mcs = MCSNotUsedPerDrop_;
      }
      else
      {
         mcs = MCSHistogramPerDrop_( MCS );
      }     
   }
   else
   {
      it_error( "Results: MCS index out of range." );
   }
   
   return mcs;
}

//------------------------------------------------------------------------------
/**
       * Mostra os resultados
       * 
       */
void
Results::
Results::displayResults()
{ 
   saveSINRCDF();
   saveDistanceCDF();
   
   ofstream file;
   file.open( simulationResultsFile_, ios::out | ios::app );
   file << "Total simulation time: " << toc() << endl;   
   file.close();  
}

//------------------------------------------------------------------------------
/**
       * Salva as funcoes de probabilidade com relacao a SINR
       * 
       */
void
Results::
Results::saveSINRCDF()
{ 
   ofstream file;
   unsigned int sum = 0;
   double mean = 0.0;
   double variance = 0.0;
   int cdf = 0;
   
   for( int i = 0; i < sinrHistogram_.size(); ++i )
   {
      sum += sinrHistogram_( i );

      mean += sinrHistogram_( i ) * ( 0.02 * i - 100 );
      variance += sinrHistogram_( i ) * 
         ( ( 0.02 * i - 100 ) * ( 0.02 * i - 100 ) );
   }
   
   mean /= static_cast< double >( sum );
   variance = variance / static_cast< double >( sum ) - mean * mean;
   
   
   file.open( "../Results/SINRCDF.dat" );
   for( int i = 0; i < sinrHistogram_.size(); ++i )
   {
      for( int j = 0; j <= i; ++j )
      {
         cdf += sinrHistogram_( j );
      }
      file << ( 0.02 * i - 100 ) << "   " 
      << 100.0 * static_cast< double >( cdf ) 
         / static_cast< double >( sum ) << endl;
      cdf = 0;
   }
   file.close();  
   
   file.open( "../Results/SINRCDFCentered.dat" );
   for( int i = 0; i < sinrHistogram_.size(); ++i )
   {
      for( int j = 0; j <= i; ++j )
      {
         cdf += sinrHistogram_( j );
      }
      file << ( 0.02 * i - 100 )  - mean << "   " 
      << 100.0 * static_cast< double >( cdf ) 
         / static_cast< double >( sum ) << endl;
      cdf = 0;
   }
   file.close();  
   
   file.open( "../Results/SINRStatistics.dat" );
   file << "Mean: " << mean << endl;
   file << "Variance: " << variance << endl;
   file << "Standard deviation: " << pow( variance, 0.5 ) << endl;
   file << "Number of samples: " << sum << endl;
   file.close();
}

//------------------------------------------------------------------------------
/**
       * Realiza calculos de media, variancia e desvio das funcoes de probabilidade em relacao a SINR
       * 
       */
void
Results::
Results::saveDistanceCDF()
{ 
   ofstream file;
   unsigned int sum = 0;
   double mean = 0.0;
   double variance = 0.0;
   int cdf = 0;
   
   for( int i = 0; i < distanceHistogram_.size(); ++i )
   {
      sum += distanceHistogram_( i );
      mean += distanceHistogram_( i ) * ( 0.025 * i );
      variance += distanceHistogram_( i ) * 
         ( ( 0.025 * i ) * ( 0.025 * i ) );
   }
   
   mean /= static_cast< double >( sum );
   variance = variance / static_cast< double >( sum ) - mean * mean;
   
   file.open( "../Results/DistanceCDF.dat" );
   for( int i = 0; i < distanceHistogram_.size(); ++i )
   {
      for( int j = 0; j <= i; ++j )
      {
         cdf += distanceHistogram_( j );
      }
      file << ( 0.025 * i ) << "   " 
      << 100.0 * static_cast< double >( cdf ) 
         / static_cast< double >( sum ) << endl;
      cdf = 0;
   }
   file.close();  
   
   file.open( "../Results/DistanceCDFCentered.dat" );
   for( int i = 0; i < distanceHistogram_.size(); ++i )
   {
      for( int j = 0; j <= i; ++j )
      {
         cdf += distanceHistogram_( j );
      }
      file << ( 0.025 * i )  - mean << "   " 
      << 100.0 * static_cast< double >( cdf ) 
         / static_cast< double >( sum ) << endl;
      cdf = 0;
   }
   file.close();  
   
   file.open( "../Results/DistanceStatistics.dat" );
   file << "Mean: " << mean << endl;
   file << "Variance: " << variance << endl;
   file << "Standard deviation: " << pow( variance, 0.5 ) << endl;
   file << "Number of samples: " << sum << endl;
   file.close();
}

//------------------------------------------------------------------------------
/**
       * Incrementa a variável de sucessos por DROP
       * 
       */
void
Results::
Results::storeSuccess()
{ 
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   if( tm->getCurrentStep() >= CQIReportDelay_ )
   {
      successPerDrop_++;
   }
}

//------------------------------------------------------------------------------
/**
       * Incrementa a variável de falhas por DROP
       * 
       */
void
Results::
Results::storeFailure()
{ 
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   if( tm->getCurrentStep() >= CQIReportDelay_ )
   {
      failurePerDrop_++;
   }
}

//------------------------------------------------------------------------------
/**
       * Salva a SINR com relacao a frequencia
       * 
       */
void
Results::
Results::storeSINR( const double sinr, const double frequency )
{  
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   double time = tm->getCurrentTime();
   
   ofstream file;
   file.open( "../Results/SINR3d.dat", ios::out | ios::app );
   if( time > oldTime_ + 0.000001 )
   {
      file << endl;
   }
   file << time << "   " << frequency / 1e6 << "   " << 10 * log10( sinr ) << endl;
    
   file.close();
   
   oldTime_ = time;
}

//------------------------------------------------------------------------------
/**
       * Salva o Histograma da SINR
       * 
       */
void
Results::
Results::storeSINR( const double sinr )
{ 
   double sir = 10 * log( sinr );
  
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   if( tm->getCurrentStep() >= CQIReportDelay_ )
   {
      if( sir > -100 && sir < 100 )
      {
         int s = static_cast< int >( 50 * sir + 5000 );
         if( s == 10000 )
         {
            s--;
         }
         sinrHistogram_( s ) += 1;
	 //cout<<sinrHistogram_(s)<<" "<<s<<"\n";
      }
   }
}

//------------------------------------------------------------------------------
/**
       * Salva o histograma de distancia
       * 
       */
void
Results::
Results::storeDistance( const double distance )
{ 
  
   TimeManager::TimeManager* tm =
      TimeManager::TimeManager::getInstance();
   
   if( tm->getCurrentStep() >= CQIReportDelay_ )
   {
      if( distance > 0 && distance < 250 )
      {
         int s = static_cast< int >( 40 * distance );
         if( s == 10000 )
         {
            s--;
         }
         distanceHistogram_( s ) += 1;
      }
   }
}

void
Results::
Results::generateCDFEffectiveUserRate()
{
	ofstream file;
	file.open("../Results/CDFEffectiveUserRate.dat");
	file<<"CDFEffectiveUserRate"<<endl<<endl;
	int s=cdfEffectiveUserRateX_.size();
	cdfEffectiveUserRateX_/=numberDrops_;
	sort(cdfEffectiveUserRateX_);
	
int k=0;
while(cdfEffectiveUserRateX_(k)==0)
{
	k++;
}

	int j = k;
	for(int i=k;i<s;i++)
	{

		while(cdfEffectiveUserRateX_(i)==cdfEffectiveUserRateX_(j))
		{
			cdfEffectiveUserRateY_(i)++;

			j++;
		}
		cdfEffectiveUserRateY_(i)=(cdfEffectiveUserRateY_(i))/(s-k);

		if(i>0)
		{
			cdfEffectiveUserRateY_(i)=cdfEffectiveUserRateY_(i-1) +cdfEffectiveUserRateY_(i);
		}


	}
	/*for(int i=k;i<s;i++)
	{
		if(cdfEffectiveUserRateX_(i) != cdfEffectiveUserRateX_(i+1) )
		{
		file<< cdfEffectiveUserRateX_(i)<<"  "<< cdfEffectiveUserRateY_(i)<<endl;
		}
		}*/
	file<<endl<<endl;
	for(int i=0;i<s;i++)
		{//cout<<cdfEffectiveUserRateX_(i)<<endl;
		file<< cdfEffectiveUserRateX_(i)<<"  "<< cdfEffectiveUserRateY_(i)*100<<endl;
		}
}

void
Results::
Results::creategraph()
{
  ofstream file;
	file.open("../Results/TransmissionRate.dat", ios::out | ios::app );
	file<<"x("<<numberUsers_<<")= "<<simlationEffectiveRate_ / numberDrops_ <<";"<<endl;
	file.close();
  
}


//------------------------------------------------------------------------------


// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
