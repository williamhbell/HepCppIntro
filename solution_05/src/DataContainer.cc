/* W. H. Bell
**
** The solution to problem 2.  (Please try the problem first before
** looking at the solution.)
**
** A data container providing some operations on private data member array.
*/

#include "DataContainer.h"
#include <iostream>

using namespace std;

/** Constructor ********************/
DataContainer::DataContainer(DATA_TYPE *array, int size) {
  m_size = size;
  m_array = new DATA_TYPE[m_size];

  cout << " DataContainer Constructor m_array={";
  for(int i=0;i<m_size;i++) {
    m_array[i] = array[i];
    cout << m_array[i];
    if(i!=m_size-1) cout << ", ";
  }
  cout << "} m_size=" << m_size << endl;
}

/** Copy Constructor ****************/
DataContainer::DataContainer(const DataContainer& dataContainer) {
  cout << " DataContainer Copy Constructor" << endl;

  m_size = dataContainer.m_size;
  m_array = new DATA_TYPE[m_size];

  for(int i=0;i<m_size;i++) {
    m_array[i] = dataContainer.m_array[i];
  }
}

/** Destructor **********************/
DataContainer::~DataContainer() {
  cout << " DataContainer Destructor" << endl;
  delete m_array;
}

/** Public member functions *********/
DATA_TYPE* DataContainer::getArray(void){
  DATA_TYPE *array = new DATA_TYPE[m_size];

  for(int i=0;i<m_size;i++) {
    array[i] = m_array[i];
  }

  return array;
}

int DataContainer::getSize(void){
  return m_size;
}

void DataContainer::printArray(void){
  for(int i=0;i<m_size;i++) {
    cout << "array[" << i << "]=" << m_array[i] << endl;
  }
}

DataContainer DataContainer::operator+(DataContainer dataContainer) {
  int size = minSize(dataContainer);
  DATA_TYPE resultant[size];

  for (int i=0;i<size;i++) resultant[i] = dataContainer.m_array[i] + m_array[i];
  return DataContainer(resultant,size);
}

DataContainer DataContainer::operator*(DataContainer dataContainer) {
  int size = minSize(dataContainer);
  DATA_TYPE resultant[size];

  for (int i=0;i<size;i++) resultant[i] = dataContainer.m_array[i] * m_array[i];
  return DataContainer(resultant,size);
}

DataContainer DataContainer::operator/(DataContainer dataContainer) {
  int size = minSize(dataContainer);
  DATA_TYPE resultant[size];

  for (int i=0;i<size;i++) resultant[i] = dataContainer.m_array[i] / m_array[i];
  return DataContainer(resultant,size);
}

/** Private member functions *********/
int DataContainer::minSize(DataContainer dataContainer) {
  if(dataContainer.m_size>m_size) {
    return m_size;
  }
  else {
    return dataContainer.m_size;
  }
}
