/**
 * @file    ENodeB.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _ENodeB_h_
#define _ENodeB_h_

#include "PhysicalNode.h"
#include "PhysicalLayer.h"
#include "SchedulingAlgorithm.h"
#include "Transmitter.h"

using namespace std;

namespace PhysicalNode
{

/**
 * ENodeB Class.
 * Detailed description.
 */
class ENodeB : public PhysicalNode
{
   public:
      
      

      /**
       * Constructor.
       * Cria EnodeB genérica
       */   
      ENodeB();
      
      /**
       * Define a posição e o ID da EnodeB
       * 
       */   
      ENodeB( Basic::Position p, int id);
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~ENodeB();
      
      /**
       * Define os parâmetros
       * 
       */
      void setParameters();
      
      /**
       * Inicializa a EnodeB
       * 
       */
      void initialize();
      
      /**
       * Evoca o ganho em antenna
       * 
       */
      double getGain( const double theta );
            
      /**
       * Evoca setPhysicalLayer em PhysicalLayer
       * 
       */
      void setPhysicalLayer( PhysicalLayer::PhysicalLayer* pl );
      
      /**
       * Evoca addUser de User
       * 
       */
      void addUser( int userId );
      
      /**
       * Evoca getNumberLinks
       * 
       */
      int getNumberLinks();
      
      /**
       * Evoca os usuários alocados
       * 
       */
      void scheduleUsers(int Direction);
      
      /**
       * Evoca setSchedulingAlgorithm
       * 
       */
      void setSchedulingAlgorithm( Scheduler::SchedulingAlgorithm* sa );
      
      /**
       * Transmite os bits de EnodeB para User
       * 
       */
      void transmit();
      
      /**
       * Retorna o número de Physical Resource Blocks
       * 
       */
      int getNumberPRBs();
      
      /**
       * Retorna o número de Slots
       * 
       */
      int getNumberSlots();
      
      /**
       * Retorna o Id do usuário alocado
       * 
       */
      int getScheduledUserId( int slot , int prb );
      
      /**
       * Retorna a potencia transmitidas
       * 
       */
      double getTransmittedPower( double Frequency );
      
      /**
       * Retorna uma frequencia
       * 
       */
      double getFrequency( int slot , int prb );
      
      /**
       * Informa as frequencias do usuário
       * 
       */
      void informUserFrequencies();
      
      /**
       * Retorna a camada física do usuário
       * 
       */
      PhysicalLayer::PhysicalLayer* getPhysicalLayer();
      
      /**
       * Retorna o número de usuários da EnodeB
       * 
       */
      int getNumberLinkedUsers();
      
      /**
       * Retorna o id do usuário conectado
       * 
       */
      int getLinkedUserId( int index );
      //ivec linkedUsers_;
        
   protected:
      
      /**
       * Ponteiro para physicalLayer
       * 
       */
      PhysicalLayer::PhysicalLayer* physicalLayer_;
      
      /**
       * Usuários alocados
       * 
       */
      ivec linkedUsers_;
      
      /**
       * Ponteiro para schedulingAlgorithm
       * 
       */
      Scheduler::SchedulingAlgorithm* schedulingAlgorithm_;
 
   private:

};

};

inline
double
PhysicalNode::
ENodeB::getGain( const double theta )
{
   return device_->getGain( theta );  
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::setPhysicalLayer( PhysicalLayer::PhysicalLayer* pl )
{
   physicalLayer_ = pl;
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::addUser( int userId )
{
   int s = linkedUsers_.size();
   linkedUsers_.set_size( s + 1, true );
   linkedUsers_( s ) = userId;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberLinks()
{
   return linkedUsers_.size();
}

//------------------------------------------------------------------------------

inline
void
PhysicalNode::
ENodeB::setSchedulingAlgorithm( Scheduler::SchedulingAlgorithm* sa )
{
   schedulingAlgorithm_ = sa;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberPRBs()
{
   return physicalLayer_->getNumberPRBsPerSlot();
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberSlots()
{
   return physicalLayer_->getNumberSlots();
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getScheduledUserId( int slot , int prb )
{
   return physicalLayer_->getUserId( slot, prb );
}

//------------------------------------------------------------------------------

inline
double
PhysicalNode::
ENodeB::getFrequency( int slot , int prb )
{
   return physicalLayer_->getFrequency( slot, prb );
}

//------------------------------------------------------------------------------

inline
PhysicalLayer::PhysicalLayer*
PhysicalNode::
ENodeB::getPhysicalLayer()
{
   return physicalLayer_;
}

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
ENodeB::getNumberLinkedUsers()
{
   return linkedUsers_.size();;
}

//------------------------------------------------------------------------------


inline
int
PhysicalNode::
ENodeB::getLinkedUserId( int index )
{
   int i = -1;
   
   if( index < linkedUsers_.size() && index > -1 )
   {
      i = linkedUsers_( index );
   }
   else
   {
      it_error("ENodeB: index out of range.");
   }
   
   return i;
}

//------------------------------------------------------------------------------


#endif

