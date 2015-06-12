#include "HepevtTree.h"

#include "hepevt.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

//---------------------------------------------------------------------

HepevtTree::HepevtTree(std::string outputFile):
  m_outputFile(outputFile),
  m_tfile(0),
  m_tree(0) {
}

//---------------------------------------------------------------------

HepevtTree::~HepevtTree() {
  if(m_tfile) delete m_tfile;
}

//---------------------------------------------------------------------

int HepevtTree::open(void) {
  m_tfile = new TFile(m_outputFile.c_str(),"RECREATE");
  if(!m_tfile) {
    std::cerr << "Error: could not open root file " << m_outputFile << std::endl;
    return 1;
  }
  
  // Create a new tree
  m_tree = new TTree("hepevt","Pythia Data");
 
  return 0;
}

//---------------------------------------------------------------------

int HepevtTree::save(void) {
  m_tfile->Write();
  
  return 0;
}

//---------------------------------------------------------------------

int HepevtTree::book(void) {
  // Create new objects but do not delete them such that they can be
  // stored in the TTree
  m_isthep = new std::vector<int>();
  m_idhep = new std::vector<int>();
  m_jmohep = new std::vector<std::vector<int> >();
  m_jdahep = new std::vector<std::vector<int> >();
  m_phep = new std::vector<std::vector<double> >();
  m_vhep = new std::vector<std::vector<double> >();

  // Assign the branch addresses
  m_tree->Branch("nevhep",&m_nevhep, "nevhep/I");
  m_tree->Branch("nhep",  &m_nhep, "nhep/I");
  m_tree->Branch("isthep",&m_isthep);
  m_tree->Branch("idhep", &m_idhep);
  m_tree->Branch("jmohep",&m_jmohep);
  m_tree->Branch("jdahep",&m_jdahep);
  m_tree->Branch("phep",  &m_phep);
  m_tree->Branch("vhep",  &m_vhep);

  return 0;
}

//---------------------------------------------------------------------

int HepevtTree::fill() {
  int ipart, j;

  std::vector<int> intComponents(2,0);
  std::vector<double> phepComponents(5,0);
  std::vector<double> vhepComponents(4,0);

  m_nevhep = hepevt_.nevhep;
  m_nhep = hepevt_.nhep;
  
  // Resize the vectors to be the correct size.  This is faster than
  // starting with an empty vector and pushing each element back.
  m_isthep->resize(m_nhep);
  m_idhep->resize(m_nhep);
  m_jmohep->resize(m_nhep);
  m_jdahep->resize(m_nhep);
  m_phep->resize(m_nhep);
  m_vhep->resize(m_nhep);

  // Loop over all particles and fill vectors  
  for(ipart=0;ipart<m_nhep;ipart++) {
    (*m_isthep)[ipart] = hepevt_.isthep[ipart];
    (*m_idhep)[ipart] = hepevt_.idhep[ipart];

    intComponents[0] = hepevt_.jmohep[ipart][0];
    intComponents[1] = hepevt_.jmohep[ipart][1];
    (*m_jmohep)[ipart] = intComponents;

    intComponents[0] = hepevt_.jdahep[ipart][0];
    intComponents[1] = hepevt_.jdahep[ipart][1];
    (*m_jdahep)[ipart] = intComponents;

    for(j=0;j<5;j++) {
      phepComponents[j] = hepevt_.phep[ipart][j];
      if(j<4) {
	vhepComponents[j] = hepevt_.vhep[ipart][j];
      }
    }
    (*m_phep)[ipart] = phepComponents;
    (*m_vhep)[ipart] = vhepComponents;
  }

  // Copy this entry into the TTree;
  m_tree->Fill();

  return 0;
}
