/*
 * CalibSpectrum.h
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */


#include <TH1.h>
#include <TF1.h>
#include <TSpectrum.h>
#include <TString.h>

#include <list>
#include <utility>

#include <vector>

#ifndef PEDESTALSPECTRUM_H_
#define PEDESTALSPECTRUM_H_

class PedestalSpectrum {
public:
	PedestalSpectrum(int chipID, int chn);
	virtual ~PedestalSpectrum();

	int Fill(double val, int memCell);
	int FitPedestals();

	std::vector<double> pedestalOffsets;
	std::vector<double> pedestalPositions;
	std::vector<double> pedestalWidths;
	double pedestalPositionAll;
	double pedestalWidthAll;


private:
	TH1F* histoAll;
	std::vector< TH1F* > histos;
	int sortPeakList(Float_t *PeakPosX, Float_t *PeakPosY, int NPeaks);



};

#endif /* PEDESTALSPECTRUM_H_ */
