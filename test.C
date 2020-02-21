void test() {
    TStopwatch t;
    t.Start();
    ROOT::RDataFrame df("Events", "root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root");
    cout << df.Mean("nMuon").GetValue() << endl;
    t.Stop();
    t.Print();
}
