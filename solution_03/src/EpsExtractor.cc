/* W. H. Bell
**
** A program to extract eps files from a ps document leaving the original
** document unchanged.
**
*/

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_LINE_LENGTH 250

void usage(char *);

int main(int argc, char *argv[]) {
  char line[MAX_LINE_LENGTH];
  char *filename;
  char beginDocument[]="%%BeginDocument: ";
  char endDocument[]="%%EndDocument";

  if(argc<2 || argc>3) {
    usage(argv[0]);
    return 0;
  } 

  std::ifstream file(argv[1]);

  if(!file) {
    std::cerr << "Error: could not open " << argv[1] << std::endl;
  }
  else {
    // Must initialise otherwise might be not NULL.
    std::ofstream *outputFile = NULL;

    while(!file.eof()) {
      file.getline(line,MAX_LINE_LENGTH);

      if((filename=strstr(line,beginDocument))!=NULL) {
	filename += strlen(beginDocument);
	outputFile =  new std::ofstream(filename);
      }
      else if(strstr(line,endDocument)!=NULL) {
	outputFile->close();
      }
      else {
	if(outputFile){
	  (*outputFile) << line << std::endl; 
	}
      }
    }
    file.close();
  }
  return 0;
}

void usage(char *exename) {
  std::cout << " Usage " << exename << " <filename>" << std::endl;
}
