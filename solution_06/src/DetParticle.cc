/* W. H. Bell
** A simple detector particle container class
*/

#include "DetParticle.h"
#include "Particle.h"

DetParticle::DetParticle (int id, 
			  double *p3vec, 
			  int trackId): Particle(id, p3vec), 
					m_trackId(trackId) {
}

int DetParticle::trackId(void) {
  return m_trackId;
}

