/* W. H. Bell
** A simple Detector Particle container class
*/

#ifndef DETPARTICLE_H
#define DETPARTICLE_H

#include "Particle.h"

class DetParticle: public Particle {
public:
  DetParticle(int id, double *p3vec, int trackId);
  int trackId(void);

private:
  int m_trackId;
};

#endif
