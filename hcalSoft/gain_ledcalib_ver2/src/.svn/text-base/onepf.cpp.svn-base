/**************************************************************************
to fit a spectrum just load and compile the macro in root:

.L MPF.C+

then use

MPF("nameoftherootfile",numberofpeaks,resolution,sigma,threshold)

plots the fit results and prints to screen the gain (in QDC channels)

**************************************************************************/


#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>
#include <TSystem.h>
#include <TSpectrum.h>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TColor.h>
#include <TCanvas.h>
#include <TPaveStats.h>
#include <TPaveText.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TStyle.h>

using namespace std;


Double_t OneGaus(Double_t *x, Double_t *par){//multi peak gaussian function
 
 //
  Double_t arg = 0;
  if (par[2] != 0) arg = (x[0] - par[1])/par[2];
  
  Double_t fitval = par[0]*TMath::Exp(-0.5*arg*arg);
  return fitval;

}
/**********************************************************************/


/**********************************************************************/
TF1* OnePFit(TH1F *peaks){

  //fitAll = MultiPFit(histoAll, 6, 1, 5, 0.15);

  //nOfpeaks -  sets the max n. of peaks stored
  //res -  resolution between peaks (min. value 1)
  //sigmapeak - sigma
  // threshold - peaks with amplitude less than threshold*highest_peak are discarded
  
  /*************finding peaks*****************/
  TSpectrum * spectrum = new TSpectrum(3,1);//searching for peaks
  spectrum->Search(peaks,5,"",0.15);

  Int_t nPeaks = spectrum->GetNPeaks();

  Float_t * x = new Float_t[nPeaks];
  Float_t * y = new Float_t[nPeaks];

  x = spectrum->GetPositionX();//getting peak positions
  y = spectrum->GetPositionY();//getting peak positions

  Int_t lookup[nPeaks];//creating a lookup table to order peaks
  Float_t dummyx[nPeaks];
  Float_t min = 0;
  for(Int_t i=0; i<nPeaks; i++){
    dummyx[i] = y[i];
  }
  for(Int_t j=0; j<nPeaks; j++){//ordering peaks
    for(Int_t i=0; i<nPeaks; i++){
      if(dummyx[i]>min){
	min = dummyx[i];
	lookup[j]=i;
      }
    }
    min = 0;
    dummyx[lookup[j]]=-1;
  }

  TF1 * fitpeak = new TF1("fitpeak",OneGaus,x[lookup[0]]-10,x[lookup[0]]+10,3);
  fitpeak->SetNpx(1000);
  fitpeak->SetLineColor(kBlue);

    /******setting initial parameters*********/
  fitpeak->SetParameter(0,y[lookup[0]]);//amplitude
  fitpeak->SetParLimits(0,0.5*y[lookup[0]],1.5*y[lookup[0]]);
  fitpeak->SetParameter(1,x[lookup[0]]);//mean
  fitpeak->SetParLimits(1,0.5*x[lookup[0]],1.5*x[lookup[0]]);
  fitpeak->SetParameter(2,15);//width


  peaks->Fit(fitpeak,"R","",x[lookup[0]]-10,x[lookup[0]]+10);
  fitpeak->SetRange(x[lookup[0]]-15,x[lookup[0]]+15);

  delete[] x;
  delete[] y;
  
  return fitpeak;

}

/*******************************************************/









