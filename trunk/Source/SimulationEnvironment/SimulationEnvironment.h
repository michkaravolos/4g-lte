/**
 * @file    SimulationEnvironment.h
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
       * Define numberUsers_ and numberENodeBs_.
       * 
       */
      void setParameters();
      
      /**
       * Interface.
       * Clear users_ and eNodeBs_.
       */
      void clear();
      
      /**
       * Creates Users and store than in users_.
       * 
       */
      void createUsers();
      
      /**
       * Creates ENodeBs and store than in eNodeBs_.
       * 
       */
      void createENodeBs();  
      
      /**
       * Gets the user by its ID.
       * 
       */
      PhysicalNode::User* getUser( int id );   
      
      /**
       * Gets the ENodeB by its ID.
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
       * Initializes numberUsers_, mobility_, userIdCounter_, eNodeBIdCounter_.
       * Calls createUsers and createENodeBs.
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
       * Calls setParameters.
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
       * Number of ENodeBs.
       */      
      int numberENodeBs_;       
      
      /**
       * Member.
       * Number of Users.
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
