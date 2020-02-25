# How to set up a XRootD proxy with cache

**NOTE:** Minimum xrootd version required is 4.7.0

Documentation: [https://xrootd.slac.stanford.edu/doc/dev50/pss_config.pdf](https://xrootd.slac.stanford.edu/doc/dev50/pss_config.pdf)

1. Copy the config `client-plugin-proxy.conf` to `$HOME/.xrootd/client.plugins.d/`
2. Adapt the server config `proxy.conf`
3. Start the proxy server with `bash start_proxy.sh`
    * you can pass `debug` string to enable debug mode on the server and check that the `.conf` file is correctly parsed
4. Open a new terminal session and run `bash test.sh`. This will copy a file from EOS to local machine
    * Again `debug` to see xrootd logs
    * Or `full` to set `XROOT_PROXY` and `XRD_PLUGIN` options. This should force `xrdcp`  to use the local machine as a caching proxy. Indeed, if proxy were working properly, this would mean appending `root://localhost:1094//` twice, hence should not work.
5. Run `bash test.sh` again and it should access the cache

Currently, if the EOS file was previously cached, e.g. with `bash test2.sh` without using the user conf, then the normal steps 1-5 work as intended. If instead the `xrdcp` process is started from scratch, it gets stuck. See the `test_coldcache.txt` log file for more info.
