# How to set up a XRootD proxy with cache

**NOTE:** Minimum xrootd version required is 4.7.0

Documentation: [https://xrootd.slac.stanford.edu/doc/dev50/pss_config.pdf](https://xrootd.slac.stanford.edu/doc/dev50/pss_config.pdf)

## ProxyPlugin caching of a file

To configure the ProxyPlugin feature, be sure to run the following as a separate user on the machine, e.g. `xrootd`. The ROOT application and the xrootd Proxy should be run as different users.
1. Adapt the server config `conf/proxy.conf`
2. Start the proxy server with `bash start_proxy.sh`
    * you can pass `debug` string to enable debug mode on the server and check that the `.conf` file is correctly parsed
Now you can run as your normal user the following steps:
1. Copy the config `conf/client-plugin-proxy.conf` to `$HOME/.xrootd/client.plugins.d/`
2. Open a new terminal session and run `bash test.sh`. This will copy a file from EOS to local machine
    * Again `debug` to see xrootd logs
    * Or `full` to set `XROOT_PROXY` and `XRD_PLUGIN` options. This should force `xrdcp`  to use the local machine as a caching proxy. Indeed, if proxy were working properly, this would mean appending `root://localhost:1094//` twice, hence should not work.
3. Run `bash test.sh` again and it should access the cache

Currently, the automatic prepending of the proxy URL and the plugin itself work for the `test` and `test2` scripts. This still leaves the questions as to why the proxy url is handled correctly even in `test2` where it's already prepended to the EOS url.


## ProxyPlugin caching with a `TTree`
Unfortunately, the caching is still at the file level, whereas we would like it to work with a single cluster of a `TTree`. The `tree/test_ttree.cpp` is the test I'm currently focused on. So far, the ProxyPlugin feature is still triggered, but doesn't cache a single cluster or branch, but the whole file.

## Serverless caching feature
I followed the documentation and produced the conf at `conf/serverless.conf` but I couldn't trigger any caching mechanism.