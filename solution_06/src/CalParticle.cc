/* W. H. Bell
** A simple calorimeter particle container class
*/

#include "CalParticle.h"
#include "Particle.h"

CalParticle::CalParticle (int id,
			  double mass,
			  double *p3vec, 
			  double eCal): Particle(id, p3vec),
					m_mass(mass),
					m_eCal(eCal) {
}

double CalParticle::eCal(void) {
  return m_eCal;
}

double CalParticle::mass(void) {
  return m_mass;
}

