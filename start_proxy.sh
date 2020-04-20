#!/bin/bash

if [[ $1 == "debug" ]]
then
    rm -f xrd_server.txt
    XRD_LOGLEVEL=Dump xrootd -d 3 -c conf/proxy.conf &> xrd_server.txt
else
    xrootd -c proxy.conf
fi