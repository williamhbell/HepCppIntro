/* W. H. Bell
** A class providing histograming functions.
*/

#ifndef HISTOGRAM_HH
#define HISTOGRAM_HH

class Histogram {
public:
  Histogram(char *filename, int nbins, float min, float max);
  ~Histogram(void);
  void saveHisto(void); // Save the contents of the histogram.
  void book(float value, float weight);  // Book an entry into the histogram.

private:
  int m_nbins;
  float *m_contents;
  float m_min;
  float m_max;
  char *m_filename;
  float m_binSize;
};

#endif
