#!/bin/bash

rm -f test.root
if [[ $1 == "debug" ]]
then
    XRD_LOGLEVEL=Dump xrdcp root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
elif [[ $1 == "full" ]]
then
    XRD_LOGLEVEL=Dump XRD_PLUGIN=/home/vpadulan/Programs/xrootd/build/src/libXrdClProxyPlugin.so XROOT_PROXY=root://localhost:1094// xrdcp root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
else
    xrdcp root://eospublic.cern.ch//eos/opendata/cms/derived-data/AOD2NanoAODOutreachTool/Run2012BC_DoubleMuParked_Muons.root test.root
fi