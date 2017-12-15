#include "Holdscan.h"

void FindPeak(TH1* hist,Float_t *res)
{
  int startbin = 3;
  int endbin = 0.1*hist->GetNbinsX();
  for(int i=startbin;i<endbin;i++) { 
    if(    hist->GetBinContent(i)<hist->GetBinContent(i+1)   
	   && hist->GetBinContent(i)<hist->GetBinContent(i+2)     
	   && hist->GetBinContent(i)<hist->GetBinContent(i+3) ) {   
      startbin=i;                                                               
      break;   
    }      
  }    
  hist->SetAxisRange(startbin,endbin); 
  int maxbin = hist->GetMaximumBin();   

  TF1* f1 = new TF1("f1","gaus",maxbin-4,maxbin+4);                                                                         
  f1->SetParLimits(1,maxbin-2,maxbin+2); 
  hist->Fit(f1,"RQ");     
  res[0] = f1->GetParameter(1);  
  res[1] = f1->GetParError(1); 

  return;  
}

//*********************************//
//*                               *//
//*********************************//

float* GainFromFFT(TH1* hist)
{
  TH1* hm = NULL;
  TVirtualFFT::SetTransform(0); 
  hm = hist->FFT(hm,"MAG");      //root FFT gives same result as fftw3 package  
  TString str = hist->GetName();
  str+="_fft"; 
  //TCanvas* FFTtmpCanvas = NewCanvas(str,800,600);                                                                      
  //hm->Draw();  
  Float_t *fitresult = new Float_t[2];    
  FindPeak(hm,fitresult);  
  Float_t norm = (fitresult[0]*hist->GetBinWidth(1));  
  Float_t normerr = (fitresult[0]+fitresult[1])*hist->GetBinWidth(1);  
  Float_t gain = hist->GetNbinsX()/norm; 
  Float_t errgain = hist->GetNbinsX()/normerr;
  Float_t err = TMath::Abs(errgain-gain);     
  delete fitresult;       
  float *retv = new float[2]; 
  retv[0] = gain;  
  retv[1] = err;                                                                                                                                                  hm->Delete();
  // delete FFTtmpCanvas;  
  return retv;
}

//*********************************//
//*                               *//
//*********************************//

string stripname(string rootfile)
{
  string strip = rootfile.substr(rootfile.find("ET_")+3, 2);

  return strip;
}

//*********************************//
//*                               *//
//*********************************//

vector<string> GetListofFiles(string directory)
{
  TSystemDirectory *dir = new TSystemDirectory("directory", directory.c_str()); // dir name, pathname
  TList *files = dir->GetListOfFiles();
  
  cout<<directory<<endl;

  files->Sort();
  TIter next(files);
  TSystemFile *fil;
  vector<string> r;
  string filename;
  
  //Look at the files in the folder and push back name in vector
  while ((fil = (TSystemFile*) next()))
    {
      if (string(fil->GetName()).find(".root") !=string::npos)
	{
	  filename=string(fil->GetName());
	  r.push_back(filename);
	}
    }

  return r;
}

//*********************************//
//*                               *//
//*********************************//

