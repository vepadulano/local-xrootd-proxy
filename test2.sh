#!/bin/bash

rm -f test.root
if [[ $1 == "debug" ]]
then
    XRD_LOGLEVEL=Dump xrdcp root://localhost:1094//root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
else
    xrdcp root://localhost:1094//root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
fi