/**
 * @file    FrequencyPlanning.cpp
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

// *****************************************************************************
// Includes
// *****************************************************************************

#include "FrequencyPlanning.h"

#include "SimulationParameters.h"
#include "ChannelParameters.h"
#include "SystemParameters.h"
#include "PhysicalLayerParameters.h"
#include "ENodeB.h"
#include "PhysicalLayer.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************

FrequencyPlanning::FrequencyPlanning* 
   FrequencyPlanning::FrequencyPlanning::instance_ = 0;

// *****************************************************************************
// Constructors
// *****************************************************************************

FrequencyPlanning::
FrequencyPlanning::FrequencyPlanning()
{
   name_ = "Frequency Planning: ";
   setParameters();
   //initialize();
}

//------------------------------------------------------------------------------

FrequencyPlanning::
FrequencyPlanning::~FrequencyPlanning()
{
   delete instance_;
}

// *****************************************************************************
// Interfaces
// *****************************************************************************

FrequencyPlanning::FrequencyPlanning* 
FrequencyPlanning::
FrequencyPlanning::getInstance()
{
   if ( !instance_)
   {
      instance_ = new FrequencyPlanning();
   }
   return instance_;
}

//------------------------------------------------------------------------------

void
FrequencyPlanning::
FrequencyPlanning::setParameters()
{
   Parameters::SimulationParameters* sp = 
      Parameters::SimulationParameters::getInstance();
   //Parameters::ChannelParameters* cp = 
      //Parameters::ChannelParameters::getInstance();
   Parameters::SystemParameters* sysp = 
      Parameters::SystemParameters::getInstance();
   Parameters::PhysicalLayerParameters* plp = 
      Parameters::PhysicalLayerParameters::getInstance();
   
   numberENodeBs_ = sp->numberENodeBs;
   
   systemBandwitdh_ = sysp->systemBandwidth;
   subcarrierBandwitdh_ = sysp->subcarrierBandwidth;
   centralFrequency_ = sysp->centralFrequency;
   reuse_=sysp->reuse;
   numberSCperPRB_ = plp->numberSCPerPRB;
}

//------------------------------------------------------------------------------

void
FrequencyPlanning::
FrequencyPlanning::clear()
{
   frequencies_.set_size( 0 );
   subcarrierFrequencies_.set_size( 0 );
   PRBFrequencies_.set_size( 0 );
}

//------------------------------------------------------------------------------

void
FrequencyPlanning::
FrequencyPlanning::initialize()
{
   simulationEnvironment_ = SimulationEnvironment::
      SimulationEnvironment::getInstance();
   
   numberSubcarriers_ = static_cast<int>( 
      systemBandwitdh_ / subcarrierBandwitdh_ );
   
   numberPRBs_ = static_cast<int>( 
      systemBandwitdh_ / ( subcarrierBandwitdh_ * numberSCperPRB_ ) );
   
   
   subcarrierFrequencies_.set_size( numberSubcarriers_ );
   for( int i = 0; i < numberSubcarriers_; ++i )
   {
      subcarrierFrequencies_( i ) = i * subcarrierBandwitdh_;
            //cout<<subcarrierFrequencies_[i]<<" "<<i<<endl;

   }
   
   PRBFrequencies_.set_size( numberPRBs_ );
   for( int i = 0; i < numberPRBs_; ++i )
   {
      PRBFrequencies_( i ) = i * subcarrierBandwitdh_ * numberSCperPRB_;
      //cout<<PRBFrequencies_[i]<<" "<<i<<endl;
   }
   
   //cout << name_ << "Number subcarriers: " << numberSubcarriers_ << endl;
   //cout << name_ << "Number PRBs: " << numberPRBs_ << endl;
}

//------------------------------------------------------------------------------

void
FrequencyPlanning::
FrequencyPlanning::allocateFrequencies()
{
   PhysicalNode::ENodeB* eNodeB;
   PhysicalLayer::PhysicalLayer* pl;
   for( int i = 0; i < numberENodeBs_; ++i )
   {
      eNodeB = simulationEnvironment_->getENodeB( i );
     switch(reuse_)
{

case 0:
	  pl = new PhysicalLayer::PhysicalLayer( PRBFrequencies_,
	                    subcarrierFrequencies_);
	                eNodeB->setPhysicalLayer( pl );
	                eNodeB->informUserFrequencies();
	       	break;

case 1:
	switch(eNodeB->getSector())
	{
    case 0:

  	  pl = new PhysicalLayer::PhysicalLayer( PRBFrequencies_.get(0,17),
  	          subcarrierFrequencies_ );
  	       eNodeB->setPhysicalLayer( pl );
  	       eNodeB->informUserFrequencies();
  	       break;
    case 1:

       pl = new PhysicalLayer::PhysicalLayer( PRBFrequencies_.get(19,36),
                subcarrierFrequencies_ );
            eNodeB->setPhysicalLayer( pl );
            eNodeB->informUserFrequencies();
            break;

    case 2:

       pl = new PhysicalLayer::PhysicalLayer( PRBFrequencies_.get(37,54),
                subcarrierFrequencies_);
            eNodeB->setPhysicalLayer( pl );
            eNodeB->informUserFrequencies();
            break;

	}
	break;
}
      
   }
}

//------------------------------------------------------------------------------


// *****************************************************************************
// Protected Methods
// *****************************************************************************

// *****************************************************************************
// Private Methods
// *****************************************************************************
