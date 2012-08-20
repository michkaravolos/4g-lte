/**
 * @file    Simulation.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2007
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


// *****************************************************************************
// Includes
// *****************************************************************************

#include <itpp/itbase.h>

#include "Simulation.h"
#include "File.h"
#include "FrequencySelectiveChannel.h"
#include "RayleighChannel.h"
#include "ClarkeChannel.h"
#include "VectorFunctions.h"
#include "SimulationParameters.h"


// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************
Simulation::
Simulation::Simulation()
{
   setParameters();
   initialize();
};

// -----------------------------------------------------------------------------
/**
       * Destructor
       * 
       */
Simulation::
Simulation::~Simulation()
{
};

// *****************************************************************************
// Interface
// *****************************************************************************
void
Simulation::
Simulation::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   simulationDrops_ = sp->DropsPerSimulation;
   numberSimulations_ = static_cast<int>( ( sp->finalUsers - sp->initialUsers ) 
      / sp->userStep );
   Direction_=sp->Direction;
   //cout<<Direction_<<"\n";
}

// -----------------------------------------------------------------------------
/**
       * Inicializa as classes da simulacao resgatando as situações de cada classes
       * geralmente iniciando novamente
       */
void
Simulation::
Simulation::initialize()
{
   results_ = Results::Results::getInstance();
   results_->initialize();
   grid_ = Grid::Grid::getInstance();
   mobility_ = Mobility::Mobility::getInstance();
   timeManager_ = TimeManager::TimeManager::getInstance(); 
   radioChannel_ = RadioChannel::RadioChannel::getInstance(); 
   radioChannel_->generateSmallScaleFading();
   simulationEnvironment_ = SimulationEnvironment::SimulationEnvironment::getInstance(); 
   link_ = Link::Link::getInstance();
   frequencyPlanning_ = FrequencyPlanning::FrequencyPlanning::getInstance();
   scheduler_ = Scheduler::Scheduler::getInstance();
   linkAdaptation_ = LinkAdaptation::LinkAdaptation::getInstance(); 
   transmission_ = Transmission::Transmission::getInstance();
   
   
}

// -----------------------------------------------------------------------------
/**
       * Inicializa todas as condições necessárias para transmissão
       * 
       */
void
Simulation::
Simulation::initializeDrop()
{
   //timeManager_->update(); 
   
   timeManager_->initialize();
   grid_->initialize();
   mobility_->initialize();
   simulationEnvironment_->initialize();  
   radioChannel_->initialize();
   
   radioChannel_->generateSmallScaleFadingIndexes();
   radioChannel_->generateLargeScaleFading();
   
   link_->initialize();
   frequencyPlanning_->initialize();
   scheduler_->initialize();
   linkAdaptation_->initialize();
   transmission_->initialize();

   timeManager_->setTimeResolution( radioChannel_->getTimeStep() );
   
   link_->createLinks();
   
   frequencyPlanning_->allocateFrequencies();
   
   scheduler_->setSchedulingAlgorithm();
}

// -----------------------------------------------------------------------------
/**
       * Calcula o ruído acrescido de interferencia, aloca os recursos e transmite
       * um certo números de vezes setados em SimulationParameters.dat StepsPerDrop.
       */
void
Simulation::
Simulation::runDrop()
{
   while( timeManager_->validateTime() )
   {    
      cout << "      Step: " << timeManager_->getCurrentStep() << endl;  
      if(Direction_==0){
       link_->calculateSINR();}
      scheduler_->schedule(Direction_); 
      transmission_->transmit();
      timeManager_->update();
   }  
}

// -----------------------------------------------------------------------------
/**
       * Finaliza a rodada limpando todos os dados
       * 
       */
void
Simulation::
Simulation::finalizeDrop()
{
    grid_->clear();
    mobility_->clear();
    linkAdaptation_->clear();
    timeManager_->clear();
    simulationEnvironment_->clear(); 
    radioChannel_->clear();
    link_->clear();
    frequencyPlanning_ ->clear();
    scheduler_->clear();
    transmission_->clear();   
}

// -----------------------------------------------------------------------------
/**
       * Inicia outra rodada
       * 
       */
void
Simulation::
Simulation::runSimulation()
{
    for( int i = 0; i < simulationDrops_; ++i )
    {
       cout << "   Drop: " << i << endl;  
       results_->initializeDrop();
       initializeDrop();
     if(Direction_==1){
      link_->calculateSINR();}
       runDrop();
       results_->finalizeDrop();
       finalizeDrop();  
    }
}

// -----------------------------------------------------------------------------
/**
       * Inicializa e finaliza a simulacao
       * 
       */
