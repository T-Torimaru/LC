/*
 * mpf.h
 *
 *  Created on: Oct 12, 2012
 *      Author: hartbrich
 */

#ifndef MPF_H_
#define MPF_H_

#include <string>
using namespace std;

Double_t MultiGaus(Double_t *x, Double_t *par);

TF1 * MultiPFit(TH1F *  peaks, Int_t nOfpeaks, Float_t res,Float_t sigmapeak,Float_t threshold);


#endif /* MPF_H_ */

