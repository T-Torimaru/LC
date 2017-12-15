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
#include "mpf.h"

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

bool ToCheckSpectrum = true;
bool ToCheckMean = true;
bool takePedestal = true;

bool CheckSpectrum(TSpectrum *spec){
  bool spectrumIsOK = true;
    
  Int_t nPeaks = spec->GetNPeaks();
    
  //cout << "CheckSpectrum: nPeaks = " << nPeaks << endl;
    
  if (nPeaks<=2) return false;
    
  Float_t * x     = new Float_t[nPeaks];
  Float_t *diffX  = new Float_t[nPeaks];
  Float_t *sigmaX = new Float_t[nPeaks];
    
  x = spec->GetPositionX();//getting peak positions
    
  Int_t lookup[nPeaks];//creating a lookup table to order peaks
  Float_t dummyx[nPeaks];
  Float_t max = 20000;
  for(Int_t i=0; i<nPeaks; i++){
    dummyx[i] = x[i];
  }
  for(Int_t j=0; j<nPeaks; j++){//ordering peaks
    for(Int_t i=0; i<nPeaks; i++){
      if(dummyx[i]<max){
	max = dummyx[i];
	lookup[j]=i;
      }
    }
    max = 20000;
    dummyx[lookup[j]]=30000;
  }
    
  for (int ix = 0; ix < nPeaks; ix++){
    cout << "peak " << ix << " x " << x[lookup[ix]] << endl;
  }
    
  diffX[0]  = 0;
  sigmaX[0] = 0;
  for (int ix = 1; ix < nPeaks; ix++){
    cout << "x[" << ix <<"] = " << x[lookup[ix]] << " x[" << ix-1 <<"] = " << x[lookup[ix-1]] << endl;
    diffX[ix]  = x[lookup[ix]] - x[lookup[ix-1]];
    sigmaX[ix] = sqrt(diffX[ix]);
        
    cout << "ix " << ix
	 << " diffX " << diffX[ix] << " sigmaX " << sigmaX[ix]
	 << " diffX-1: " << diffX[ix-1] << " sigmaX-1 : " << sigmaX[ix-1] << endl;
        
    if (ix<2){
      cout << "first peak: verification not started yet" << endl;
      continue;
    }
    if ( (diffX[ix] < diffX[ix-1]-2*sigmaX[ix-1]) || (diffX[ix] > diffX[ix-1]+2*sigmaX[ix-1]) ){
      cout << "distance  between peak " << ix << " and peak " << ix-1
	   << " is too different from the distance between peak " << ix-1 << " and peak " << ix-2 <<endl;
      spectrumIsOK = false;
    }
  }
    
  return spectrumIsOK;

  delete x;
  delete diffX;
  delete sigmaX;
}


