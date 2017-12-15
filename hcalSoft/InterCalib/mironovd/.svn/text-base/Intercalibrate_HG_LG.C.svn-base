/* vim: set ts=2 sw=2*/
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

#include "PedestalCalibrator.h"

using namespace std;
//using TMath::Sqrt;


int* Linear(int start, int stop, int N){
	int* a = new int[N];
	for (int i = 0; i < N; i++){
		a[i] = start + i * (stop - start)/(N-1);
	}
	return a;
}

bool pedestals = true;
bool hit_bit_check = true;


//HBU 213 ET
/*
TString rawRootInPublicFName = "InterCalibAnotherHBU/calib";
TString pedestalOffsetsInPublicFName = "InterCalibAnotherHBUPedestal/pedestal_offsets_";
TString outputPath = "./HBU_213_ET/";
TString HBU = "HBU 213 ET";


const int ntype = 3;
const int nVcal = 6; //6 for 213, 11 for 214
const int nRun  = 10; //Runs per VCalibr
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6000, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF", "400fF", "1575fF"};

/**/


//HBU 214 ET
/*
TString rawRootInPublicFName = "InterCalib/calib";
TString pedestalOffsetsInPublicFName = "InterCalib/Pedestal/pedestal_offsets_";
TString outputPath = "./HBU_214_ET/";
TString HBU = "HBU 214 ET";

const int ntype = 3;
const int nVcal = 11; //6 for 213, 11 for 214
const int nRun  = 10; //Runs per VCalibr
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6000, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF", "400fF", "1575fF"};

/**/

//HBU 213 AT 300 funny: 132 17, 131 15, 131 3, 131 0, 130 35, 130 34, 130 33, 130 31,
//129 26, 132 30 - dense at corner
/*
TString rawRootInPublicFName = "InterCalib_213_AT_300/calib";
TString pedestalOffsetsInPublicFName = "InterCalibAnotherHBUPedestal/pedestal_offsets_";
TString outputPath = "./HBU_213_AT_300/";
TString HBU = "HBU 213 AT 300";

const int ntype = 1;
const int nVcal = 6; //6 for 213, 11 for 214
const int nRun  = 10; //Runs per VCalibr
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6000, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF"};
/**/

//HBU 213 Pedestal
/*
TString rawRootInPublicFName = "InterCalibAnotherHBUPedestal/ped";
TString pedestalOffsetsInPublicFName = "InterCalibAnotherHBUPedestal/pedestal_offsets_";
TString outputPath = "./HBU_213_Pedestal/";
TString HBU = "HBU 213 Pedestal";

const int ntype = 3;
const int nVcal = 1; 
const int nRun  = 10; //Runs per VCalibr
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int VCals[] = {0};

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF", "400fF", "1575fF"};

/**/

//HBU 214 repaired AT 300 
/*
TString rawRootInPublicFName = "InterCalib_214_repaired/AT/calib";
TString pedestalOffsetsInPublicFName = "InterCalib_214_repaired/Pedestal/pedestal_offsets_";
TString outputPath = "./HBU_214_rep_AT/";
TString HBU = "HBU 214 repaired AT 300";

const int ntype = 1;
const int nVcal = 11; //6 for 213, 11 for 214
const int nRun  = 1; //Runs per VCalibr (merged files, actually 6)
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6000, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF"};
/**/

//HBU 214 repaired ET      — channels (131; 0-17) LEDs are off.
/*
TString rawRootInPublicFName = "InterCalib_214_repaired/ET/calib";
TString pedestalOffsetsInPublicFName = "InterCalib_214_repaired/Pedestal/pedestal_offsets_";
TString outputPath = "./HBU_214_rep_ET/";
TString HBU = "HBU 214 repaired ET";

const int ntype = 1;
const int nVcal = 11; //6 for 213, 11 for 214
const int nRun  = 1; //Runs per VCalibr (merged files, actually 7)
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6000, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF"};
/**/

//HBU 214 repaired AT 300 no ps
/*
TString rawRootInPublicFName = "InterCalib_214_repaired_no_ps/AT/calib";
TString pedestalOffsetsInPublicFName = "InterCalib_214_repaired_no_ps/Pedestal/pedestal_offsets_";
TString outputPath = "./HBU_214_rep_AT_no_ps/";
TString HBU = "HBU 214 repaired AT 300 no ps";

const int ntype = 1;
const int nVcal = 11; //6 for 213, 11 for 214
const int nRun  = 1; //Runs per VCalibr (merged files, actually 6)
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6050, 6500, nVcal);

const int nCycle = 500; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF"};
/**/

//HBU 214 repaired ET no ps
/*
TString rawRootInPublicFName = "InterCalib_214_repaired_no_ps/ET/calib";
TString pedestalOffsetsInPublicFName = "InterCalib_214_repaired_no_ps/Pedestal/pedestal_offsets_";
TString outputPath = "./HBU_214_rep_ET_no_ps/";
TString HBU = "HBU 214 repaired ET no ps";

const int ntype = 1;
const int nVcal = 11; //6 for 213, 11 for 214
const int nRun  = 1; //Runs per VCalibr (merged files, actually 7)
const int nChip = 4;
const int nChan = 36;

double ped_err = 30;
int* VCals = Linear(6050, 6500, nVcal);

const int nCycle = 100; //To estimate error only
const int nCell = 15;

TString type[ntype] = {"100fF"};
/**/



/********************************************************************************/

bool local = false;
bool errorbars = true;

int VCalib (int iV){
	if (iV == -1) {
		if (nVcal < 2) return VCals[0] - 50;
		return 2 * VCals[0] - VCals[1];
	}
	if (iV == nVcal) {
		if (nVcal < 2) return VCals[0] + 50;
		return 2*VCals[nVcal - 1] - VCals[nVcal - 2];
	}
	return VCals[iV]; 
}

double mean_HG_chan[ntype][nVcal][nChip][nChan], mean_LG_chan[ntype][nVcal][nChip][nChan];
double rms_HG_chan[ntype][nVcal][nChip][nChan], rms_LG_chan[ntype][nVcal][nChip][nChan];
double mean_HG[ntype][nVcal], mean_LG[ntype][nVcal];
double rms_HG[ntype][nVcal], rms_LG[ntype][nVcal];
double ped_HG[ntype][nChip][nChan], ped_LG[ntype][nChip][nChan];
double ped_rms_HG[ntype][nChip][nChan], ped_rms_LG[ntype][nChip][nChan];
double ped_HG_NoFit[ntype][nChip][nChan], ped_LG_NoFit[ntype][nChip][nChan];
double ped_rms_HG_NoFit[ntype][nChip][nChan], ped_rms_LG_NoFit[ntype][nChip][nChan];


//gStyle->SetCanvasPreferGL(true);

TString PublicFolder(){
	TString Public = local ? "/home/dimok/remotes/desy_home/public/": "/afs/desy.de/user/m/mironovd/public/";
	return Public;
}

