HTTP Live Streaming
* a.k.a **HLS**
* an HTTP-based media streaming communications protocol
* implemented by Apple Inc.
* part of its QuickTime, Safari, OS X, and iOS software.
* breaking the overall stream into a sequence of small HTTP-based file downloads, each download loading one short chunk of an overall potentially unbounded transport stream.
* the client may select from a number of different alternate streams containing the same material encoded at a variety of data rates, allowing the streaming session to adapt to the available data rate. At the start of the streaming session, it downloads an extended M3U playlist containing the metadata for the various sub-streams which are available.
* Due to the fact of using only standard HTTP transactions, HTTP Live Streaming can traverse any firewall or proxy server that lets through standard HTTP traffic, unlike UDP-based protocols such as RTP.
* Can apply to conventional HTTP servers as origin and delivered over widely available HTTP-based content delivery networks.

References:

1. [Wiki on HTTP Live Streaming](https://en.wikipedia.org/wiki/HTTP_Live_Streaming

History:

* 2015/11/04  init
