/**
 * @file    PhysicalNode.h
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


#ifndef _PhysicalNode_h_
#define _PhysicalNode_h_

#include <itpp/itbase.h>

#include "Position.h"
#include "Device.h"

using namespace itpp;
using namespace std;

/**
 * PhysicalNode Namespace. 
 * Detailed Description.
 */
namespace PhysicalNode
{

/**
 * PhysicalNode Class.
 * Detailed description.
 */
class PhysicalNode
{
   public:

      /**
       * Constructor.
       * Detailed description.
       */   
      PhysicalNode();
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~PhysicalNode();
      
      /**
       * Returns position.
       * 
       */
      Basic::Position getPosition();
      
      /**
       * Returns the ID.
       *  
       */
      int getId();
      
      /**
       * Returns the Gain.
       * 
       */
      virtual double getGain( double theta );
      
      /**
       * Returns the Site.
       * 
       */
      int getSite();
      
      /**
       * Returns the sector.
       * 
       */
      int getSector();
      
      /**
       * Returns the amount of raw bits.
       *  
       */
      int getRawBits();
      
      /**
       * Returns the amount of effective bits.
       * 
       */
      double getEffectiveBits();
      
      /**
       * Calls setBits.
       * 
       */
      void setBits( int rawBits, double effectiveBits );
                   
   protected:
      
      /**
       * Raw Bits.
       * Contains effective bits and redudancy bits.
       * 
       */
      int rawBits_;
      
      /**
       * Effective Bits.
       *
       */
      double effectiveBits_;
      
      /**
       * Absolute Position on the Grid.
       * 
       */
      Basic::Position position_;
      
      /**
       * Site
       * 
       */
      int site_;
      
      /**
       * Sector
       * 
       */
      int sector_;
      
      /**
       * Id
       * 
       */
      int id_;
      
      /**
       * Device
       * 
       */
      Device* device_;
     
   private:
   

};

};

inline
void
PhysicalNode::
PhysicalNode::setBits( int rawBits, double effectiveBits )
{
   rawBits_ += rawBits;
   effectiveBits_ += effectiveBits;
   //r = true;
};

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
PhysicalNode::getRawBits()
{
   return rawBits_;
};

//------------------------------------------------------------------------------

inline
double
PhysicalNode::
PhysicalNode::getEffectiveBits()
{
   return effectiveBits_;
};

//------------------------------------------------------------------------------



#endif

