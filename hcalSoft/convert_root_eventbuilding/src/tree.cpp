/*
 * mktree.cpp
 *
 *  Created on: 09.05.2011
 *      Author: jsauer
 */

#include <iostream>
#include "TFile.h"
#include <sstream>
#include <fstream>
#include "TTree.h"
#include "tree.h"
#include "mini_tools.h"
#include <map>
#include <vector>
#include <locale>

using namespace std;

void mktree(string input_file, string output_file, string data_format)
{
  cout << "Make tree for file " << input_file << endl;

  int nHits = 0;
  int iEvt = 0; //global event number , after sorting

  const static unsigned int MAXCELLS  = 10000; /*should be big enough for all detectors!*/

  int BunchXID[MAXCELLS];
  int CycleNr[MAXCELLS];
  int ChipID[MAXCELLS];
  int EvtNr[MAXCELLS];
  int Channel[MAXCELLS];
  int TDC[MAXCELLS];
  int ADC[MAXCELLS];
  int HitBit[MAXCELLS];
  int GainBit[MAXCELLS];


  TFile* output_tree_file = new TFile(output_file.c_str(),"RECREATE");

  TTree *myTree = new TTree ("myTree", "myTree");

  TString _prefix ="ahcal_";

  myTree->Branch( string(_prefix + "nHits").c_str(), &nHits,  string(_prefix+"nHits/I").c_str());
  myTree->Branch( string(_prefix+"iEvt").c_str(), &iEvt, string(_prefix+"iEvt/I").c_str());
        
  myTree->Branch( string(_prefix + "BunchXID").c_str(), &BunchXID, string(_prefix+"BunchXID["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "CycleNr").c_str(), &CycleNr, string(_prefix+"CycleNr["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "ChipID").c_str(), &ChipID, string(_prefix+"ChipID["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "EvtNr").c_str(), &EvtNr, string(_prefix+"EvtNr["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "Channel").c_str(), &Channel, string(_prefix+"Channel["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "TDC").c_str(), &TDC, string(_prefix+"TDC["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "ADC").c_str(), &ADC, string(_prefix+"ADC["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "HitBit").c_str(), &HitBit, string(_prefix+"HitBit["+_prefix+"nHits]/I").c_str() );
  myTree->Branch( string(_prefix + "GainBit").c_str(), &GainBit, string(_prefix+"GainBit["+_prefix+"nHits]/I").c_str() );

  ifstream streamed_data_file;
  streamed_data_file.open(input_file.c_str());
  if (streamed_data_file.is_open())
    cout << "open" << endl;
  else
    cout << "closed" << endl;

  string line;
  string word, word_temp;
  int tmp=0;

  //look for the change of cycle number
  int currentCycleNr = -1;
  int lastCycleNr = -1;
  bool CycleNrChanged = false;
  
  std::map< int, std::vector< vector<int> > > readOutCycleData; 

  //in the USB labview the memory cell are inverted
  //  std::map< int, int>
  int maxmemcell[255];
  for(int ichip=0; ichip<255; ichip++) maxmemcell[ichip]=-1;

  int memcell=-1;

  while(!streamed_data_file.eof()) {
  
    getline(streamed_data_file, line);

    while( line.c_str()[0] != '#' && !streamed_data_file.eof())  {

      std::vector<int> Data;
      int bxid=-1;
      int chipid=-1;

      // **********************************************************
      //        Processing data
      //  build events according to the different BunchXID
      //  within one CycleNr, and remove them,
      //  until all collected data have been asigned to an event.
      //  Then readin the next CycleNr raw data.
      // **********************************************************

      //for multilayer DAQ:	  currentCycleNr = Data[1];

      if(data_format=="HDMI") {
	// ----------------------------------------------
	//DATA FORMAT
	//for HDMI (LDA) DAQ:
	//  sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i", &CycleNr, &BunchXID, &ChipID2, &EvtNr, &chn, &TDC, &ADC, &Hit_Bit, &Gain_Bit);
	Data.resize(9);
	sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i",&Data[0],&Data[1],&Data[2],&Data[3],&Data[4],&Data[5],&Data[6],&Data[7],&Data[8]);
	//	currentCycleNr = Data[0];
	bxid=Data[1];
      }

      if(data_format=="USB") {
	// ----------------------------------------------
	//DATA FORMAT
	//for single layer USB DAQ:
	//sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i %i %i %i", &BunchXID, &CycleNr, &ChipID2, &ASICNr, &EvtNr, &chn, &TDC, &ADC, &xPos, &yPos, &Hit_Bit, &Gain_Bit);
	//or 
	//sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i %i %i %i", &BunchXID, &CycleNr, &ChipID2, &ASICNr, &EvtNr, &chn, &ADC, &TDC, &xPos, &yPos, &Hit_Bit, &Gain_Bit);//HG = ADC, LG = TDC
	Data.resize(12);
	sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i %i %i %i",&Data[0],&Data[1],&Data[2],&Data[3],&Data[4],&Data[5],&Data[6],&Data[7],&Data[8],&Data[9],&Data[10],&Data[11]);
	bxid=Data[0];
	chipid=Data[2];
	memcell=Data[4];
      }


      if(data_format!="USB" && data_format!="HDMI") {
	cout<<" ####################################################################################################### "<<endl;
	cout<<" ERROR "<<endl;
	cout<<" Not existing data format, please choose USB or HDMI:  "<<endl;
	cout<<"                                                    >  ./convert_root [INPUT PATH] [OUTPU_PATH] USB"<<endl;
	cout<<" or"<<endl;
	cout<<"                                                    >  ./convert_root [INPUT PATH] [OUTPU_PATH] HDMI"<<endl;
	return;
      }

      currentCycleNr = Data[1];
 
      //if different cycle number is found, proccess the ROC and sort it in events according to BXID

      if( lastCycleNr != currentCycleNr && currentCycleNr>1)
	{
	  CycleNrChanged = true;
	  lastCycleNr = currentCycleNr;

	  if(CycleNrChanged == true){

	    for(  map< int, vector< vector<int> > >::iterator it=readOutCycleData.begin(); it!=readOutCycleData.end(); it++ )
	      {
		 
		nHits = 0;

		for (unsigned int inhit = 0; inhit < it->second.size(); inhit++ )
		  {
		    vector<int> &v = it->second.at(inhit);
		    if(data_format=="USB") {
		      BunchXID[nHits] = v[0];
		      CycleNr[nHits]  = v[1];
		      ChipID[nHits]   = v[2];
		      EvtNr[nHits]    = maxmemcell[ChipID[nHits]]-v[4]; //memory cells are inverted in the USB Labview output
		      // if(EvtNr[nHits]==0) cout<<CycleNr[nHits]<<" "<<ChipID[nHits]<<" "<<EvtNr[nHits] <<" "<<maxmemcell[ChipID[nHits]]-v[4]<<" "<<maxmemcell[ChipID[nHits]]<<" "<<v[4]<<endl;
		      Channel[nHits]  = v[5];
		      TDC[nHits]      = v[6];
		      ADC[nHits]      = v[7];
		      HitBit[nHits]   = v[10];
		      GainBit[nHits]  = v[11];
		    }
		    if(data_format=="HDMI") {
		      BunchXID[nHits] = v[1];
		      CycleNr[nHits]  = v[0];
		      ChipID[nHits]   = v[2];
		      EvtNr[nHits]    = v[3];
		      Channel[nHits]  = v[4];
		      TDC[nHits]      = v[5];
		      ADC[nHits]      = v[6];
		      HitBit[nHits]   = v[7];
		      GainBit[nHits]  = v[8];
		    }

		    nHits ++;
		    iEvt ++;
		  }
		
		myTree->Fill();
	      }
	    
	    CycleNrChanged = false;
	  }
	   
	  readOutCycleData.clear();
	  for(int ichip=0; ichip<255; ichip++) maxmemcell[ichip]=-1;
	  memcell=-1;
	}
     
      readOutCycleData[bxid].push_back(Data);
      if(memcell>maxmemcell[chipid]) maxmemcell[chipid]=memcell;
      Data.clear();

      getline(streamed_data_file, line);
      tmp++;
      if (tmp%100000==0)
	cout << "data part: " << tmp << endl;
    }
  }
    
  myTree->Write();
  output_tree_file->Close();
  streamed_data_file.close();


}

void mk_many_trees(string path_in, string path_out, string d_format)
{

  vector<string> listoffiles = loop_over_files_in_folder_ofspec_type(path_in, ".txt");
  for (unsigned int i=0; i<listoffiles.size();i++)
    {
      cout << listoffiles[i] <<" is a file in the given folder" << endl;
      mktree(path_in+"/"+listoffiles[i],path_out+"/"+snip_name(listoffiles[i])+".root", d_format);
    }
}
