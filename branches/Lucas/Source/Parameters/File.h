/**
 * @file    File.h
 * Name:    3G LTE System Simulator
 * @author  Guilherme Silveira Rabelo
 * Date:    03/05/2008
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

#ifndef _FILE_H_
#define _FILE_H_

#include <itpp/itbase.h>
#include <string>

using namespace itpp;
using namespace std;

/**
 * Parameters Namespace. 
 * Detailed Description.
 */
namespace Parameters
{

/**
 * File Class.
 * Detailed description.
 */
class File
{
   public:
   
      /**
       * Constrcutor.
       * Detailed description.
       */	
      File();

      /**
       * Destructor.
       * Detailed description.
       */	
      virtual ~File();

      /**
       * Operator.
       * Detailed description.
       */	


      /**
       * Interface.
       * Detailed description.
       */
      void write( char* fileName, vec& xValues, vec& yValues );
      
      /**
       * Interface.
       * Detailed description.
       */
      void writeMatlab( char* fileName, vec& xValues, vec& yValues );
      
      /**
       * Interface.
       * Detailed description.
       */
      void writeMatlab( char* fileName, vec& xValues, vec& yValues, Array<vec> zValues );
      
      /**
       * Interface.
       * Detailed description.
       */
      void write( char* fileName, vec& xValues, vec& yValues, Array<vec>& zValues );
      
      void write( char* fileName, vec& xValues, vec& y0, vec& y1, vec& y2, vec& y3, vec& y4 );
      
      /**
       * Interface.
       * Detailed description.
       */
      void saveChannel( char* fileName, 
                        Array<vec>& array,
                        double timeStep,
                        double frequencyStep );
      
      /**
       * Interface.
       * Detailed description.
       */
      void readChannel( char* fileName, 
                        Array<vec>& array,
                        double& timeStep,
                        double& frequencyStep );
      
      /**
       * Interface.
       * Detailed description.
       */
      void read( const string fileName, 
                 const string varName,
                 int& var );
      
      /**
       * Interface.
       * Detailed description.
       */
      void read( const string fileName, 
                 const string varName,
                 double& var );

   protected:

   private:

 
};

};

#endif

