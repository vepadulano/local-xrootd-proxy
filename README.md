# How to set up a XRootD proxy with cache

1. Copy the config `client-plugih-proxy.conf` to `$HOME/.xrootd/client.plugins.d/`
2. Adapt the server config `proxy.conf`
3. Start the proxy server with `bash start_proxy.sh`
4. Test the caching with `bash test.sh`
5. Remove the output file and try again
