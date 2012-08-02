/**
 * @file    Position.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _Position_h_
#define _Position_h_

#include <itpp/itbase.h>

using namespace itpp;
using namespace std;

namespace Basic
{

/**
 * Position Class.
 * Detailed description.
 */
class Position
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      Position();
      
      /**
       * Constructor.
       * Detailed description.
       */   
      Position( double x, double y );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~Position();
      
      /**
       * Interface
       * Detailed description
       */
      double x();
      
      /**
       * Interface
       * Detailed description
       */
      double y();
      
      /**
       * Interface
       * Detailed description
       */
      void x( double x_arg );
      
      /**
       * Interface
       * Detailed description
       */
      void y( double y_arg );
      
      /**
       * Interface
       * Detailed description
       */
      void xy( double x, double y );
      
      /**
       * Interface
       * Detailed description
       */
      double arg();
      
      /**
       * Interface
       * Detailed description
       */
      double abs();
      
      /** 
       * Operator.
       * @return Sum of two Timestamps.
       */
      Position operator+( Position p ) const;
      
      /** 
       * Operator.
       * @return Stream for Timestamp class.
       */
      friend std::ostream& operator <<( std::ostream& os, Position p );
             
   protected:
      
      /**
       * Member.
       * Detailed description.
       */
      complex<double> position_;
     
   private:
   

};

};

#endif

