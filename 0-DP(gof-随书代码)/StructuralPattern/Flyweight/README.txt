The pattern for saving memory (basically) by sharing properties of objects. Imagine a huge ammount of similar objects which all have most of their properties the same. That's natural to move these properties out of these objects to some external data structure and provide each object with the link to that data structure.

In the realization, the key point is to provide a pool/warehouse for shared objects, when requiring for shared objects, the existing one will just be returned, or created and keep in the pool/warehouse.


A flyweight is an object that minimizes memory use by sharing as much data as possible with other similar objects; it is a way to use objects in large numbers when a simple repeated representation would use an unacceptable amount of memory. Often some parts of the object state can be shared, and it is common practice to hold them in external data structures and pass them to the flyweight objects temporarily when they are used.

A classic example usage of the flyweight pattern is the data structures for graphical representation of characters in a word processor. It might be desirable to have, for each character in a document, a glyph object containing its font outline, font metrics, and other formatting data, but this would amount to hundreds or thousands of bytes for each character. Instead, for every character there might be a reference to a flyweight glyph object shared by every instance of the same character in the document; only the position of each character (in the document and/or the page) would need to be stored internally.

