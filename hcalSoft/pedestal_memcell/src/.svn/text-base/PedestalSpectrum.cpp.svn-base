/*
 * PedestalSpectrum.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */

#include "PedestalSpectrum.h"

using namespace std;

PedestalSpectrum::PedestalSpectrum(int chipID, int chn) {
	// TODO Auto-generated constructor stub

	histoAll = new TH1F(TString::Format("z_PEDESTAL_chip%d_chn%d_all",chipID, chn),TString::Format("Pedestal Spectrum Chip %d, Channel %d, all MemCells",chipID, chn),4096,-0.5,4095.5);

	histos.resize(16);
	for (int i=0; i<16; i++){
		histos.at(i) = new TH1F(TString::Format("z_PEDESTAL_chip%d_chn%d_cell%d",chipID, chn, i),TString::Format("Pedestal Spectrum Chip %d, Channel %d, MemCell %d",chipID, chn, i),4096,-0.5,4095.5);
	}
	pedestalPositions.resize(16,0);
	pedestalOffsets.resize(16,0);
	pedestalWidths.resize(16,0);


}

PedestalSpectrum::~PedestalSpectrum() {
	delete histoAll;
	for (int i=0; i<16; i++){
		delete histos.at(i);
	}

	// TODO Auto-generated destructor stub
}

int PedestalSpectrum::Fill(double val, int memCell){
	histoAll->Fill(val);
	histos.at(memCell)->Fill(val);
}



int PedestalSpectrum::FitPedestals(){
	TSpectrum *s = new TSpectrum();
	for (int i=0; i<=16; i++){
		TH1F* thisHisto;
		double *thisPedestalWidth, *thisPedestalPosition;
		if (i<16){
			thisHisto = histos.at(i);
			thisPedestalWidth = &(pedestalWidths.at(i));
			thisPedestalPosition = &(pedestalPositions.at(i));
		} else {
			thisHisto = histoAll;
			thisPedestalWidth = &pedestalWidthAll;
			thisPedestalPosition = &pedestalPositionAll;
		}

		s->Search(thisHisto, 4, "", 0.5);

		Float_t *PeakPosX, *PeakPosY;
		double PeakX, PeakY;
		int NPeaks;

		NPeaks = s->GetNPeaks();
		PeakPosX = s->GetPositionX();
		PeakPosY = s->GetPositionY();

		if (NPeaks>0){
			thisHisto->Fit("gaus","","", PeakPosX[0]-7, PeakPosX[0]+7);
			TF1* fit = thisHisto->GetFunction("gaus");
			if (fit != 0){
				*thisPedestalPosition = fit->GetParameter(1);
				*thisPedestalWidth = fit->GetParameter(2);
			} else {
				*thisPedestalPosition = 0;
				*thisPedestalWidth = 0;
			}
		}
	}

	for (int i=0; i<16; i++){
	  pedestalOffsets.at(i) = pedestalPositions.at(1) - pedestalPositions.at(i);
	  //pedestalOffsets.at(i) =  - pedestalPositions.at(i);
		cout << "cell " << i << " pedestalPositions.at(1) " << pedestalPositions.at(1) 
		     << " pedestalPositions.at(i) " << pedestalPositions.at(i) << endl;
	}
}

int PedestalSpectrum::sortPeakList(Float_t *PeakPosX, Float_t *PeakPosY, int NPeaks){
	std::list< std::pair<Float_t, Float_t> > PeakList;
	for (int i=0; i<NPeaks; i++){
		PeakList.push_back(std::pair<Float_t, Float_t>(PeakPosX[i], PeakPosY[i]));
	}
	PeakList.sort();

	int i=0;
	for (std::list< std::pair<Float_t, Float_t> >::iterator it = PeakList.begin(); it!=PeakList.end(); it++){
		PeakPosX[i] = it->first;
		PeakPosY[i] = it->second;
		i++;
	}
	if (i!=(NPeaks)){
		std::cout << "EXTERMINATE!" << std::endl;
		return 1;
	}

	return 0;
}
