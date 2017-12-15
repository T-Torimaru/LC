/*
Be carefull, do not manipulate the range of hist with hist->GetXaxis()->SetRangeUser()
before passing it to this function, it will cause strange result
*/
Float_t GainFromAutoCor(TH1I* hist){
    TH1I* histext = NULL;
    Int_t oplen = 4*4096-1;
    histext = new TH1I("hist_for_auto","hist for autocorrelation",oplen,0.5,oplen+0.5);
    for(int i=1;i<=4096;i++){
	histext->SetBinContent(i,hist->GetBinContent(i));
    }
    histext->SetBinContent(1,0); //just in case there is underflow

//do fft,get re and im part, times its conjugate
    TH1 *hRE =0;
    TVirtualFFT::SetTransform(0);
    hRE = histext->FFT(hRE, "MAG");
    TH1 *hIM =0;
    hIM = histext->FFT(hIM, "IM");
    Double_t *re_full = new Double_t[oplen];
    Double_t *im_full = new Double_t[oplen];
    for(int i=1;i<=oplen;i++){
	re_full[i-1] = hRE->GetBinContent(i);
	im_full[i-1] = hIM->GetBinContent(i);
    }
    for(int i=0;i<oplen;i++){
	re_full[i] = re_full[i]*re_full[i]+im_full[i]*im_full[i];
	im_full[i] = 0;
    }

//ifft transform:
    TVirtualFFT *fft_back = TVirtualFFT::FFT(1, &oplen, "C2R M K");
    fft_back->SetPointsComplex(re_full,im_full);
    fft_back->Transform();
    TH1 *hb = 0;
    hb = TH1::TransformHisto(fft_back,hb,"Re");

//only keep the fruitful part
    TH1F *hist_auto = new TH1F("hist_auto","The auto-correlation hist",4096,0,4096);
    for(int i=1;i<=4096;i++){
	hist_auto->SetBinContent(i,(hb->GetBinContent(i)/oplen));
    }
    TCanvas* AutohistCanvas = NewCanvas("auto-correlation",800,600);
    hist_auto->Draw();

//find out the position of first harmony, it is the gain.
//if the original hist was set to a range, this number is screwed up
    Float_t retv = FindHarmonyPeak(hist_auto);
    delete[] re_full;
    delete[] im_full;
    delete hRE;
    delete hIM;
    delete histext;
    return retv;
}
