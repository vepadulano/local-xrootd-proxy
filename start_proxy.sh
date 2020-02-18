#!/bin/bash

if [[ $1 == "debug" ]]
then    
    XRD_LOGLEVEL=Dump xrootd -c proxy.conf
else
    xrootd -c proxy.conf
fi