//============================================================================
// Name        : pedestalshift_FE.cpp
// Author      : ohartbri
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <boost/lexical_cast.hpp>
#include "GainRunFolderParser.h"
#include "CalibSpectrum.h"
#include "PedestalCalibrator.h"
#include "style.h"
//#include "mpf.h"

#include <TApplication.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TBranch.h>
#include <TVector.h>
#include <TMath.h>

#include <TH2.h>

#include <iostream>
#include <fstream>
#include <sstream>
            
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <string>

#include <TCanvas.h>
#include <TPad.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TSpectrum.h>
#include <TProfile.h>

#include <TLegend.h>
#include <TText.h>
#include <TPaveText.h>
#include <unistd.h>

bool takePedestal = true;

int main(int argv, char **argc) {
   
  if(argv < 3)
    {
      cout << "Please provide input root file : ./ADCdistribution_properties FILE y/n" << endl;
      return -1;
    }
  
  cout << "******************************************************" << endl;
  cout << "                                                      " << endl;
  cout << "              Files run with ADC HG-LG?               " << endl;
  cout << "                                                      " << endl;
  cout << "******************************************************" << endl;
    
  string answer = "y";
  bool isHGLG = true;
  cout << "y or n? (Default : y)" << endl;

  bool batch_mode = false;

  if(batch_mode)
    cin >> answer;
  else
    answer = argc[2];
  
  if(answer == "n")
    {
      isHGLG = false;
    }
    
  stylemacro();
    
  string PATH = argc[1];
    
  string PATH_PEDCALIB = "../../../output_pedestal_test0/pedestal_offsets_in.tsv";
  string PATH_OUT = "../../../output_holdscan/";

  stringstream out;
 
  map<int, map<int, vector<CalibSpectrum* > > > histos;
    
  int BunchXID, CycleNr, ChipID2, EvtNr, chn, TDC, ADC, Hit_Bit, Gain_Bit;
  PedestalCalibrator b(PATH_PEDCALIB);
  GainRunFolderParser g(PATH);
  vector<RunInfo> v = g.getRunInfos();
    
	
  for (vector<RunInfo>::iterator thisRun = v.begin(); thisRun != v.end(); thisRun++){
        
    string vcalib = boost::lexical_cast<std::string>(thisRun->vCalib);
    TFile* output_file = new TFile((PATH_OUT+"Plots_Hold"+vcalib+".root").c_str(),"RECREATE");
    
    cout << endl <<"current path: " << thisRun->filePath << " Hold Value:" << thisRun->vCalib << endl;
    cout << "output path: " << TString::Format("%sADCchecks_%d.tsv",PATH_OUT.c_str(), thisRun->vCalib).Data() << endl;
        
    histos[thisRun->vCalib]; //makes sure that histos[thisRun->vCalib] exists.
        
    TFile* myFile = TFile::Open(thisRun->filePath.c_str());
        
    TTree* myTree = (TTree*)myFile->Get("tree"); //see above
        
        
    myTree->SetBranchAddress("BunchXID", &BunchXID);
    myTree->SetBranchAddress("CycleNr", &CycleNr);
    myTree->SetBranchAddress("ChipID2", &ChipID2);
    myTree->SetBranchAddress("EvtNr", &EvtNr);
    myTree->SetBranchAddress("chn", &chn);
    myTree->SetBranchAddress("TDC", &TDC);
    myTree->SetBranchAddress("ADC", &ADC);
    myTree->SetBranchAddress("Hit_Bit", &Hit_Bit);
    myTree->SetBranchAddress("Gain_Bit", &Gain_Bit);
        
       
    output_file->cd();
        
        
    for (int entryID=0; entryID<myTree->GetEntries(); entryID++){
            
      myTree->GetEntry(entryID);
          
      if (CycleNr<=1){
	continue;
      }
      if (entryID%100000 == 1){
	cout << "." << flush;
      }
                       
            
      //generate new histos if necessary:
      if (histos[thisRun->vCalib].count(ChipID2) == 0){
                
	histos[thisRun->vCalib][ChipID2] = vector<CalibSpectrum*>(36);
	for (int i=0; i<36; i++){
	  histos[thisRun->vCalib][ChipID2][i] = new CalibSpectrum(ChipID2, i, thisRun->vCalib);
	}
                
	cout << "creating ChipID " << ChipID2 << flush << endl;
      }
            
      output_file->cd();
           
      int VarToFill = ADC;
      if (isHGLG) VarToFill = TDC;
            
            
      if (VarToFill > 0 && Gain_Bit == 1 ){
	if (takePedestal)
	  {
	    histos[thisRun->vCalib][ChipID2][chn]->Fill(VarToFill+b.getOffset(ChipID2, chn, EvtNr));//change this because of HGLG files
	  }
	else
	  histos[thisRun->vCalib][ChipID2][chn]->Fill(VarToFill);
      }
    }
        
    int cntTotal(0), cntChn(0);
    fstream file_out;
               
    file_out.open(TString::Format("%sADCchecks_%d.tsv",PATH_OUT.c_str(), thisRun->vCalib).Data(),ios::out);
    //out <<"fit output:" << endl;
    for (map<int, vector<CalibSpectrum* > >::iterator  itChips = histos[thisRun->vCalib].begin(); itChips!=histos[thisRun->vCalib].end(); itChips++){
      cntChn = -1;
      for (vector<CalibSpectrum*>::iterator it = itChips->second.begin(); it!=itChips->second.end(); it++){
                
	//counters 
	// cntChn is needed to associate the fited gain value to the proper channel in the chip, the information is stored in the gainfit_*.tsv file)
	cntChn++;

	//Reject spectra that have too high signal (>3000)
	double ADCMean = (*it)->histoAll->GetMean(1);                
	double ADCWidth = (*it)->histoAll->GetStdDev(1);                
	((*it)->histoAll)->Write();
	//counters 
	// cntTotal is only used for debuging and screen messages, counts fo the number of evaluated histograms
	cntTotal ++;

	//Reject weird chipID
	if ( (itChips->first < 100) || (itChips->first > 300) ) {
	  cout<<""<<endl;
	  cout<< " ERROR, this chip number "<< itChips->first<< " does is classified as not existing, check carefuylly !!!!              !!!!"<<endl;
	  cout<<""<<endl;
	  continue;
	}              
      
	double gainFFT(0);
        gainFFT = (*it)->FFTGain();

	//vcalib is, in this case, the hold value (extracted from the root file name)
	file_out << thisRun->vCalib <<"\t"<< itChips->first << "\t" << cntChn << "\t" << ADCMean << "\t" << ADCWidth << "\t" << gainFFT<<endl;

        
      }
    }

    out << "Hold value: " << thisRun->vCalib << " total: " << cntTotal  << endl;
    file_out.close();
    output_file->Write();
    
  }
  
  cout << out.str();
  
  return 0;
}

