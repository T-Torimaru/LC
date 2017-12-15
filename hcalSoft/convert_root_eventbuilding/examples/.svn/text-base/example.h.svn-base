//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Apr 10 22:04:28 2016 by ROOT version 5.34/18
// from TTree myTree/myTree
// found on file: cosmics_threshold240_length16ms__2016p04p08__16o26o01.root
//////////////////////////////////////////////////////////

#ifndef example_h
#define example_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class example {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           ahcal_nHits;
   Int_t           ahcal_iEvt;
   Int_t           ahcal_BunchXID[144];   //[ahcal_nHits]
   Int_t           ahcal_CycleNr[144];   //[ahcal_nHits]
   Int_t           ahcal_ChipID[144];   //[ahcal_nHits]
   Int_t           ahcal_EvtNr[144];   //[ahcal_nHits]
   Int_t           ahcal_Channel[144];   //[ahcal_nHits]
   Int_t           ahcal_TDC[144];   //[ahcal_nHits]
   Int_t           ahcal_ADC[144];   //[ahcal_nHits]
   Int_t           ahcal_HitBit[144];   //[ahcal_nHits]
   Int_t           ahcal_GainBit[144];   //[ahcal_nHits]

   // List of branches
   TBranch        *b_ahcal_nHits;   //!
   TBranch        *b_ahcal_iEvt;   //!
   TBranch        *b_ahcal_BunchXID;   //!
   TBranch        *b_ahcal_CycleNr;   //!
   TBranch        *b_ahcal_ChipID;   //!
   TBranch        *b_ahcal_EvtNr;   //!
   TBranch        *b_ahcal_Channel;   //!
   TBranch        *b_ahcal_TDC;   //!
   TBranch        *b_ahcal_ADC;   //!
   TBranch        *b_ahcal_HitBit;   //!
   TBranch        *b_ahcal_GainBit;   //!

   example(TTree *tree=0);
   virtual ~example();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef example_cxx
example::example(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("cosmics_threshold240_length16ms__2016p04p08__16o26o01.root");
      if (!f || !f->IsOpen()) {
	f = new TFile("../../../Rootfiles_cosmics/cosmics_all.root");//../../../Rootfiles_Sr90/sr90_threshold220__2016p04p11__12o52o55.root");//sr90_threshold240__2016p04p11__11o52o58.root");//cosmics_threshold240__2016p04p08__18o44o30.root");//cosmics_threshold240_length16ms__2016p04p08__16o26o01.root");//cosmics_all.root");//cosmics_all.root");
      }
      f->GetObject("myTree",tree);

   }
   Init(tree);
}

example::~example()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t example::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t example::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void example::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ahcal_nHits", &ahcal_nHits, &b_ahcal_nHits);
   fChain->SetBranchAddress("ahcal_iEvt", &ahcal_iEvt, &b_ahcal_iEvt);
   fChain->SetBranchAddress("ahcal_BunchXID", ahcal_BunchXID, &b_ahcal_BunchXID);
   fChain->SetBranchAddress("ahcal_CycleNr", ahcal_CycleNr, &b_ahcal_CycleNr);
   fChain->SetBranchAddress("ahcal_ChipID", ahcal_ChipID, &b_ahcal_ChipID);
   fChain->SetBranchAddress("ahcal_EvtNr", ahcal_EvtNr, &b_ahcal_EvtNr);
   fChain->SetBranchAddress("ahcal_Channel", ahcal_Channel, &b_ahcal_Channel);
   fChain->SetBranchAddress("ahcal_TDC", ahcal_TDC, &b_ahcal_TDC);
   fChain->SetBranchAddress("ahcal_ADC", ahcal_ADC, &b_ahcal_ADC);
   fChain->SetBranchAddress("ahcal_HitBit", ahcal_HitBit, &b_ahcal_HitBit);
   fChain->SetBranchAddress("ahcal_GainBit", ahcal_GainBit, &b_ahcal_GainBit);
   Notify();
}

Bool_t example::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void example::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t example::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef example_cxx
