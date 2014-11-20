/**
 * @file    ResourceElement.h
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

#ifndef _ResourceElement_h_
#define _ResourceElement_h_

using namespace std;

namespace PhysicalLayer
{

/**
 * ResourceElement Class.
 * Detailed description.
 */
class ResourceElement
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      ResourceElement();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~ResourceElement();

      /**
       * Interface.
       * Detailed description.
       */   
      void setParameters();
      
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
      void setRawBits( const int rawBits );
      
      /**
       * Member
       * Detailed description
       */
      void setEffectiveBits( const double effectiveBits );
             
   protected:
      
      /**
       * Member
       * Detailed description
       */
      int rawBits_;
      
      /**
       * Member
       * Detailed description
       */
      double effectiveBits_;
   
   
   private:
   

};

};

inline
int
PhysicalLayer::
ResourceElement::getRawBits()
{
   return rawBits_;
};

// -----------------------------------------------------------------------------

inline
double
PhysicalLayer::
ResourceElement::getEffectiveBits()
{
   return effectiveBits_;
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
ResourceElement::setRawBits( const int rawBits )
{
   rawBits_ = rawBits;
};

// -----------------------------------------------------------------------------

inline
void
PhysicalLayer::
ResourceElement::setEffectiveBits( const double effectiveBits )
{
   effectiveBits_ = effectiveBits;
};

// -----------------------------------------------------------------------------

#endif

