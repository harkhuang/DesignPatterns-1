Composite lets clients treat individual objects and compositions of objects uniformly. The Composite pattern can represent both the conditions. In this pattern, one can develop tree structures for representing part-whole hierarchies.


The composite pattern describes that a group of objects are to be treated in the same way as a single instance of an object. The intent of a composite is to "compose" objects into tree structures to represent part-whole hierarchies. Implementing the composite pattern lets clients treat individual objects and compositions uniformly.

                  --------------------
                        Component       0..*
                      + operation()    -------------------|
                  --------------------  child             |
                          ^                               |
                          |                               |
         |-------------------------------|                |
--------------------           --------------------       |
Leaf                           Composite          |       |
+ operation()                  + getChild()       |<>-----|
--------------------           + operation()      |
                               + add()            |
                               + remove()         |
                               - vector<Component*>: leaves
                               --------------------

Component
- is the abstraction for all components, including composite ones
- declares the interface for objects in the composition
- (optional) defines an interface for accessing a component's parent in the recursive structure, and implements it if that's appropriate
Leaf
- represents leaf objects in the composition
- implements all Component methods
Composite
- represents a composite Component (component having children)
- implements methods to manipulate children (have one or more Leaf objects, accessed by Component pointer)
- implements all Component methods, generally by delegating them to its children


The only problem with composite pattern is that the management strategy for Leaf objects must be provided. in example, vector is used, other methods like array, linked list, hash table etc. can also be used.
