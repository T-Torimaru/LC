#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

#include<TFile.h>
#include<TH1F.h>
#include<TCanvas.h>
#include<TLegend.h>
//#include<>

//#include<>

using namespace std;

void findholdvalue(string filename, int initichip=241, string outputdir="./"){

  string name="";
  stringstream ss;
  ss.str("");
  
  string histhead = "histo/z_ADC_chip";
  
  const int npoints = 20;
  string holdsuffix[npoints];
  int holdoffset = 2;
  int holdstep   = 2;
  for(int i=0;i<npoints;i++){
    ss.str("");
    ss << "_hold" << holdoffset+i*holdstep;
    holdsuffix[i] = ss.str();
  }
  
  TH1F* histhold = new TH1F("histhold","histhold",20,1,41);
  TH1F* histholdchip[4];
  int colors[4] = {1,2,4,6};
  for(int i=0;i<4;i++){
    ss.str("");
    ss << "hold_chip" << initichip+i;
    name = ss.str();
    histholdchip[i] = new TH1F(name.c_str(),name.c_str(),20,1,41);
    histholdchip[i]->SetLineColor(colors[i]);
    histholdchip[i]->GetXaxis()->SetTitle("Hold timing (binary)");
  }
  
  TFile* holdscanfile = new TFile(filename.c_str());
  float meanmax=0;
  int lastchipnum = initichip+4; /// for 1 HBU
  for(int ichip=initichip;ichip<lastchipnum;ichip++){
    int chipindex = ichip - initichip;
    for(int ich=0;ich<36;ich++){
      meanmax=0;
      map<float,int> map_mean_hold;
      for(int ihold=0;ihold<npoints;ihold++){
	ss.str("");
	ss << histhead << ichip << "_chn" << ich << holdsuffix[ihold];
	name = ss.str();
	// cout << name << endl;
	float mean = ((TH1F*) holdscanfile->Get(name.c_str()))->GetMean();
	if(mean>meanmax) meanmax=mean;
	// cout << ((TH1F*) holdscanfile->Get(name.c_str()))->GetMean() << endl;;
	map_mean_hold[mean] = ihold*holdstep + holdoffset;
      }
 
     if(meanmax>300&&meanmax<3000){
       histhold->Fill(map_mean_hold[meanmax]);
       histholdchip[chipindex]->Fill(map_mean_hold[meanmax]);
     }
    }
  }

  TCanvas* can1 = new TCanvas("can1","can1");
  can1->Divide(2,1);
  can1->cd(1);
  histhold->SetTitle("Hold timing");
  histhold->GetXaxis()->SetTitle("Hold timing (binary)");
  histhold->Draw();

  can1->cd(2);
  TH1F* frame = gPad->DrawFrame(1,0,41,histholdchip[0]->GetEntries()*0.7);
  frame->GetXaxis()->SetTitle("Hold timing (binary)");
  TLegend* leg = new TLegend(0.55,0.65,0.9,0.9);
  for(int i=0;i<4;i++){
    leg->AddEntry(histholdchip[i]);
    histholdchip[i]->Draw("Same");
  }
  leg->Draw("Same");

  name = outputdir + "/tmpoutput_holdtime.pdf"; 
  can1->Print(name.c_str());

  name = outputdir + "/tmpoutput_holdtime.root"; 
  TFile* orfile = new TFile(name.c_str(),"RECREATE");

  can1->Write();
  histhold->Write();
  for(int i=0;i<4;i++){
    histholdchip[i]->Write();
  }
  orfile->Close();

  name = outputdir + "/tmpoutput_holdtime.txt"; 
  ofstream ofile(name.c_str());
  ofile  << histhold->GetBinCenter(histhold->GetMaximumBin())<< "  most probable hold timing " << endl;;
  ofile.close();

  cout << "most probable hold timing: " << histhold->GetBinCenter(histhold->GetMaximumBin()) << endl;;

}
