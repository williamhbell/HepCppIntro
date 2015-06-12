/* W. H. Bell
** A program to illustrate some of the uses of algorithms.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int>, char []);

int main() {
  // Fill the vector with sequential numbers from 0 to 100
  std::vector<int> numbers;
  int i;
  for(i=0;i<=100;i++) {
    numbers.push_back(i);
  }

  // Print the contents before shuffling
  std::cout << "Before shuffling" << std::endl;
  printVector(numbers,"numbers");
  std::cout << std::endl;

  // Shuffle the vector
  std::vector<int>::iterator first;
  std::vector<int>::iterator last;
  first = numbers.begin();
  last = numbers.end();
  std::random_shuffle(first, last);
  
  // Print the contents after shuffling
  std::cout << "After shuffling" << std::endl;
  printVector(numbers,"numbers");
  std::cout << std::endl;

  // Find 7 within the vector.
  first = numbers.begin();
  last = numbers.end();
  std::vector<int>::iterator itr = numbers.begin();
  i=0;
  int num = 7;
  while (*itr != num && itr != numbers.end()) {
    i++;
    itr++;
  }
  if(*itr == num) {
    std::cout << "Found " << num << " in vector element " << i << std::endl;
  }
  else {
    std::cout << num << "was not found" << std::endl;
  }

  return 0;
}

void printVector(std::vector<int> vec, char name[]) {
  std::vector<int>::iterator itr;

  std::cout << name <<"={";
  for(itr=vec.begin();itr != vec.end(); itr++) {
    std::cout << *itr;
    if((itr+1) != vec.end()) std::cout << ",";
  }
  std::cout << "}" << std::endl;
}
