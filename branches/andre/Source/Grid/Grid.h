/**
 * @file    Grid.h
 * Name:    3G LTE Statistics Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
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

#ifndef _Grid_h_
#define _Grid_h_

#include "User.h"
#include "ENodeB.h"

using namespace itpp;
using namespace std;

/**
 * Grid Namespace. 
 * Detailed Description.
 */
namespace Grid
{

/**
 * Grid Class. 
 * Detailed Description.
 */
class Grid
{
   public:
           
      /**
       * Destructor.
       * Left empty.
       */
      ~Grid();
      
      /**
       * Interface.
       * Sinlgetown instance of the class.
       * Initializes name_. 
       */
      static Grid* getInstance();
      
      /**
       * Interface.
       * Initializes numberENodeBs_ from Simulation Parameters, interSiteDistance_, minimumDistance_.
       */
      void setParameters();
      
      /**
       * Interface.
       * Initializes  numberSites_, siteIndex_, triangleIndex_.
       */
      void initialize();
      
      /**
       * Interface.
       * Left empty.
       */
      void clear();
      
      /**
       * Interface.
       * Detailed description.
       */
      //void createUsers();
      
      /**
       * Interface.
       * Detailed description.
       */
      //void createENodeBs();   
          
      /**
       * Interface.
       * Generates the User Position acording the parameters.
       * Calls the other generating methods listed on the class.
       *
       */
      void generateUserPosition( Basic::Position& p, 
                                 int& site, 
                                 int& sector );
      
      /**
       * Interface.
       * Generates an Uniform_RNG position between 0 and xMax, inside the triangle.
       * yMax = xMax / sqrt( 3.0 ), therefore, the angle of the triangle is 60º.
       * It may be called while p.abs < minimumDistance_.
       */
      void generatePositionInsideTriangle( Basic::Position& p, 
                                           double xMax);
      
      /**
       * Interface.
       * Uses the result of generatePositionInsideTriangle.
       */
      void generatePositionInsideHexagon( Basic::Position& p, 
                                          int index);
      
      /**
       * Interface.
       * Detailed description.
       */
      int getSector( Basic::Position& p );
      
      /**
       * Interface.
       * Generates the position of p according of position of the index of the ENodeB.
       * @return The absolute position of p on the simulation space.
       */
      void generateAbsolutePosition( Basic::Position& p, int site );
      
      /**
       * Interface.
       * Generates position of ENodeB accoding of position of the index of the ENodeB.
       */
      void generateENodeBPosition( Basic::Position& p, int& index );
      
      
      
   private:
      
      /**
       * Constructor.
       * Sets name_.
       * Calls setParameteres.
       */
      Grid();
      
      /**
       * Interface.
       * Detailed description.
       */
      void updateIndexes();
      
      /**
       * Member.
       * Names the Grid of the simulation.
       */      
      string name_;
      
      /**
       * Member.
       * Sets the instance of Grid.
       */      
      static Grid* instance_;     
      
      /**
       * Member.
       * The distance between Sites.
       */      
      double interSiteDistance_;  
      
      /**
       * Member.
       * The minimum distance between User and ENodeB.
       */      
      double minimumDistance_;  
      
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
      int numberSites_;
      
      /**
       * Member.
       * Between 0 and numberSites_.
       */      
      int siteIndex_;
      
      /**
       * Member.
       * Between 0 and 6.
       */      
      int triangleIndex_;
};

};

#endif
