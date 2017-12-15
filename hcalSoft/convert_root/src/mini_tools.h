/*
 * mini_tools.h
 *
 *  Created on: 16.05.2011
 *      Author: jsauer
 */

#ifndef MINI_TOOLS_H_
#define MINI_TOOLS_H_

#include <vector>
#include <string>

using namespace std;

vector<string> loop_over_files_in_folder_ofspec_type(string folder, string ending);
//returns all .<input> files at a given path

string snip_name(string inp);
//removes the .txt ending

#endif /* MINI_TOOLS_H_ */
