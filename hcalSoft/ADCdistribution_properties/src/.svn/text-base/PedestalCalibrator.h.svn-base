/*
 * PedestalCalibrator.h
 *
 *  Created on: Jan 29, 2014
 *      Author: ohartbri
 */

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

#ifndef PEDESTALCALIBRATOR_H_
#define PEDESTALCALIBRATOR_H_


class PedestalCalibrator {
public:
	PedestalCalibrator(std::string path);
	virtual ~PedestalCalibrator();
	double getOffset(int chip, int chn, int memCell);
	double getWidthTotal(int chip, int chn);
	double getPositionTotal(int chip, int chn);

private:
	std::map<int, std::vector< std::vector<double> > > pedOffsets;
	std::map<int, std::vector<double> > pedPossAll;
	std::map<int, std::vector<double> > pedWidthsAll;
};

#endif /* PEDESTALCALIBRATOR_H_ */
