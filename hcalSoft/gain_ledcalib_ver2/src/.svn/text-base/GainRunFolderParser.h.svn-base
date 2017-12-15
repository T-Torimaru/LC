/*
 * GainRunFolderParser.h
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


#ifndef GAINRUNFOLDERPARSER_H_
#define GAINRUNFOLDERPARSER_H_

struct RunInfo {
	std::string filePath;
	int vCalib;
};


class GainRunFolderParser {
public:
	GainRunFolderParser(std::string folderPath);
	virtual ~GainRunFolderParser();

	std::vector<RunInfo> getRunInfos();

private:
	std::vector<RunInfo> runInfos;
	std::vector<std::string> getFilePathsInFolder(std::string folderPath, std::string fileEnding);


};

#endif /* GAINRUNFOLDERPARSER_H_ */
