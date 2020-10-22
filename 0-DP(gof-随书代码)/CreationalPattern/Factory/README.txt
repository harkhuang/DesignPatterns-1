The factory method pattern is an object-oriented creational design pattern to implement the concept of factories and deals with the problem of creating objects (products) without specifying the exact class of object that will be created. The essence of this pattern is to "Define an interface for creating an object, but let the classes that implement the interface decide which class to instantiate. The Factory method lets a class defer instantiation to subclasses."

Creating an object often requires complex processes not appropriate to include within a composing object. The object's creation may lead to a significant duplication of code, may require information not accessible to the composing object, may not provide a sufficient level of abstraction, or may otherwise not be part of the composing object's concerns. The factory method design pattern handles these problems by defining a separate method for creating the objects, which subclasses can then override to specify the derived type of product that will be created.

Some of the processes required in the creation of an object include determining which object to create, managing the lifetime of the object, and managing specialized build-up and tear-down concerns of the object. Outside the scope of design patterns, the term factory method can also refer to a method of a factory whose main purpose is creation of objects.

The factory method pattern relies on inheritance, as object creation is delegated to subclasses that implement the factory method to create objects.

The factory pattern can be used when:

- The creation of an object precludes its reuse without significant duplication of code.
- The creation of an object requires access to information or resources that should not be contained within the composing class.
- The lifetime management of the generated objects must be centralized to ensure a consistent behavior within the application.
Factory methods are common in toolkits and frameworks, where library code needs to create objects of types that may be subclassed by applications using the framework.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
