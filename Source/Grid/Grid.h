/**
 * @file    Grid.h
 * Name:    3G LTE Statistics Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       */
      static Grid* getInstance();
      
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
      //void createUsers();
      
      /**
       * Interface.
       * Detailed description.
       */
      //void createENodeBs();   
          
      /**
       * Interface.
       * Detailed description.
       */
      void generateUserPosition( Basic::Position& p, 
                                 int& site, 
                                 int& sector );
      
      /**
       * Interface.
       * Detailed description.
       */
      void generatePositionInsideTriangle( Basic::Position& p, 
                                           double xMax);
      
      /**
       * Interface.
       * Detailed description.
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
       * Detailed description.
       */
      void generateAbsolutePosition( Basic::Position& p, int site );
      
      /**
       * Interface.
       * Detailed description.
       */
      void generateENodeBPosition( Basic::Position& p, int& index );
      
      
      
   private:
      
      /**
       * Constructor.
       * Left empty.
       */
      Grid();
      
      /**
       * Interface.
       * Detailed description.
       */
      void updateIndexes();
      
      /**
       * Member.
       * Left empty.
       */      
      string name_;
      
      /**
       * Member.
       * Left empty.
       */      
      static Grid* instance_;     
      
      /**
       * Member.
       * Left empty.
       */      
      double interSiteDistance_;  
      
      /**
       * Member.
       * Left empty.
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
       * Left empty.
       */      
      int siteIndex_;
      
      /**
       * Member.
       * Left empty.
       */      
      int triangleIndex_;
};

};

#endif
