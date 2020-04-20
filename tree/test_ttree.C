void test_ttree () {

    gDebug = 2;
    gSystem->Setenv("XROOT_PROXY","root://localhost:1094//");
    gSystem->Setenv("XRD_LOGLEVEL","Dump");

    TStopwatch t;
    t.Start();
    // TFile::SetCacheFileDir(".");
    TFile *f = TFile::Open("root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root");
    auto t1 = f->Get<TTree>("Events");
    UInt_t nMuon;
    t1->SetBranchStatus("*",0);
    t1->SetBranchStatus("nMuon",1);
    t1->SetBranchAddress("nMuon",&nMuon);

    // Loop over entries and std::accumulate
    // std::vector<UInt_t> nMuon_vec;

    Long64_t nMuon_sum=0;

    //read all entries and fill the histograms
    Long64_t nentries = t1->GetEntries();
    // nMuon_vec.reserve(nentries);
    for (Long64_t i=0;i<nentries;i++) {
        t1->GetEntry(i);
        nMuon_sum += nMuon;
        // nMuon_vec.emplace_back(nMuon);
    }

    std::cout << float(nMuon_sum) << "/" << float(nentries) << "\n";
    auto nMuon_mean_iter = float(nMuon_sum) / float(nentries);
    std::cout << nMuon_mean_iter << "\n";

    // Compute mean using std::vector
    // auto nMuon_vec_sum = std::accumulate(std::begin(nMuon_vec), std::end(nMuon_vec), 0.0);
    // auto nMuon_vec_size = nMuon_vec.size();
    // auto nMuon_vec_mean = nMuon_vec_sum / nMuon_vec_size;
    // std::cout << "vec_sum: " << nMuon_vec_sum << " vec_size: " << nMuon_vec_size << " vec_mean: " << nMuon_vec_mean << "\n";

    // Draw histogram and get mean
    // t1->Draw("nMuon>>h_nMuon");
    // TH1F *h_nMuon = (TH1F*)gDirectory->Get("h_nMuon");
    // auto nMuon_mean = h_nMuon->GetMean(); 
    // std::cout << nMuon_mean << std::endl;

    t.Stop();
    t.Print();
}