void MakeGraphs(int file_nb, vector<int> hold_value)
{
  cout << endl;
  cout << "******************************************" << endl;
  cout << "*                     Creating Graphs                       *" << endl;
  cout << "******************************************" << endl;

  tgraph->cd();
  map<int, vector<TGraph* > >::iterator it;

  for(int file = 0; file < file_nb; ++file)
    {
      for(it = graph_mean.begin(); it != graph_mean.end(); it++)
	{
	  int ChipID2 = it->first;
	  for(int i = 0; i < 36; i++)
	    {
	      graph_mean[ChipID2][i]->SetPoint(file, hold_value.at(file), histos[file][ChipID2][i]->GetMean());
	      //cout << graph[ChipID2][i]->Integral() << endl;
	      graph_mean[ChipID2][i]->SetName(TString::Format("Graph ADC vs Holdtime chip %d, channel %d", ChipID2, i));
	      graph_mean[ChipID2][i]->SetMarkerStyle(20);
	      graph_mean[ChipID2][i]->SetMarkerColor(i+1);
	      graph_mean[ChipID2][i]->GetYaxis()->SetTitle("ADC mean");
	      if(graph_mean[ChipID2][i]->Integral() > 6000) multigraph_mean[ChipID2]->Add(graph_mean[ChipID2][i]);
	    }

	  TString multititle = " MultiGraph Chip ";
	  multititle += ChipID2;
	  multigraph_mean[ChipID2]->SetName(multititle+", ADC mean");
	  if(file == file_nb -1) multigraph_mean[ChipID2]->Write();
	}

      for(it = graph_width.begin(); it != graph_width.end(); it++)
	{
	  int ChipID2 = it->first;
	  for(int i = 0; i < 36; i++)
	    {
	      graph_width[ChipID2][i]->SetPoint(file, hold_value.at(file), histos[file][ChipID2][i]->GetRMS());
	      //cout << graph[ChipID2][i]->Integral() << endl;
	      graph_width[ChipID2][i]->SetName(TString::Format("Graph ADC vs Holdtime chip %d, channel %d", ChipID2, i));
	      graph_width[ChipID2][i]->SetMarkerStyle(20);
	      graph_width[ChipID2][i]->SetMarkerColor(i+1);
 	      graph_width[ChipID2][i]->GetYaxis()->SetTitle("ADC width");
	      if(graph_width[ChipID2][i]->Integral() > 100) multigraph_width[ChipID2]->Add(graph_width[ChipID2][i]); 
	    }
	  TString multititle = " MultiGraph Chip ";
	  multititle += ChipID2;
	  multigraph_width[ChipID2]->SetName(multititle+", ADC width");
	  if(file == file_nb -1) multigraph_width[ChipID2]->Write();
	}

      for(it = graph_gain.begin(); it != graph_gain.end(); it++)
	{
	  int ChipID2 = it->first;
	  for(int i = 0; i < 36; i++)
	    {
	      float gainFFT = GainFromFFT(histos[file][ChipID2][i])[0];
	      if(gainFFT>5 && gainFFT<60) graph_gain[ChipID2][i]->SetPoint(file, hold_value.at(file), gainFFT);
	      //cout << graph[ChipID2][i]->Integral() << endl;
	      graph_gain[ChipID2][i]->SetName(TString::Format("Graph ADC vs Holdtime chip %d, channel %d", ChipID2, i));
	      graph_gain[ChipID2][i]->SetMarkerStyle(20);
	      graph_gain[ChipID2][i]->SetMarkerColor(i+1); 
	      graph_gain[ChipID2][i]->GetYaxis()->SetTitle("gain (FFT)");
	      if(graph_gain[ChipID2][i]->Integral() > 100) multigraph_gain[ChipID2]->Add(graph_gain[ChipID2][i]); 

	    }
	  TString multititle = " MultiGraph Chip ";
	  multititle += ChipID2;
	  multigraph_gain[ChipID2]->SetName(multititle+", gain FFT");
	  if(file == file_nb -1) multigraph_gain[ChipID2]->Write();
	}
    }

  return;
}

//*********************************//
//*                               *//
//*********************************//

