#include <string>
#include <TFile.h>
#include <TH1.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TString.h>
#include <TList.h>
#include <stdlib.h>
#include <TTree.h>
#include <TMath.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TApplication.h>

using namespace std;

vector<string> GetListOfFiles(string PATH, string ending)
{
  TSystem sys;
  TSystemDirectory dir("testname", PATH.c_str() ); // dir name, pathname
  TList *files = dir.GetListOfFiles();
  files->Sort();
  TIter next(files);
  TSystemFile *fil;
  
  TString pwd = TString(gSystem->WorkingDirectory());

  std::vector<std::string> returnvec;

  while ((fil = (TSystemFile*) next()))
    {
      if (std::string(fil->GetName()).find(ending) !=std::string::npos)
	{
	  returnvec.push_back(std::string(fil->GetName())) ;
	}
    }

  return returnvec;
}

double poisson(double *x, double *par)
{
  return par[0]*TMath::Poisson(x[0], par[1]);
}

int main(int argc, char **argv)
{

  TApplication app("app", &argc, argv);
   
  if(argc < 2)
    {
      cout << "./noise INPUT OUTPUT" << endl;
      return 1;
    }

  gSystem->Load("libPhysics");
  
  //string PATH = argv[1];
  //string OUTPUT = argv[2];

  string PATH = app.Argv(1);
  string OUTPUT = app.Argv(2);
 
  string board_name = "SM_1";
  
  vector<string> files = GetListOfFiles(PATH, ".root");
  cout << "Number of files " << files.size() << endl;
  
  int CycleNr;
  int ChipID;
  int EvtNr;
  int Channel;
  int TDC;
  int ADC;
  int HitBit;
  int GainBit;

  int ifile = 0;

  TF1 *poissonfit = new TF1("poissonfit", poisson, 0, 15, 2);
  poissonfit->SetParameter(0, 10);
  poissonfit->SetParameter(1, 1);
  poissonfit->SetParNames("Amplitude", "lambda");
  poissonfit->SetNpx(300);
  poissonfit->SetLineStyle(2);
  
  TFile *fOut = new TFile((OUTPUT+"Plot_comp.root").c_str(), "RECREATE");
  ofstream noise((OUTPUT+"fit_param.txt").c_str());
  noise << "Chip \t Time \t Thr \t Amplitude \t Amplitude_err \t lambda \t lambda_err \t Chi2" << endl;

  map<int, map<int, TH1F*> > hNoise;
  
  for(vector<string>::iterator it = files.begin(); it != files.end(); ++it)
    {
      //if(ifile > 0) continue;
      
      string filename = *it;
      //cout << "file " << PATH+filename << endl; 

      string Threshold_str = filename.substr(filename.find("AT_")+3, 3);
      int Threshold = atoi(Threshold_str.c_str());
      
      string time_window_str = filename.substr(filename.find(Threshold_str)+4, filename.find("us") - filename.find(Threshold_str)+4);
      int time_window = atoi(time_window_str.c_str());

      //cout << Threshold << "\t" << time_window << endl;

      TFile *f = new TFile((PATH+filename).c_str(),"OPEN");
      TTree *myTree = (TTree*)f->Get("tree");

      myTree->SetBranchAddress("CycleNr", &CycleNr);
      myTree->SetBranchAddress("ChipID2", &ChipID);
      myTree->SetBranchAddress("EvtNr", &EvtNr);
      myTree->SetBranchAddress("chn", &Channel);
      myTree->SetBranchAddress("TDC", &TDC);
      myTree->SetBranchAddress("ADC", &ADC);
      myTree->SetBranchAddress("Hit_Bit", &HitBit);
      myTree->SetBranchAddress("Gain_Bit", &GainBit);

      map<int, int> oldEvtNr;
      map<int, map<int, TH1I*> > hFilledMem;
      
      int oldCycle = -1;
      
      for (int entryID=0; entryID<myTree->GetEntries(); entryID++)
	{
	  myTree->GetEntry(entryID);

	  if(hFilledMem[ChipID].count(time_window*1000+Threshold) == 0)
	    {
	      hFilledMem[ChipID][time_window*1000+Threshold] = new TH1I(TString::Format("hFilledMem_Chip%i_Thr%i_Time%i", ChipID, Threshold, time_window), TString::Format("hFilledMem_Chip%i_Thr%i_Time%i", ChipID, Threshold, time_window), 17, -0.5, 16.5);
	      //cout << "Creating histo " << ChipID << " thr " << Threshold << " time " << time_window << endl;
	    }

	  if(CycleNr > 1)
	    {
	      if(oldCycle != CycleNr)
		{
		  oldCycle = CycleNr;
		   
		  for(map<int, int>::iterator it2 = oldEvtNr.begin(); it2 != oldEvtNr.end(); ++it2)
		    {
		      //cout << Threshold << "\t" <<  time_window  << "\t" << oldCycle << "\t" << it2->first << "\t" << it2->second << endl;
		      hFilledMem[it2->first][time_window*1000+Threshold]->Fill(it2->second);
		    }
		  
		  oldEvtNr.clear();
		}
	    }
	  
	  if(oldEvtNr.count(ChipID) == 0)
	    oldEvtNr[ChipID] = 0;
	  
	  if(EvtNr == 0) continue;
	  if(HitBit != 1) continue;
	  
	  if(EvtNr > oldEvtNr[ChipID])
	    {
	      oldEvtNr[ChipID] = EvtNr;
	    }
	}

      fOut->cd();
      
      for(map<int, map<int, TH1I*> >::iterator it2 = hFilledMem.begin(); it2 != hFilledMem.end(); ++it2)
	{
	  for(map<int, TH1I*>::iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
	    {
	      if(it3->second->GetBinContent(it3->second->FindBin(15)) == 0)
		{
		  it3->second->Fit(poissonfit, "QREM", "", 0, 15);

		  float Amplitude = poissonfit->GetParameter(0);
		  float Amplitude_err = poissonfit->GetParError(0);
		  
		  float lambda = poissonfit->GetParameter(1);
		  float lambda_err = poissonfit->GetParError(1);

		  int Chip = it2->first;
		  int Time = it3->first/1000;
		  int Thr = it3->first%1000;

		  float Chi2 = poissonfit->GetChisquare();

		  if(Chi2 < 3 && Chi2 > 0.01)
		    {
		      cout << "Chip " << Chip << " Time " << Time << " Thr " << Thr << " Amplitude " << Amplitude << " +/- " << Amplitude_err << " Lambda " << lambda << " +/- " << lambda_err << " Chi2 " << Chi2 << endl;
		      cout << " Noise rate " << lambda/(float)Time*1000000  << " Hz" << endl;

		      noise << Chip << "\t" << Time << "\t" << Thr << "\t" << Amplitude << "\t" << Amplitude_err << "\t" << lambda << "\t" << lambda_err << "\t" << Chi2 << endl;

		      //For each Chip and Trigger fill histo with Noise rate
		      if(hNoise[Chip].count(Thr) == 0)
			{
			  hNoise[Chip][Thr] = new TH1F(TString::Format("hNoise_Chip%i_Thr%i", Chip, Thr), TString::Format("hNoise_Chip%i_Thr%i", Chip, Thr), 100, 0, 2000);
			}
		      
		      hNoise[Chip][Thr]->Fill(lambda/(float)Time*1000000);
		    }
		  
		  it3->second->Write();
		}
	    }
	}

      ifile++;
    }

  map<int, TGraphErrors*> gr;
  int Chipfirst = 0;
  int ii = 0;
  
  for(map<int, map<int, TH1F*> >::iterator it = hNoise.begin(); it != hNoise.end(); ++it)
    {
      if(ii == 0)
	Chipfirst = it->first;

      int Chip = it->first;
      int i = 0;
      for(map<int, TH1F*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	{
	  int Thr = it2->first;
	  float Noise = it2->second->GetMean();
	  float Noise_err = it2->second->GetRMS();
	  
	  if(gr.count(Chip-Chipfirst) == 0)
	    {
	      gr[Chip-Chipfirst] = new TGraphErrors();
	      gr[Chip-Chipfirst]->SetName(TString::Format("Noise_rate_Chip%i", Chip));
	      gr[Chip-Chipfirst]->SetMarkerStyle(20 + Chip-Chipfirst);
	      gr[Chip-Chipfirst]->SetMarkerColor( 2 + Chip-Chipfirst);
	      gr[Chip-Chipfirst]->SetLineColor( 2 + Chip-Chipfirst);
	    }
	  
	  gr[Chip-Chipfirst]->SetPoint(i, Thr, Noise);
	  gr[Chip-Chipfirst]->SetPointError(i, 0, Noise_err);
	  i++;
	}
      ii++;
    }

  TLegend *leg = new TLegend(0.7, 0.6, 0.9, 0.8);
  leg->SetHeader(board_name.c_str());
  leg->AddEntry(gr[0], "Chip 0", "p");
  leg->AddEntry(gr[1], "Chip 1", "p");
  leg->AddEntry(gr[2], "Chip 2", "p");
  leg->AddEntry(gr[3], "Chip 3", "p");
  leg->SetBorderSize(0);


  
  TCanvas *c1 = new TCanvas("c1", "Noise", 1000, 600);
  c1->cd();
  gr[0]->Draw("APL");
  gPad->SetLogy();
  gr[0]->GetXaxis()->SetTitle("Trigger Threshold [DAC]");
  gr[0]->GetYaxis()->SetTitle("Noise Rate [Hz]");
  gr[0]->GetYaxis()->SetRangeUser(1, 2000);
  gr[1]->Draw("PL SAME");
  gr[2]->Draw("PL SAME");
  gr[3]->Draw("PL SAME");
  leg->Draw("SAME");
    
  c1->Write();
  
  fOut->Write();
  fOut->Close();
  
  app.Run();
}

