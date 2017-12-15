#define example_cxx
#include "example.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include <vector>
#include <iostream>
#include <TString.h>
#include <TLegend.h>
#include <TLatex.h>

using namespace std;

void example::Loop()
{
  //   In a ROOT session, you can do:
  //      Root > .L example.C
  //      Root > example t
  //      Root > t.GetEntry(12); // Fill t data members with entry number 12
  //      Root > t.Show();       // Show values of entry 12
  //      Root > t.Show(16);     // Read and show values of entry 16
  //      Root > t.Loop();       // Loop on all entries
  //

  //     This is the loop skeleton where:
  //    jentry is the global entry number in the chain
  //    ientry is the entry number in the current Tree
  //  Note that the argument to GetEntry must be:
  //    jentry for TChain::GetEntry
  //    ientry for TTree::GetEntry and TBranch::GetEntry
  //
  //       To read only selected branches, Insert statements like:
  // METHOD1:
  //    fChain->SetBranchStatus("*",0);  // disable all branches
  //    fChain->SetBranchStatus("branchname",1);  // activate branchname
  // METHOD2: replace line
  //    fChain->GetEntry(jentry);       //read all branches#include <iostream>

  //by  b_branchname->GetEntry(ientry); //read only this branch

  if (fChain == 0) return;

  //Loop for the different cases,
  // in the example, we have a set of 3x3 tiles placed just in the middle of the HBU
  // in such a way that the central tile is shared by 4 MPPCs: (chip, channel) (193,0), (194,5), (195,35) and (196,30)
  for(int k=0; k<4; k++) {

    // description of every case and its neighbourh channels
    // toy example, setting every case individually 
   
    //channel 34, 195
    int channel_center=5;
    int chip_center=194;
 
    int channel_near[] = {0,6,11,10,4,35,30,31};
    int chip_near[] = {193,193,194,194,194,195,196,196};
    int nearby = sizeof(channel_near)/sizeof(channel_near[0]);

    //channel 0, 193
    if(k==1) {
      channel_center=0;
      chip_center=193;
      int channel_temp[] = {1,6,7,5,11,34,35,30};
      int chip_temp[] = {193,193,193,194,194,195,195,196};
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

    //channel 35, 195
    if(k==2) {
      channel_center=35;
      chip_center=195;
      int channel_temp[] = {0,1,5,34,29,28,30,24};
      int chip_temp[] = {193,193,194,195,195,195,196,196};
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

    //channel 30, 196
    if(k==3) {
      channel_center=30;
      chip_center=196;
      int channel_temp[] = {0,5,4,35,29,24,25,31};
      int chip_temp[] = {193,194,194,195,195,196,196,196};
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

   //channel 7, 193
    if(k==4) {
      channel_center=7;
      chip_center=193;
      int channel_temp[] = {1,6,7};
      int chip_temp[] = {193,193,193}
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

  //channel 28, 195
    if(k==5) {
      channel_center=28;
      chip_center=195;
      int channel_temp[] = {29,34,35};
      int chip_temp[] = {195,195,195};
      
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

 //channel 28, 195
    if(k==6) {
      channel_center=25;
      chip_center=196;
      int channel_temp[] = {24,31,30};
      int chip_temp[] = {196,196,196};
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }

 //channel 10, 1954
    if(k==7) {
      channel_center=10;
      chip_center=194;
      int channel_temp[] = {4,5,11};
      int chip_temp[] = {194,194,194};
   
      for(int i=0; i< sizeof(channel_temp)/sizeof(channel_temp[0]); i++) {channel_near[i]=channel_temp[i]; chip_near[i]=chip_temp[i];}
      nearby = sizeof(channel_temp)/sizeof(channel_temp[0]);
    }
  
    TString title =TString::Format("ChipID%i_chn%i",chip_center,channel_center);

    // Define histograms:
    // adc_histo[0]= adc for channel of case k if its hit bit == 1
    // adc_histo[X]= adc for channel of case k if its hit bit == 1 and has exactly X channels nearby with hit bit ==1

    //----------------------------------
    //histograms
    float bins=800;
    float min =0;
    float max =1600; 
    std::vector<TH1F*> adc_histo;
    for(int j=0; j<9; j++) {
      TH1F* h1= new TH1F (TString::Format("ChipID%i_chn%i_NearHits%i",chip_center,channel_center, j),TString::Format("ChipID%i_chn%i_NearHits%i",chip_center,channel_center, j), bins, min-(max-min)/(2*bins), max-(max-min)/(2*bins));
      adc_histo.push_back(h1);
    }
    //----------------------------------


    // Loop over all events
    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {  
      if (fChain == 0) return;

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      int NearHits=0;
      int adc_signal=0;

      //Loop over all hits in the same event (up to 144 since we only have 4 chips)
      for(int ihits=0; ihits<ahcal_nHits; ihits++) {
	
	if(ahcal_HitBit[ihits]==1 ){
	  if(ahcal_Channel[ihits]==channel_center && ahcal_ChipID[ihits]==chip_center) adc_signal=ahcal_ADC[ihits];

	  for(int j=0; j<nearby; j++) {
	    if(ahcal_Channel[ihits]==channel_near[j] && ahcal_ChipID[ihits]==chip_near[j])  NearHits++;
	  }
	}
      }

      //Fil histograms
      if(adc_signal>0) {
	adc_histo[0]->Fill(adc_signal);  
	for(int j=1; j<NearHits+1; j++) { 	adc_histo[j]->Fill(adc_signal);  }

      }
 

    }

    std::cout<<"end"<<endl;
  
    //---------------------------------------------------------------------------------------
    // Plot section
    //---------------------------------------------------------------------------------------  

    gStyle->SetLegendBorderSize(0);

    TCanvas* ADC= new TCanvas(TString::Format("ADC%i", k),TString::Format("ADC%i", k),1400,1200);
    ADC->cd(1);
    adc_histo[0]->GetXaxis()->SetTitle("ADC");
    adc_histo[0]->SetTitle("Cosmic Run, "+title);
    adc_histo[0]->SetName("All entries");
    adc_histo[0]->SetLineColor(1);
    adc_histo[0]->SetLineWidth(2);
    adc_histo[0]->Draw("");
    gPad->Update();
    TPaveStats* temp= (TPaveStats*)(adc_histo[0]->GetListOfFunctions()->FindObject("stats"));
    temp->SetY2NDC(1); 
    temp->SetY1NDC(0.9);
    temp->SetX2NDC(1); 
    temp->SetX1NDC(0.85);
    gPad->Modified();

    std::vector<TPaveStats*> sb2;

    for(int j=1; j<nearby+1; j++) {
      adc_histo[j]->SetName(TString::Format("%i NearHits", j));
      adc_histo[j]->SetLineColor(j+1);
      adc_histo[j]->SetLineStyle(j+1);
      adc_histo[j]->SetLineWidth(2);
      adc_histo[j]->Draw("sames");
      gPad->Update();
      TPaveStats* temp= (TPaveStats*)(adc_histo[j]->GetListOfFunctions()->FindObject("stats"));
      sb2.push_back(temp);
    }
    for(int j=1; j<nearby+1; j++) {
      sb2[j-1]->SetTextColor(j+1);
      sb2[j-1]->SetX2NDC(1); sb2[j-1]->SetX1NDC(0.85);
      if(j==1) {sb2[j-1]->SetY2NDC(0.9); sb2[j-1]->SetY1NDC(0.8); }
      if(j==2) {sb2[j-1]->SetY2NDC(0.8); sb2[j-1]->SetY1NDC(0.7);}
      if(j==3) {sb2[j-1]->SetY2NDC(0.7); sb2[j-1]->SetY1NDC(0.6);}
      if(j==4) {sb2[j-1]->SetY2NDC(0.6); sb2[j-1]->SetY1NDC(0.5);}
      if(j==5) {sb2[j-1]->SetY2NDC(0.5); sb2[j-1]->SetY1NDC(0.4);}
      if(j==6) {sb2[j-1]->SetY2NDC(0.4); sb2[j-1]->SetY1NDC(0.3);}
      if(j==7) {sb2[j-1]->SetY2NDC(0.3); sb2[j-1]->SetY1NDC(0.2);}
      if(j==8) {sb2[j-1]->SetY2NDC(0.2); sb2[j-1]->SetY1NDC(0.1);}
      if(j==9) {sb2[j-1]->SetY2NDC(0.1); sb2[j-1]->SetY1NDC(0.0);}
      gPad->Modified();
    }

    TLegend * leg= new TLegend(0.11,0.6,0.25,0.89);
    leg->AddEntry(adc_histo[0],"All entries","l");
    for(int j=1; j<nearby+1; j++) leg->AddEntry(adc_histo[j],TString::Format("%i NearHits", j),"l");
    leg->SetFillColor(0);
    leg->Draw();

    ADC->Print("Sr90_th220_"+title+".png");


    TCanvas* ADC2= new TCanvas(TString::Format("ADC2%i", k),TString::Format("ADC2%i", k),1400,1200);
    ADC2->cd(1);
    ADC2->SetLogy();

    adc_histo[0]->GetXaxis()->SetTitle("ADC");
    adc_histo[0]->SetTitle("Cosmic Run, "+title);
    adc_histo[0]->SetName("All entries");
    adc_histo[0]->SetLineColor(1);
    adc_histo[0]->SetLineWidth(2);
    adc_histo[0]->Draw("");
    gPad->Update();
    TPaveStats* temp= (TPaveStats*)(adc_histo[0]->GetListOfFunctions()->FindObject("stats"));
    temp->SetY2NDC(1); 
    temp->SetY1NDC(0.9);
    temp->SetX2NDC(1); 
    temp->SetX1NDC(0.85);
    gPad->Modified();

    std::vector<TPaveStats*> sb2;

    for(int j=1; j<nearby+1; j++) {
      adc_histo[j]->SetName(TString::Format("%i NearHits", j));
      adc_histo[j]->SetLineColor(j+1);
      adc_histo[j]->SetLineStyle(j+1);
      adc_histo[j]->SetLineWidth(2);
      adc_histo[j]->Draw("sames");
      gPad->Update();
      TPaveStats* temp= (TPaveStats*)(adc_histo[j]->GetListOfFunctions()->FindObject("stats"));
      sb2.push_back(temp);
    }
    for(int j=1; j<nearby+1; j++) {
      sb2[j-1]->SetTextColor(j+1);
      sb2[j-1]->SetX2NDC(1); sb2[j-1]->SetX1NDC(0.85);
      if(j==1) {sb2[j-1]->SetY2NDC(0.9); sb2[j-1]->SetY1NDC(0.8); }
      if(j==2) {sb2[j-1]->SetY2NDC(0.8); sb2[j-1]->SetY1NDC(0.7);}
      if(j==3) {sb2[j-1]->SetY2NDC(0.7); sb2[j-1]->SetY1NDC(0.6);}
      if(j==4) {sb2[j-1]->SetY2NDC(0.6); sb2[j-1]->SetY1NDC(0.5);}
      if(j==5) {sb2[j-1]->SetY2NDC(0.5); sb2[j-1]->SetY1NDC(0.4);}
      if(j==6) {sb2[j-1]->SetY2NDC(0.4); sb2[j-1]->SetY1NDC(0.3);}
      if(j==7) {sb2[j-1]->SetY2NDC(0.3); sb2[j-1]->SetY1NDC(0.2);}
      if(j==8) {sb2[j-1]->SetY2NDC(0.2); sb2[j-1]->SetY1NDC(0.1);}
      if(j==9) {sb2[j-1]->SetY2NDC(0.1); sb2[j-1]->SetY1NDC(0.0);}
      gPad->Modified();
    }

    TLegend * leg= new TLegend(0.11,0.6,0.25,0.89);
    leg->AddEntry(adc_histo[0],"All entries","l");
    for(int j=1; j<nearby+1; j++) leg->AddEntry(adc_histo[j],TString::Format("%i NearHits", j),"l");
    leg->SetFillColor(0);
    leg->Draw();

    ADC2->Print("Sr90_th220_"+title+"_log.png");

  }
  

}

