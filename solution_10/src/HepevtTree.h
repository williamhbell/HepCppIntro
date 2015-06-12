
#ifndef HEPEVTTREE_H
#define HEPEVTTREE_H

#include <string>
#include <map>
#include <vector>

// Forward declarations to reduce precompile time.
class TFile;
class TTree;

// HepevtTree class declaration.
class HepevtTree {
  
 public: 
  HepevtTree(std::string outputFile);
  ~HepevtTree();
  int open(void);
  int book(void);
  int fill(void);
  int save(void);
  
 private:
  std::string m_outputFile;
  TFile *m_tfile;
  TTree *m_tree;
  
  int m_nevhep;
  int m_nhep;
  std::vector<int>* m_isthep;
  std::vector<int>* m_idhep;
  std::vector<std::vector<int> >* m_jmohep;
  std::vector<std::vector<int> >* m_jdahep;
  std::vector<std::vector<double> >* m_phep;
  std::vector<std::vector<double> >* m_vhep;
};

#endif
