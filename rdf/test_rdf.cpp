#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"
#include "TSystem.h"
#include <iostream>

int main()
{
   gSystem->Setenv("XRD_LOGLEVEL", "Dump");
   ROOT::RDataFrame df("Events", "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/"
                                 "Run2012BC_DoubleMuParked_Muons.root");
   auto mean_op = df.Mean("nMuon");
   const auto &mean_val = mean_op.GetValue();
   std::cout << mean_val << std::endl;
}