/*
 * RunFolderParser.h
 *
 *  Created on: Dec 19, 2013
 *      Author: hartbrich
 */

#include <string>
#include <vector>
#include <iostream>


#include <TString.h>
#include <TSystemDirectory.h>
#include <TList.h>
#include <TSystem.h>


#ifndef RUNFOLDERPARSER_H_
#define RUNFOLDERPARSER_H_

struct RunInfo {
	std::string filePath;
	int vCalib;
};


class RunFolderParser {
 public:
  RunFolderParser();
  RunFolderParser(std::string folderPath, bool ET);
  virtual ~RunFolderParser();

  std::vector<RunInfo> getRunInfos();

 private:
  std::vector<RunInfo> runInfos;
  std::vector<std::string> getFilePathsInFolder(std::string folderPath, std::string fileEnding, bool ET);


};

#endif /* RUNFOLDERPARSER_H_ */
