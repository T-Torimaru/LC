
#include <TH1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TSpectrum.h>
#include <TString.h>
#include <TMath.h>
#include <TF1.h>
#include <TVirtualFFT.h>

Int_t    FitGainLog(TH1* hist, Int_t npks, Float_t *mean, Float_t *sigma);
Float_t* GainFromFFT(TH1* hist);
void     FindPeak(TH1* hist, Float_t *res);
TCanvas* NewCanvas(TString cname,Int_t x,Int_t y);
Float_t* GetDCR(TH1* hist, Float_t pedestal, Float_t gain,Float_t effgate);
Int_t    FitGainWithKnowledge(TH1* hist,Int_t npks, Float_t *mean, Float_t *sigma, Float_t kped, Float_t kgn);
Float_t* GainFromFFTNoPed(TH1* hist,Float_t kped, Float_t kgain);
