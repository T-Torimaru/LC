//============================================================================
// Name        : 
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Edit ~361 for LG/HG ADC or HG ADC/TDC
#include <stdlib.h>
#include <math.h>
#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TF1.h>
#include <TProfile.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <dirent.h>
#include <algorithm>
#include <TPaveText.h>
#include <TDirectory.h>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TString.h>

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

int main (int argc, char **argv)
{

  float Threshold = 0.25;
  int NThreshold = 16;
  int Threshold_start = 200;
  int step = 10;

  int LY = 30;//Light Yield
  int Gain = 13;//Gain
  
  /////////Get list of files and split into ET and AT/////////////////
  vector<string> fnames_ET, fnames_AT;

  string ext = ".root";//set file types
  string AT_path = "/home/calice/Commissioning/SM_1/Threshold_Scan/Rootfiles/";//set folder for raw root data(AT)
  string ET_path = "/home/calice/Commissioning/SM_1/Gain_650fF/Rootfiles/"; //ET, because we have many folders... 
  string Ped_path = "/home/calice/Commissioning/SM_1/Gain_650fF/Rootfiles/VCalib_1500cycles_0000mV_ET__14p07p2016__14o06o49.root"; //Ped, and even more folders...
  
  string output_root_path ="/home/calice/Commissioning/SM_1/Threshold_Scan/output_threshold/thres_scan.root"; //output root path
  string output_threshold_path ="/home/calice/Commissioning/SM_1/Threshold_Scan/output_threshold/Threshold_values.tsv";
 
  string fitparameters_output_path ="/home/calice/Commissioning/SM_1/Threshold_Scan/output_threshold/fitparam.txt"; //output txt for fit results
  string channels_turnOff_list =""; //path for list of disabled channels
  string ADC_per_MIP_list ="/home/calice/Commissioning/SM_1/Threshold_Scan/output_threshold/dummy_mip.txt";//ADC/MIP which includes pedestal.It will be subtracted

  //Make a vector of files for pedestal, AT and ET files (need to match AT/ET files with LED voltage)
  //Get first list of AT files

  fnames_AT = GetListOfFiles(AT_path, ext);
  vector<string> fnames_ET_temp = GetListOfFiles(ET_path, ext);
  
  vector<string> voltageList_AT;
  
  //Get list of LED Voltage in AT
  for(int i = 0; i < fnames_AT.size(); i++)
    {
      string voltage = fnames_AT.at(i).substr( fnames_AT.at(i).find("mV")-4, 4 );
      if( find(voltageList_AT.begin(), voltageList_AT.end(), voltage) == voltageList_AT.end() )
	voltageList_AT.push_back(voltage);
    }

  for(int i = 0; i < voltageList_AT.size(); i++)
    {
      cout << "Voltage done in AT " << voltageList_AT.at(i) << endl;
    }

  //Delete ET files that don t have corresponding AT LED Voltage
  for(vector<string>::iterator it = fnames_ET_temp.begin(); it != fnames_ET_temp.end(); ++it)
    {
      string voltage = (*it).substr( (*it).find("mV")-4, 4 );
      if( find(voltageList_AT.begin(), voltageList_AT.end(), voltage) != voltageList_AT.end() )
	{
	  fnames_ET.push_back(*it);
	}
    }
  
  cout << "ET vector size " << fnames_ET.size() << endl;
  cout << "AT vector size " << fnames_AT.size() << endl;
 
  ///////////////Steps for LED range//////////////////
  //int strvol=atoi((fnames_ET.at(0).substr(5,4)).c_str());
  //int dvol=atoi((fnames_ET.at(1).substr(5,4)).c_str())-atoi((fnames_ET.at(0).substr(5,4)).c_str());
  //voltage increment per step, not for runs with different voltage increament per step
    
  /////////////Make directory and histograms///////////////////
  gStyle->SetOptFit(1111);//maybe useless
  int binSize = 16; //histogram bin size
  int bin=4096/binSize; //histogram bin count for 12 bit ADC
  TCanvas* c1 = new TCanvas("c1","",800,600);
  TFile *output_file = new TFile (output_root_path.c_str(),"RECREATE");
  TDirectory *dirChannelsOff = output_file->mkdir("Channels_Off");
  TDirectory *dirPedestal = output_file->mkdir("Pedestal");
  TDirectory *dirSpectra = output_file->mkdir("Spectra");
  TDirectory *dirSubSpectra[4][36];
  TDirectory *dirgRatio=output_file->mkdir("gRatio");
  TDirectory *dirRatio = output_file->mkdir("Ratio");
  TDirectory *dirParDists = output_file->mkdir("ParDists");
  TDirectory *dirTrgPos = dirParDists->mkdir("TrgPosition");
  TDirectory *dirTrgWidth = dirParDists->mkdir("TrgWidth");
  TDirectory *dirFitSlope = dirParDists->mkdir("hFitSlope");
  TDirectory *dirFitOffset = dirParDists->mkdir("hFitOffset");
  TDirectory *dirFitRedChiSqr = dirParDists->mkdir("hFitRedChiSqr");
  TDirectory *dirGraph = output_file->mkdir("Graphs");
  TDirectory *dirProfile = output_file->mkdir("Profile");
  TDirectory *dirThreshold = output_file->mkdir("Threshold");
  
  //create subfolders
  for (int i=0; i<4; i++){
    for (int j=0; j<36; j++){
      dirSubSpectra[i][j] = dirSpectra->mkdir(TString::Format("Spectra_Chip_%d_Chn_%d",i,j));
    }
  }
  //create profile plots
  dirProfile->cd();
  TProfile *pTrgPos[4];
  TProfile *pTrgWidth[4];
  for (int ichip = 0; ichip<4; ichip++){
    pTrgPos[ichip]= new TProfile(TString::Format("pTrgPos_%d",ichip),TString::Format("pTrgPos_%d",ichip), 3, 275, 425, 0, 4000,"s");
    pTrgWidth[ichip]= new TProfile(TString::Format("pTrgWidth_%d", ichip),TString::Format("pTrgWidth_%d",ichip), 3, 275, 425, 0, 200,"s"); 
    //pTrgPos[ichip]= new TProfile(TString::Format("pTrgPos_%d",ichip),TString::Format("pTrgPos_%d",ichip), 4000/50, 25, 4025, 275, 425,"s");
    //pTrgWidth[ichip]= new TProfile(TString::Format("pTrgWidth_%d", ichip),TString::Format("pTrgWidth_%d",ichip), 4000/50, 25, 4025, 275, 425,"s"); 
  }
  
  //create graphs
  dirGraph->cd();
  TGraphErrors *gTrgPos[4][36];
  for (int ichip = 0; ichip<4; ichip++){
    for (int ichn = 0; ichn<36; ichn++){
      gTrgPos[ichip][ichn]= new TGraphErrors();
    }
  }
  //create histograms for fit position, width, slope, offset and reduced chi square
  dirParDists->cd();
  TH1F *hTrgPos[NThreshold][4];
  TH1F *hTrgWidth[NThreshold][4];
  TH1F *hFitSlope[4];
  TH1F *hFitOffset[4];
  TH1F *hFitRedChiSqr[4];
  for (int ithr = 0; ithr<NThreshold; ithr++){
    for (int ichip = 0; ichip<4; ichip++){
      dirTrgPos->cd();
      hTrgPos[ithr][ichip]= new TH1F(TString::Format("hTrgPos_%d_%d",ithr*step+Threshold_start, ichip),TString::Format("hTrgPos_%d_%d",ithr*step+Threshold_start, ichip),400, 0, 4000);
      dirTrgWidth->cd();
      hTrgWidth[ithr][ichip]= new TH1F(TString::Format("hTrgWidth_%d_%d",ithr*step+Threshold_start, ichip),TString::Format("hTrgWidth_%d_%d",ithr*step+Threshold_start, ichip),40, 0, 200);
    }
  }
  for (int ichip = 0; ichip<4; ichip++){
    dirFitSlope->cd();
    hFitSlope[ichip]= new TH1F(TString::Format("hFitSlope_%d", ichip),TString::Format("hFitSlope_%d", ichip),50, 0, 5);
    dirFitOffset->cd();
    hFitOffset[ichip]= new TH1F(TString::Format("hFitOffset_%d", ichip),TString::Format("hFitOffset_%d", ichip),100, -1000, 0);
    dirFitRedChiSqr->cd();
    hFitRedChiSqr[ichip]= new TH1F(TString::Format("hFitRedChiSqr_%d", ichip),TString::Format("hFitRedChiSqr_%d", ichip),100, 0, 10);
  }
  
  //create histograms for ET, AT & pedestal
  dirSpectra->cd();
  TH1F *hET[4][36];
  //TH1F *h2ET[4][36];
  //TH1F *hAT[3][4][36];
  TH1F *hAT_scale[NThreshold][4][36];
   
  for (int ichip = 0; ichip<4; ichip++){
    for (int ichn = 0; ichn<36; ichn++){
      dirSubSpectra[ichip][ichn]->cd();
      hET[ichip][ichn] = new TH1F(TString::Format("ADC_HG_ET_%d_%d_Sum", ichip, ichn),
				  TString::Format("ADC_HG_ET_Chip_%d_Chn_%d_Sum", ichip, ichn),bin, 0,4095);
      //h2ET[ichip][ichn] = new TH1F(TString::Format("ADC_HG_ET_%d_%d_Sum_Unscaled", ichip, ichn),
      //				  TString::Format("ADC_HG_ET_Chip_%d_Chn_%d_Sum_Unscaled", ichip, ichn),bin, 0,4095);
      for (int ithr = 0; ithr<NThreshold; ithr++){
	//hAT[ithr][ichip][ichn] = new TH1F(TString::Format("ADC_HG_AT_%d_%d_%d_Sum_Unscaled", 300+50*ithr, ichip, ichn),
	//				  TString::Format("ADC_HG_AT_Thr_%d_Chip_%d_Chn_%d_Sum_Unscaled", 300+50*ithr, ichip, ichn),bin, 0, 4095);
	hAT_scale[ithr][ichip][ichn] = new TH1F(TString::Format("ADC_HG_AT_%d_%d_%d_Sum", ithr*step+Threshold_start, ichip, ichn),
						TString::Format("ADC_HG_AT_Thr_%d_Chip_%d_Chn_%d_Sum", ithr*step+Threshold_start, ichip, ichn),bin, 0, 4095);
	//hAT[ithr][ichip][ichn]->Sumw2();
	hAT_scale[ithr][ichip][ichn]->Sumw2();
      }
      hET[ichip][ichn]->Sumw2();
      //h2ET[ichip][ichn]->Sumw2();
    }
  }

  dirPedestal->cd();
  TH1F *hPed[4][36];
  for (int ichip = 0; ichip<4; ichip++){
    for (int ichn = 0; ichn<36; ichn++){
      hPed[ichip][ichn] = new TH1F(TString::Format("ADC_HG_Ped_%d_%d_Sum", ichip, ichn),
				   TString::Format("ADC_HG_Ped_Chip_%d_Chn_%d_Sum", ichip, ichn),501, 0,500);
    }
  }


  //create histogram  divide plots, just for crosscheck, can remove actually since it was replaced with TGraphAsymmErrors...
  dirRatio->cd();
  TH1F *hRatio[NThreshold][4][36];
  for (int ichip = 0; ichip<4; ichip++){
    for (int ichn = 0; ichn<36; ichn++){
      for (int ithr = 0; ithr<NThreshold; ithr++){
	hRatio[ithr][ichip][ichn] = new TH1F(TString::Format("hRatio_%d_%d_%d",ithr*step+Threshold_start, ichip, ichn),
					     TString::Format("hRatio_%d_%d_%d",ithr*step+Threshold_start, ichip, ichn),bin,0,4095);
      }
    }
  }
  
  //create divide graphs using TGraphAsymmError to apply uneven errors
  dirgRatio->cd();
  TGraphAsymmErrors *gr[NThreshold][4][36];
 
  ////////Fill Pedestal and get mean, i should do the correction for memory cell offset but i didn't..//////////
  int nentries = 0; float ref_cy = 0;//int chip_start = 169;
 
  int Cy=0; int ChipID=0;int chn=0; int TDC=0;int ADC=0;int Hit_Bit=0;int Gain_Bit=0;
  TBranch *b_Cy=0; TBranch *b_ChipID=0; TBranch *b_chn=0; TBranch *b_TDC=0; TBranch *b_ADC=0; TBranch *b_Hit_Bit=0; TBranch *b_Gain_Bit=0;
  
  //Fill pedestal histogram
  TFile* myFile = TFile::Open(Ped_path.c_str());
  TTree* myTree = (TTree*)myFile->Get("tree"); 
  myTree->SetBranchAddress("CycleNr",&Cy,&b_Cy);
  myTree->SetBranchAddress("ChipID2", &ChipID, &b_ChipID);
  myTree->SetBranchAddress("chn", &chn, &b_chn);
  myTree->SetBranchAddress("TDC", &TDC, &b_TDC);
  myTree->SetBranchAddress("ADC", &ADC, &b_ADC);

  nentries = myTree->GetEntries();
  myTree->GetEntry(1); 
  int chip_start = ChipID;
  cout<<"\nProceding with chip ID: "<<chip_start<<" to "<<chip_start+3<<"\n"<<endl;
  usleep(2000000);
  cout<<"Filling plot for: " << Ped_path <<endl;
  
  for (int k=0; k<nentries; k++){
    myTree->GetEntry(k);
    if (ADC != 0 && TDC != 0 && ChipID >= chip_start && ChipID <= chip_start+3){
      hPed[ChipID-chip_start][chn]->Fill(TDC);//HG_LG mode
    }
  }
  myFile->Close();

  cout<<"\nCalculating pedestal mean..."<<endl;
  float Pedestal_Mean[4][36];
  float fit_range_sigma = 1.65;
  for (int ichip = 0; ichip < 4; ichip++){
    for (int ichn =0; ichn < 36; ichn++){
      int maxheight=0;
      int maxpos=0;
      float ped_rms = hPed[ichip][ichn]->GetRMS();
      for (int pedbin=1; pedbin<501; pedbin++){
	int temp = hPed[ichip][ichn]->GetBinContent(pedbin);
	if (maxheight<temp){
	  maxheight=temp;
	  maxpos=pedbin;
	}
      }
      Pedestal_Mean[ichip][ichn]=hPed[ichip][ichip]->GetXaxis()->GetBinCenter(maxpos);
      //cout<<maxheight<<"\t"<<maxpos<<"\t"<< Pedestal_Mean[ichip][ichn]<<endl;
      hPed[ichip][ichn]->GetXaxis()->SetRangeUser(maxpos-ped_rms*2,maxpos+ped_rms*2);
      Pedestal_Mean[ichip][ichn] = hPed[ichip][ichn]->GetMean();
      cout<<"Pedestal for chip "<<ichip<<" channel "<<ichn<<" has a mean of: "<<Pedestal_Mean[ichip][ichn]<<endl;
      // usleep(10000000);
    }
  }

  ////////////Fill AT && ET histograms, i should also do the memory cell correction.. ////////////
  //Fill ET histogram
  for (int ipath = 0; ipath<fnames_ET.size(); ipath++){
    TFile* myFile = TFile::Open((ET_path + fnames_ET.at(ipath)).c_str());
    TTree* myTree = (TTree*)myFile->Get("tree"); 
    cout<<"Filling plot for: "+fnames_ET.at(ipath)<<endl;
    //int ivolt = (atoi(fnames_ET.at(ipath).substr(5,4).c_str())-strvol)/dvol;//eg. scan_6000_0_AT_300...
    myTree->SetBranchAddress("CycleNr",&Cy,&b_Cy);
    myTree->SetBranchAddress("ChipID2", &ChipID, &b_ChipID);
    myTree->SetBranchAddress("chn", &chn, &b_chn);
    myTree->SetBranchAddress("TDC", &TDC, &b_TDC);
    myTree->SetBranchAddress("ADC", &ADC, &b_ADC);
    	
    nentries = myTree->GetEntries();
    if (ipath == 0){ //Get total cycle for first run in ET, all other cycles will be scaled to this
      myTree->GetEntry(nentries-1);
      ref_cy = Cy;
      cout<<"reference cycle: "<<ref_cy<<endl;
    }
    else {
      myTree->GetEntry(nentries-1);
      cout<<"Total cycle in run: "<<Cy<<endl;
    }
    float scale = ref_cy/Cy;//Scalling factor for histogram division	
    cout<<"scale: "<<scale<<endl;
    for (int k=0; k<nentries; k++){
      myTree->GetEntry(k);
      if (ADC != 0 && TDC != 0 && ChipID >= chip_start && ChipID <= chip_start+3 ){
	hET[ChipID-chip_start][chn]->Fill(ADC-Pedestal_Mean[ChipID-chip_start][chn],scale);//TDC off!!
	//h2ET[ChipID-chip_start][chn]->Fill(TDC);
      }
    }
    myFile->Close();
  }

  cout << "Fill AT histo " << endl;
  
  //Fill AT histogram
  for (int ipath = 0; ipath<fnames_AT.size(); ipath++){
    size_t found = fnames_AT.at(ipath).find("AT_");
    int ithr = 0;
    if(found!=std::string::npos)
      {
	cout << "AT_ found at " << found << endl;
	ithr = (atoi(fnames_AT.at(ipath).substr(found+3,3).c_str()) - Threshold_start)/step;//threshold number..
	cout << "Threshold : " << ithr << endl;
      }
    else
      {
	cout << "Can't find Threshold value..." << endl;
	exit(1);
      }

    if(ithr >= NThreshold) continue;
    
    TFile* myFile = TFile::Open((AT_path + fnames_AT.at(ipath)).c_str());
    TTree* myTree = (TTree*)myFile->Get("tree"); 
    cout<<"Filling plot for: "+fnames_AT.at(ipath)<<endl;
    myTree->SetBranchAddress("CycleNr",&Cy,&b_Cy);
    myTree->SetBranchAddress("ChipID2", &ChipID, &b_ChipID);
    myTree->SetBranchAddress("chn", &chn, &b_chn);
    myTree->SetBranchAddress("TDC", &TDC, &b_TDC);
    myTree->SetBranchAddress("ADC", &ADC, &b_ADC);
    myTree->SetBranchAddress("Hit_Bit", &Hit_Bit, &b_Hit_Bit);
    myTree->SetBranchAddress("Gain_Bit", &Gain_Bit, &b_Gain_Bit);
    nentries = myTree->GetEntries();
    myTree->GetEntry(nentries-1);
    cout<<"Total cycle in run: "<<Cy<<endl;
    float scale = ref_cy/Cy;	
    cout<<"scale: "<<scale<<endl;
    for (int k=0; k<nentries; k++){
      myTree->GetEntry(k);
      if (ADC != 0 && TDC != 0 && Hit_Bit == 1 && Gain_Bit==1 && ChipID >= chip_start && ChipID <= chip_start+3){
	//hAT[ithr][ChipID-chip_start][chn]->Fill(TDC);
	hAT_scale[ithr][ChipID-chip_start][chn]->Fill(ADC-Pedestal_Mean[ChipID-chip_start][chn],scale);
      }
    }
    myFile->Close();
  }

  //////////Divide and fit///////////////

  cout << "Dividing AT/ET" << endl;
 
  TF1 *fScurve = new TF1("fScurve","[2]*(TMath::Erf((x-[0])/[1])/2+0.5)",0,2000);//fitting function
  float bErr_ratio[NThreshold][4][36][bin];//array for errors of divided spectra AT/ET
  float gx[NThreshold][4][36][bin]; //array for TGraphAsymmError x points, which is just the bin position on x
  float gy[NThreshold][4][36][bin]; //array for TGraphAsymmError y points
  
  for (int ichip=0; ichip<4; ichip++){
    for (int ichn=0; ichn<36; ichn++){
      for (int ibin=0; ibin<bin; ibin++){ //calculate for each bin to create points for TGraphAsymmError
	float bET = hET[ichip][ichn]->GetBinContent(ibin+1);//Get ET spectra bin content and error
	if (bET>0){ //ET with bin content of 0 will not be divided nor taken into account when fit
	  float bETerr = hET[ichip][ichn]->GetBinError(ibin+1);
	  for (int ithr=0; ithr<NThreshold; ithr++){ //For each trigger threshold, get AT spectra bin content and error
	    //cout << "Threshold " << ithr << endl;
	    float bAT = (hAT_scale[ithr][ichip][ichn]->GetBinContent(ibin+1));
	    float bATerr = hAT_scale[ithr][ichip][ichn]->GetBinError(ibin+1);
	    hRatio[ithr][ichip][ichn]->Fill((ibin)*binSize,bAT/bET);
	    if (bAT==0){
	      bErr_ratio[ithr][ichip][ichn][ibin] = 1/bET*sqrt(1+pow(bETerr/bET,2));//error calculation for AT/ET = 0
	      gx[ithr][ichip][ichn][ibin] = ibin;
	      gy[ithr][ichip][ichn][ibin] = bAT/bET;
	    }
	    else {
	      bErr_ratio[ithr][ichip][ichn][ibin] = bAT/bET*sqrt(pow(bATerr/bAT,2)+pow(bETerr/bET,2));//error calculation for AT/ET>0
	      gx[ithr][ichip][ichn][ibin] = ibin;
	      gy[ithr][ichip][ichn][ibin] = bAT/bET;
	    } 	   	     
	  }
	}
	else { //set all other points/bins for TGraphAsymmError to 0
	  for (int ithr=0; ithr<NThreshold; ithr++){
	    gx[ithr][ichip][ichn][ibin] = ibin;
	    gy[ithr][ichip][ichn][ibin] = 0;
	  }
	}
      }
    }
  }
 
  //define bla bla to plot asymmetric error graph
  const int n = 256;
  float x[n] = {0};
  float y[n] = {0};
  float exl[n]= {0};
  float eyl[n] = {0};
  float exh[n] = {0};
  float eyh[n] = {0};

  cout << "create asymmetric error graph" << endl;
  
  //create asymmetric error graph
  for (int ichip=0; ichip<4; ichip++){
    for (int ichn=0; ichn<36; ichn++){
      for (int ithr=0; ithr<NThreshold; ithr++){
	for (int i=0; i<n; i++){
	  x[i]=gx[ithr][ichip][ichn][i]*16+8;
	  y[i]=gy[ithr][ichip][ichn][i];
	  exl[i]=binSize/2;
	  exh[i]=binSize/2;
	  if (y[i]==0){
	    eyl[i] = 0;
	    eyh[i] = bErr_ratio[ithr][ichip][ichn][i];
	  }
	  else {
	    eyl[i] = bErr_ratio[ithr][ichip][ichn][i];
	    if ((y[i]-eyl[i])<0) eyl[i] = y[i];
	    eyh[i] = bErr_ratio[ithr][ichip][ichn][i];
	  }
	}
	gr[ithr][ichip][ichn] = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
	gr[ithr][ichip][ichn]->SetName(TString::Format("gr_%d_%d_%d",ithr*step+Threshold_start,ichip,ichn));

	dirgRatio->Add(gr[ithr][ichip][ichn]);
      }
    }
  }

  cout << "Do Fit" << endl;
  
  //now, divide and fit, then get fit parameters and put into profile, histogram and graphs
  output_file->cd();
  ofstream output_par(fitparameters_output_path.c_str()); 
  output_par<<"#Chip\tChannel\tOffset\tOffset_Error\tSlope\tSlope_Error\tRedChiSqr\tPedestalMean"<<endl;
  for (int ichip=0; ichip<4; ichip++){
    cout<<"Fitting ratio for chip:"<<"\t"<<ichip<<endl;
    for (int ichn=0; ichn<36; ichn++){
      for (int ithr=0; ithr<NThreshold; ithr++){
	float trgPosEstimate = hRatio[ithr][ichip][ichn]->GetBinCenter(hRatio[ithr][ichip][ichn]->FindFirstBinAbove(Threshold));//Find bin above X MIP
	float range = 200; //range of fit
	fScurve->SetParameter(0,trgPosEstimate);
	fScurve->SetParameter(1,20);
	fScurve->FixParameter(2,1);
	gr[ithr][ichip][ichn]->Fit(fScurve,"Q","",trgPosEstimate-range,trgPosEstimate+range); 
	pTrgPos[ichip]->Fill(ithr*step+Threshold_start,fScurve->GetParameter(0));
	pTrgWidth[ichip]->Fill(ithr*step+Threshold_start,fScurve->GetParameter(1));
	hTrgPos[ithr][ichip]->Fill(fScurve->GetParameter(0));
	hTrgWidth[ithr][ichip]->Fill(fScurve->GetParameter(1));
	//gTrgPos[ichip][ichn]->SetPoint(ithr,fScurve->GetParameter(0),ithr*50+300);
	gTrgPos[ichip][ichn]->SetPoint(ithr,ithr*step+Threshold_start,fScurve->GetParameter(0));
	//gTrgPos[ichip][ichn]->SetPointError(ithr,fScurve->GetParError(0),0);
	gTrgPos[ichip][ichn]->SetPointError(ithr,0,fScurve->GetParError(0));
      }
    }
  }

  //do profile plot for each chip
  dirProfile->cd();
  for (int ichip = 0; ichip<4; ichip++){
    cout<<"Fitting pTrgPos for chip:"<<"\t"<<ichip<<endl;
    pTrgPos[ichip]->Fit("pol1","Q");
  }

  //for each channel, get ADC vs DAC slope, offset, chisqr, erros.. output to txt file for 0.5MIP position calculation
  dirGraph->cd();
  for (int ichip = 0; ichip<4; ichip++){
    for (int ichn = 0; ichn<36; ichn++){
      cout<<"Fitting gTrgPos of chip: "<<ichip<<"\tchn:"<<ichn<<endl;
      gTrgPos[ichip][ichn]->Fit("pol1","Q");
      TF1 *f = gTrgPos[ichip][ichn]->GetFunction("pol1");
      float fitSlope = f->GetParameter(1);
      float fitOffset = f->GetParameter(0);
      float fitChi2 = f->GetChisquare()/f->GetNDF();
      output_par<<ichip<<"\t"<<ichn<<"\t"<<f->GetParameter(0)<<"\t"<<f->GetParError(0)<<"\t"<<f->GetParameter(1)<<"\t"<<f->GetParError(1)<<"\t"<<f->GetChisquare()/f->GetNDF()<<"\t"<<Pedestal_Mean[ichip][ichn]<<endl;
      hFitSlope[ichip]->Fill(fitSlope);
      hFitOffset[ichip]->Fill(fitOffset);
      hFitRedChiSqr[ichip]->Fill(fitChi2);
      gTrgPos[ichip][ichn]->Write(TString::Format("gTrgPos_%i_%i", ichip, ichn));
    }
  }
  output_par.close();
  
  //////////New section to read channels that are off///////////////
  int dis_layerID = 0;
  int dis_chipID = 0;
  int dis_chnID = 0;
  int at = 0;
  int et = 0;
  int count[4]={0};
  bool enable[4][36];
  for (int ichip=0;ichip<4;ichip++){
    for (int ichn=0;ichn<36;ichn++){
      enable[ichip][ichn]=true;
    }
  }

  //Read list for channels that are turned off
  ifstream f(channels_turnOff_list.c_str());
  while (1){
    char line[256];
    f.getline(line,256);
    if(line[0]=='#') continue;
    if (strlen(line)==0) break;
    sscanf(line, "%i %i %i %i %i", &dis_layerID,&dis_chipID,&dis_chnID,&at,&et);
    enable[dis_chipID][dis_chnID]=false;
    count[dis_chipID]++;
  }
  f.close();
  
  dirChannelsOff->cd();
  TCanvas *c = new TCanvas("c");
  TPaveText *pt = new TPaveText(.05,.1,.95,.8);
  pt->AddText("List of channels turned off");
  pt->AddText("**********************************************");
  for (int ichip=0; ichip<4; ichip++){
    for (int ichn=0;ichn<36;ichn++){
      if (enable[ichip][ichn]==false){
	pt->AddText(TString::Format("Chip_%d_Channel_%d", ichip, ichn));
      }
    }
  }
  pt->AddText("********************END***********************");
  pt->Draw();
  dirChannelsOff->Add(c);

  cout<<"-------------------------------------------------------------------------------------------------"<<endl;
  for (int ichip=0;ichip<4;ichip++){
    //cout<<"Chip "<<ichip<<" has "<<count[ichip]<<" channels off"<<endl;
  }
  
  int mip_adc[4][36]={{0}};
  int ichip = 0;
  int ichn =0;
  int tmip =0;

  //Read MIP (pedestal + signal) list
  ifstream f2(ADC_per_MIP_list.c_str());
  while (1){
    char line[256];
    f2.getline(line,256);
    if(line[0]=='#') continue;
    if (strlen(line)==0) break;
    sscanf(line, "%i %i %i",&ichip, &ichn, &tmip);
    mip_adc[ichip][ichn]=tmip;
    //cout <<"Chip: "<<ichip<<"\tChannel: "<<ichn<<"\tADC/MIP: "<<mip_adc[ichip][ichn]<<endl;
  }
  f2.close();

  int chip=0;
  int chan=0;
  float bad_chn[4]={0};
  float offset=0;
  float offset_err=0;
  float slope=0;
  float slope_err=0;
  float redchisqr=0;
  float pedestal=0;
  float DAC[4][36]={{0}};
  float ADC_halfmip=0;
  
  cout<<"-------------------------------------------------------------------------------------------------"<<endl;
  //Make histograms for hDAC of 0.5MIP
  dirThreshold->cd();
  TH1F *hDAC[4];
  TH1F *hDAC_all[4];

  for (int ih=0; ih<4; ih++){
    hDAC[ih] = new TH1F(TString::Format("hDAC_chip_%d",ih),TString::Format("hDAC_chip_%d",ih),30,-100,1000);
    hDAC_all[ih] = new TH1F(TString::Format("hDAC_all_chip_%d",ih),TString::Format("hDAC_all_chip_%d",ih),30,-100,1000);
  }


  ifstream fin(fitparameters_output_path.c_str());
  while (1){
    char line[256];
    fin.getline(line,256);
    if(line[0]=='#') continue;
    if (strlen(line)==0) break;
    sscanf(line, "%i %i %f %f %f %f %f %f", &chip, &chan, &offset, &offset_err, &slope, &slope_err, &redchisqr, &pedestal );
    if (enable[chip][chan]==false) continue;
    ADC_halfmip =  LY*Gain*Threshold; //substract MIP from pedestal
    DAC[chip][chan] = (ADC_halfmip-offset)/slope;

    hDAC_all[chip]->Fill(DAC[chip][chan]);

    if (redchisqr>1e3||redchisqr<1e-5||slope<1.0||offset>1e3||offset<-1e3){ //limits to select good and bad data for channels
      //cout<<"Bad data! Check:\tChip: "<<chip<<"\tChannel: "<<chan<<"  \tOffset: "<<offset<<"  \tSlope: "<<slope<<"    \tRedChiSqr: "<<redchisqr<<endl;
      bad_chn[chip]=bad_chn[chip]+1;
    }
    else {
      if (DAC[chip][chan]<0){
        //cout<<"Bad data! Check:\tChip: "<<chip<<"\tChannel: "<<chan<<" \tOffset: "<<offset<<"  \tSlope: "<<slope<<"   \tRedChiSqr"<<redchisqr<<endl;
        bad_chn[chip]=bad_chn[chip]+1;
      }

      else {
        hDAC[chip]->Fill(DAC[chip][chan]);
      }
    }
  }

  fin.close();

  cout<<"-------------------------------------------------------------------------------------------------"<<endl;

  for (int i=0;i<4;i++){
    cout<<"Chip "<<i<<" has "<<bad_chn[i]<<" channels with bad data: " <<bad_chn[i]/36*100<<"% ("<< count[i] << " disabled channels already excluded)"<<endl;
  }

  cout<<"------------------------------------------------------------------------------------------------"<<endl;

  ofstream threshold(output_threshold_path.c_str(), ios::out | ios::trunc);
  threshold << "Chip " << "\t "<< Threshold << " MIP DAC threshold \t Error" << endl;

  for (int i=0;i<4;i++){
    cout<<"Chip: "<<i<< " " << Threshold << "MIP DAC threshold = "<< hDAC[i]->GetMean() << " +/- " << hDAC[i]->GetRMS() <<endl;
    threshold << i << "\t " << hDAC[i]->GetMean() << "\t" << hDAC[i]->GetRMS() << endl;
  }

  threshold.close();
  cout<<"------------------------------------------------------------------------------------------"<<endl;


  //TApplication app("test_app", &argc, argv);
  //TBrowser *b = new TBrowser;
  //app.Run();
  
  
  output_file->Write();
  output_file->Close();

  return 0;
}
  
 
  
