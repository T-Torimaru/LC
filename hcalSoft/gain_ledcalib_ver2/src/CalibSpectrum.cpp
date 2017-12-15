/*
 * CalibSpectrum.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */

#include "CalibSpectrum.h"

CalibSpectrum::CalibSpectrum(int chipID, int chn, int vCalib) {
	// TODO Auto-generated constructor stub

	histoAll = new TH1F(TString::Format("z_ADC_chip%d_chn%d_%dmV",chipID, chn, vCalib),TString::Format("ADC Spectrum Chip %d, Channel %d, V#_{calib} %dmV",chipID, chn, vCalib),4096,-0.5,4095.5);
	//histoEven = new TH1D(TString::Format("z_ADC_chip%d_chn%d_%dmV_even",chipID, chn, vCalib),TString::Format("ADC Spectrum Chip %d, Channel %d, V#_{calib} %dmV (even events)",chipID, chn, vCalib),4096,-0.5,4095.5);
	//histoOdd = new TH1D(TString::Format("z_ADC_chip%d_chn%d_%dmV_odd",chipID, chn, vCalib),TString::Format("ADC Spectrum Chip %d, Channel %d, V#_{calib} %dmV (odd events)",chipID, chn, vCalib),4096,-0.5,4095.5);

	fillParity = 0;
	ChiSquareNDF = 0;
}

CalibSpectrum::~CalibSpectrum() {
	delete histoAll;
	//delete histoEven;
	//delete histoOdd;

	// TODO Auto-generated destructor stub
}

int CalibSpectrum::Fill(double val){
	histoAll->Fill(val);

	/*if (fillParity == 0){
		histoEven->Fill(val);
		fillParity = 1;
	} else if (fillParity == 1){
		histoOdd->Fill(val);
		fillParity = 0;
	}*/
}


std::pair<double,double> CalibSpectrum::FitOnePeak(float V){
	//return FitGainMultiGauss();

	TF1 *fitAll;
	double width, mean;

	//Lan change the maximum number of peaks to find
	fitAll = OnePFit(histoAll);

	if (fitAll != 0){
		mean = fitAll->GetParameter(1);
		width = fitAll->GetParameter(2);
	}

	if (fitAll != 0){
	  return std::make_pair<double,double>(mean,width);
	}
	
	return std::make_pair<double,double>(0,0);;
}


std::pair<double,double> CalibSpectrum::FitGain(float V){
	//return FitGainMultiGauss();

	TF1 *fitAll;
	double gainAll, gainErr;

	//int npeaksToFind = 6;
	//if (V>=7000) npeaksToFind = 10;

	//Lan change the maximum number of peaks to find
	//fitAll = MultiPFit(histoAll, 10, 1, 5, 0.15);
	fitAll = MultiPFit(histoAll, 10, 1, 2, 0.10);
	//fitAll = MultiPFit(histoAll, npeaksToFind, 1, 5, 0.15);
	if (fitAll != 0){
		gainAll = fitAll->GetParameter(1);
		gainErr = fitAll->GetParError(1);
		double fitrangeLower, fitRangeUpper;
		fitAll->GetRange(fitrangeLower, fitRangeUpper);
		ChiSquareNDF = fitAll->GetChisquare()/(histoAll->FindBin(fitRangeUpper)-histoAll->FindBin(fitrangeLower)-fitAll->GetNumberFreeParameters());
	}

	if (fitAll != 0){
	  return std::make_pair<double,double>(gainAll,gainErr);
	}
	
	return std::make_pair<double,double>(0,0);;
}

double CalibSpectrum::FFTGain(){
	return GainFromFFT(histoAll)[0];
}


double CalibSpectrum::FitGainMultiGauss(){
	TF1 *fitAll, *fitEven, *fitOdd;
	fitEven = MultiPFit(histoEven, 6, 1, 2, 0.25);
	fitOdd = MultiPFit(histoOdd, 6, 1, 2, 0.25);


	if (fitEven != 0 && fitOdd != 0){
		double gainEven, gainOdd, gainRatio, gainAll;

		gainEven = fitEven->GetParameter(1);
		gainOdd = fitOdd->GetParameter(1);
		gainRatio = TMath::Abs(1-gainEven/gainOdd);

		if (gainRatio < 0.05){

//			int nParEven = fitEven->GetNpar();
//			int nParOdd = fitOdd->GetNpar();
//
//			if (nParEven == nParOdd){
//				fitAll = new TF1(*fitEven);
//
//				for (int iPar = 0; iPar<nParEven; iPar++){
//					fitAll->SetParameter(iPar, (fitEven->GetParameter(iPar)+fitOdd->GetParameter(iPar))/2);
//				}
//				for (int iPar = 3; iPar<nParEven; iPar+=2){ //double all gauss amplitudes
//					fitAll->SetParameter(iPar, fitAll->GetParameter(iPar)*2);
//				}
//			}



			fitAll = MultiPFit(histoAll, 6, 1, 2, 0.25);
			if (fitAll != 0){
				gainAll = fitAll->GetParameter(1);
				double fitrangeLower, fitRangeUpper;
				fitAll->GetRange(fitrangeLower, fitRangeUpper);
				ChiSquareNDF = fitAll->GetChisquare()/(histoAll->FindBin(fitRangeUpper)-histoAll->FindBin(fitrangeLower)-fitAll->GetNumberFreeParameters());
			}
			delete fitAll;
		}

		delete fitEven;
		delete fitOdd;


		if (fitAll != 0){
			return gainAll;
		}
	}
	return 0;

}

void CalibSpectrum::Delete()
{
  histoAll->Delete();
}
