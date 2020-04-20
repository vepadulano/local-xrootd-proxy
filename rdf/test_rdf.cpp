#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "ROOT/RDF/RInterface.hxx"
#include <iostream>

int main(){
    ROOT::RDataFrame df("Events", "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root");
    auto mean_op = df.Mean("nMuon");
    auto mean_val = mean_op.GetValue();
    std::cout << mean_val << std::endl;
}