int main(int argv, char **argc) {
   
  if(argv < 3)
    {
      cout << "Please provide input root file : ./gain_ledcalib FILE y/n" << endl;
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

  string PATH_PEDCALIB = "/home/calice/Commissioning/SM_2/Gain_650fF/output_pedestal/pedestal_offsets_in.tsv";
    
  string PATH_OUT = "/home/calice/Commissioning/SM_2/Gain_650fF/output_gain/";

  stringstream out;
 
  TH1D *hChiSquare = new TH1D("hChiSquare",";Chisquare over ndf of SPS fit;entries",100,0,10);
  TH1D *hFitOverFFT = new TH1D("hFitoverFFT",";Fit gain over FFT gain;entries",200,0.5,1.5);
  TH1D *hFitMinusFFT = new TH1D("hFitminusFFT",";Fit gain minus FFT gain;entries",1000,-50,50);
  TH2D *hFit2FFT = new TH2D("hFit2FFT",";Fit gain;FFT gain",500,0,50,500,0,50);
    
  map<int, map<int, vector<CalibSpectrum* > > > histos;
    
  int BunchXID, CycleNr, ChipID2, EvtNr, chn, TDC, ADC, Hit_Bit, Gain_Bit;
  PedestalCalibrator b(PATH_PEDCALIB);

  cout << "Gain Run folder parser" << endl;
  GainRunFolderParser g(PATH);

  cout << "RunInfo" << endl;
  vector<RunInfo> v = g.getRunInfos();
    
  fstream fListHighSignal;
  fListHighSignal.open(TString::Format("%slistHighSignalSpectra.txt",PATH_OUT.c_str()).Data(),ios::out);
	
  for (vector<RunInfo>::iterator thisRun = v.begin(); thisRun != v.end(); thisRun++){
        
    string vcalib = boost::lexical_cast<std::string>(thisRun->vCalib);
    TFile* output_file = new TFile((PATH_OUT+"Plots_comp"+vcalib+".root").c_str(),"RECREATE");
    
    //Lan
    TFile *fTest = new TFile((PATH_OUT+"Test"+vcalib+".root").c_str(),"RECREATE");
    TTree *tTest = new TTree("Chi2info","Chi2info");
    float b_chi2 = 0,
      b_chip = 0, b_chan = 0, b_Vcalib = 0;
    tTest->Branch("chi2",   &b_chi2);
    tTest->Branch("chip",   &b_chip);
    tTest->Branch("chan",   &b_chan);
    tTest->Branch("Vcalib", &b_Vcalib);

    TFile *fHighSignal = new TFile((PATH_OUT+"HighSignal"+vcalib+".root").c_str(),"RECREATE");
    cout << endl <<"current path: " << thisRun->filePath << " vcalib:" << thisRun->vCalib << endl;
    cout << "output path: " << TString::Format("%sgainfits_%d.tsv",PATH_OUT.c_str(), thisRun->vCalib).Data() << endl;
        
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
	//GainHistoGenerator::getHistos(ChipID2, thisRun->vCalib, histosRun->at(ChipID2));
      }
            
            
      int VarToFill = ADC;
      if (isHGLG) VarToFill = TDC;
            
            
      //cout << "VCalib: " << thisRun->vCalib <<  " Filling histo TDC/ADC " << TDC << " Chip " << ChipID2 << " chn " << chn << " Evt " << EvtNr << endl;
            
      if (VarToFill > 0 && Gain_Bit == 1){
	if (takePedestal)
	  {
	    histos[thisRun->vCalib][ChipID2][chn]->Fill(VarToFill+b.getOffset(ChipID2, chn, EvtNr));//change this because of HGLG files
	  }
	else
	  histos[thisRun->vCalib][ChipID2][chn]->Fill(VarToFill);
      }
    }
        
    int cntTotal(0), cntFitted(0), cntChn(0);
    fstream file_out;
     
    file_out.open(TString::Format("%sgainfits_%d.tsv",PATH_OUT.c_str(), thisRun->vCalib).Data(),ios::out);


    for (map<int, vector<CalibSpectrum* > >::iterator  itChips = histos[thisRun->vCalib].begin(); itChips!=histos[thisRun->vCalib].end(); itChips++){
      cntChn = -1;
      for (vector<CalibSpectrum*>::iterator it = itChips->second.begin(); it!=itChips->second.end(); it++){
                          
	//counters 
	// cntChn is needed to associate the fited gain value to the proper channel in the chip, the information is stored in the gainfit_*.tsv file)
	cntChn++;
	cout << "Lan print-out: chip " << itChips->first << " chan " << cntChn << " Vcalib " << thisRun->vCalib << endl;
	cout<<	(*it)->histoAll->GetMean(1)<<" -----------------------------------------------------------------------------------"<<endl;

	//Reject spectra that have too high signal (>3000)
	double ADCMean = (*it)->histoAll->GetMean(1);                

	if ( ADCMean > 3000 ) {
	  continue;
	}
	  
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
               
      	double gainFit(-1), gainErr(-1), gainFFT(0);
                
               
	gainFFT = (*it)->FFTGain();
	//To check the distance between the peaks, it is better to just look at small number of peaks around the mean
	TSpectrum * spectrum = new TSpectrum(5,2);//searching for peaks
	spectrum->Search((*it)->histoAll,2,"",0.10);
	Int_t nPeaks = spectrum->GetNPeaks();
	cout << "nPeaks CheckSpectrum = " << nPeaks << endl;
                
	//Check if the initial spectrum is okay
	bool SpectrumIsOK = CheckSpectrum(spectrum);
	if ( ToCheckSpectrum && (!SpectrumIsOK) ) {
	  fHighSignal->cd();
	  ((*it)->histoAll)->Write();
	  fListHighSignal << thisRun->vCalib  << "\t" << itChips->first << "\t" << cntChn << endl;
	  //cntChn++;
	  continue;
	}

	delete spectrum;

	output_file->cd();
                
	//To check mean value condition, it is better to see if it is the case of having many peaks or not
	TSpectrum * spectrumToCheckMean = new TSpectrum(10,2);//searching for peaks
	spectrumToCheckMean->Search((*it)->histoAll,2,"",0.10);
	Int_t nPeaksToCheckMean = spectrumToCheckMean->GetNPeaks();
                
	cout << "nPeaksToCheckMean = " << nPeaksToCheckMean << endl;
                
	if ( ToCheckMean && nPeaksToCheckMean<8 ){//if the number of peaks < 8: ask for the mean condition
	  if ((*it)->histoAll->GetMean(1)<(b.getPositionTotal(itChips->first, cntChn)+5*30)
	      //&& (*it)->histoAll->GetMean(1)>(b.getPositionTotal(itChips->first, cntChn)+2*b.getWidthTotal(itChips->first, cntChn))
	      ){
	    cout << "nPeaks < 8: Condition satisfied" << endl;
	    std::pair<double,double> gainInfo = (*it)->FitGain(thisRun->vCalib);
	    gainFit = gainInfo.first;
	    gainErr = gainInfo.second;
	    hChiSquare->Fill((*it)->ChiSquareNDF);
	    b_chi2 = (*it)->ChiSquareNDF;
	    b_chip = itChips->first;
	    b_chan = cntChn;
	    b_Vcalib = thisRun->vCalib;
	    tTest->Fill();
	    //fHighSignal->cd();
	    ((*it)->histoAll)->Write();
	  } else {
	    cout << "nPeaks < 8: Mean condition not satisfied ==> No FitGain" << endl;
	    //fHighSignal->cd();
	    ((*it)->histoAll)->Write();
	    fListHighSignal << thisRun->vCalib  << "\t" << itChips->first << "\t" << cntChn << endl;
	  }
	} else {//if the number of peaks >= 8: drop the mean condition
	  cout << "nPeaks >= 8: No need to compare mean values" << endl;
	  std::pair<double,double> gainInfo = (*it)->FitGain(thisRun->vCalib);
	  gainFit = gainInfo.first;
	  gainErr = gainInfo.second;
	  hChiSquare->Fill((*it)->ChiSquareNDF);
	  b_chi2 = (*it)->ChiSquareNDF;
	  b_chip = itChips->first;
	  b_chan = cntChn;
	  b_Vcalib = thisRun->vCalib;
	  tTest->Fill();
	  //fHighSignal->cd();
	  ((*it)->histoAll)->Write();
	}

	delete spectrumToCheckMean;
                
	cout << "Result: gainFit = " << gainFit << " gainFFT = " << gainFFT << endl;
	if (gainFit <= 0){
	  //delete *it;
	} else {
	  file_out << itChips->first << "\t" << cntChn << "\t" << gainFit << "\t" << gainFFT << "\t" << gainErr << endl;
	  cntFitted += 1;
                    
	  cout << "cntFitted = " << cntFitted << endl;
                    
	  hFit2FFT->Fill(gainFit, gainFFT);
	  hFitOverFFT->Fill(gainFit/gainFFT);
	  hFitMinusFFT->Fill(gainFit-gainFFT);
                    
	  //	  cout << "hehe" << endl;
	}
	(*it)->Delete();
      }
      cout << "end of chip loop" << endl;
    }
        
    out << "vcalib: " << thisRun->vCalib << " total: " << cntTotal << " fitted: " << cntFitted << endl;
    file_out.close();

    myFile->Close();
    output_file->Write();
    output_file->Close();
    
    fTest->cd();
    tTest->Write();
    fTest->Close();
    
    fHighSignal->Close();
  }
    
  fListHighSignal.close();   
  cout << out.str();
    
  return 0;
}

