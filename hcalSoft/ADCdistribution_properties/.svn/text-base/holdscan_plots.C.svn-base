#include "Riostream.h"
#include "<iostream>"
#include "<string>"
#include "TString.h"
#include <stdio.h>
#include <stdlib.h>

void holdscan_plots() {
  //  Read data from an ascii file and create a root file with an histogram and an ntuple.
  //   see a variant of this macro in basic2.C
  //Author: Rene Brun

  gROOT->Reset();


  Int_t ncols;
  Int_t hold_, i,j;
  Float_t mean_, width_, gain_;
  Int_t nlines = 0;
  
  float hold[100];
  float width[100];
  float mean[100];
  float gain[100];



  TCanvas *chip193 = new TCanvas("chip193","chip193",1400,800);
  chip193->Divide(3,1);

  TCanvas *chip194 = new TCanvas("chip194","chip194",1400,800);
  chip194->Divide(3,1);

  TCanvas *chip195 = new TCanvas("chip195","chip195",1400,800);
  chip195->Divide(3,1);

  TCanvas *chip196 = new TCanvas("chip196","chip196",1400,800);
  chip196->Divide(3,1);

  //TCanvas *c2 = new TCanvas("c1","c1",1000,1000);

  for(int nchip=193; nchip<197; nchip ++) {

    for(int jch=0; jch<36; jch++) {

      for(int ic=0; ic<100; ic++) {
	hold[ic]=0; mean[ic]=0; width[ic]=0;
      }

      FILE *fp = fopen("../../output_holdscan/ADCchecks.tsv","r");
     
      int ncounter=0;
      while (1) {
       
	ncols = fscanf(fp,"%i %i %i %f %f %f",&hold_, &i, &j, &mean_, &width_, &gain_);
	if (ncols < 0) break;    
	//      if (nlines < 10) 
	//   printf("hold_=%i,i=%i,j=%i,mean_=%f\n",hold_,i,j,mean_);
       
	if(i==nchip && j==jch) {
	  hold[ncounter]=hold_;
	  mean[ncounter]=mean_;
	  gain[ncounter]=gain_;
	  width[ncounter]=width_;
	  ncounter++;
	}
	nlines++;
      }
     
      TGraph *holdscan_mean = new TGraph(ncounter,hold,mean);
      TGraph *holdscan_width = new TGraph(ncounter,hold,width);
      TGraph *holdscan_gain = new TGraph(ncounter,hold,gain);

      printf(" found %d points\n",nlines);
     
      fclose(fp);
      char str[15];
      sprintf(str, "%i", jch);
      // c1->cd(jch+1); 
      //holdscan->Draw("alp");

      //------------------------------------------
      // Gain Value
      if(nchip==193) chip193->cd(1);
      if(nchip==194) chip194->cd(1);
      if(nchip==195) chip195->cd(1);
      if(nchip==196) chip196->cd(1);

      if(jch<9) {
	holdscan_gain->SetLineColor(jch+1);
	holdscan_gain->SetLineStyle(1);
	holdscan_gain->SetLineWidth(2);
      }
      if(jch>8 && jch<18) {
	holdscan_gain->SetLineColor(jch+1-9);
	holdscan_gain->SetLineStyle(2);
	holdscan_gain->SetLineWidth(1);
      }
      if(jch>17 && jch<27) {
	holdscan_gain->SetLineColor(jch+1-18);
	holdscan_gain->SetLineStyle(3);
	holdscan_gain->SetLineWidth(1);
      }
      if(jch>26 && jch<376) {
	holdscan_gain->SetLineColor(jch+1-27);
	holdscan_gain->SetLineStyle(2);
	holdscan_gain->SetLineWidth(2);
      }
      holdscan_gain->GetYaxis()->SetRangeUser(0,60);
      if(nchip==193) holdscan_gain->SetTitle("Chip 193");
      if(nchip==194) holdscan_gain->SetTitle("Chip 194");
      if(nchip==195) holdscan_gain->SetTitle("Chip 195");
      if(nchip==196) holdscan_gain->SetTitle("Chip 196");
      holdscan_gain->GetYaxis()->SetTitle("gain [ADC]");
      holdscan_gain->GetXaxis()->SetTitle("hold");
      if(jch==0) holdscan_gain->Draw("alp");
      else holdscan_gain->Draw("lp");

      //------------------------------------------
      // Mean Value
      if(nchip==193) chip193->cd(2);
      if(nchip==194) chip194->cd(2);
      if(nchip==195) chip195->cd(2);
      if(nchip==196) chip196->cd(2);

      if(jch<9) {
	holdscan_mean->SetLineColor(jch+1);
	holdscan_mean->SetLineStyle(1);
	holdscan_mean->SetLineWidth(2);
      }
      if(jch>8 && jch<18) {
	holdscan_mean->SetLineColor(jch+1-9);
	holdscan_mean->SetLineStyle(2);
	holdscan_mean->SetLineWidth(1);
      }
      if(jch>17 && jch<27) {
	holdscan_mean->SetLineColor(jch+1-18);
	holdscan_mean->SetLineStyle(3);
	holdscan_mean->SetLineWidth(1);
      }
      if(jch>26 && jch<376) {
	holdscan_mean->SetLineColor(jch+1-27);
	holdscan_mean->SetLineStyle(2);
	holdscan_mean->SetLineWidth(2);
      }
      holdscan_mean->GetYaxis()->SetRangeUser(0,2000);
      if(nchip==193) holdscan_mean->SetTitle("Chip 193");
      if(nchip==194) holdscan_mean->SetTitle("Chip 194");
      if(nchip==195) holdscan_mean->SetTitle("Chip 195");
      if(nchip==196) holdscan_mean->SetTitle("Chip 196");
      holdscan_mean->GetYaxis()->SetTitle("ADC mean [ADC]");
      holdscan_mean->GetXaxis()->SetTitle("hold");
      if(jch==0) holdscan_mean->Draw("alp");
      else holdscan_mean->Draw("lp");
     
      //------------------------------------------
      // Width Value
      if(nchip==193) chip193->cd(3);
      if(nchip==194) chip194->cd(3);
      if(nchip==195) chip195->cd(3);
      if(nchip==196) chip196->cd(3);

      if(jch<9) {
	holdscan_width->SetLineColor(jch+1);
	holdscan_width->SetLineStyle(1);
	holdscan_width->SetLineWidth(2);
      }
      if(jch>8 && jch<18) {
	holdscan_width->SetLineColor(jch+1-9);
	holdscan_width->SetLineStyle(2);
	holdscan_width->SetLineWidth(1);
      }
      if(jch>17 && jch<27) {
	holdscan_width->SetLineColor(jch+1-18);
	holdscan_width->SetLineStyle(3);
	holdscan_width->SetLineWidth(1);
      }
      if(jch>26 && jch<376) {
	holdscan_width->SetLineColor(jch+1-27);
	holdscan_width->SetLineStyle(2);
	holdscan_width->SetLineWidth(2);
      }
      holdscan_width->GetYaxis()->SetRangeUser(0,800);
      if(nchip==193) holdscan_width->SetTitle("Chip 193");
      if(nchip==194) holdscan_width->SetTitle("Chip 194");
      if(nchip==195) holdscan_width->SetTitle("Chip 195");
      if(nchip==196) holdscan_width->SetTitle("Chip 196");
      holdscan_width->GetYaxis()->SetTitle("ADC width [ADC]");
      holdscan_width->GetXaxis()->SetTitle("hold");
      if(jch==0) holdscan_width->Draw("alp");
      else holdscan_width->Draw("lp");



    }

  }


}