void
Simulation::
Simulation::runCampaign()
{int way;
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
        
   for( int i = 0; i <= numberSimulations_; ++i )
    {
       cout << "Simulation: " << i << endl;
       results_->initializeSimulation();
       runSimulation();
       results_->finalizeSimulation();
       sp->update();
    }
   results_->displayResults();
   testChannel();
   testResults();
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testChannel()
{
   Parameters::File f;
   vec h;
   vec yValues;
   vector<double> h1;
   RadioChannel::ClarkeChannel ch;
   int N = 100000;
   double fm = 5.555;
   
   h = ch.generateAbsoluteVector( N, fm );
   
   N = h.size();
   yValues.set_size( N );
   
   priority_queue< double, vector<double>, greater<double> > queue;
   
   for( int i = 0; i < h.size(); ++i)
   {
      queue.push( h(i) );
      yValues( i ) = 100 * static_cast<double>( i ) / static_cast<double>( N );
   }
   int i = 0;
   while( queue.empty() == false)
   {
      h(i) =  queue.top();
      queue.pop();
      ++i;
   }
   Basic::Statistics s;
   double mean = s.calculateMean( h );
   double sd = s.calculateStandardDeviation( h );
   double e = s.calculateMeanEnergy( h );
   
   cout << "N: " << N << endl ;
   cout << "Mean: " << mean << endl;
   cout << "Standard Deviation: " << sd << endl;
   cout << "Mean Energy: " << e << endl;
   
   f.write("/home/gustavo/Charts/TestChannel.dat", h, yValues );
   f.writeMatlab("/home/gustavo/Charts/TestChannel.m", h, yValues );
   
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testLosses()
{
   PhysicalNode::PhysicalNode* user;
   PhysicalNode::PhysicalNode* eNodeB;
   Basic::Position p;
   for( int i = 0; i < 1; i++)
   {
      //user = static_cast<PhysicalNode::User*>( simulationEnvironment_->getUser( i ) );
      user = simulationEnvironment_->getUser( i );
      //cout << "Position: " << user->getPosition();
      //cout << " Site: " << user->getSite();
      //cout << " Sector: " << user->getSector() << endl;
   }
   //user = static_cast<PhysicalNode::User*>( simulationEnvironment_->getUser( 0 ) );
   //node = simulationEnvironment_->getENodeB( 3 );
   //cout << "Loss( " << 0 << " ): " << radioChannel_->getLargeScaleFading( user, node ) << endl;
   /*for( int i = 0; i < 10; ++i )
   {
      node = simulationEnvironment_->getUser( i );
      cout << user->getId() << endl;
      //cout << "Loss( " << i << " ): " << radioChannel_->getLargeScaleFading( user, node ) << endl;
      //cout << "x(" << i+1 << ")=" << p.x() << endl;
      //cout << "y(" << i+1 << ")=" << p.y() << endl;
      //cout << "z(" << i+1 << "," << i+1 << ")=" << link_->getLoss( i ) << endl;
      //cout << p.x() << "\t" << p.y() << "\t" << 1 << endl;//
      //cout << link_->getLoss( i ) << endl;
   }*/
   for( int i = 0; i < 57; ++i )
   {
      eNodeB = simulationEnvironment_->getENodeB( i );
      //cout << node1->getId() << endl;
      //cout << "Loss( " << i << " ): " << radioChannel_->getLargeScaleFading( user, eNodeB ) << endl;
      //cout << "x(" << i+1 << ")=" << p.x() << endl;
      //cout << "y(" << i+1 << ")=" << p.y() << endl;
      //cout << "z(" << i+1 << "," << i+1 << ")=" << link_->getLoss( i ) << endl;
      //cout << p.x() << "\t" << p.y() << "\t" << 1 << endl;//
      //
   }

   //cout << "Link loss: " << link_->getLoss( 0 ) << endl;
   //cout << ((PhysicalNode::User* )user)->getENodeBId() << endl;
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testFading()
{
   ofstream f;
   f.open( "/home/gustavo/Charts/testfading.dat" );
   for( int i = 0; i < 1000; ++i)
   {
      f << /*"Fading(" << i << "): " << */ i << radioChannel_->getFading( 0, 0, 0, 10000 * i, 0 ) << endl;
   }
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testPathLoss()
{
   PhysicalNode::PhysicalNode* user;
   Basic::Position p;
   double min = 1e300;
   double max = -1e300;
   ofstream f;
   f.open( "/home/gustavo/Charts/pathloss.dat" );
   for( int x = 0; x < 100; ++x)
   {
      for( int y = 0; y < 100; ++y)
      {
          user = simulationEnvironment_->getUser( 100*x + y );
          p = user->getPosition();
          if ( (link_->getLoss( 100*x + y )) != 300 )
          {
             f << p.x() << " " << p.y() << " " << -1 * link_->getLoss( 100*x + y ) << endl;
          }
          if(link_->getLoss( 100*x + y ) > max)
          {
             max = link_->getLoss( 100*x + y );
          }
          if(link_->getLoss( 100*x + y ) < min)
          {
             min = link_->getLoss( 100*x + y );
          }
          
      }
      f << endl;
   }
   cout << max << endl;
   cout << min << endl;
   
   /*for( int i = 0; i < 90000; i++)
   {
      user = simulationEnvironment_->getUser( i );
      p = user->getPosition();
      f << p.x() << " " << p.y() << " " << link_->getLoss( i ) << endl;
      //f << "x(" << i+1 << ")= " << p.x() << ";" << endl;
      //f << "y(" << i+1 << ")= " << p.y() << ";" << endl;
      //f << "z(" << i+1 << ")= " << link_->getLoss( i ) << ";" << endl;
   }*/
   //user = static_cast<PhysicalNode::User*>( simulationEnvironment_->getUser( 0 ) );
   //node = simulationEnvironment_->getENodeB( 3 );
   //cout << "Loss( " << 0 << " ): " << radioChannel_->getLargeScaleFading( user, node ) << endl;
   /*for( int i = 0; i < 10; ++i )
   {
      node = simulationEnvironment_->getUser( i );
      cout << user->getId() << endl;
      //cout << "Loss( " << i << " ): " << radioChannel_->getLargeScaleFading( user, node ) << endl;
      //cout << "x(" << i+1 << ")=" << p.x() << endl;
      //cout << "y(" << i+1 << ")=" << p.y() << endl;
      //cout << "z(" << i+1 << "," << i+1 << ")=" << link_->getLoss( i ) << endl;
      //cout << p.x() << "\t" << p.y() << "\t" << 1 << endl;//
      //cout << link_->getLoss( i ) << endl;
   }
   for( int i = 0; i < 57; ++i )
   {
      //eNodeB = simulationEnvironment_->getENodeB( i );
      //cout << node1->getId() << endl;
      //cout << "Loss( " << i << " ): " << radioChannel_->getLargeScaleFading( user, eNodeB ) << endl;
      //cout << "x(" << i+1 << ")=" << p.x() << endl;
      //cout << "y(" << i+1 << ")=" << p.y() << endl;
      //cout << "z(" << i+1 << "," << i+1 << ")=" << link_->getLoss( i ) << endl;
      //cout << p.x() << "\t" << p.y() << "\t" << 1 << endl;//
      //
   }*/

   //cout << "Link loss: " << link_->getLoss( 0 ) << endl;
   //cout << ((PhysicalNode::User* )user)->getENodeBId() << endl;
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testLink()
{
   PhysicalNode::ENodeB* eNodeB;
   double sum = 0.0;
   for( int i = 0; i < 57; ++i )
   {
      eNodeB = simulationEnvironment_->getENodeB( i );
      cout << "Number of links (" << eNodeB->getId() << "): " << eNodeB->getNumberLinks() << endl;
      sum += eNodeB->getNumberLinks();
   }
   cout << "Sum: " << sum << endl;
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testResults()
{
   //PhysicalNode::User* user;
   int s = results_->getNumberUsers();
   cout << "Test results: number of users: " << s << endl;
   for( int i = 0; i < s; ++i )
   {
      //user = static_cast<PhysicalNode::User*>( simulationEnvironment_->getUser( results_->getUserId( i ) ) );
      //cout << user->eNodeBId_ << endl;
      //cout << user->r << endl;
      //cout << user->getLastRawBits() << endl;
      //cout << user->getLastEffectiveBits() << endl;     
      //cout << user->rawBits_ << endl;
      //cout << user->effectiveBits_ << endl;
      
   }
   cout << "Test results: raw rate: " << results_->getAverageUserRawRate() << endl;
   cout << "Test results: effective rate: " << results_->getAverageUserEffectiveRate() << endl;
   
}

// -----------------------------------------------------------------------------

void
Simulation::
Simulation::testFrequencyPlanning()
{
   PhysicalNode::ENodeB* eNodeB;
   double sum = 0.0;
   for( int i = 0; i < 57; ++i )
   {
      eNodeB = simulationEnvironment_->getENodeB( i ) ;
      //cout << "Number of links (" << eNodeB->getId() << "): " << eNodeB->getNumberLinks() << endl;
      sum += eNodeB->getNumberLinks();
   }
   //cout << "Sum: " << sum << endl; 
}

// -----------------------------------------------------------------------------


// *****************************************************************************
// Operators
// *****************************************************************************

// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************

// -----------------------------------------------------------------------------
