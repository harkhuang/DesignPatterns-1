The Bridge Pattern is used to separate out the interface from its implementation. Doing this gives the flexibility so that both can vary independently.

The bridge pattern is a design pattern used in software engineering which is meant to "decouple an abstraction from its implementation so that the two can vary independently".[1] The bridge uses encapsulation, aggregation, and can use inheritance to separate responsibilities into different classes.

When a class varies often, the features of object-oriented programming become very useful because changes to a program's code can be made easily with minimal prior knowledge about the program. The bridge pattern is useful when both the class as well as what it does vary often. The class itself can be thought of as the implementation and what the class can do as the abstraction. The bridge pattern can also be thought of as two layers of abstraction.

The bridge pattern is often confused with the adapter pattern. In fact, the bridge pattern is often implemented using the class adapter pattern, e.g. in the Java code below.

Variant: The implementation can be decoupled even more by deferring the presence of the implementation to the point where the abstraction is utilized.



* Abstraction
  defines the abstract interface
  maintains the Implementor reference.
* RefinedAbstraction
  extends the interface defined by Abstraction
* Implementor
  defines the interface for implementation classes
* ConcreteImplementor
  implements the Implementor interface



In bridge pattern, the abstraction and implementation of abstraction are realized independedly.
