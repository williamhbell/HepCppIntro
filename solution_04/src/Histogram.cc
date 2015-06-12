/* W. H. Bell
** A data container providing some operations on private data member array.
*/

#include "Histogram.h"
#include <iostream>
#include <fstream>

using namespace std;

/** Constructors ********************/
Histogram::Histogram(char *filename, int nbins, float min, float max)
{
  m_filename = filename;
  m_nbins = nbins;
  m_min = min;
  m_max = max;
  m_contents = new float[nbins+2]; // 2 extra bin for underflow and overflow
  for(int i=0;i<(nbins+2);i++) m_contents[i] = 0;
  m_binSize = ((float)(m_max - m_min))/((float)m_nbins);
}

/** Destructor **********************/
Histogram::~Histogram()
{
  delete m_contents;
}

/** Public member functions *********/
void Histogram::book(float value, float weight){
  int i = 0;

  if(value<m_min) { //underflow
    m_contents[m_nbins] += weight;
  }
  else if (value>=m_max) { //overflow
    m_contents[m_nbins] += weight;
  }
  else {
    while(i<m_nbins && value>(i*m_binSize+m_min)) {
	i++;
    }
    m_contents[i-1] += weight;
  }
}

void Histogram::saveHisto(void){
  ofstream file(m_filename);

  if(!file) {
    std::cerr << "Error: could not open " << m_filename << std::endl;
  }
  else {
    cout << "Writing file " << m_filename << std::endl;

    // Under flow
    file << (-0.5*m_binSize + m_min) 
	 << '\t' << m_contents[m_nbins] << std::endl;
    
    for(int i=0;i<m_nbins;i++) {
      file << ((((float)i)+0.5)*m_binSize + m_min) 
	   << '\t' << m_contents[i] << std::endl;
    }
    
    // Overflow
    file << ((((float)m_nbins)+0.5)*m_binSize + m_min) 
	 << '\t' << m_contents[m_nbins] << std::endl;

    file.close();
  }
}
