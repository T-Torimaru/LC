#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>

#include <TROOT.h>
#include <TF1.h>
#include <TH1F.h>
#include <TSystem.h>
#include "TSpectrum.h"
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
/**************************************************************************
to fit a spectrum just load and compile the macro in root:

.L MPF.C+

then use

MPF("nameoftherootfile",numberofpeaks,resolution,sigma,threshold)

plots the fit results and prints to screen the gain (in QDC channels)

**************************************************************************/




using namespace std;


Double_t MultiGaus(Double_t *x, Double_t *par){//multi peak gaussian function
  //sum of npeaks gaussians
  //peak distance is a fit parameter
  //
  Double_t xx = x[0];
  Double_t npeaks = par[0];//number of peaks
  Double_t gain = par[1];//gain
  Double_t p0 = par[2];//first peak position

  Double_t mg=0;
  for(Int_t i=0; i<npeaks; i++){

    mg += par[2*i+3]*TMath::Gaus(xx,gain*i+p0,par[2*i+4]);
  }
  return mg;
}
/**********************************************************************/


/**********************************************************************/
TF1 * MultiPFit(TH1F *  peaks, Int_t nOfpeaks, Float_t res,Float_t sigmapeak,Float_t threshold){

  //nOfpeaks -  sets the max n. of peaks stored
  //res -  resolution between peaks (min. value 1)
  //sigmapeak - sigma
  // threshold - peaks with amplitude less than threshold*highest_peak are discarded
  
  /*************finding peaks*****************/
  TSpectrum * spectrum = new TSpectrum(nOfpeaks,res);//searching for peaks
  spectrum->Search(peaks,sigmapeak,"goff",threshold);

  Int_t nPeaks = spectrum->GetNPeaks();

  if (nPeaks > 1) {

    Float_t * x = new Float_t[nPeaks];
    Float_t * y = new Float_t[nPeaks];

    x = spectrum->GetPositionX();//getting peak positions
    y = spectrum->GetPositionY();//getting amplitude

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

    TF1 * mpeak = new TF1("mpeak",MultiGaus,0,4000,2*nPeaks+3);
    mpeak->SetNpx(100000);
    mpeak->SetLineColor(kRed);

    /******setting initial parameters*********/

    Float_t gain = x[lookup[1]]-x[lookup[0]]; //gain distance between first 2 peaks
    Float_t szero = gain/5; //initial sigma

    mpeak->FixParameter(0,nPeaks);//number of peaks FIXED

    mpeak->SetParameter(1,gain);//gain
    mpeak->SetParLimits(1,0.5*gain,1.5*gain);

    mpeak->SetParameter(2,x[lookup[0]]);//pede
    mpeak->SetParLimits(2,x[lookup[0]]-szero/2,x[lookup[0]]+szero/2);

    for(Int_t i=0; i<nPeaks; i++){
      mpeak->SetParameter(2*i+3,y[lookup[i]]);
      mpeak->SetParLimits(2*i+3,0.8*y[lookup[i]],1.5*y[lookup[i]]);//height


      mpeak->SetParameter(2*i+4,TMath::Sqrt(i+1)*szero);
      mpeak->SetParLimits(2*i+4,TMath::Sqrt(i+1)*szero/10,2*TMath::Sqrt(i+1)*szero);//sigma

    }

    peaks->Fit(mpeak,"RNO","",x[lookup[0]]-szero,x[lookup[nPeaks-1]]+1.5*szero);

    delete[] x;
    delete[] y;

    return mpeak;
  } else {

    return NULL;

  }
}

/*******************************************************/









