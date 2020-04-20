#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"
#include <iostream>

int main(){
    // gSystem->Setenv("XRD_LOGLEVEL","Dump");
    // gSystem->Setenv("LD_PRELOAD","/lib64/libXrdPosixPreload.so");
    // gSystem->Setenv("XRDPOSIX_CONFIG","/home/vincenzo/Programs/local-xrootd-proxy/conf/serverless.conf");

    TFile *f = TFile::Open("root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root");
    auto t1 = f->Get<TTree>("Events");
    UInt_t nMuon;
    t1->SetBranchStatus("*",0);
    t1->SetBranchStatus("nMuon",1);
    t1->SetBranchAddress("nMuon",&nMuon);

    Long64_t nMuon_sum=0;
    Long64_t nentries = t1->GetEntries();

    for (Long64_t i=0;i<nentries;i++) {
        t1->GetEntry(i);
        nMuon_sum += nMuon;
    }

    auto nMuon_mean_iter = float(nMuon_sum) / float(nentries);
    std::cout << "Average with division: " << nMuon_mean_iter << "\n";
}