/* W. H. Bell
**
** A program to read a particle configuration file into memory and
** then print its contents.
**
** There are much more tidy ways of doing this with dynamic memory
** allocation.
**
*/

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_LINE_LENGTH 250
#define MAX_FILE_LENGTH 30
#define MAX_WORD_LENGTH 15

using namespace std;

void usage(char[]);
void readfile(char[]);

int main(int argc, char *argv[]) {
  if(argc!=2) {
    usage(argv[0]);
  }
  else {
    readfile(argv[1]);
  }

  return 0;
}

void usage(char exeName[]) {
  cerr << " Usage: " << exeName << " <configuration file>" << endl;
}

void readfile(char fileName[]) {
  char str[MAX_LINE_LENGTH];
  char tmpstr[MAX_WORD_LENGTH];
  ifstream file(fileName);
  int lineLength,i,j,column,line;

  char names[MAX_FILE_LENGTH][MAX_WORD_LENGTH];
  char idCodes[MAX_FILE_LENGTH][MAX_WORD_LENGTH];
  char masses[MAX_FILE_LENGTH][MAX_WORD_LENGTH];
  char charges[MAX_FILE_LENGTH][MAX_WORD_LENGTH];
  char spins[MAX_FILE_LENGTH][MAX_WORD_LENGTH];

  if(!file) {
    cerr << "Error: could not open " << fileName << endl;
  }
  else {
    cout << "Reading file " << fileName << endl;

    line=0;
    while(!file.eof() && line<MAX_FILE_LENGTH) {
      file.getline(str,MAX_LINE_LENGTH);
      lineLength = strlen(str);

      if(str[0]!='#') {
	i=0;
	column=0;
	while(i<lineLength && i<MAX_LINE_LENGTH) {
	  while(str[i]==' ' && i<lineLength && i<MAX_LINE_LENGTH) {
	    i++;
	  }
	  j=0;
	  while(str[i]!=' ' && str[i]!='\t' && 
		i<lineLength && i<MAX_LINE_LENGTH && j<MAX_WORD_LENGTH) {
	    tmpstr[j] = str[i];
	    i++;
	    j++;
	  }
	  tmpstr[j] = '\0';
	  
	  switch (column) {
	  case 0 : strcpy(names[line],tmpstr); break;
	  case 1 : strcpy(idCodes[line],tmpstr); break;
	  case 2 : strcpy(masses[line],tmpstr); break;
	  case 3 : strcpy(charges[line],tmpstr); break;
	  case 4 : strcpy(spins[line],tmpstr); break;
	  }

	  column++;
	}
	
	line++;
      }
    }
    file.close();

    cout << "Names, ID Codes, Masses, Charges, Spins" << endl;
    for(i=0;i<(line-1);i++) {
      cout << names[i] << ','
	   << idCodes[i] << ','
	   << masses[i] << ','
	   << charges[i] << ','
	   << spins[i] << endl;
    }
  }
}
