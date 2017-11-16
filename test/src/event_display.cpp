void event_display(int evenum = 12348){
  TString matchfile;
  matchfile.Form("../result/test.root");
  TFile *fmatch = new TFile(matchfile.Data(), "read");
  TTree *tmatch = (TTree*)fmatch->Get("bigtree");
  Int_t HhitI[256],HhitJ[256],HhitK[256],Hnhit;
  Double_t HhitPos[256][3];
  Float_t  HADC[256];
  Double_t nph[2][64];
  Int_t    nX[2];
  Double_t recoX[2][8];
  Int_t    nY[2];
  Double_t recoY[2][8];

  tmatch->SetBranchAddress("ahc_nHits", &Hnhit);
  tmatch->SetBranchAddress("ahc_hitI", HhitI);
  tmatch->SetBranchAddress("ahc_hitJ", HhitJ);
  tmatch->SetBranchAddress("ahc_hitK", HhitK);
  tmatch->SetBranchAddress("ahc_hitEnergy", HADC);
  TString ephname,nxname,nyname,recxname,recyname;
  for (int m = 0; m < 2; m++) {
    ephname.Form("hod%d_nph",m+1);
    nxname.Form("hod%d_nRecoX",m+1);
    nyname.Form("hod%d_nRecoY",m+1);
    recxname.Form("hod%d_recoX",m+1);
    recyname.Form("hod%d_recoY",m+1);
    tmatch->SetBranchAddress(ephname,nph[m]);
    tmatch->SetBranchAddress(nxname,&nX[m]);
    tmatch->SetBranchAddress(nyname,&nY[m]);
    tmatch->SetBranchAddress(recxname,recoX[m]);
    tmatch->SetBranchAddress(recyname,recoY[m]);
  }

  for (int i=evenum;i<tmatch->GetEntries();i++) {
    tmatch->GetEntry(i);
    if (Hnhit<=1) continue;
    int flag[2]={0,0};
    for (int n=0;n<Hnhit;n++) {
      if (HhitK[n]==11) flag[0]=1;
      else flag[1]=1;
    }
    if (flag[0]==1 && flag[1]==1) {
      evenum=i;
      break;
    }
    else continue;
  }

  TCanvas *canvas1 = new TCanvas("canvas1","scintillator plate",500,500);
  TCanvas *canvas2 = new TCanvas("canvas2","scintillator plate",500,500);
  TCanvas *canvas3 = new TCanvas("canvas3","combined",900,600);
  //TCanvas *canvas4 = new TCanvas("canvas4","combined",900,600);

  /*number of photo electron and corrected ...*/

  /*Get event*/
  tmatch->GetEntry(evenum);
  /*convert calibrated EASIROC data to array*/
  Double_t ly[2][2][16];
  for(int ch=0;ch<16;ch++) {
    ly[0][0][ch]=nph[0][32+(ch+12)%16]+nph[0][63-(ch+12)%16];
    ly[0][1][ch]=nph[0][15-(ch+12)%16]+nph[0][16+(ch+12)%16];
    ly[1][0][ch]=nph[1][ch]+nph[1][16+(ch+12)%16];
    ly[1][1][ch]=nph[1][47-ch]+nph[1][48+ch];
  }

  cout<<"evenum: "<<evenum<<endl;
  cout<<"  hod1: "<<nX[0]<<"x"<<nY[0]<<endl;
  cout<<"  hod2: "<<nX[1]<<"x"<<nY[1]<<endl;
  cout<<"  nhit: "<<Hnhit<<endl;

  TH2F *hcr[2];
  TGraphErrors *recoG[2];
  TGraph2D *Edisplay = new TGraph2D();
  TGraph2D *Hdisplay = new TGraph2D();
  int gcount=0;
  double height[2]={43.3*13,0};

  hcr[0] = new TH2F("hcr1","CR1 ly display;x[mm];y[mm]",84,0,420,84,0,420);
  hcr[1] = new TH2F("hcr2","CR2 ly display;x[mm];y[mm]",84,0,420,84,0,420);
  for (int m=0;m<2;m++) {
    for (int chx=0;chx<84;chx++) {
      for (int chy=0;chy<84;chy++) {
        hcr[m]->Fill((chx+0.5)*5,(chy+0.5)*5,ly[m][0][chx%16]*ly[m][1][chy%16]);
      }
    }
  }

  Edisplay->SetMarkerStyle(20);
  Hdisplay->SetMarkerStyle(21);
  Hdisplay->SetMarkerColor(2);
  Edisplay->SetTitle("3d display;x[mm];y[mm];z[mm]");
  for (int m=0;m<2;m++) {
    recoG[m] = new TGraphErrors();
    recoG[m]->SetMarkerStyle(20);
    recoG[m]->SetMarkerColor(0);
    for (int x=0;x<nX[m];x++) {
      for (int y=0;y<nY[m];y++) {
        recoG[m]->SetPoint(x*nY[m]+y,recoX[m][x],recoY[m][y]);
        Edisplay->SetPoint(gcount,recoX[m][x]-210,recoY[m][y]-210,height[m]);
        gcount++;
      }
    }
  }
  double true[6];
  true[0] = recoX[0][2]-210;
  true[1] = recoY[0][3]-210;
  true[2] = height[0];
  true[3] = recoX[1][1]-210;
  true[4] = recoY[1][3]-210;
  true[5] = height[1];
  TPolyLine3D *line = new TPolyLine3D(2,true);
  line->SetLineColor(2);

  for (int n=0;n<Hnhit;n++) {
    if(HhitK[n]==8) {
      HhitPos[n][0]=(HhitI[n]-12.5)*30.;
      HhitPos[n][1]=(HhitJ[n]-18.5)*30.;
      HhitPos[n][2]=43.3*3;
    } else if(HhitK[n]==9) {
      HhitPos[n][0]=(HhitI[n]-12.5)*30.;
      HhitPos[n][1]=(HhitJ[n]-6.5)*30.;
      HhitPos[n][2]=43.3*3;
    } else {
      HhitPos[n][0]=(HhitI[n]-12.5)*30.;
      HhitPos[n][1]=(HhitJ[n]-6.5)*30.+75.;
      HhitPos[n][2]=43.3*12;
    }
    Hdisplay->SetPoint(n,HhitPos[n][0],HhitPos[n][1],HhitPos[n][2]);
    cout<<n<<" "<<HhitPos[n][0]<<" "<<HhitPos[n][1]<<" "<<HhitPos[n][2]<<endl;
  }

  Edisplay->GetXaxis()->SetRangeUser(-210,210);
  Edisplay->GetYaxis()->SetRangeUser(-210,210);
  Edisplay->GetZaxis()->SetRangeUser(0,43.3*13);
  canvas1->cd();
  hcr[0]->Draw("colz");
  recoG[0]->Draw("Psame");
  canvas2->cd();
  hcr[1]->Draw("colz");
  recoG[1]->Draw("Psame");
  canvas3->cd();
  Edisplay->Draw("P");
  Hdisplay->Draw("P same");
  line->Draw("same");
  //canvas4->cd();
  //Hdisplay->Draw("P");

}
