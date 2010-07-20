This is a node.js module, written in C++, that compares two buffers.
For now it implements just eqBuf to test if two buffers are equal, fast.

It was written by Peteris Krumins (peter@catonmat.net).
His blog is at http://www.catonmat.net  --  good coders code, great reuse.

------------------------------------------------------------------------------

The module exports one function:

    * eqBuf - given two buffers, compare if they are equal.

Example usage:

    var eqBuf = require('bufferdiff');
    // ...
    if (eqBuf(buf1, buf2)) {
        sys.log('buffers buf1 and buf2 are equal');
    }


How to compile?
---------------

As usual,

    node-waf configure build

The module will be called `bufferdiff.node`. To use it, make sure it's in NODE_PATH.


Extra info
----------

This library was written for my and SubStack's StackVM startup:

    http://www.stackvm.com

    http://github.com/pkrumins/stackvm
    http://github.com/substack/stackvm


------------------------------------------------------------------------------

Yo dawg, I heard you liked buffers so I put a buffer in yo buffer so you can
compare while you compare.


Sincerely,
Peteris Krumins
http://www.catonmat.net

