/**
 * @file    SimulationEnvironment.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/12/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _SimulationEnvironment_h_
#define _SimulationEnvironment_h_

#include <itpp/itbase.h>

#include "User.h"
#include "ENodeB.h"
#include "Mobility.h"

using namespace itpp;
using namespace std;

/**
 * SimulationEnvironment Namespace. 
 * Detailed Description.
 */
namespace SimulationEnvironment
{

/**
 * SimulationEnvironment Class. 
 * Detailed Description.
 */
class SimulationEnvironment
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~SimulationEnvironment();
      
      /**
       * Interface.
       * Sinlgetown instance of the class. 
       */
      static SimulationEnvironment* getInstance();
      
      /**
       * Define os parametros
       * 
       */
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */
      void clear();
      
      /**
       * Cria os usuários
       * 
       */
      void createUsers();
      
      /**
       * Cria as EnodeBs
       * 
       */
      void createENodeBs();  
      
      /**
       * Retorna um usuario pelo seu id
       * 
       */
      PhysicalNode::User* getUser( int id );   
      
      /**
       * Retorna uma EnodeB pelo seu id
       * 
       */
      PhysicalNode::ENodeB* getENodeB( int id ); 
      
      /**
       * Interface.
       * Detailed description.
       */
      Array<PhysicalNode::PhysicalNode*>* getUsers();   
      
      /**
       * Interface.
       * Detailed description.
       */
      Array<PhysicalNode::PhysicalNode*>* getENodeBs(); 
      
      /**
       * Inicializa o ambiente de simulação
       * 
       */
      void initialize();  
      
   private:
      
      /**
       * Member.
       * Left empty.
       */      
      string name_;
      
      /**
       * Constructor.
       * Left empty.
       */
      SimulationEnvironment();
      
      /**
       * Member.
       * Left empty.
       */      
      static SimulationEnvironment* instance_;    
     
      /**
       * Member.
       * Left empty.
       */      
      Array<PhysicalNode::PhysicalNode*> users_;
      
      /**
       * Member.
       * Left empty.
       */      
      Array<PhysicalNode::PhysicalNode*> eNodeBs_;
      
      /**
       * Member.
       * Left empty.
       */      
      int numberENodeBs_;       
      
      /**
       * Member.
       * Left empty.
       */      
      int numberUsers_;
      
      /**
       * Member.
       * Left empty.
       */      
      int userIdCounter_;
      
      /**
       * Member.
       * Left empty.
       */      
      int eNodeBIdCounter_;
      
      /**
       * Member.
       * Left empty.
       */      
      Mobility::Mobility* mobility_;
};

};

inline
PhysicalNode::User*
SimulationEnvironment::
SimulationEnvironment::getUser( int id )
{
   return static_cast<PhysicalNode::User*>( users_( id ) ); 
}

//------------------------------------------------------------------------------

inline
PhysicalNode::ENodeB*
SimulationEnvironment::
SimulationEnvironment::getENodeB( int id )
{
   return static_cast<PhysicalNode::ENodeB*>( eNodeBs_( id ) ); 
}

//------------------------------------------------------------------------------

inline
Array<PhysicalNode::PhysicalNode*>*
SimulationEnvironment::
SimulationEnvironment::getUsers()
{
   return &users_; 
}

//------------------------------------------------------------------------------

inline
Array<PhysicalNode::PhysicalNode*>*
SimulationEnvironment::
SimulationEnvironment::getENodeBs()
{
   return &eNodeBs_; 
}

//------------------------------------------------------------------------------

#endif
