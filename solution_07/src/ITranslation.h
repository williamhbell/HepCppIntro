/*
** W. H. Bell
**
** An interface of translations on 2D space points.
*/
#ifndef ITRANSLATION_HH
#define ITRANSLATION_HH

class ITranslation {
 public:
  virtual void translate(double *vec) = 0;
  virtual void reverse(double *vec) = 0;
};

#endif
