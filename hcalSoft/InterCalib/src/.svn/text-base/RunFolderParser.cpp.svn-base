/*
 * RunFolderParser.cpp
 *
 *  Created on: Dec 19, 2013
 *      Author: hartbrich
 */

#include "RunFolderParser.h"

#include <iostream>

using namespace std;

RunFolderParser::RunFolderParser(){

}

RunFolderParser::RunFolderParser(std::string folderPath, bool ET) {

  cout << "enter here??" << endl;

  std::vector<std::string> files = getFilePathsInFolder(folderPath, "root", ET);
  
  for (std::vector<std::string>::iterator it = files.begin(); it != files.end(); it++){
    RunInfo r;
    int vCalib;
    std::string t;
    //t = it->substr(it->find("_")+6, it->find("_"));
    t = it->substr(it->find("_")+1, it->find("_")+5);
    //t = it->substr(0, 4);
    
    cout << "t " << t << endl;
    
    sscanf(t.c_str(),"%d", &vCalib);
    std::string fullPath = folderPath + *it;
    
    cout << "vCalib " << vCalib << " fullPath " << fullPath << endl;
    
    r.vCalib = vCalib;
    r.filePath = fullPath;
    
    runInfos.push_back(r);
    
    std::cout << vCalib << "\t" << *it << std::endl;
    
  }


}

RunFolderParser::~RunFolderParser() {
	// TODO Auto-generated destructor stub
}

std::vector<RunInfo> RunFolderParser::getRunInfos(){
	return runInfos;
}


std::vector<std::string> RunFolderParser::getFilePathsInFolder(std::string folderPath, std::string fileEnding, bool ET){


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
	  if(ET)
	    {
	      if (std::string(fil->GetName()).find(fileEnding) !=std::string::npos)
		{
		  returnvec.push_back(std::string(fil->GetName())) ;
		}
	    }
	  else
	    {
	      if (std::string(fil->GetName()).find(fileEnding) !=std::string::npos && std::string(fil->GetName()).find("_300") !=std::string::npos)
		{
		  returnvec.push_back(std::string(fil->GetName())) ;
		}
	    }
	}

	return returnvec;
}