TFile* LoadFile(TString pa_type, int VCalib, int iRun = -1){
	TFile *f; 
  TString fnameAdd = PublicFolder();
	fnameAdd += rawRootInPublicFName;

	TString fname = fnameAdd + "_"; fname += VCalib; fname += "_"; fname += iRun; fname += "_";
	fname += pa_type; fname += ".root";
	f = new TFile(fname);
	//cout << endl << fname << "\topen: " << f->IsOpen() << "\tzombie: " << f->IsZombie() << endl;
	return f;
}

TTree* LoadTree(TString pa_type, int VCalib){
	TTree *t, *rt;
	TFile *f = LoadFile(pa_type, VCalib);

	TString fnameAdd =  "../HBU_calibr_root/FullHBU214";
	TString fname = fnameAdd + "_" + pa_type + "_"; fname += VCalib; fname += "mV_cut.root";


	TFile *cutf = TFile::Open(fname,"RECREATE");
	const char cut[] = "CycleNr>1 && ADC>1 && TDC>1 && ChipID2 >= 129 && ChipID2<=132 && chn>=0 && chn<=35";
	t = ((TTree*) f -> Get("tree")) -> CopyTree(cut);
	rt = t -> CloneTree();
	delete t;
	delete f;
	cutf->Close();
	return rt; 
}


