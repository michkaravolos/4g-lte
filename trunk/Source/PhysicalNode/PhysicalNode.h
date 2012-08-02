/**
 * @file    PhysicalNode.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/11/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
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
       * Retorna a posição
       * 
       */
      Basic::Position getPosition();
      
      /**
       * Retorna o ID
       *  
       */
      int getId();
      
      /**
       * Evoca Gain
       * 
       */
      virtual double getGain( double theta );
      
      /**
       * Retorna o site
       * 
       */
      int getSite();
      
      /**
       * Retorna o setor
       * 
       */
      int getSector();
      
      /**
       * Evoca getRawBits
       *  
       */
      int getRawBits();
      
      /**
       * Evoca getEffectiveBits
       * 
       */
      double getEffectiveBits();
      
      /**
       * Evoca setBits
       * 
       */
      void setBits( int rawBits, double effectiveBits );
                   
   protected:
      
      /**
       * Bits brutos
       * 
       */
      int rawBits_;
      
      /**
       * Bits efetivos
       *
       */
      double effectiveBits_;
      
      /**
       * Posição no Grid
       * 
       */
      Basic::Position position_;
      
      /**
       * Site
       * 
       */
      int site_;
      
      /**
       * Setor
       * 
       */
      int sector_;
      
      /**
       * Id
       * 
       */
      int id_;
      
      /**
       * Dispositivo
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

