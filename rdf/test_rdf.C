void test_rdf() {
    // gDebug = 3;
    // gSystem->Setenv("XROOT_PROXY","root://localhost:1094//");
    // gSystem->Setenv("XRD_LOGLEVEL","Dump");
    // gEnv->SetValue("TFile.AsyncPrefetching", 1);
    // gEnv->SetValue("Cache.Directory","file:/home/vincenzo/Programs/local-xrootd-proxy/xrootd-cache/");
    TStopwatch t;
    t.Start();
    ROOT::RDataFrame df("Events", "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root");
    cout << df.Mean("nMuon").GetValue() << endl;
    t.Stop();
    t.Print();
}