void writeMeans() {
	ofstream means ( outputPath + "means.dat", ios::out | ios::binary | ios::trunc);
	means.write((char*)mean_HG, sizeof(double)*ntype * nVcal);
	means.write((char*)mean_LG, sizeof(double)*ntype * nVcal);
	means.write((char*)mean_HG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.write((char*)mean_LG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.write((char*)rms_HG, sizeof(double)*ntype * nVcal);
	means.write((char*)rms_LG, sizeof(double)*ntype * nVcal);
	means.write((char*)rms_HG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.write((char*)rms_LG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.write((char*)ped_HG, sizeof(double)*ntype * nChip * nChan);
	means.write((char*)ped_LG, sizeof(double)*ntype * nChip * nChan);
	means.write((char*)ped_rms_HG, sizeof(double)*ntype * nChip *nChan);
	means.write((char*)ped_rms_LG, sizeof(double)*ntype * nChip *nChan);
	means.write((char*)ped_HG_NoFit, sizeof(double)*ntype * nChip * nChan);
	means.write((char*)ped_LG_NoFit, sizeof(double)*ntype * nChip * nChan);
	means.write((char*)ped_rms_HG_NoFit, sizeof(double)*ntype * nChip *nChan);
	means.write((char*)ped_rms_LG_NoFit, sizeof(double)*ntype * nChip *nChan);
	means.close();
}


void readMeans(){
	//cout << "from " << mean_HG[0][0];
	ifstream means (outputPath + "means.dat", ios::in | ios::binary);
	means.read((char*)mean_HG, sizeof(double)*ntype * nVcal);
	means.read((char*)mean_LG, sizeof(double)*ntype * nVcal);
	means.read((char*)mean_HG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.read((char*)mean_LG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.read((char*)rms_HG, sizeof(double)*ntype * nVcal);
	means.read((char*)rms_LG, sizeof(double)*ntype * nVcal);
	means.read((char*)rms_HG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.read((char*)rms_LG_chan, sizeof(double)*ntype * nVcal * nChip *nChan);
	means.read((char*)ped_HG, sizeof(double)*ntype * nChip * nChan);
	means.read((char*)ped_LG, sizeof(double)*ntype * nChip * nChan);
	means.read((char*)ped_rms_HG, sizeof(double)*ntype * nChip *nChan);
	means.read((char*)ped_rms_LG, sizeof(double)*ntype * nChip *nChan);
	means.read((char*)ped_HG_NoFit, sizeof(double)*ntype * nChip * nChan);
	means.read((char*)ped_LG_NoFit, sizeof(double)*ntype * nChip * nChan);
	means.read((char*)ped_rms_HG_NoFit, sizeof(double)*ntype * nChip *nChan);
	means.read((char*)ped_rms_LG_NoFit, sizeof(double)*ntype * nChip *nChan);
	means.close();
	//cout << "to " << mean_HG[0][0] << endl;

}

double GetMean(int itype, int iV, int iChip = -1, int iChan = -1, bool HG = true){
	if (iChip < 0 || iChan < 0) {
		if (HG){
			return mean_HG[itype][iV];
		}
		else {// LG
			return mean_LG[itype][iV];
		}
	}
	else { //iChip, iChan
		if (HG){
			return mean_HG_chan[itype][iV][iChip][iChan];
		}
		else {// LG 
			return mean_LG_chan[itype][iV][iChip][iChan];
		}
	}
}

double GetRms(int itype, int iV, int iChip = -1, int iChan = -1, bool HG = true){
	if (iChip < 0 || iChan < 0) { 
		if (HG){
			return rms_HG[itype][iV];
		}
		else {// LG
			return rms_LG[itype][iV];
		}
	}
	else { //iChip, iChan
		if (HG){
			return rms_HG_chan[itype][iV][iChip][iChan];
		}
		else {// LG 
			return rms_LG_chan[itype][iV][iChip][iChan];
		}
	}
}

double GetPedMean(int itype, int iChip, int iChan, bool HG, bool NoFit){
	if (HG) {
		if (NoFit){
			return ped_HG_NoFit[itype][iChip][iChan];
		} else { // fit
			return ped_HG[itype][iChip][iChan];
		}
	} else { // LG
		if (NoFit) {
			return ped_LG_NoFit[itype][iChip][iChan];
		} else { // fit
			return ped_LG[itype][iChip][iChan];
		}
	}
}

double GetPedRms(int itype, int iChip, int iChan, bool HG, bool NoFit){
	if (HG) {
		if (NoFit){
			return ped_rms_HG_NoFit[itype][iChip][iChan];
		} else { // fit
			return ped_rms_HG[itype][iChip][iChan];
		}
	} else { // LG
		if (NoFit) {
			return ped_rms_LG_NoFit[itype][iChip][iChan];
		} else { // fit
			return ped_rms_LG[itype][iChip][iChan];
		}
	}
}

void GraphPrettify(TGraph* g, int color){
	gStyle->SetOptStat(111111);
	gStyle->SetOptFit(1111);
	g->SetLineColor(color);
	g->SetMarkerColor(color);
	g->SetLineWidth(2);
	g->SetMarkerStyle(20);
	g->SetMarkerSize(1);
}

void MultiPadWrite(TCanvas* c1, TCanvas* c2, TCanvas* c3 = NULL ){
	TCanvas* c = new TCanvas();
	c->cd();
	int n = (c3 ? 3 : 2);
	c->Divide(n);
	c->SetTitle((HBU + " ") + c1->GetTitle());
	c->SetName ((HBU + " ") + c1->GetName());
	c->cd(1);
	c1->DrawClonePad();
	c->cd(2);
	c2->DrawClonePad();
	if (c3){
		c->cd(3);
		c3->DrawClonePad();
	}
	c->Write();
	//TPad* p = (TPad*) (c->GetPad(0));
	//p->Write();
	//delete p;

	delete c1;
	delete c2;
	if (c3) delete c3;
	delete c;
}


void Intercalibrate_HG_LG_process(){
	cout << "all the intercalibration stuff at once\n";
	gROOT->SetBatch(true);
	cout.flush();
	
	TString pedcalibPath = PublicFolder();
	pedcalibPath += pedestalOffsetsInPublicFName;
	PedestalCalibrator *pc_hg[ntype],
										 *pc_lg[ntype];

	if (pedestals) {

		for (int itype = 0; itype < ntype; itype++){
			cout << "loading pedestals for " << type[itype].Data() << endl;
			cout.flush();

			pc_hg[itype] = new PedestalCalibrator((pedcalibPath + type[itype] + "_HG.tsv").Data());
			pc_lg[itype] = new PedestalCalibrator((pedcalibPath + type[itype] + "_LG.tsv").Data());	
		}

		cout << "pedestals loaded\n";
		cout.flush();
	}
	gStyle->SetOptFit(1111);
	gStyle->SetOptStat(11111111);

  
	ofstream means (outputPath + "means.dat", ios::in | ios::binary);


  TFile *f, *fRes, *fHgLg;
  TTree *t;
  TH1F *h_ch_HG[ntype][nVcal][nChip][nChan];
  TH1F *h_ch_LG[ntype][nVcal][nChip][nChan];
  TH2F *h_ch_LG_HG[ntype][nChip][nChan];
	TProfile *p_ch_LG_HG[ntype][nChip][nChan];
  TH1F *h_HG_LG[ntype];
  TH1F *h_HG_LG_3[ntype];
  TH1F *h_HG[ntype][nVcal];
  TH1F *h_LG[ntype][nVcal];
  TH1F *h_HG_mean[ntype][nVcal];
  TH1F *h_LG_mean[ntype][nVcal];

  TF1 l("l", "pol1", 600, 2300); //!fit
  TH1F::StatOverflows(true);

	fRes = new TFile(outputPath + "Histos.root","recreate");
	fHgLg = new TFile(outputPath + "HgLg.root","recreate");


  TString hname = "", hnamech;
  TString fname = "";
  for (int itype = 0; itype < ntype; itype++){
		ofstream lghg (outputPath + type[itype] + "_LgHg.tsv", ios::out | ios::trunc);
		lghg << "#chip\tchan\tLg/Hg\t+-\n";

		
		hname = "ADC_"; hname += type[itype]; 
		h_HG_LG[itype] = new TH1F(hname + "_HG_LG_hist", hname + "_HG_LG_hist", 50, 0, .2);
		h_HG_LG_3[itype] = new TH1F(hname + "_HG_LG_hist_3rd_chip", hname + "_HG_LG_hist_3rd_chip", 50, 0, .2);

		for (int iChip = 0; iChip < nChip; iChip++){
			for (int iChan = 0; iChan < nChan; iChan++){
					hname = "ADC_"; hname += type[itype]; hname += "_";
					hnamech = hname;
					hnamech += (129+iChip); hnamech += "_"; hnamech += iChan; 
					h_ch_LG_HG[itype][iChip][iChan] = new TH2F(hnamech + "_HG_LG", hnamech + "_HG_LG", 1400, -200, 4000, 1400, -200, 4000);
					h_ch_LG_HG[itype][iChip][iChan]->SetXTitle("HG");
					h_ch_LG_HG[itype][iChip][iChan]->SetYTitle("LG");
					p_ch_LG_HG[itype][iChip][iChan] = new TProfile(hnamech + "_LG_HG_p", hnamech + "_LG_HG", 3500, 0, 3500);
					p_ch_LG_HG[itype][iChip][iChan]->SetXTitle("HG"); 
					p_ch_LG_HG[itype][iChip][iChan]->SetYTitle("LG"); 
					//cout << "hc " << h_ch_LG_HG[itype][iChip][iChan]->GetName() << endl;
			}
		}

    for (int iV = 0; iV < nVcal; iV++){
			hname = "ADC_"; hname += type[itype]; hname += "_"; hname += VCalib(iV); hname+= "_";
			h_HG[itype][iV] = new TH1F(hname + "_HG", hname + "_HG", 4200, -200, 4000);
			h_LG[itype][iV] = new TH1F(hname + "_LG", hname + "_LG", 4200, -200, 4000);
			h_HG_mean[itype][iV] = new TH1F(hname + "_HG_means", hname + "_HG_means", 4200, -200, 4000);
			h_LG_mean[itype][iV] = new TH1F(hname + "_LG_means", hname + "_LG_means", 4200, -200, 4000);

			for (int iChip = 0; iChip < nChip; iChip++){
				for (int iChan = 0; iChan < nChan; iChan++){
					hnamech = hname;
					hnamech += (129+iChip); hnamech += "_"; hnamech += iChan; 
					h_ch_HG[itype][iV][iChip][iChan] = new TH1F(hnamech + "_HG", hnamech + "_HG", 4200, -200, 4000);
					h_ch_LG[itype][iV][iChip][iChan] = new TH1F(hnamech + "_LG", hnamech + "_LG", 4200, -200, 4000);

					if (pedestals) {
						ped_HG[itype][iChip][iChan] = pc_hg[itype]->getPositionTotal(iChip + 129, iChan);
						ped_LG[itype][iChip][iChan] = pc_lg[itype]->getPositionTotal(iChip + 129, iChan);
						ped_rms_HG[itype][iChip][iChan] = pc_hg[itype]->getWidthTotal(iChip + 129, iChan);
						ped_rms_LG[itype][iChip][iChan] = pc_lg[itype]->getWidthTotal(iChip + 129, iChan);

						ped_HG_NoFit[itype][iChip][iChan] = pc_hg[itype]->getPositionTotalNoFit(iChip + 129, iChan);
						ped_LG_NoFit[itype][iChip][iChan] = pc_lg[itype]->getPositionTotalNoFit(iChip + 129, iChan);
						ped_rms_HG_NoFit[itype][iChip][iChan] = pc_hg[itype]->getWidthTotalNoFit(iChip + 129, iChan);
						ped_rms_LG_NoFit[itype][iChip][iChan] = pc_lg[itype]->getWidthTotalNoFit(iChip + 129, iChan);
					}
				}
			}

			for (int iRun = 0; iRun < nRun; iRun++){
		
				//Read files
				f = LoadFile(type[itype], VCalib(iV), iRun);
				t = (TTree*)f->Get("tree");
				//const TCut tcut = "ADC>0 && TDC>0 && ChipID2>= 129 && ChipID2<=132 && chn>=0 && chan<=35";
		
				for (int iev = 0; iev < t->GetEntries(); iev++){
					t->GetEntry(iev);

					int CycleNr = (int)t->GetLeaf("CycleNr")->GetValue(); if (CycleNr<=1) continue;
					int ADC_HG = (int)t->GetLeaf("ADC")->GetValue(); if (ADC_HG<=0) continue;
					int ADC_LG = (int)t->GetLeaf("TDC")->GetValue(); if (ADC_LG<=0) continue;
					
					int Chip = (int)t->GetLeaf("ChipID2")->GetValue(); if (Chip<129||Chip>132) continue;
					int chan = (int)t->GetLeaf("chn")->GetValue(); if (chan<0||chan>35) continue;

					bool HitBit = (bool) t->GetLeaf("Hit_Bit")->GetValue(); if (hit_bit_check && !HitBit) continue;
					
					double ADC_HG_shifted = pedestals ? ADC_HG-ped_HG_NoFit[itype][Chip-129][chan] : ADC_HG;
					double ADC_LG_shifted = pedestals ? ADC_LG-ped_LG_NoFit[itype][Chip-129][chan] : ADC_LG;

					h_ch_HG [itype][iV][Chip-129][chan]->Fill(ADC_HG_shifted);
					h_ch_LG [itype][iV][Chip-129][chan]->Fill(ADC_LG_shifted);
					h_ch_LG_HG [itype][Chip-129][chan]->Fill(ADC_HG_shifted, ADC_LG_shifted);
					if (true) {
						p_ch_LG_HG [itype][Chip-129][chan]->Fill(ADC_HG_shifted, ADC_LG_shifted);
					}
					
					h_HG [itype][iV]->Fill(ADC_HG_shifted);
					h_LG [itype][iV]->Fill(ADC_LG_shifted);

						
					if (iev%100000==0) {
						cout << "iev " << iev << "\tiRun " << iRun << "\titype " << itype << "\tiV " << iV << "\tChip " << Chip << "\tChan " << chan << "\tADC_LG " << ADC_LG << "\tADC_HG " << ADC_HG << "\tshifted: ADC_LG " << ADC_LG_shifted << "\tADC_HG " << ADC_HG_shifted << endl;
						cout.flush();
					}
				}
				f -> Close();
				delete f;
			}

			fRes->cd();

			h_HG [itype][iV]->Write();
			h_LG [itype][iV]->Write();
			h_HG_mean [itype][iV]->Write();
			h_LG_mean [itype][iV]->Write();

			for (int iChip = 0; iChip < nChip; iChip++){
				for (int iChan = 0; iChan < nChan; iChan++){
					h_HG_mean[itype][iV]->Fill(h_ch_HG [itype][iV][iChip][iChan]->GetMean(1));
					h_LG_mean[itype][iV]->Fill(h_ch_LG [itype][iV][iChip][iChan]->GetMean(1));
					h_ch_HG [itype][iV][iChip][iChan]->Write();
					h_ch_LG [itype][iV][iChip][iChan]->Write();
					if (iV == nVcal - 1){
						fHgLg->cd();
						h_ch_LG_HG [itype][iChip][iChan]->Write();
						TCanvas *c = new TCanvas();
						c->cd();
						gPad->Update();
						TProfile *p = p_ch_LG_HG [itype][iChip][iChan];
						p->SetStats(1);
						double slope[] = {0, 1./12.};
						l.SetParameters(slope);
						p->Draw();
						gPad->Update();
						TProfile::Approximate(1);
						TFitResultPtr fp = p->Fit(&l, "RS", "sames");
						l.GetParameters(slope);
						h_HG_LG[itype]->Fill(slope[1]);
						if (iChip == 2 && iChan > 17) {
							h_HG_LG_3[itype]->Fill(slope[1]);
						}
						lghg << iChip << "\t" << iChan << "\t" << slope[1] << "\t" << l.GetParError(1) << endl;
						c->SetName(p->GetName());
						c->SetTitle(p->GetTitle());
						c->Write();
						delete c;
						delete h_ch_LG_HG [itype][iChip][iChan];
						delete p_ch_LG_HG [itype][iChip][iChan];
						fRes->cd();
					}

				}
			}
			mean_HG [itype][iV] = h_HG [itype][iV]->GetMean(1);
			mean_LG [itype][iV] = h_LG [itype][iV]->GetMean(1);
			rms_HG  [itype][iV] = h_HG_mean [itype][iV]->GetRMS(1);
			rms_LG  [itype][iV] = h_LG_mean [itype][iV]->GetRMS(1);
			delete h_HG [itype][iV];
			delete h_LG [itype][iV];
			delete h_HG_mean [itype][iV];
			delete h_LG_mean [itype][iV];


			for (int iChan = 0; iChan < nChan; iChan++){
				for (int iChip = 0; iChip < nChip; iChip++){
					mean_HG_chan [itype][iV][iChip][iChan] = h_ch_HG [itype][iV][iChip][iChan]->GetMean(1);
					mean_LG_chan [itype][iV][iChip][iChan] = h_ch_LG [itype][iV][iChip][iChan]->GetMean(1);
					rms_HG_chan  [itype][iV][iChip][iChan] = h_ch_HG [itype][iV][iChip][iChan]->GetMeanError(1);
					rms_LG_chan  [itype][iV][iChip][iChan] = h_ch_LG [itype][iV][iChip][iChan]->GetMeanError(1);
					delete h_ch_HG [itype][iV][iChip][iChan];
					delete h_ch_LG [itype][iV][iChip][iChan];
				}
			}
		}
		fHgLg->cd();
		h_HG_LG[itype]->Write();
		h_HG_LG_3[itype]->Write();
		delete h_HG_LG[itype];
		delete h_HG_LG_3[itype];
		fRes->cd();
		lghg.close();
  }


	//save histos by channel
	fRes->Write();
	fRes->Close();
	fHgLg->Write();
	fHgLg->Close();

	gROOT->SetBatch(false);

	writeMeans();
}


void SingleChipHisto(	int iChip, int itype, int iV){

	TH1F* hglg = new TH1F("hg_to_lg_chip", "hg_to_lg_chip", 500, 0, 100);

	for (int iChan = 0; iChan < nChan; iChan++){
		double hg = mean_HG_chan [itype][iV][iChip][iChan], 
					 lg = mean_LG_chan [itype][iV][iChip][iChan];
		hglg->Fill(hg/lg);
		if (hg/lg > 10.) cout << "itype " << itype << "\tiV " << iV << "\tchip " << iChip+129 << "\tiChan " << iChan << "\tlg " << lg << "\thg " << hg << "\thg/lg " << hg/lg << endl;
	}
	hglg->Draw();
}

void SingleChipScatter(	int iChip, int itype, int iV){

	TH2F *hglg = new TH2F("hg_to_lg_chip", "hg_to_lg_chip", 500, 0, 1000, 50, 0, 100);

	for (int iChan = 0; iChan < nChan; iChan++){
		hglg->Fill(mean_HG_chan [itype][iV][iChip][iChan],
							 mean_LG_chan [itype][iV][iChip][iChan]);
	}
	hglg->Draw("colz");
}

void SingleHbuScatter(int itype, int iV){

	TString gtitle = "HG_to_LG_for_V="; gtitle += VCalib(iV); gtitle += "_"; gtitle += type[itype]; 

	TH2F *hglg = new TH2F(gtitle, gtitle, 500, 0, 1000, 50, 0, 100);

	for (int iChan = 0; iChan < nChan; iChan++){
		for (int iChip = 0; iChip < nChip; iChip++){
			double hg = mean_HG_chan [itype][iV][iChip][iChan],
						 lg = mean_LG_chan [itype][iV][iChip][iChan];
			hglg->Fill(hg,lg);
			cout << "\tchip " << iChip+129 << "\tiChan " << iChan << "\tlg " << lg << "\thg " << hg << "\thg/lg " << hg/lg << endl;

		}
	}
	hglg->Draw("colz");

}

void SaturationHbuScatter(){

	TString gtitle = "Saturation for different chips and channels for HG 100fF / 400fF";

	TH2F *hglg = new TH2F(gtitle, gtitle, 4200, -200, 4000, 120, -1, 2);

	for (int iChan = 0; iChan < nChan; iChan++){
		for (int iChip = 0; iChip < nChip; iChip++){
			hglg->Fill(mean_HG_chan[0][nVcal-1][iChip][iChan], 
				mean_HG_chan[0][nVcal/2][iChip][iChan]/mean_HG_chan[1][nVcal/2][iChip][iChan] - 
				mean_HG_chan[0][nVcal-1][iChip][iChan]/mean_HG_chan[1][nVcal-1][iChip][iChan]
			);
		}
	}
	hglg->Draw("colz");

}


				

	//dependence of hg/lg of Voltage for the whole HBU
void HgLgRatioVsVoltageHbu(int itype){
	float x[nVcal], y[nVcal];
	for (int iV = 0; iV < nVcal; iV++){
		x[iV] = VCalib(iV);
		y[iV] = mean_HG[itype][iV] / mean_LG[itype][iV];
	}
	TGraph *g = new TGraph(nVcal, x, y);
	TString gtitle = "HG/LG vs V_Calib for the whole HBU "; gtitle += type[itype];
	g->SetTitle(gtitle);
	g->Draw("AC*");
}


	//dependence of hg/lg of Voltage for one channel
void HgLgRatioVsVoltageChan(int itype, int iChip, int iChan){
	float x[nVcal], y[nVcal];
	for (int iV = 0; iV < nVcal; iV++){
		x[iV] = VCalib(iV);
		y[iV] =  mean_HG_chan [itype][iV][iChip][iChan]/mean_LG_chan [itype][iV][iChip][iChan];
	}
	TGraph *g = new TGraph(nVcal, x, y);
	TString gtitle = "HG/LG vs V_Calib for "; gtitle += type[itype]; 
	gtitle += " chip "; gtitle += (iChip + 129); gtitle += " chan "; gtitle += iChan;
	g->SetTitle(gtitle);
	g->Draw("AC*");
}


	//dependence of hg/lg of PA for the whole HBU

void HgLgRatioVsPaHbu(int iV){
	float x[ntype], y[ntype];
	for (int itype = 0; itype < ntype; itype++){
		x[itype] = type[itype].Atoi();
		y[itype] = mean_HG[itype][iV] / mean_LG[itype][iV];
	}
	TGraph *g = new TGraph(ntype, x, y);
	TString gtitle = "HG/LG vs PA for V="; gtitle += VCalib(iV);
	g->SetTitle(gtitle);
	g->Draw("AC*");
}

	//dependence of hg/lg of PA for one channel
void HgLgRatioVsPaChan (int iV, int iChip, int iChan){
	float x[ntype], y[ntype];
	for (int itype = 0; itype < ntype; itype++){
		x[itype] = type[itype].Atoi();
		y[itype] = mean_HG_chan[itype][iV][iChip][iChan] / mean_LG_chan[itype][iV][iChip][iChan];
	}
	TGraph *g = new TGraph(ntype, x, y);
	TString gtitle = "HG/LG vs PA for V="; gtitle += VCalib(iV); 
	gtitle += " chip "; gtitle += (iChip + 129); gtitle += " chan "; gtitle += iChan;
	g->SetTitle(gtitle);
	g->Draw("AC*");
}

TCanvas *ModesRatioVsVoltage(bool HG = true, int iChip = -1, int iChan = -1){
	TGraph* g[2];
	TLegend* leg = new TLegend(0.6,0.7,0.9,0.9);
	float x[nVcal], xerr[nVcal], y[2][nVcal], yerr[2][nVcal];
	TCanvas *c = new TCanvas();
	TString cTitle;
	if (HG) cTitle = "HG"; else cTitle = "LG";
	cTitle += " modes Ratio vs V_Calib for "; 
	if (iChip < 0 || iChan < 0) {cTitle += "whole HBU";}
	else { cTitle += "chip "; cTitle += (iChip + 129); cTitle += " chan "; cTitle+=iChan; }
	c->SetTitle(cTitle);
	c->SetName(cTitle);
	c->cd();
	TH1F *frame = c->DrawFrame(VCalib(-1), 0, VCalib(nVcal), (HG ? 12 : 18));
	frame->SetXTitle("V_calib");
	frame->SetYTitle("mean ADC ratio with different PA");
	frame->SetTitleSize(1., "X");
	frame->SetTitleSize(1., "Y");
	frame->SetTitle(cTitle);


	for (int iV = 0; iV < nVcal; iV++){
		x[iV] = VCalib(iV);
		xerr[iV] = 0;
		double a0, a1, a2, a0err, a1err, a2err;
		a0 = GetMean(0, iV, iChip, iChan, HG);
		a1 = GetMean(1, iV, iChip, iChan, HG);
		a2 = GetMean(2, iV, iChip, iChan, HG);

		a0err = GetRms(0, iV, iChip, iChan, HG);
		a1err = GetRms(1, iV, iChip, iChan, HG);
		a2err = GetRms(2, iV, iChip, iChan, HG);

		double rat, raterrr;


		a0err += ped_err; a1err += ped_err; a2err += ped_err;
		y[0][iV] = a0 / a1;
		rat = y[1][iV] = a0 / a2;
		yerr[0][iV] = a0 / a1 * (a0err / a0 + a1err / a1);
		raterrr = (a0err / a0 + a2err / a2);
		yerr[1][iV] = a0 / a2 * (a0err / a0 + a2err / a2);

		if (!HG)  cout << iChip << "\t" << iChan << ":\t" << a0 << "\t" << rat << "\t+-" << rat*raterrr << "%" << endl;


	}
	g[0] = (errorbars ? new TGraphErrors(nVcal, x, y[0], xerr, yerr[0]) : new TGraph (nVcal, x, y[0]));
	GraphPrettify(g[0], 2);
	g[0]->SetTitle(cTitle);
	leg->AddEntry(g[0], "100fF HG / 400fF HG", "lp");
	g[0]->Draw("PC");


	g[1] = (errorbars ? new TGraphErrors(nVcal, x, y[1], xerr, yerr[0]) : new TGraph(nVcal, x, y[1]));
	GraphPrettify(g[1], 3);
	leg->AddEntry(g[1], "100fF HG/ 1575fF HG", "lp");
	g[1]->Draw("PC");


  leg->Draw();
	return c;
}

TH1F* modesRatioHist1 = NULL, *modesRatioHist2 = NULL, *modesRatioHist3 = NULL;

TCanvas *ModesScatter(bool HG = true, int iChip = -1, int iChan = -1, ofstream* f = NULL){
	TF1 l("l", "[0]*x", 0, 2300); //!fit
	double slope;
	TGraph* g[2];
	TLegend* leg = new TLegend(0.1,0.75,0.4,0.9);
	float x[nVcal], xerr[nVcal], y[2][nVcal], yerr[2][nVcal];
	TCanvas *c = new TCanvas();
	TString cTitle;
	if (HG) cTitle = "HG"; else cTitle = "LG";
	cTitle += " modes Ratio vs V_Calib for "; 
	if (iChip < 0 || iChan < 0) {cTitle += "whole HBU";}
	else { cTitle += "chip "; cTitle += (iChip + 129); cTitle += " chan "; cTitle+=iChan; }
	c->SetTitle(cTitle);
	c->SetName(cTitle);
	c->Divide(2);
	c->cd(1);
	TH1F *frame = HG ? c->DrawFrame(0, 0, 4000, 4000) : c->DrawFrame(0, 0, 1000, 500);


	for (int iV = 0; iV < nVcal; iV++){
		double a0, a1, a2, a0err, a1err, a2err;
		a0 = GetMean(0, iV, iChip, iChan, HG);
		a1 = GetMean(1, iV, iChip, iChan, HG);
		a2 = GetMean(2, iV, iChip, iChan, HG);

		a0err = GetRms(0, iV, iChip, iChan, HG);
		a1err = GetRms(1, iV, iChip, iChan, HG);
		a2err = GetRms(2, iV, iChip, iChan, HG);


		a0err += ped_err; a1err += ped_err; a2err += ped_err;
		x[iV] = a0;
		y[0][iV] = a1;
		y[1][iV] = a2;
		xerr[iV] = a0err;
		yerr[0][iV] = a1err;
		yerr[1][iV] = a2err;

	}
	g[0] = (errorbars ? new TGraphErrors(nVcal, x, y[0], xerr, yerr[0]) : new TGraph (nVcal, x, y[0]));
	GraphPrettify(g[0], 2);
	l.SetLineColor(2);
	g[0]->SetTitle(cTitle);
	g[0]->GetXaxis()->SetTitle("ADC mean 100fF");
	g[0]->GetYaxis()->SetTitle("ADC mean 400fF");
	g[0]->Fit(&l, "R+", "sames");
	leg->AddEntry(g[0], "400fF HG", "lp");
	if (modesRatioHist1){
		slope = 0;
		l.GetParameters(&slope);
		if (slope > 0 && slope < 1){
			modesRatioHist1->Fill(slope);
			if (iChip == 3 && iChan > 17) {
				modesRatioHist3->Fill(slope);
			}
			if (f) {
				*f << " 400/100\t" << ( HG ? "HG" : "LG" )<<"\t"<<iChip<<"\t"<<iChan<<"\t"<<l.GetParameter(0) << "\t" << l.GetParError(0) << endl;
			}
		}
	}
	g[0]->Draw("PC");

	c->cd(2);
	frame = HG ? c->DrawFrame(0, 0, 4000, 2000) : c->DrawFrame(0, 0, 1000, 300);

	g[1] = (errorbars ? new TGraphErrors(nVcal, x, y[1], xerr, yerr[0]) : new TGraph(nVcal, x, y[1]));
	GraphPrettify(g[1], 3);
	g[1]->GetXaxis()->SetTitle("ADC mean 100fF");
	g[1]->GetYaxis()->SetTitle("ADC mean 1575fF");
	g[1]->SetTitle(cTitle);

	l.SetLineColor(3);
	g[1]->Fit(&l, "R+", "sames");
	leg->AddEntry(g[1], "1575fF HG", "lp");
	g[1]->Draw("PC");
	if (modesRatioHist2){
		slope = 0;
		l.GetParameters(&slope);
		if (slope > 0 && slope < 1) {
			modesRatioHist2->Fill(slope);
			if (f) {
				*f << "1575/100\t"<< ( HG ? "HG" : "LG" )<<"\t"<<iChip<<"\t"<<iChan<<"\t"<<l.GetParameter(0) << "\t" << l.GetParError(0) << endl;
			}

		}
	}
	leg->Draw();
	return c;
}

TCanvas* AdcVsVoltage(bool HG = true, int iChip = -1, int iChan = -1){
	TGraph* g[ntype];
	TLegend* leg = new TLegend(0.1,0.1,0.3,0.3);
	float x[nVcal], y[ntype][nVcal], xerr[nVcal], yerr[ntype][nVcal];
	TCanvas *c = new TCanvas();
	TString cTitle;
	if (HG) cTitle = "HG"; else cTitle = "LG";
	cTitle += " vs V_Calib for ";
	if (iChip < 0 || iChan < 0) cTitle += "whole HBU";
	else {cTitle += "chip "; cTitle += (iChip + 129); cTitle += " chan "; cTitle+=iChan;}
	c->SetTitle(cTitle);
	c->SetName(cTitle);
	c->cd();
	TH1F *frame = c -> DrawFrame(VCalib(-1), 0, VCalib(nVcal), (HG ? 4000 : 1000));
	frame->SetXTitle("V_calib");
	frame->SetYTitle("mean ADC");
	frame->SetTitleSize(1., "X");
	frame->SetTitleSize(1., "Y");
	frame->SetTitle(cTitle);
	for (int itype = 0; itype < ntype; itype++){
		for (int iV = 0; iV < nVcal; iV++){
			x[iV] = VCalib(iV);
			xerr[iV] = 0;
			y   [itype][iV] = GetMean(itype, iV, iChip, iChan, HG);
			yerr[itype][iV] = GetRms (itype, iV, iChip, iChan, HG) + ped_err;
		}
		g[itype] = (errorbars ? new TGraphErrors(nVcal, x, y[itype], xerr, yerr[itype]) : new TGraph(nVcal, x, y[itype]));
		GraphPrettify(g[itype], itype + 1);
		g[itype]->SetTitle(cTitle);
		leg->AddEntry(g[itype], type[itype], "lp");
		g[itype]->Draw("PC");
	}

  leg->Draw();
	return c;
}

void ModesRatioVsVoltageToRoot(){
	gROOT->SetBatch(true);
	TFile *f = new TFile(
		outputPath + (errorbars ? "Modes_ratio_vs_V.root" : "Modes_ratio_vs_V_no_eb.root" ), "RECREATE");
	f->cd();
	MultiPadWrite(ModesRatioVsVoltage(true ), AdcVsVoltage(true ));
	MultiPadWrite(ModesRatioVsVoltage(false), AdcVsVoltage(false));
	for (int iChip = 0; iChip < nChip; iChip++){
		cout << "Chip " << iChip+129 << endl;
		for (int iChan = 0; iChan < nChan; iChan++)
			for (char HG = 0; HG < 2; HG++){
				MultiPadWrite( ModesRatioVsVoltage(HG, iChip, iChan),
											 AdcVsVoltage       (HG, iChip, iChan));
			}
	}
	f->Close();
	gROOT->SetBatch(false);
}

void ModesScatterToRoot(){
	gROOT->SetBatch(true);
	modesRatioHist1 = new TH1F("400fF / 100fF hist" , "400fF / 100fF hist", 50, 0 , 1 );
	modesRatioHist2 = new TH1F("1575fF / 100fF hist" , "1575fF / 100fF hist", 50, 0 , 1 );
	modesRatioHist3 = new TH1F("400fF / 100fF hist 3rd Chip" , "400fF / 100fF hist 3rd Chip", 50, 0 , 1 );
	ofstream* mrf = new ofstream(outputPath + "ModesRatio.tsv", ios::out | ios::trunc);
	*mrf << "#PAs\t\tG\tchip\tchan\tslope\t+-\n";
	TCanvas *c;
	TFile *f = new TFile(
		outputPath + (errorbars ? "Modes_scatter.root" : "Modes_scatter_no_eb.root" ), "RECREATE");
	f->cd();
	c = ModesScatter(true , -1, -1, mrf);
	c->Write();
	delete c;
	c = ModesScatter(false, -1, -1, mrf);
	c->Write();
	delete c;
	for (int iChip = 0; iChip < nChip; iChip++){
		cout << "Chip " << iChip+129 << endl;
		for (int iChan = 0; iChan < nChan; iChan++)
			for (char HG = 0; HG < 2; HG++){
				c = ModesScatter(HG, iChip, iChan, mrf);
				c->Write();
				delete c;
			}
	}
	modesRatioHist1->Write();
	modesRatioHist2->Write();
	modesRatioHist3->Write();
	delete modesRatioHist1;
	delete modesRatioHist2;
	delete modesRatioHist3;
	f->Close();
	mrf->close();
	delete mrf;
	gROOT->SetBatch(false);
}

TCanvas* HgLgRatioVsVoltage(int iChip = -1, int iChan = -1){
	TGraph* g[ntype];
	TLegend* leg = new TLegend(0.5,0.7,0.9,0.9);
	float x[nVcal], y[ntype][nVcal], xerr[nVcal], yerr[ntype][nVcal] ;
	TCanvas *c = new TCanvas();
	TString cTitle = "HG/LG vs V_Calib for different PA for ";
	if (iChip < 0 || iChan < 0) cTitle += "whole HBU";
	else {cTitle += "chip "; cTitle += (iChip + 129); cTitle += " chan "; cTitle+=iChan;}
	c->SetTitle(cTitle);
	c->SetName(cTitle);
	c->cd();
	TH1F *frame = c->DrawFrame(VCalib(-1), 0, VCalib(nVcal), 20);
	frame->SetXTitle("V_calib");
	frame->SetYTitle("HG / LG mean ADC ratio");
	frame->SetTitleSize(1., "X");
	frame->SetTitleSize(1., "Y");
	frame->SetTitle(cTitle);
	for (int itype = 0; itype < ntype; itype++){
		for (int iV = 0; iV < nVcal; iV++){
			x[iV] = VCalib(iV);
			xerr[iV] = 0;
			double hg, lg, hgerr, lgerr;
			hg = GetMean(itype, iV, iChip, iChan, true );
			lg = GetMean(itype, iV, iChip, iChan, false);
			hgerr = GetRms(itype, iV, iChip, iChan, true );
			lgerr = GetRms(itype, iV, iChip, iChan, false);

			y[itype][iV] = hg / lg;
			yerr[itype][iV] = hg / lg * (hgerr/hg + lgerr/lg);
		}
		g[itype] = (errorbars ? new TGraphErrors(nVcal, x, y[itype], xerr, yerr[itype]) : new TGraph(nVcal, x, y[itype]));
		TString gtitle = cTitle + " "; gtitle += type[itype];
		g[itype]->SetTitle(gtitle);
		GraphPrettify(g[itype], itype+1);
		leg->AddEntry(g[itype], type[itype], "lp");
		g[itype]->Draw("PC");
	}

  leg->Draw();
	return c;
}

void HgLgRatioVsVoltageToRoot(){
	gROOT->SetBatch(true);
	TFile *f = new TFile(
		outputPath + (errorbars ? "HgLg_ratio_vs_V.root" : "HgLg_ratio_vs_V_no_eb.root") , "RECREATE");
	f->cd();
	MultiPadWrite( HgLgRatioVsVoltage(),
								 AdcVsVoltage(true ),
								 AdcVsVoltage(false));
	for (int iChip = 0; iChip < nChip; iChip++){
		cout << "Chip " << iChip+129 << endl;
		for (int iChan = 0; iChan < nChan; iChan++){
			MultiPadWrite( HgLgRatioVsVoltage(iChip, iChan),
							 AdcVsVoltage(true,  iChip, iChan),
							 AdcVsVoltage(false, iChip, iChan));
		}	
	}
	f->Close();
	gROOT->SetBatch(false);
}

void ToRoot(int eb = 1){
	readMeans();
	double old_eb = errorbars;
	if (eb == 1 || eb == -1){
		errorbars = true;
		HgLgRatioVsVoltageToRoot();
		ModesRatioVsVoltageToRoot();
	}
	if (eb == 0 || eb == -1) {
		errorbars = false;
		HgLgRatioVsVoltageToRoot();
		ModesRatioVsVoltageToRoot();
	}
	errorbars = old_eb;
}

double GetAdequateModesRatio(int iChip, int iChan, bool HG = true, double thresold = .005){
	for (int iV = 0; iV < nVcal; iV++){
		double a0, a2, a0err, a2err, rat, raterrr;
		a0 = GetMean(0, iV, iChip, iChan, HG);
		a2 = GetMean(2, iV, iChip, iChan, HG);

		a0err = GetRms(0, iV, iChip, iChan, HG);
		a2err = GetRms(2, iV, iChip, iChan, HG);


		a0err += ped_err; a2err += ped_err;

		rat = a0 / a2;
		raterrr = (a0err / a0 + a2err / a2);

		if (a0 < 2500 && abs(raterrr) < thresold) {
			cout << iChip << "\t" << iChan << ":\t" << a0 << "\t" << rat << "\t+-" << raterrr*100 << "% \tOK" << endl;
			return rat;
		}
		else cout << iChip << "\t" << iChan << ":\t" << a0 << "\t" << rat << "\t+-" << raterrr*100 << "%" << endl; 
	}
	cout << "FAIL No adequate modes ratio: chip " << iChip + 129 << "\tchan " << iChan << endl;
	return 0;
}

void ModesRatioHist(bool HG = true, double thresold = .005){
	TH1F *h = new TH1F("modes ratio hist", "modes ratio hist", 160, 0, 20);
	for (int iChip = 0; iChip < nChip; iChip++) {
		for (int iChan = 0; iChan < nChan; iChan++){
			double k = GetAdequateModesRatio(iChip, iChan, HG, thresold);
			if (k) h->Fill(k);
			if (HG && k > 7.) cout << "strange: chip " << iChip+129 << "\tchan " << iChan << endl;
		}
	}
	h->Draw();
}

double* GetAdequateHgLgRatioFull(int iChip, int iChan, int itype, double thresold = .005){
	double *r = new double[3];
	for (int iV = 0; iV < nVcal; iV++){
		double hg, lg, hgerr, lgerr, rat, raterrr;
		hg = GetMean(itype, iV, iChip, iChan, true );
		lg = GetMean(itype, iV, iChip, iChan, false);
		hgerr = GetRms(itype, iV, iChip, iChan, true );
		lgerr = GetRms(itype, iV, iChip, iChan, false);

		rat = hg / lg;
	  raterrr = (hgerr/hg + lgerr/lg);



		if (hg < 2500 && abs(raterrr) < thresold) {
			cout << "Adequate: chip " << iChip << "\tchan " << iChan << "\tVcal " << VCalib(iV) << "\thglg " << rat <<
				 "\thg " << hg << "\tlg " << lg << endl;
			r[0] = rat; r[1] = raterrr; r[2] = iV;
			return r;
		}
	}

	return NULL;
}

double GetAdequateHgLgRatio(int iChip, int iChan, int itype, double thresold = .005){
	double* r = GetAdequateHgLgRatioFull(iChip, iChan, itype, thresold);
	if (r) {
		return r[0];
	}
	else {
		cout << "!!! strange: " << iChip+129 << "\tchan " << iChan << endl;
		return 0;
	}

}



void HgLgRatioHist(int itype, int Chip = -1, double thresold = .005){
	TH1F *h = new TH1F("hglg ratio hist", "hglg ratio hist", 160, 0, 20);
	for (int iChip = 0; iChip < nChip; iChip++) {
		for (int iChan = 0; iChan < nChan; iChan++){
			double k = GetAdequateHgLgRatio(iChip, iChan, itype, thresold);
			if (k && (Chip == -1 || iChip == Chip)) h->Fill(k);
			if ( k < 0.) cout << "strange: k "<< k << "\tchip " << iChip+129 << "\tchan " << iChan << endl;
		}
	}
	h->Draw();
}

void HgLgRatioRatioHist(int Chip = -1, double thresold = .005){
	TCanvas *c = new TCanvas();
	c->Divide(2);
	TString h1Title = "(hg/lg)_400fF / (hg/lg)_100fF hist",
					h2Title = "(hg/lg)_1575fF / (hg/lg)_100fF hist";

	TH1F *h1 = new TH1F(h1Title, h1Title, 160, 0, 2),
			 *h2 = new TH1F(h2Title, h2Title, 160, 0, 2);
	for (int iChip = 0; iChip < nChip; iChip++) {
		for (int iChan = 0; iChan < nChan; iChan++){
			double k0 = GetAdequateHgLgRatio(iChip, iChan, 0, thresold),
						 k1 = GetAdequateHgLgRatio(iChip, iChan, 1, thresold),
						 k2 = GetAdequateHgLgRatio(iChip, iChan, 2, thresold);

			if (k0 && k1 && (Chip == -1 || iChip == Chip)) h1->Fill(k1/k0);
			if (k0 && k2 && (Chip == -1 || iChip == Chip)) h2->Fill(k2/k0);
		}
	}
	c->cd(1);
	h1->Draw();
	c->cd(2);
	h2->Draw();
}


void HgLgRatioScatter(int itype){
	TString cTitle = "hg/lg vs hg and lg scatters ";
	cTitle += type[itype];
	TCanvas *c = new TCanvas(cTitle, cTitle);
	c->Divide(2);
	TH2F *hh = new TH2F("hglg ratio vs hg", "hglg ratio vs hg", 160, 0, 20, 160, 0, 2000);
	TH2F *hl = new TH2F("hglg ratio vs lg", "hglg ratio vs lg", 160, 0, 20, 160, 0, 250);
	hh->SetXTitle("hg/lg");
	hl->SetXTitle("hg/lg");
	hh->SetYTitle("hg");
	hl->SetYTitle("lg");
	for (int iChip = 0; iChip < nChip; iChip++) {
		for (int iChan = 0; iChan < nChan; iChan++){
			double* k = GetAdequateHgLgRatioFull(iChip, iChan, itype);
			if (k) {
				hh->Fill(k[0], GetMean(itype, k[2], iChip, iChan, true ));
				hl->Fill(k[0], GetMean(itype, k[2], iChip, iChan, false));
				if ( k[0] < 0.) cout << "strange: k "<< k << "\tchip " << iChip+129 << "\tchan " << iChan << endl;
				delete[] k;
			}
		}
	}
	c->cd(1);
	hh->Draw("colz9");
	c->cd(2);
	hl->Draw("colz9");

}

void HgLgScatter(int itype){
	gStyle->SetOptFit(11111111);
	gStyle->SetOptStat(11111111);
	TString cTitle = "hg vs lg  ";
	cTitle += type[itype];
	TCanvas *c = new TCanvas(cTitle, cTitle);
	c->Divide(2);
	gStyle->SetOptFit(11111111);
	gStyle->SetOptStat(11111111);
	TH2F *h = new TH2F("hg vs lg", "hg vs lg", 800, 0, 2000, 800, 0, 4000);
	h->SetXTitle("hg");
	h->SetXTitle("lg");
	for (int iChip = 0; iChip < nChip; iChip++) {
		for (int iChan = 0; iChan < nChan; iChan++){
			for (int iV = 0; iV < nVcal; iV++){
					double hg = GetMean(itype, iV, iChip, iChan, true ),
								 lg = GetMean(itype, iV, iChip, iChan, false);
					if (true || hg < 2500 && lg > 50 && hg > 1500) h->Fill(lg, hg);
			}
		}
	}
	c->cd(1);
	TProfile *prof = h->ProfileX();
	TProfile::Approximate(1);
	prof->Fit("pol1");
	gStyle->SetOptFit(11111111);
	gStyle->SetOptStat(11111111);

	c->cd(2);
	gStyle->SetOptFit(11111111);
	gStyle->SetOptStat(11111111);

	h->Draw("colz9");
}



void PedHist(int itype, bool HG, bool NoFit){
	TString cTitle = "Pedestal ";
	cTitle += (HG ? "HG " : "LG ");
	cTitle += (NoFit ? "NoFit" : "Fit");
	TCanvas *c = new TCanvas(cTitle, cTitle);
	c->cd();
	TH1F *h = new TH1F ("ped", "ped", 400, 0, 400);
	for (int iChip = 0; iChip < nChip; iChip++){
		for (int iChan = 0; iChan < nChan; iChan++){
			h->Fill(GetPedMean(itype, iChip, iChan, HG, NoFit));
		}
	}
	h->Draw();

}

