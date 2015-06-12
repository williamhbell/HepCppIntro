/* W. H. Bell
** A simple Calorimeter Particle container class
*/

#ifndef CALPARTICLE_H
#define CALPARTICLE_H

#include "Particle.h"

class CalParticle: public Particle {
public:
  CalParticle(int id, double mass, double *p3vec, double eCal);
  double eCal(void);
  double mass(void);

private:
  double m_eCal;
  double m_mass;
};

#endif
