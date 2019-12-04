# How to set up a XRootD proxy with cache

**NOTE:** Minimum xrootd version required is 4.7.0

Documentation: [https://xrootd.slac.stanford.edu/doc/dev47/pss_config.htm](https://xrootd.slac.stanford.edu/doc/dev47/pss_config.htm)

1. Copy the config `client-plugih-proxy.conf` to `$HOME/.xrootd/client.plugins.d/`
2. Adapt the server config `proxy.conf`
3. Start the proxy server with `bash start_proxy.sh`
4. Test the caching with `bash test.sh`
5. Run `bash test.sh` again and it should access the cache
