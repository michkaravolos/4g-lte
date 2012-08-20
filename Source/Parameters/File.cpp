/**
 * @file    File.cpp
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


// *****************************************************************************
// Includes
// *****************************************************************************

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "File.h"

// *****************************************************************************
// Static attributes initialization
// *****************************************************************************


// *****************************************************************************
// Constructors
// *****************************************************************************

Parameters::
File::File()
{
}

// -----------------------------------------------------------------------------

Parameters::
File::~File()
{
}

// *****************************************************************************
// Operators
// *****************************************************************************


// *****************************************************************************
// Interface
// *****************************************************************************

void 
Parameters::
File::write( char* fileName, vec& xValues, vec& yValues )
{
   if( xValues.size() != yValues.size() )
   {
      cout << "xValues and yValues have not same size!" << endl;
      return;
   }
   
   ofstream file;
   file.open( fileName );
   
   for( int i = 0; i < xValues.size(); i++)
   {
      file << xValues( i ) << "\t" << yValues( i ) << "\n"; 
   }
   file.close();
   

}

// -----------------------------------------------------------------------------

void 
Parameters::
File::writeMatlab( char* fileName, vec& xValues, vec& yValues )
{
   if( xValues.size() != yValues.size() )
   {
      cout << "xValues and yValues have not same size!" << endl;
      return;
   }
   
   ofstream file;
   file.open( fileName );
   
   for( int i = 0; i < xValues.size(); i++)
   {
      file << "x(" << i+1 << ")= " << xValues( i ) << ";"<< endl;
   }
   for( int i = 0; i < yValues.size(); i++)
   {
      file << "y(" << i+1 << ")= " << yValues( i ) << ";"<< endl;
   }
   file.close();
   

}

// -----------------------------------------------------------------------------

void 
Parameters::
File::writeMatlab( char* fileName, vec& xValues, vec& yValues, Array<vec> zValues )
{
   ofstream file;
   file.open( fileName );
   
   for( int i = 0; i < xValues.size(); i++)
   {
      file << "x(" << i+1 << ")= " << xValues( i ) << ";"<< endl;
   }
   for( int i = 0; i < yValues.size(); i++)
   {
      file << "y(" << i+1 << ")= " << yValues( i ) << ";"<< endl;
   }
   
   for( int i = 0; i < zValues.size(); i++)
   {
      for( int j = 0; j < zValues( 0 ).size(); j++)
      {
         file << "z(" << i+1 << "," << j+1 << ")= " << zValues( i )( j ) 
            << ";"<< endl;
      }
   }
   
   
   file.close();
   

}

// -----------------------------------------------------------------------------

void
Parameters::
File::write( char* fileName, vec& xValues, vec& yValues, Array<vec>& zValues )
{
   if( xValues.size() != zValues.size() || yValues.size() != zValues( 0 ).size() )
   {
      cout << "Error!" << endl;
      return;
   }
   
   ofstream file;
   file.open( fileName );
   
   for( int i = 0; i < xValues.size(); i++)
   {
      for( int j = 0; j < yValues.size(); ++j)
      {
      file << xValues( i ) << "\t" << yValues( j ) << "\t" 
         << zValues( i )( j ) << endl;    
      }
      file << endl;
      
   }
   file.close();
   

}

// -----------------------------------------------------------------------------

void 
Parameters::
File::write( char* fileName, vec& xValues, vec& y0, vec& y1, vec& y2, vec& y3, vec& y4 )
{
   
   ofstream file;
   file.open( fileName );
   
   for( int i = 0; i < xValues.size(); i++)
   {
      file << xValues( i ) << "\t" << y0( i ) << "\t" << y1( i ) << "\t" 
         <<  y2( i ) << "\t" << y3( i ) << "\t" << y4( i ) << endl; 
   }
   file.close();
   

}

// -----------------------------------------------------------------------------

void 
Parameters::
File::saveChannel( char* fileName, Array<vec>& array, double timeStep,
   double frequencyStep )
{
   string s = string(fileName);
   
   it_file f(s);
   
   cout << "Saving channel" << endl;
   cout << "Rows: " << array.size() << endl;
   cout << "Cols: " << array( 0 ).size() << endl;
   
   f << Name("timeStep") << timeStep;
   f << Name("frequencyStep") << frequencyStep;
   f << Name("array") << array;

}

// -----------------------------------------------------------------------------

void 
Parameters::
File::readChannel( char* fileName, Array<vec>& array, double& timeStep,
   double& frequencyStep )
{
   string s = string(fileName);
   
   it_ifile f(s);
   
   //f >> Name("timeStep") >> timeStep;
   //f >> Name("frequencyStep") >> frequencyStep;
   f >> Name("array") >> array;
}

// -----------------------------------------------------------------------------

void 
Parameters::
File::read( const string fileName, const string varName, int& var )
{
   const char* c;
   c = fileName.c_str(); 
   //cout << c << endl;
   string line;
   ifstream myfile( c );
   size_t found;
   bool foundVar = false;
   
   if( myfile.is_open() )
   {
      while ( !myfile.eof() )
      {
         getline( myfile, line );
         found = line.find( varName );
         //cout << line << endl;
         if( found != string::npos )
         {
            //cout << "string found: " << line << endl;
            found = line.find("=");
            line.erase( 0 , found+  1 );
            stringstream myStream( line );
            myStream >> var;
            foundVar = true;
            //cout << "d: " << var << endl;
         }
         //cout << "1: " << line << endl;
      }
      myfile.close();
      
      if( !foundVar )
      {
         string w = "Variable " + varName + " was not found.";
         it_warning( w );
      }
   }
}

// -----------------------------------------------------------------------------

void 
Parameters::
File::read( const string fileName, const string varName, double& var )
{
   const char* c;
   c = fileName.c_str(); 
   //cout << c << endl;
   string line;
   ifstream myfile( c );
   size_t found;
   bool foundVar = false;
   
   if( myfile.is_open() )
   {
      while ( !myfile.eof() )
      {
         getline( myfile, line );
         found = line.find( varName );
         //cout << line << endl;
         if( found != string::npos )
         {
            //cout << "string found: " << line << endl;
            found = line.find("=");
            line.erase( 0 , found+  1 );
            stringstream myStream( line );
            myStream >> var;
            foundVar = true;
            //cout << "d: " << var << endl;
         }
         //cout << "1: " << line << endl;
      }
      myfile.close();
      
      if( !foundVar )
      {
         string w = "Variable " + varName + " was not found.";
         it_warning( w );
      }
   }
}

// -----------------------------------------------------------------------------


// *****************************************************************************
// Protected Methods
// *****************************************************************************


// *****************************************************************************
// Private Methods
// *****************************************************************************




