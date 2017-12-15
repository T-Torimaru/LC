#ifndef HOLDSCAN_H_
#define HOLDSCAN_H_

#include <string>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TString.h>
#include <TPad.h>
#include <TMath.h>
#include <TAxis.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TF1.h>
#include <TMinuit.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TVirtualFitter.h>
#include <TStyle.h>
#include <TTree.h>
#include <TList.h>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TDirectory.h>
#include <TSpectrum.h>
#include <TString.h>
#include <TMath.h>
#include <TF1.h>
#include <TVirtualFFT.h>

using namespace std;

void ProcessFile(string directory, string PATH_OUT);

vector<string> GetListofFiles(string directory);

void FindPeak(TH1* hist,Float_t *res);

float* GainFromFFT(TH1* hist);

string stripname(string rootfile);

void MakeGraphs(int file_nb, int *hold_value);

map<int, map<int, vector<TH1F* > > > histos;//map of histogram per chip per chn
map<int, vector<TGraph* > > graph_mean;//map of graph per chip
map<int, vector<TGraph* > > graph_width;//map of graph per chip
map<int, vector<TGraph* > > graph_gain;//map of graph per chip
map<int , TMultiGraph* > multigraph_mean;//map of multigraph per chip
map<int , TMultiGraph* > multigraph_width;//map of multigraph per chip 
map<int , TMultiGraph* > multigraph_gain;//map of multigraph per chip 

TFile* output_file;
TDirectory *histo;
TDirectory *tgraph;

#endif
