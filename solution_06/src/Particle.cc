/* W. H. Bell
** A simple particle container class
*/

#include "Particle.h"
#include <iostream>

Particle::Particle (int id, double *p3vec): m_id(id) {
  m_p3vec = new double[3];

  for(int i=0;i<3;i++) {
    m_p3vec[i] = p3vec[i];
  }
}

Particle::~Particle() {
  std::cout << "~Particle() deleting m_p3vec" << std::endl;  
  delete m_p3vec;
}

int Particle::id(void) {
  return m_id;
}

/**
 * Return a copy of the private datamember m_p3vec
 */
double* Particle::p3vec(void) {
  double *p3vec = new double[3];

  for(int i=0;i<3;i++) {
    p3vec[i] = m_p3vec[i];
  }

  return p3vec;
}

