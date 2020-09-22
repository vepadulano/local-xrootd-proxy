#include "TFile.h"
#include "TSystem.h"
#include "TEnv.h"
#include "TTree.h"
#include <iostream>
#include "TBranch.h"
#include <memory>

int main()
{
   // gEnv->SetValue("TFile.AsyncPrefetching", 1);
   // gEnv->SetValue("Cache.Directory", "file:cache/");
   // gSystem->Setenv("XRD_LOGLEVEL", "Dump");
   // gSystem->Setenv("LD_PRELOAD","/lib64/libXrdPosixPreload.so");
   // gSystem->Setenv("XRDPOSIX_CONFIG","/home/vincenzo/Programs/local-xrootd-proxy/conf/serverless.conf");

   // const std::unique_ptr<TFile> f{TFile::Open("root://eospublic.cern.ch//eos/opendata/cms/derived-data/"
   //                                            "AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root")};


   const std::unique_ptr<TFile> f{TFile::Open("root://eosuser.cern.ch//eos/user/v/vpadulan/reftree.root")};

   const std::unique_ptr<TTree> t1{f->Get<TTree>("reftree")};

   const std::unique_ptr<TBranch> bnMuon{t1->GetBranch("b1")};

   bnMuon->Print();
   // unsigned int nMuon;
   // t1->SetBranchStatus("*", 0);
   // t1->SetBranchStatus("nMuon", 1);
   // t1->SetBranchAddress("nMuon", &nMuon);

   // auto nMuon_sum = 0ull;
   // const auto nentries = t1->GetEntries();

   // constexpr auto maxiterations = 10;
   // for (auto i = 0; i < nentries; i++) {
   //    t1->GetEntry(i);
   //    nMuon_sum += nMuon;
   // }

   // const auto nMuon_mean_iter = float(nMuon_sum) / float(nentries);
   // std::cout << "\n\n\n Average with division: " << nMuon_mean_iter << "\n Entries processed: " << nentries << "\n\n\n";
}


/*

1. Try with increasing number of entries and see difference between TFilePrefetch and xrootd
2. 
*/