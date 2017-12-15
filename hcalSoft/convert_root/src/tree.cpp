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

using namespace std;

void mktree(string input_file, string output_file, string data_format)
{
  cout << "Make tree for file " << input_file << endl;
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

	TFile* output_tree_file = new TFile(output_file.c_str(),"RECREATE");

	TTree *myTree = new TTree ("tree", "tree");

	myTree->Branch ("CycleNr",&CycleNr,"CycleNr/I");
	myTree->Branch ("BunchXID",&BunchXID,"BunchXID/I");
	myTree->Branch ("ChipID2",&ChipID2,"ChipID2/I");
	myTree->Branch ("ASICNr",&ASICNr,"ASICNr/I");
	myTree->Branch ("EvtNr",&EvtNr,"EvtNr/I");
	myTree->Branch ("chn",&chn,"chn/I");
	myTree->Branch ("TDC",&TDC,"TDC/I");
	myTree->Branch ("ADC",&ADC,"ADC/I");
	myTree->Branch ("xPos",&xPos,"xPos/I");
	myTree->Branch ("yPos",&yPos,"yPos/I");
	myTree->Branch ("Hit_Bit",&Hit_Bit,"Hit_Bit/I");
	myTree->Branch ("Gain_Bit",&Gain_Bit,"Gain_Bit/I");

	ifstream streamed_data_file;
	streamed_data_file.open(input_file.c_str());
	if (streamed_data_file.is_open())
		cout << "open" << endl;
	else
		cout << "closed" << endl;
	cout << "blablabla" << endl;
	string line;
	string word, word_temp;
	int tmp=0;

    while(!streamed_data_file.eof()) {

      getline(streamed_data_file, line);

      while( line.c_str()[0] != '#' && !streamed_data_file.eof())  {

      if(data_format=="HDMI") {
	// ----------------------------------------------
	//DATA FORMAT
	//for HDMI (LDA) DAQ:
	sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i", &CycleNr, &BunchXID, &ChipID2, &EvtNr, &chn, &TDC, &ADC, &Hit_Bit, &Gain_Bit);
      }

      if(data_format=="USB") {
	// ----------------------------------------------
	//DATA FORMAT
	//for single layer USB DAQ:
	sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i %i %i %i", &BunchXID, &CycleNr, &ChipID2, &ASICNr, &EvtNr, &chn, &TDC, &ADC, &xPos, &yPos, &Hit_Bit, &Gain_Bit);
	//or 
	//sscanf(line.c_str(), "%i %i %i %i %i %i %i %i %i %i %i %i", &BunchXID, &CycleNr, &ChipID2, &ASICNr, &EvtNr, &chn, &ADC, &TDC, &xPos, &yPos, &Hit_Bit, &Gain_Bit);//HG = ADC, LG = TDC

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

			
        myTree->Fill();
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
