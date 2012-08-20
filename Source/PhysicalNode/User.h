/**
 * @file    Sector.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/06/2008
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

#ifndef _User_h_
#define _User_h_

#include "PhysicalNode.h"
#include "Receiver.h"

using namespace std;

namespace PhysicalNode
{

/**
 * User Class.
 * Detailed description.
 */
class User : public PhysicalNode
{
   public:

      
      
      /**
       * Constructor.
       * Detailed description.
       */   
      User();
      
      /**
       * Constructor.
       * Creates an user with the parameters below.
       */ 
      User( Basic::Position p, int site, int sector, int id );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~User();
      
      /**
       * Left white.
       * 
       */
      void initialize();
      
      /**
       * Defines orientation, device_, CQI_, CQIUpdatePeriod_, numberCQIBits_, maxSINRConsidered_, minSINRConsidered_,
       CQIUpdateCounter_, CQISD_, reuse_, vf, SINR_.
       *
       */
      void setParameters();
      
      /**
       * Returns the Id of the ENodeB.
       * 
       */
      int getENodeBId();
      
      /**
       * Defines the Id da EnodeB.
       *  
       */
      void setENodeBId( int eNodeBId );
       /**
       * Returns EnodeB sector.
       * 
       */
      int getENodeBSector();
      
      /**
       * Defines EnodeB sector.
       *  
       */
      void setENodeBSector( int eNodeBSector );
      
      /**
       * Returns Gain of the user.
       * 
       */
      double getGain( double theta );
      
      /**
       * Defines frequencies for the user.
       */
      void setFrequencies( vec frequencies );
      
      /**
       * Return the number of frequencies allocated to the user.
       * 
       */
      int getNumberFrequencies();
      
      /**
       * Returns the frequency Identified by the index.
       * 
       */
      double getFrequency( int index );
      
      /**
       * Saves the Channel Quality Indication
       * 
       */
      void storeCQI( double sinr,  
                     double frequency,
                     int antenna );
      
      /**
       * Clears the Channel Quality Indication
       * 
       */
      void clearCQI();
      
      /**
       * Clears the Signal Interference Noise Ratio
       * 
       */
      void clearSINR();
      
      /**
       * Saves ths Signal Interference Noise Ratio
       *  
       */
      void storeSINR( double sinr,  
                      double frequency,
                      int antenna);
      
      /**
       * Reports the CQI
       *  
       */
      double reportCQI( double frequency,
                        int antenna );
      
      /**
       * Returns the SINR
       * 
       */
      double getSINR( double frequency,
                      int antenna );
      
      /**
       * Update the CQI
       * 
       */
      void updateCQI();
      
      /**
       * Returns the average SINR by the passed antenna.
       *  
       */
      double getAverageSINR( int antenna );
      
      /**
       * Returns the average SINR.
       * 
       */
      double getAverageSINR();
      
      /**
       * Returns the Average CQI by the passed antenna.
       * 
       */
      double getAverageCQI( int antenna );
      
      /**
       * Returns the Average CQI.
       * 
       */
      double getAverageCQI();
      
      /**
       * Adjust the CQI.
       *  
       */
      void adjustCQI( double& CQI );
      
      /**
       * Returns the average CQI from the frequencies by antenna.
       */
      double getAverageCQI( vec frequencies, int antenna );
      
      //bool r;
      //int rawBits_;
      //int effectiveBits_;
      //int eNodeBId_;
             
   protected:
      
      /**
       * Id of the EnodeB
       * 
       */
      int eNodeBId_;
      
      /**
       * Matrix of SINR
       * 
       */
      Array< vec > SINR_;
      /**
       * Second Matrix of SINR
       * 
       */
      Array< vec > SINR2_;
      
      /**
       * Matrix of CQI
       * 
       */
      Array< Array< vec > > CQI_;
      
      /**
       * Vector of frequencies.
       * 
       */
      vec frequencies_;
      
      /**
       * CQI Update Period.
       */
      int CQIUpdatePeriod_;
      
      /**
       * CQI Update Counter.
       * 
       */
      int CQIUpdateCounter_;
      
      /**
       * Number of CQI bits.
       * 
       */
      int numberCQIBits_;
      
      /**
       * Maximum SINR Considered.
       * 
       */
      double maxSINRConsidered_;
      
      /**
       * Minimum SINR Considered.
       * 
       */
      double minSINRConsidered_;
      
      /**
       * Member
       * Detailed description
       */
      double CQISD_;
      int reuse_;
      int eNodeBSector_;
          
   private:
   
};

};

inline
void
PhysicalNode::
User::setENodeBId( int eNodeBId )
{
   eNodeBId_ = eNodeBId;
};

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
User::getENodeBId()
{
   return eNodeBId_;
};

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
User::getNumberFrequencies()
{
   return frequencies_.size();
};

// -----------------------------------------------------------------------------

inline
void
PhysicalNode::
User::setENodeBSector( int eNodeBSector )
{
   eNodeBSector_ = eNodeBSector;
};

//------------------------------------------------------------------------------

inline
int
PhysicalNode::
User::getENodeBSector()
{
   return eNodeBSector_;
};





#endif

