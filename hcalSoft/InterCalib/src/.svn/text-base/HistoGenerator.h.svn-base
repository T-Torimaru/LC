/*
 * HistoGenerator.h
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */

#include <TProfile.h>
#include <TString.h>
#include <TF1.h>

#ifndef HISTOGENERATOR_H_
#define HISTOGENERATOR_H_

using namespace std;

class HistoGenerator {
public:
  HistoGenerator(int chipID, int chn);
	virtual ~HistoGenerator();

	void Fill(double val, double val2);
	void Fit(TF1 *l);
	void SetStats(int v);
	float GetMean(int t);

	TProfile* histoAll;
};

#endif /* HISTOGENERATOR_H_ */
