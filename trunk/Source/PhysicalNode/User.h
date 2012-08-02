/**
 * @file    Sector.cpp
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/06/2008
 *
 * This file is part of the undergraduate final project, under the supervision 
 * of Robson Domingos and Paulo Portela.
 */ 

#ifndef _User_h_
#define _User_h_

#include "PhysicalNode.h"
#include "Reciever.h"

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
       * Cria o usuário com posição, site, setor e id.
       */ 
      User( Basic::Position p, int site, int sector, int id );
      
      /**
       * Destructor.
       * Detailed description.
       */   
      virtual ~User();
      
      /**
       * Inicializa o usuário
       * 
       */
      void initialize();
      
      /**
       * Define os parâmetros
       *
       */
      void setParameters();
      
      /**
       * Retorna o id da EnodeB
       * 
       */
      int getENodeBId();
      
      /**
       * Define o Id da EnodeB
       *  
       */
      void setENodeBId( int eNodeBId );
      
      /**
       * Evoca getGain
       * 
       */
      double getGain( double theta );
      
      /**
       * Define frequencias para o usuário
       * 
       */
      void setFrequencies( vec frequencies );
      
      /**
       * Retorna o número de frequencias
       * 
       */
      int getNumberFrequencies();
      
      /**
       * Retorna uma frequencia
       * 
       */
      double getFrequency( int index );
      
      /**
       * Salva o Channel Quality Indication
       * 
       */
      void storeCQI( double sinr,  
                     double frequency,
                     int antenna );
      
      /**
       * Limpa o Channel Quality Indication
       * 
       */
      void clearCQI();
      
      /**
       * Limpa o Signal Interference Noise Ratio
       * 
       */
      void clearSINR();
      
      /**
       * Salva o Signal Interference Noise Ratio
       *  
       */
      void storeSINR( double sinr,  
                      double frequency,
                      int antenna );
      
      /**
       * Informa o CQI
       *  
       */
      double reportCQI( double frequency,
                        int antenna );
      
      /**
       * Retorna o SINR
       * 
       */
      double getSINR( double frequency,
                      int antenna );
      
      /**
       * Atualiza o CQI
       * 
       */
      void updateCQI();
      
      /**
       * Retorna o SINR médio por antena
       *  
       */
      double getAverageSINR( int antenna );
      
      /**
       * Retorna o SINR médio
       * 
       */
      double getAverageSINR();
      
      /**
       * Retorna o CQI médio por antena
       * 
       */
      double getAverageCQI( int antenna );
      
      /**
       * Retorna o CQI médio
       * 
       */
      double getAverageCQI();
      
      /**
       * Ajusta o CQI
       *  
       */
      void adjustCQI( double& CQI );
      
      /**
       * Retorna o CQI médio nas frequencias por antena
       * 
       */
      double getAverageCQI( vec frequencies, int antenna );
      
      //bool r;
      //int rawBits_;
      //int effectiveBits_;
      //int eNodeBId_;
             
   protected:
      
      /**
       * Id da EnodeB
       * 
       */
      int eNodeBId_;
      
      /**
       * Matriz de SINR
       * 
       */
      Array< vec > SINR_;
      
      /**
       * Matriz de SINR
       * 
       */
      Array< Array< vec > > CQI_;
      
      /**
       * vetor frequencias
       * 
       */
      vec frequencies_;
      
      /**
       *Período de atualização do CQI
       *
       */
      int CQIUpdatePeriod_;
      
      /**
       * Contador de atualizações de CQI
       * 
       */
      int CQIUpdateCounter_;
      
      /**
       * Numero de Bits do CQI
       * 
       */
      int numberCQIBits_;
      
      /**
       * SINR máxima considerada
       * 
       */
      double maxSINRConsidered_;
      
      /**
       * SINR mínima considerada
       * 
       */
      double minSINRConsidered_;
      
      /**
       * Member
       * Detailed description
       */
      double CQISD_;
          
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




#endif

