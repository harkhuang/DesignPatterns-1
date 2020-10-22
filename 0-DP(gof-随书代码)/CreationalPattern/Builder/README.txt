The builder pattern is an object creation software design pattern. The intention is to abstract steps of construction of objects so that different implementations of these steps can construct different representations of objects. Often, the builder pattern is used to build products in accordance with the composite pattern.
Main ingredients are: Director, Builder, ConcreteBuider, Product(Parts)

----------             ----------               ----------
Director               Builder                  ConcreteBuilder     <<create>>   ----------
+builder      <>------ +BuildPart()  <|-------- +BuildPart()       ............> Product
+construct()           ----------               +getResult: Product              ----------
----------                                      ----------

* Director
  Direct the builder to build the necessary parts, then construct the product
* Builder
  Abstract interface for creating objects (product).
* Concrete Builder
  Provides implementation for Builder. It is an object able to construct other objects. Constructs and assembles parts to build the objects.

Useful tips
+ Builder focuses on constructing a complex object step by step. Abstract Factory emphasizes a family of product objects (either simple or complex). Builder returns the product as a final step, but as far as the Abstract Factory is concerned, the product gets returned immediately.
+ Builder often builds a Composite.
+ Often, designs start out using Factory Method (less complicated, more customizable, subclasses proliferate) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, more complex) as the designer discovers where more flexibility is needed.
+ Sometimes creational patterns are complementary: Builder can use one of the other patterns to implement which components are built. Abstract Factory, Builder, and Prototype can use Singleton in their implementations.
+ Builders are good candidates for a fluent interface.
