/* W. H. Bell
**
** The solution to problem 2.  (Please try the problem first before
** looking at the solution.)
**
** A data container providing some operations on private data member array.
*/

#ifndef DATA_CONTAINER_HH
#define DATA_CONTAINER_HH

#define DATA_TYPE float

class DataContainer {
public:
  DataContainer(DATA_TYPE *array, int);
  DataContainer(const DataContainer&);  // Copy constructor
  ~DataContainer(void);
  DATA_TYPE* getArray(void);
  int getSize(void);
  void printArray(void);
  DataContainer operator+(DataContainer);
  DataContainer operator*(DataContainer);
  DataContainer operator/(DataContainer);


private:
  int minSize(DataContainer);
  DATA_TYPE *m_array;
  int m_size;
};

#endif
