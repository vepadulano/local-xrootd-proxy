#!/bin/bash

rm -f test.root
/home/stefan/xrootd/build/src/XrdCl/xrdcp root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
