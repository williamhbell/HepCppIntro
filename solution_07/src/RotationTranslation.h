#ifndef ROTATION_TRANSLATION_HH
#define ROTATION_TRANSLATION_HH

#include "ITranslation.h"

class RotationTranslation : public ITranslation {
 public:
  RotationTranslation(double theta);

  virtual void translate(double *vec); // array with 2 elements
  virtual void reverse(double *vec); // array with 2 elements

 private:
  double m_theta;
};

#endif
