/*
 * HistoGenerator.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: ohartbri
 */

#include "HistoGenerator.h"

HistoGenerator::HistoGenerator(int chipID, int chn) {

  histoAll = new TProfile(TString::Format("HG_LG_ADC_chip%d_chn%d",chipID, chn),TString::Format("ADC HG LG Spectrum Chip %d, Channel %d",chipID, chn),4096,-0.5,4095.5);
 
}

HistoGenerator::~HistoGenerator() {
	delete histoAll;
}

void HistoGenerator::Fill(double val, double val2){
  histoAll->Fill(val, val2);
}

void HistoGenerator::Fit(TF1 *l)
{
  histoAll->Fit(l, "RQS", "sames");
}

void HistoGenerator::SetStats(int v)
{
  histoAll->SetStats(v);
}

float HistoGenerator::GetMean(int t)
{
  float mean = histoAll->GetMean(t);
  return mean;
}