void ProcessFile(string directory, string PATH_OUT, int mode)
{
  vector<string> r = GetListofFiles(directory);

  const int file_nb =  r.size(); 
  cout << "Number of files " << file_nb << endl;

  output_file = new TFile((PATH_OUT+"Plots_comp.root").c_str(),"RECREATE");//results root file

  histo = output_file->mkdir("histo");
  tgraph = output_file->mkdir("graph");

  TFile *f[file_nb];

  int CycleNr = 0;
  int BunchXID = 0;
  int ChipID2 = 0;
  int ASICNr = 0;
  int EvtNr = 0;
  int chn = 0;
  int TDC = 0;
  int ADC = 0;
  int xPos = 0;
  int yPos = 0;
  int Hit_Bit = 0;
  int Gain_Bit = 0;

  vector<int> hold_value;
  hold_value.resize(file_nb);

  for(int file = 0; file < file_nb; ++file)//loop over all files
    {
      histos[file];
      string rootfile = r.at(file);
      string path = directory;
      path += rootfile;

      cout << endl;
      cout << "Opening file " << rootfile << endl;

      f[file] = new TFile(path.c_str(), "OPEN");

      //TSubString hold_str = rootfile(21,2);
      //get hold value from the name of the file
     
      string hold_str = stripname(rootfile);
      hold_value.at(file) = atoi(hold_str.c_str());//convert to int

      TTree *myTree = (TTree*)f[file]->Get("tree");
      cout << "Hold value " << hold_value.at(file)  << endl;

      myTree->SetBranchAddress ("CycleNr",&CycleNr);
      myTree->SetBranchAddress ("BunchXID",&BunchXID);
      myTree->SetBranchAddress ("ChipID2",&ChipID2);
      myTree->SetBranchAddress ("ASICNr",&ASICNr);
      myTree->SetBranchAddress ("EvtNr",&EvtNr);
      myTree->SetBranchAddress ("chn",&chn);
      myTree->SetBranchAddress ("TDC",&TDC);
      myTree->SetBranchAddress ("ADC",&ADC);
      myTree->SetBranchAddress ("xPos",&xPos);
      myTree->SetBranchAddress ("yPos",&yPos);
      myTree->SetBranchAddress ("Hit_Bit",&Hit_Bit);
      myTree->SetBranchAddress ("Gain_Bit",&Gain_Bit);

      int nentries = myTree->GetEntries();

      histo->cd();

      for(int IDEntry = 0; IDEntry < nentries; ++IDEntry)//loop over entries in rootfile
	{
	  myTree->GetEntry(IDEntry);

	  if (CycleNr <=1)
	    {
	      continue;
	    }

	  if (IDEntry%10000 == 1)
	    {
	      cout << "." << flush;
	    }
	  
	  if (histos[file].count(ChipID2) == 0)
	    {
	      histos[file][ChipID2] = vector<TH1F*>(36);
	      graph_mean[ChipID2] = vector<TGraph*>(36);
	      graph_width[ChipID2] = vector<TGraph*>(36);
	      graph_gain[ChipID2] = vector<TGraph*>(36);
	      multigraph_mean[ChipID2] = new TMultiGraph();
	      multigraph_width[ChipID2] = new TMultiGraph();
	      multigraph_gain[ChipID2] = new TMultiGraph();

	      for (int i=0; i<36; i++)
		{
		  histos[file][ChipID2][i] = new TH1F(TString::Format("z_ADC_chip%d_chn%d_hold%d",ChipID2, i, hold_value[file]),TString::Format("ADC Spectrum Chip %d, Channel %d, Hold value %d",ChipID2, i, hold_value[file]),4096,-0.5,4095.5);
		  graph_mean[ChipID2][i] = new TGraph(file_nb);
		  graph_width[ChipID2][i] = new TGraph(file_nb);
		  graph_gain[ChipID2][i] = new TGraph(file_nb);
		}
	      cout << "creating ChipID " << ChipID2 << flush << endl;
	    }
	  
	  if(mode == 1)
	    {
	      if(ADC > 200 && Gain_Bit == 1)
		histos[file][ChipID2][chn]->Fill(ADC);
	    }
	  else
	    {
	      if(TDC > 200 && Gain_Bit == 1)
		histos[file][ChipID2][chn]->Fill(TDC);
	    }
	}		  
    }

  MakeGraphs(file_nb, hold_value);

  cout << "Writing rootfile " << endl;
  output_file->Write();
  output_file->Close();

  return;
}

//*********************************//
//*                               *//
//*********************************//

int main(int argc, char **argv)
{
  
  if(argc < 3)
    {
      cout << "Provide INPUT / OUTPUT PATH / Mode (HG/LG (0) or HG/TDC (1))" << endl;
      return 1;
    }
  
  gSystem->Load("libPhysics");

  string directory = argv[1];//PATH INPUT root files
  string PATH_OUT = argv[2];//PATH output results
  int mode = atoi(argv[3]);
 
  ProcessFile(directory, PATH_OUT, mode);
}

