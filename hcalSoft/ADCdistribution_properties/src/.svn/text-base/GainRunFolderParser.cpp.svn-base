/*
 * GainRunFolderParser.cpp
 *
 *  Created on: Dec 19, 2013
 *      Author: hartbrich
 */

#include "GainRunFolderParser.h"

#include <iostream>

using namespace std;

GainRunFolderParser::GainRunFolderParser(std::string file) {

  cout << "enter here??" << endl;

 
  RunInfo r;
  int vCalib;
  std::string t;

  t = file.substr(file.find("Hold")+4,2);
  sscanf(t.c_str(),"%d", &vCalib);
  cout << "vCalib " << vCalib << " fullPath " << file << endl;
  r.vCalib = vCalib;
  r.filePath = file;
    
  runInfos.push_back(r);
  std::cout << vCalib << "\t" << file << std::endl;

}

GainRunFolderParser::~GainRunFolderParser() {
	// TODO Auto-generated destructor stub
}

std::vector<RunInfo> GainRunFolderParser::getRunInfos(){
	return runInfos;
}


std::vector<std::string> GainRunFolderParser::getFilePathsInFolder(std::string folderPath, std::string fileEnding){


	TSystem sys;
	TSystemDirectory dir("testname", folderPath.c_str() ); // dir name, pathname
	TList *files = dir.GetListOfFiles();

	files->Sort();
	TIter next(files);
	TSystemFile *fil;


	TString pwd = TString(gSystem->WorkingDirectory());

	std::vector<std::string> returnvec;

	while ((fil = (TSystemFile*) next()))
	{
		if (std::string(fil->GetName()).find(fileEnding) !=std::string::npos)
		{

		returnvec.push_back(std::string(fil->GetName())) ;
		}
	}

	return returnvec;
}
