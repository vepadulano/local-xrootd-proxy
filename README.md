# How to set up a XRootD proxy with cache

**NOTE:** Minimum xrootd version required is 4.7.0

Documentation: [https://xrootd.slac.stanford.edu/doc/dev47/pss_config.htm](https://xrootd.slac.stanford.edu/doc/dev47/pss_config.htm)

1. Copy the config `client-plugin-proxy.conf` to `$HOME/.xrootd/client.plugins.d/`
2. Adapt the server config `proxy.conf`
3. Start the proxy server with `bash start_proxy.sh`
    * you can pass `debug` string to enable debug mode on the server and check that the `.conf` file is correctly parsed
4. Open a new terminal session and run `bash test.sh`. This will copy a file from EOS to local machine
    * Again `debug` to see xrootd logs
    * Or `full` to set `XROOT_PROXY` and `XRD_PLUGIN` options. This should force `xrdcp`  to use the local machine as a caching proxy
5. Run `bash test.sh` again and it should access the cache

There is another test called `test2.sh` that works like `test.sh` but prepends `root://localhost:1094//` to the EOS url. This means that the location of the local proxy is explicitly told to the `xrdcp` command. This is not what we want, but until now it's the only thing that seems to work.
