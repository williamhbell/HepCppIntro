#include "RotationTranslation.h"
#include <cmath>

RotationTranslation::RotationTranslation(double theta) {
  m_theta = theta;
}

void RotationTranslation::translate(double *vec) {
  double x_prime, y_prime;
  x_prime = vec[0]*cos(m_theta)-vec[1]*sin(m_theta);
  y_prime = vec[1]*cos(m_theta)+vec[0]*sin(m_theta);
  vec[0] = x_prime;
  vec[1] = y_prime;
}

void RotationTranslation::reverse(double *vec) {
  double x_prime, y_prime;
  x_prime = vec[0]*cos(-m_theta)-vec[1]*sin(-m_theta);
  y_prime = vec[1]*cos(-m_theta)+vec[0]*sin(-m_theta);
  vec[0] = x_prime;
  vec[1] = y_prime;
}
