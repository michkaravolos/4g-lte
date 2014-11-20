/**
 * @file    PhysicalResourceBlock.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/26/2008
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

#ifndef _PhysicalResourceBlock_h_
#define _PhysicalResourceBlock_h_

#include <itpp/itbase.h>

#include "Subcarrier.h"

#include "User.h"

using namespace std;
using namespace itpp;

namespace PhysicalLayer
{

/**
 * PhysicalResourceBlock Class.
 * Detailed description.
 */
class PhysicalResourceBlock
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      PhysicalResourceBlock( double Frequency );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~PhysicalResourceBlock();

      /**
       * Interface.
       * Detailed description.
       */   
      void setParameters();
      
      /**
       * Interface.
       * Detailed description.
       */   
      void initialize( double frequency );
      
      /**
       * Member
       * Detailed description
       */
      double getFrequency();
      
      /**
       * Member
       * Detailed description
       */
      void setUser( int userId, int userAntenna );
      
      /**
       * Member
       * Detailed description
       */
      int getUserId();
      
      /**
       * Member
       * Detailed description
       */
      int getUserAntenna();
      
      /**
       * Member
       * Detailed description
       */
      int getRawBits();
      
      /**
       * Member
       * Detailed description
       */
      double getEffectiveBits();
      
      /**
       * Member
       * Detailed description
       */
      double getBER();
      
      /**
       * Member
       * Detailed description
       */
      void clearUser();
      
      /**
       * Member
       * Detailed description
       */
      vec getSCFrequencies();
      
      /**
       * Member
       * Detailed description
       */
      int getNumberSubcarriers();
      
      /**
       * Member
       * Detailed description
       */
      Subcarrier* getSubcarrier( int index );
      
      /**
       * Member
       * Detailed description
       */
      void setBits( const int rawBits, 
                    const double effectiveBits );
      
            
   protected:
      
      /**
       * Member
       * Detailed description
       */
      int numberSubcarriers_;
      
      /**
       * Member
       * Detailed description
       */
      double initialFrequency_;
      
      /**
       * Member
       * Detailed description
       */
      double subcarrierFrequency_;
      
      
      /**
       * Member
       * Detailed description
       */
      Array<Subcarrier*> subcarriers_;
      
      /**
       * Member
       * Detailed description
       */
      int userId_;
      
      /**
       * Member
       * Detailed description
       */
      double BER_;
      
      /**
       * Member
       * Detailed description
       */
      int userAntenna_;
   
   
   private:
   

};

};

inline
double
PhysicalLayer::
PhysicalResourceBlock::getFrequency()
{
   return initialFrequency_;
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
PhysicalResourceBlock::setUser( int userId, int userAntenna )
{
   userId_ = userId;
   userAntenna_ = userAntenna;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalResourceBlock::getUserId()
{
   return userId_;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalResourceBlock::getUserAntenna()
{
   return userAntenna_;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalResourceBlock::getRawBits()
{
   int r = 0;
   int size = subcarriers_.size();
   
   for( int i = 0; i < size; ++i )
   {
      r += subcarriers_( i )->getRawBits(); 
   }
   
   return r;
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalResourceBlock::getEffectiveBits()
{
   double e = 0;
   int size = subcarriers_.size();
   
   for( int i = 0; i < size; ++i )
   {
      e += subcarriers_( i )->getEffectiveBits(); 
   }
   
   return e;
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
PhysicalResourceBlock::clearUser()
{
   userId_ = -1;
   userAntenna_ = -1;
};

// -----------------------------------------------------------------------------

inline
int
PhysicalLayer::
PhysicalResourceBlock::getNumberSubcarriers()
{
   return subcarriers_.size();
};

// -----------------------------------------------------------------------------

inline
PhysicalLayer::Subcarrier*
PhysicalLayer::
PhysicalResourceBlock::getSubcarrier( int index )
{
   Subcarrier* s = 0;
   if ( index < subcarriers_.size() )
   {
      s = subcarriers_( index );
   }
   else
   {
      it_error( "Physical Resource Block: Index out of range" );
   }  
   return s; 
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
PhysicalResourceBlock::getBER()
{
   return BER_;
   
};

// -----------------------------------------------------------------------------



#endif

