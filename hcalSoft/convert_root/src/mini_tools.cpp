/*
 * mini_tools.cpp
 *
 *  Created on: 16.05.2011
 *      Author: jsauer
 */

#include "TString.h"
#include <vector>
#include "TSystemDirectory.h"
#include <string>
#include <iostream>
#include <fstream>
#include "TList.h"
#include "TSystem.h"


using namespace std;

vector<string> loop_over_files_in_folder_ofspec_type(string folder, string ending)
{

  std::cout << "folder " << folder << endl;

	TSystem sys;
	TSystemDirectory dir("testname", folder.c_str() ); // dir name, pathname
	TList *files = dir.GetListOfFiles();


	files->Sort();
	TIter next(files);
	TSystemFile *fil;


	TString pwd = TString(gSystem->WorkingDirectory());

	string fullfilename;
	
	vector<string> returnvec;

	while ((fil = (TSystemFile*) next()))
	{
		if (string(fil->GetName()).find(ending) !=string::npos)
		{
                    fullfilename=string(fil->GetName());
		    returnvec.push_back(fullfilename) ;

		    std::cout << "fullfilename " << fullfilename << endl;
		}
	}

	return returnvec;
}

string snip_name(string inp)
{
	size_t a = inp.find(".txt");

	std::cout << "inp.substr(0,a) " << inp.substr(0,a) << endl;

	return inp.substr(0,a);
}

