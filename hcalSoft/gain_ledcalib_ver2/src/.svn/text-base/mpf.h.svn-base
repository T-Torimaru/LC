/*
 * mpf.h
 *
 *  Created on: Oct 12, 2012
 *      Author: hartbrich
 */

#ifndef MPF_H_
#define MPF_H_

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>

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

Double_t MultiGaus(Double_t *x, Double_t *par);

TF1* MultiPFit(TH1F *peaks, Int_t nOfpeaks, Float_t res,Float_t sigmapeak,Float_t threshold);


#endif /* MPF_H_ */

