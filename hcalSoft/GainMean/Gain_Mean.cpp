#include <map>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TString.h>
#include <TPad.h>
#include <TMath.h>
#include <TAxis.h>
#include <TROOT.h>
#include <TSystem.h>
#include <stdio.h>
#include <TF1.h>
#include <TMinuit.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TVirtualFitter.h>
#include <TStyle.h>
#include <TTree.h>
#include "TList.h"
#include "TSystem.h"
#include "TSystemDirectory.h"
#include <vector>
#include <TDirectory.h>
#include <TH2.h>

using namespace std;

map<int, int> m_mapHBU;

void MakeMapHBU()
{
  ifstream fIn("MapHBU.txt");
  string line;

  if(fIn.is_open())
    {
      while(getline(fIn, line))
	{
	  if(line.at(0) == '#') continue;
	  istringstream iss(line);
	  int Layer, ChipNb, Chn, I, J, K;
	  
	  iss >> Layer >> ChipNb >> Chn >> I >> J >> K;

	  m_mapHBU.insert(make_pair(ChipNb*100+Chn, I*100+J));
	}

      cout << "Map HBU size " << m_mapHBU.size() << endl;
    }
  else
    {
      cout << "Can t open HBUMap file" << endl;
      return;
    }

}

int FindI(int Chip, int Chn)
{
  int I = -1;

  map<int, int>::iterator found = m_mapHBU.find(Chip*100+Chn);
  if(found != m_mapHBU.end())
    {
      I = found->second/100;
    }
  
  return I;
}

int FindJ(int Chip, int Chn)
{
  int J = -1;

  map<int, int>::iterator found = m_mapHBU.find(Chip*100+Chn);
  if(found != m_mapHBU.end())
    {
      J = found->second%100;
    }
  
  return J;
}

