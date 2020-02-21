#!/bin/bash

if [[ $1 == "debug" ]]
then
    rm -f xrd_server.txt
    XRD_LOGLEVEL=Dump xrootd -c proxy.conf
else
    xrootd -c proxy.conf
fi