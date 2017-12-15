#include <TFile.h>
#include <TTree.h>
#include <TLeaf.h>
#include <TString.h>
#include <TH1F.h>
#include <TF1.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TGraph.h>
#include <TPaveStats.h>
#include <TPad.h>
#include <TStyle.h>
#include <TFitResult.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <TMath.h>
#include <TPaveText.h>
#include <iostream>
#include <fstream>
#include <map>
#include "PedestalCalibrator.h"
#include "RunFolderParser.h"
#include "style.h"
#include "HistoGenerator.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{

  cout << "Intercalib soft : usage ./intercalib [ET:AT]" << endl;
  cout << endl; 

  stylemacro();
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(11111111);

  bool takePedestal = true;
  bool ET = true;

  //cout << argv[1] << endl;

  if(argc < 2)
    {
      cout << "No argument given... exiting...!!" << endl;
      exit(1);
    }
  
  if(strcmp(argv[1],"ET") == 0)
    ET = true;
  else{
    ET = false;
  }

  sleep(2);

  printf("%s \n", "**********************************************************");
  printf("%s \n", "********                                                                  ************");
  printf("%s \n", "********         Files run with ADC HG-LG?               ************");
  printf("%s \n", "********                                                                  ************");
  printf("%s \n", "**********************************************************");

  string answer = "y";

  cout << "y or n? (Default : y)" << endl;
  cin >> answer;

  if(answer == "n")
    {
      cout << "Files needs to be HG/LG !!!" << endl;
      exit(1);
    }

  string PATH_ET =  "/nfs/dust/ilc/group/flchcal/Commissioning_Aug_2014/HBU2_14/Data/rootfiles/ET_run/Calib/";
  string PATH_AT =  "/nfs/dust/ilc/group/flchcal/Commissioning_Aug_2014/HBU2_14/Data/rootfiles/";

  string PATH_PEDCALIB = "/nfs/dust/ilc/group/flchcal/Commissioning_Aug_2014/HBU2_14/Data/rootfiles/Pedestal/pedestal_offsets_in.tsv";
  string PATH_OUT = "/nfs/dust/ilc/group/flchcal/Commissioning_Aug_2014/HBU2_14/Data/rootfiles/ET_run/output_intercalib/Calib/";

  PedestalCalibrator b(PATH_PEDCALIB);
  RunFolderParser *g = new RunFolderParser();

  if(ET)
    g = new RunFolderParser(PATH_ET, ET);
  else{
    g =new RunFolderParser(PATH_AT,ET);
  }

  vector<RunInfo> v = g->getRunInfos();

  TFile* output_file;
  if(ET)  
    output_file = new TFile((PATH_OUT+"Plots_comp_ET.root").c_str(),"RECREATE");
  else {
    output_file = new TFile((PATH_OUT+"Plots_comp_AT.root").c_str(),"RECREATE");
  }

  map<int, vector<HistoGenerator* > > histos_HG_LG;
  map<int, TH1F*> histos_slope;
 
  int BunchXID, CycleNr, ChipID2, EvtNr, chn, TDC, ADC, xPos, yPos, Hit_Bit, Gain_Bit;

  if(ET)
    {
      cout << "**********************************************************" << endl;
      cout << "****                                                                                       ****" << endl; 
      cout << "****                        Reading ET files !!!!!                               ****" << endl;
      cout << "****                                                                                       ****" << endl;
      cout << "**********************************************************" << endl;
    }
  else
    {
      cout << "**********************************************************" << endl;
      cout << "****                                                                                       ****" << endl; 
      cout << "****                        Reading AT files !!!!!                               ****" << endl;
      cout << "****                                                                                       ****" << endl;
      cout << "**********************************************************" << endl;
    }

  int index = 0;

  for (vector<RunInfo>::iterator thisRun = v.begin(); thisRun != v.end(); thisRun++){

    cout << endl << index << " current path: " << thisRun->filePath << " vcalib:" << thisRun->vCalib << endl;

    TFile* myFile = TFile::Open(thisRun->filePath.c_str());

    TTree* myTree = (TTree*)myFile->Get("tree"); //see above

    myTree->SetBranchAddress("BunchXID", &BunchXID);
    myTree->SetBranchAddress("CycleNr", &CycleNr);
    myTree->SetBranchAddress("ChipID2", &ChipID2);
    myTree->SetBranchAddress("EvtNr", &EvtNr);
    myTree->SetBranchAddress("chn", &chn);
    myTree->SetBranchAddress("TDC", &TDC);
    myTree->SetBranchAddress("ADC", &ADC);
    myTree->SetBranchAddress("xPos", &xPos);
    myTree->SetBranchAddress("yPos", &yPos);
    myTree->SetBranchAddress("Hit_Bit", &Hit_Bit);
    myTree->SetBranchAddress("Gain_Bit", &Gain_Bit);

    output_file->cd();

    for (int entryID=0; entryID<myTree->GetEntries(); entryID++){

      myTree->GetEntry(entryID);
			
      if (ChipID2< 100) continue;

      if (CycleNr<=1)
	{
	  continue;
	}
      if (entryID%100000 == 1){
	cout << "." << flush;
      }

      //generate new histos if necessary:
      if (histos_HG_LG.count(ChipID2) == 0){

	histos_HG_LG[ChipID2] = vector<HistoGenerator*>(36);
	for (int i=0; i<36; i++){
	  histos_HG_LG[ChipID2][i] = new HistoGenerator(ChipID2, i);
	}

	cout << "creating ChipID " << ChipID2 << flush << endl;
      }

      if (histos_slope.count(ChipID2) == 0){
	histos_slope[ChipID2] = new TH1F(TString::Format("Histo_slope_chip%d", ChipID2), TString::Format("Histo slopes Chip %d", ChipID2), 30, 4.5, 34.5);
      } 

      int VarToFill_HG = TDC;
      int VarToFill_LG = ADC;

      // if (takePedestal)
      // 	{
      // 	  if(chn == 0 && VarToFill_HG+b.getOffset(ChipID2, chn, EvtNr) > 1000 && VarToFill_LG+b.getOffset(ChipID2, chn, EvtNr) > 0 && index == 0)
      // 	    {
      // 	      cout << endl << VarToFill_HG+b.getOffset(ChipID2, chn, EvtNr) << " " << VarToFill_LG+b.getOffset(ChipID2, chn, EvtNr) << endl;
      // 	      cout << "Suspect HG?TDC mode...." << endl;
      // 	      output_file->Close();
      // 	      exit(1);
      // 	    }
      // 	}
      // else
      // 	{
      // 	  if(chn == 0 && VarToFill_HG > 1000 && VarToFill_LG > 0 && index == 0)
      // 	    {
      // 	      cout << endl << VarToFill_HG << " " << VarToFill_LG << endl;
      // 	      cout << "Suspect HG?TDC mode...." << endl;
      // 	      output_file->Close();
      // 	      exit(1);
      // 	    }
      // 	}

      if (VarToFill_HG > 0 && VarToFill_LG > 0){

	if (takePedestal)
	  histos_HG_LG[ChipID2][chn]->Fill(VarToFill_HG+b.getOffset(ChipID2, chn, EvtNr), VarToFill_LG+b.getOffset(ChipID2, chn, EvtNr));//change this because of HGLG files
	else
	  histos_HG_LG[ChipID2][chn]->Fill(VarToFill_HG, VarToFill_LG);
      }

    }

    cout << endl;
    cout << "vcalib: " << thisRun->vCalib << " end of loop" << endl;
    index++;
  }

  TF1 *l = new TF1("l", "pol1", 600, 2000);

  TH1D *hChiSquare = new TH1D("hChiSquare",";Chisquare over ndf; #entries",80,0,10);
  TH1F* histo_all = new TH1F("Intercalib_factor_all_chips", "Intercalibration factor all Chips", 30, 4.5, 34.5);
  TH1F* histo_all_check = new TH1F("Intercalib_factor_all_chips_check", "Intercalibration factor all Chips (CHECK)", 30, 4.5, 34.5);

  TFile *fTest;
  if(ET) 
    fTest = new TFile((PATH_OUT+"Test_ET.root").c_str(),"RECREATE");
  else{
    fTest = new TFile((PATH_OUT+"Test_AT.root").c_str(),"RECREATE");
  }

  TTree *tTest = new TTree("Chi2info","Chi2info");
  float b_chi2 = 0,  b_chip = 0, b_chan = 0;
  tTest->Branch("chi2",   &b_chi2);
  tTest->Branch("chip",   &b_chip);
  tTest->Branch("chan",   &b_chan);
  
  string filename;
  string filename2;

  if(ET){
    filename = "intercalib_ET.tsv";
    filename2 ="bad_chn_ET.txt";
  }
  else{
    filename = "intercalib_AT.tsv";
    filename2 ="bad_chn_AT.txt";
  }

  ofstream lghg((PATH_OUT + filename).c_str(), ios::out | ios::trunc);
  ofstream wrong_chn((PATH_OUT + filename2).c_str(), ios::out | ios::trunc);;

  lghg << "#Chip" << "\t" << "chn" << "\t" << "IC factor" << "\t" << "error" << "\t"<< "chi2/ndf" << endl;
  wrong_chn << "#Chip" << "\t" << "chn" << "\t" << "IC factor" << "\t" << "error" << "\t"<< "chi2/ndf" << endl;
 
  map<int, vector<HistoGenerator* > >::iterator  itChips;

  for (itChips = histos_HG_LG.begin(); itChips!=histos_HG_LG.end(); itChips++)
    {
      int index = 0;
      for (vector<HistoGenerator* >::iterator it = itChips->second.begin(); it!=itChips->second.end(); it++)
	{
	  (*it)->SetStats(1);
	  float mean_y = (*it)->GetMean(2);
	  float mean_x = (*it)->GetMean(1);
	  cout << "Mean X Profile " << mean_x << " Mean Y Profile " << mean_y << " chn " << index << " chip " << itChips->first << endl;
	  double slope[] = {0, 1./12.};
	  l->SetParameters(slope);
	  TProfile::Approximate(1);
	  (*it)->Fit(l);
	  l->GetParameters(slope);

	  fTest->cd();

	  hChiSquare->Fill(l->GetChisquare()/l->GetNDF());
	  b_chi2 = l->GetChisquare()/l->GetNDF();
	  b_chip = itChips->first;
	  b_chan = index;
	  tTest->Fill();

	  //if(b_chi2 > 3) continue;

	  histo_all_check->Fill(1/slope[1]);

	  cout << "Before check ---------------- Mean histo " << histo_all_check->GetMean() << " loop chn " << index << " for chip " << itChips->first << endl;

	  if(histo_all_check->GetMean() >= 10 && histo_all_check->GetMean() < 20)
	    {
	      if(1/slope[1] > (histo_all_check->GetMean() + 2*histo_all_check->GetRMS()) || 1/slope[1] < (histo_all_check->GetMean() -  2*histo_all_check->GetRMS()))
		{
		  cout << endl;
		  cout << "Check +-2 sigma wrong..." << endl;
		  cout << itChips->first << "\t" << index << "\t" << 1/slope[1] << "\t" << l->GetParError(1) <<  "\t" << l->GetChisquare()/l->GetNDF() << endl;
		  cout << endl;
		  wrong_chn << itChips->first << "\t" << index << "\t" << 1/slope[1] << "\t" << l->GetParError(1) <<  "\t" << l->GetChisquare()/l->GetNDF() << endl;
		  index++;
		  continue;
		}
	    }

	  histos_slope[itChips->first]->Fill(1/slope[1]);
	  histo_all->Fill(1/slope[1]);
	  cout << "After check ---------------- Mean histo " << histo_all->GetMean() << " loop chn " << index << " for chip " << itChips->first << endl;

	  lghg << itChips->first << "\t" << index << "\t" << 1/slope[1] << "\t" << l->GetParError(1) <<  "\t" << l->GetChisquare()/l->GetNDF() << endl;

	  //cout << "ChipID " <<  itChips->first << " chn " << index << " slope " <<  slope[1] << endl;
	  index++;
	}
      cout << "end loop Chip" << endl;
    }

  lghg.close();
  wrong_chn.close();
  
  fTest->Write();
  fTest->Close();

  output_file->Write();
  output_file->Close();

  return 0;
}

