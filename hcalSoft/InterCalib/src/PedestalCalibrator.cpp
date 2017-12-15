/*
 * PedestalCalibrator.cpp
 *
 *  Created on: Jan 29, 2014
 *      Author: ohartbri
 */

#include "PedestalCalibrator.h"

PedestalCalibrator::PedestalCalibrator(std::string path) {
	std::ifstream file;
	file.open(path.c_str(),std::ifstream::in);

	std::string line;
	int chip, channel, cnt(0);
	double pedWidthAll, pedPosAll;
	double pedPosMemCell[16];
	for (int imcell = 0; imcell < 16; imcell++){
	  pedPosMemCell[imcell] = 0;
	}

	while(!file.eof()){
		getline(file, line);
		if (!line.length()) continue;
		if (line[0]=='#') continue;

		sscanf(line.c_str(), "%d\t%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf",
				&chip, &channel, &pedPosAll, &pedWidthAll,
				pedPosMemCell+0, pedPosMemCell+1, pedPosMemCell+2, pedPosMemCell+3, pedPosMemCell+4, pedPosMemCell+5, pedPosMemCell+6, pedPosMemCell+7,
				pedPosMemCell+8, pedPosMemCell+9, pedPosMemCell+10, pedPosMemCell+11, pedPosMemCell+12, pedPosMemCell+13, pedPosMemCell+14, pedPosMemCell+15);
		cnt += 1;
		//fill pedestal offsets:
		if (pedOffsets.count(chip) == 0){
			pedOffsets[chip]; //this makes sure that the key chip has been default-constucted in the data map
			pedOffsets[chip].resize(36); //this makes sure the corresponding vector is long enough.
		}
		pedOffsets[chip][channel].resize(16);
		for (int i=0; i<16; i++){
			pedOffsets[chip][channel][i] = pedPosMemCell[i];
		}

		//fill combined pedestal position:
		if (pedPossAll.count(chip) == 0){
			pedPossAll[chip]; //this makes sure that the key chip has been default-constucted in the data map
			pedPossAll[chip].resize(36); //this makes sure the corresponding vector is long enough.
		}
		pedPossAll[chip][channel] = pedPosAll;

		//fill combined pedestal width:
		if (pedWidthsAll.count(chip) == 0){
			pedWidthsAll[chip]; //this makes sure that the key chip has been default-constucted in the data map
			pedWidthsAll[chip].resize(36); //this makes sure the corresponding vector is long enough.
		}
		pedWidthsAll[chip][channel] = pedWidthAll;

	}

	file.close();
	std::cout << "PedestalCalibrator: read file \"" << path << "\", found " << cnt << " entries." << std::endl;
}

PedestalCalibrator::~PedestalCalibrator() {
	// TODO Auto-generated destructor stub
}

double PedestalCalibrator::getOffset(int chip, int chn, int memCell){
	if (pedOffsets.count(chip) != 0){
		return pedOffsets[chip][chn][memCell];
	} else {
		return 0;
	}
}

double PedestalCalibrator::getPositionTotal(int chip, int chn){
	if (pedOffsets.count(chip) != 0){
		return pedPossAll[chip][chn];
	} else {
		return 0;
	}

}

double PedestalCalibrator::getWidthTotal(int chip, int chn){
	if (pedOffsets.count(chip) != 0){
		return pedWidthsAll[chip][chn];
	} else {
		return 0;
	}

}

