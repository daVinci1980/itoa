# itoa
The worst implementation of itoa imaginable, using no external string library 
functions.

Although the license is MIT, this code should never be used by anyone
in any production code base, anywhere.

NOTE: This does use rand, which we could remove with some complexity. But using
rand means that there are almost definitely values that this will never complete
on, because C's rand is awesome.