int main(int argc, char **argv)
{
  if(argc < 3)
    {
      cout << "gain_mean InputDirectoryPath ReferencePA (PA value of the Run)" << endl;
      return -1;
    }

  MakeMapHBU();
  //  string directory = "/home/calice/Commissioning/SM_1/Gain_650fF/output_gain/";
  string directory = argv[1];
  int PA_Ref = atoi(argv[2]);
  
  TSystemDirectory *dir = new TSystemDirectory("directory", directory.c_str()); // dir name, pathname

  TList *files = dir->GetListOfFiles();

  files->Sort();
  TIter next(files);
  TSystemFile *fil;
  vector<string> r;
  string filename;

  while ((fil = (TSystemFile*) next()))
    {
      if (string(fil->GetName()).find(".tsv") !=string::npos)
	{
	  filename=string(fil->GetName());
	  r.push_back(filename);
	  //cout << filename << endl;
	}
    }

  const int file_nb =  r.size(); 

  int ChipID = 0;
  int chn = 0;
  float GainFit = 0;
  float GainFFT = 0;
  float ErrorGain = 0;

  string line;
  string path = directory;
  string path_out = directory;
  string namefile[file_nb];

  TFile *output = new TFile((path_out + "Gain_distribution.root").c_str(), "RECREATE");

  TString histotitle = "Distrib_gain_";
  //histotitle+= HBU;
  histotitle+= "_total";

  TString histotitle2 = "Distrib_gain_";
  //histotitle2+= HBU;
  histotitle2+= "_per_chn";

  map <int, map<int, TH1F* > > histo;
  map<int, TH1F*> histo_chip;

  TH1F *Gain_histo_total = new TH1F(histotitle, histotitle, 80, -0.5, 79.5);
  TH1F *Gain_histo = new TH1F(histotitle2, histotitle2, 80, -0.5, 79.5);

  output->cd();
  for(int i = 0; i < file_nb; ++i)
    {
      namefile[i] = r.at(i);
      string open = path + namefile[i];
      cout << endl;
      cout << "Opening file " << open << endl;
      ifstream file(open.c_str());
      if(file.is_open())
	{
	  while( getline(file, line) )
	    {
	      sscanf(line.c_str(), "%i %i %f %f %f", &ChipID, &chn, &GainFit, &GainFFT, &ErrorGain);
	      //cout << ChipID << "\t" << chn << "\t" << GainFit << endl;
	      if(ChipID < 100) continue;

	      if(histo_chip.count(ChipID) == 0)
		{
		  histo_chip[ChipID] = new TH1F(TString::Format("Gain_distri_Chip%d", ChipID), TString::Format("Gain distri Chip %d", ChipID), 80, -0.5, 79.5);
		}
	      if(histo[ChipID].count(chn) == 0)
		{
		  histo[ChipID][chn] = new TH1F(TString::Format("Gain_distri_Chip%d_chn%d", ChipID, chn), TString::Format("Gain distri Chip %d, chn %d", ChipID, chn), 80, -0.5, 79.5);
		  cout << "creating ChipID " << ChipID << " Channel " << chn << flush << endl;
		}

	      if(GainFit != 0 && TMath::Abs(GainFit - GainFFT) < 10)
		{
		  histo[ChipID][chn]->Fill(GainFit);
		  histo_chip[ChipID]->Fill(GainFit);
		  Gain_histo_total->Fill(GainFit);
		}
	      else
		{
		  cout << "GainFit and GainFFT too different" << endl;
		  continue;
		}
	    }
	      
	  for(int j = 0; j < 100; j++)  cout << "." << flush;
	}
      cout << endl;
      file.close();
    }

  TH2F *Map_Gain = new TH2F("Map_Gain", "Map_Gain", 24, 0, 24, 24, 0, 24);
  int ChipID1 = 0;
  int i = 0;

  //General PA curve normalize to 1 at 100 fF
  TF1 *PAcurve = new TF1("PA_curve", "[0]/([1]+x)", 50, 1000); //f(x) -> Gain/Gain100fF; x -> PA
  PAcurve->FixParameter(0, 281.516);
  PAcurve->FixParameter(1, 182.687);
  PAcurve->SetParError(0, 11.7054);
  PAcurve->SetParError(1, 14.8736);

  map<int, float> m_Gain;
  
  for(map <int, map<int, TH1F* > >::iterator it = histo.begin(); it != histo.end(); it++)
    {
      ChipID = it->first;
      if(i == 0)
	ChipID1 = ChipID;
      
      int chn_fitted = 0;
      
      for(map<int, TH1F* >::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
	{	  	  
	  if(it2->second->GetMean() != 0)
	    {
	      chn_fitted++;
	      chn = it2->first;
	      
	      Gain_histo->Fill(it2->second->GetMean());

	      m_Gain.insert(make_pair( ChipID*100+chn, it2->second->GetMean() ));
	      
	      int ChipNb = ChipID - ChipID1;
	      int I = FindI(ChipNb, chn);
	      int J = FindJ(ChipNb, chn);
	      
	      Map_Gain->Fill(I, J, it2->second->GetMean());
	    }
	}
      
      cout << "Chip " <<  ChipID  << " Number of Chn fitted " << chn_fitted << endl;
      i++;
    }

  /* Check for outliers!!!! */
  //-------------------------------------------- IF CHANNEL IS MORE THAN 3 SIGMA FROM MEAN, RECALCULATE THE PA NEEDED ------------------------------------------------------

  cout << "/***********************************************************/" << endl;
  cout << " Check Outliers " << endl;
  cout << "/***********************************************************/" << endl;
  
  float MeanModule = Gain_histo->GetMean();
  float RMSModule =  Gain_histo->GetRMS();

  for(map<int, float>::iterator it = m_Gain.begin(); it != m_Gain.end(); ++it)
    {
      float Gain = it->second;
      float Deviation = TMath::Abs(Gain - MeanModule)/RMSModule;

      if(Deviation > 3)
	{	  
	  float ratio = Gain/MeanModule;
	  
	  cout << "Chip " << it->first/100 << " Chn " << it->first%100 << " has a deviation of over 3 sigma (" << Deviation << ") from the Mean" << " /  Gain " << Gain << " Mean " << MeanModule << " ratio " << ratio << endl;

	  if(ratio < 1)
	    {
	      //Calculate PA in order that f(x)/f(650) = ratio
	      for(float PA = PA_Ref; PA > 100;)
		{
		  float ratio2 = PAcurve->Eval(650)/PAcurve->Eval(PA);
		  Deviation = TMath::Abs(Gain/ratio2 - MeanModule)/RMSModule;
		  if(Deviation < 1)
		    {
		      cout << "PA needed " << PA << " would give a gain of " << Gain/ratio2 << endl;
		      break;
		    }
		  PA -= 25;
		}
	    }
	  else
	    {
	      for(float PA = PA_Ref; PA < 1000;)
		{
		  float ratio2 = PAcurve->Eval(650)/PAcurve->Eval(PA);
		  Deviation = TMath::Abs(Gain/ratio2 - MeanModule)/RMSModule;
		  if(Deviation < 1)
		    {
		      cout << "PA needed " << PA << " would give a gain of " << Gain/ratio2 << endl;
		      break;
		    }
		  PA += 25;
		}
	    }
	}
    }
  
  output->Write();
  output->Close();
  
}
