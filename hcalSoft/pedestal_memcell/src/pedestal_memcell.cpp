//============================================================================
// Name        : pedestalshift_FE.cpp
// Author      : ohartbri
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================


#include "PedestalSpectrum.h"
#include "PedestalCalibrator.h"
#include "style.h"

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


int main(int argc, char **argv) 
{
  if(argc < 4)
    {
      cout << "Provide flag for running rootfile : HG/LG(0) or HG/TDC(1)" << endl;
      cout << "InputFilePath OutputDirctoryPath Flag" << endl;
      return 1;
    }

  int mode = atoi(argv[3]);

  string PA = "100";

  TCanvas *c = new TCanvas();
  stylemacro();

  //  string PATH = "/home/calice/Commissioning/SM_1/Gain_650fF/Rootfiles/VCalib_1500cycles_0000mV_ET__14p07p2016__14o06o49.root";
  // string PATH_OUT = "/home/calice/Commissioning/SM_1/Gain_650fF/output_pedestal/";

  string PATH = argv[1];

  string PATH_OUT = argv[2];

  string PATH_OUT_VALUES = (PATH_OUT + "pedestal_offsets_in.tsv");

  TFile* output_file = new TFile((PATH_OUT+"Plots_comp.root").c_str(),"RECREATE");

  TH1F *hWidthRatio = new TH1F("hWidthRatio",";RMS_all / RMS_singles;entries",100,0,5);
  TH1F *hOffset = new TH1F("hOffsets",";Offsets;entries",100,-20,20);

  //map<int, map<int, vector<CalibSpectrum* > > > histosAll;
  map<int, vector<PedestalSpectrum* > > histos;

  //PedestalCalibrator pCalibIn(PATH_IN_VALUES);

  int BunchXID, CycleNr, ChipID2, ASICNr, EvtNr, chn, TDC, ADC, xPos, yPos, Hit_Bit, Gain_Bit;
  TBranch *b_BunchXID, *b_CycleNr, *b_ChipID2,*b_ASICNr, *b_EvtNr, *b_chn, *b_TDC, *b_ADC, *b_Hit_Bit, *b_Gain_Bit;
  
  //	GainRunFolderParser g(PATH);
  //	vector<RunInfo> v = g.getRunInfos();
  //
  //	for (vector<RunInfo>::iterator thisRun = v.begin(); thisRun != v.end(); thisRun++){

  cout << endl <<"current path: " << PATH << endl;
  TFile* myFile = TFile::Open(PATH.c_str());
  TTree* myTree = (TTree*)myFile->Get("tree"); //see above

  myTree->SetBranchAddress("BunchXID", &BunchXID, &b_BunchXID);
  myTree->SetBranchAddress("CycleNr", &CycleNr, &b_CycleNr);
  myTree->SetBranchAddress("ChipID2", &ChipID2, &b_ChipID2);
  myTree->SetBranchAddress("EvtNr", &EvtNr, &b_EvtNr);
  myTree->SetBranchAddress("chn", &chn, &b_chn);
  myTree->SetBranchAddress("TDC", &TDC, &b_TDC);
  myTree->SetBranchAddress("ADC", &ADC, &b_ADC);
  myTree->SetBranchAddress("Hit_Bit", &Hit_Bit, &b_Hit_Bit);
  myTree->SetBranchAddress("Gain_Bit", &Gain_Bit, &b_Gain_Bit);

  output_file->cd();

  for (int entryID=0; entryID<myTree->GetEntries(); entryID++){
    myTree->GetEntry(entryID);

    if (CycleNr <=1){
      continue;
    }

    if (entryID%100000 == 1){
      cout << "." << flush;
    }

    //generate new histos if necessary:
    if (histos.count(ChipID2) == 0){

      histos[ChipID2] = vector<PedestalSpectrum*>(36);
      for (int i=0; i<36; i++){
	histos[ChipID2][i] = new PedestalSpectrum(ChipID2, i);
      }

      cout << "creating ChipID " << ChipID2 << flush << endl;
      //GainHistoGenerator::getHistos(ChipID2, thisRun->vCalib, histosRun->at(ChipID2));
    }

    if(mode == 1)
      {
	if (ADC > 150 && Gain_Bit == 1){

	  //histos[ChipID2][chn]->Fill(ADC+pCalibIn.getOffset(ChipID2, chn, EvtNr), EvtNr);
	  histos[ChipID2][chn]->Fill(ADC, EvtNr);
	}
      }
    else
      {
	if (TDC > 150 && Gain_Bit == 1){

	  //histos[ChipID2][chn]->Fill(TDC+pCalibIn.getOffset(ChipID2, chn, EvtNr), EvtNr);
	  histos[ChipID2][chn]->Fill(TDC, EvtNr);
	}
      }

  }

  stringstream out;
  ofstream myfile;
  myfile.open (PATH_OUT_VALUES.c_str());
  myfile <<"#pedestal positions & memory cell dependent offsets (tpedOffsetcellX = tpedOffsetcell2 - tpedOffsetcellX) from file \"" << PATH << "\"" << endl;
  myfile <<"#format: the ordering of memory cells is inverted for DAQ HBU" << endl;
  myfile <<"#chip\tchn\tpedposall\tpedwidthall\tpedOffsetcell1\tpedOffsetcell2\tpedOffsetcell3\t...\tpedOffsetcell16" << endl;

  int cntChn;
  for (map<int, vector<PedestalSpectrum* > >::iterator  itChips = histos.begin(); itChips!=histos.end(); itChips++){
    cntChn = 0;
    for (vector<PedestalSpectrum* >::iterator it = itChips->second.begin(); it!=itChips->second.end(); it++){
      (*it)->FitPedestals();
      myfile << itChips->first << "\t" << cntChn << "\t" << (*it)->pedestalPositionAll << "\t" << (*it)->pedestalWidthAll;
      for (int i=0; i<16; i++){
	double thisWidthRatio;
	thisWidthRatio = (*it)->pedestalWidthAll / (*it)->pedestalWidths.at(i);
	hWidthRatio->Fill(thisWidthRatio);
	hOffset->Fill((*it)->pedestalOffsets.at(i));

	cout << "cell " << i+1 << " thisWidthRatio " << thisWidthRatio 
	     << " offset " << (*it)->pedestalOffsets.at(i) << endl;

	myfile << "\t" << (*it)->pedestalOffsets.at(i);

	if (fabs((*it)->pedestalOffsets.at(i))>200) 
	  cout << "Strange shift : Chip " << itChips->first << "chan " << cntChn << endl;
      }
      myfile << endl;
      //out << itChips->first << " " << cntChn << " " <<

      cntChn += 1;
    }
  }


  myfile.close();



  output_file->Write();
  output_file->Close();


  //cout << "total: " << cntTotal << " fitted: " << cntFitted << endl;

}

