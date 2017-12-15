/*
 * CalibSpectrum.h
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */

#include "mpf.h"
#include "onepf.h"
#include "UHHExtractGain.h"

#include <TH1.h>
#include <TString.h>

#ifndef CALIBSPECTRUM_H_
#define CALIBSPECTRUM_H_

using namespace std;

class CalibSpectrum {
public:
	CalibSpectrum(int chipID, int chn, int vCalib = 0);
	virtual ~CalibSpectrum();

	int Fill(double val);
	void Delete();

	std::pair<double,double> FitOnePeak(float V);
	std::pair<double,double> FitGain(float V);
	double FFTGain();


	double ChiSquareNDF;
	TH1F* histoAll;
private:
	double FitGainMultiGauss();

	int fillParity;

	//TH1D* histoAll;
	TH1F* histoEven;
	TH1F* histoOdd;
};

#endif /* CALIBSPECTRUM_H_ */
