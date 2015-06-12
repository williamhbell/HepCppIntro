/* W. H. Bell
**
** A program to 'encrypt' files by using a binary mask.  The program
** can either encrypt or decrypt files.
** 
** Two exclusive or operations cancel.  This can be proven by example:
** 
**   101010     001110
** ^ 100100   ^ 100100
** --------   --------
**   001110     101010
*/

#include <iostream>
#include <cstring>

void usage(char *);

int main(int argc, char *argv[]) {
  int mask = 0xA3;
  char c;

  if(argc<2 || argc>3) {
    usage(argv[0]);
    return 0;
  } 

  if(strcmp(argv[1],"-e")) {
    while ((c=std::cin.get()) != EOF) {
      c ^= mask;
      std::cout << c;
    }
  }
  else if(strcmp(argv[1],"-d")) {
    while ((c=std::cin.get()) != EOF) {
      c ^= mask;
      std::cout << c;
    } 
  }
  else {
    std::cout << "Error: unknown flag \'" << argv[1] << "\'" << std::endl;
    usage(argv[0]);
  }

  return 0;
}

void usage(char *exename) {
  std::cout << " Usage " << exename << " <-e/-d>" << std::endl;
  std::cout << " where  -e => encode & -d => decode" << std::endl;
}
