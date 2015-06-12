/* W. H. Bell
** A simple particle container class
*/

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
public:
  Particle (int id, double *p3vec);
  ~Particle();
  int id(void);
  double* p3vec(void);

private:
  double *m_p3vec;
  int m_id;
};

#endif
