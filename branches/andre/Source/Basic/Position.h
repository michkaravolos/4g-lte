/**
 * @file    Position.h
 * Name:    3G LTE System Simulator
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
       * Initializes position_ with (0,0) arguments.
       */   
      Position();
      
      /**
       * Constructor.
       * @param x Real part of position_.
       * @param y Imag part of position_.
       * Initializes position_ with (x,y) arguments.
       */   
      Position( double x, double y );
      
      /**
       * Destructor.
       * Left empty.
       */   
      virtual ~Position();
      
      /**
       * Interface
       * @return Real value of position_.
       */
      double x();
      
      /**
       * Interface
       * @return Complex value of position_.
       */
      double y();
      
      /**
       * Interface
       * Sets x_arg as the new value of real part of position_.
       */
      void x( double x_arg );
      
      /**
       * Interface
       * Sets y_arg as the new value of imag part of position_.
       */
      void y( double y_arg );
      
      /**
       * Interface
       * @param x Real part of position_.
       * @param y Imag part of position_.       
       * Sets new values to real part and imag part of position_.
       */
      void xy( double x, double y );
      
      /**
       * Interface
       * @return The argument value of position_.
       */
      double arg();
      
      /**
       * Interface
       * @return The absolute value of position_.
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
       * Saves the value of each entity positioned in the space of the simulation.
       */
      complex<double> position_;
     
   private:
   

};

};

#endif

