#include <TRandomGen.h>
#include <ROOT/RDataFrame.hxx>
#include <RtypesCore.h>
#include <ROOT/RSnapshotOptions.hxx>

int main()
{
   TRandomMixMax r;

   ROOT::RDF::RSnapshotOptions opts;
   opts.fAutoFlush = 100000000;

   ROOT::RDataFrame df{1000000000};

   df.Define("b1", [](ULong64_t e) { return e; }, {"rdfentry_"})
      .Define("b2", [](ULong64_t e) { return 2 * e; }, {"b1"})
      .Define("b3", [&r] { return r.Gaus(10, 1); })
      .Define("b4", [&r] { return r.Poisson(10); })
      .Define("b5", [&r] { return r.Rndm(); })
      .Snapshot("reftree", "reftree.root", {"b1", "b2", "b3", "b4", "b5"}, opts);
}