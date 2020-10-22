The decorator pattern helps to attach additional behavior or responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality. This is also called “Wrapper”. If your application does some kind of filtering. Decorator might be good pattern to consider for the job.


The decorator pattern is a design pattern that allows behavior to be added to an individual object, either statically or dynamically, without affecting the behavior of other objects from the same class.

The decorator pattern can be used to extend (decorate) the functionality of a certain object statically, or in some cases at run-time, independently of other instances of the same class, provided some groundwork is done at design time. This is achieved by designing a new decorator class that wraps the original class. This wrapping could be achieved by the following sequence of steps:
1. Subclass the original "Component" class into a "Decorator" class;
2. In the Decorator class, add a Component pointer as a field;
3. Pass a Component to the Decorator constructor to initialize the Component pointer;
4. In the Decorator class, redirect all "Component" methods to the "Component" pointer; and
5. In the ConcreteDecorator class, override any Component method(s) whose behavior needs to be modified.

                  --------------------
                        Component
                      + operation()    -------------------
                  --------------------                    |
                          ^                               |
                          |                               |
         |-------------------------------|                |
--------------------           --------------------       |
ConcreteComponent             Decorator           |       |
+ operation()                 - component         |<>-----|
--------------------          + operation()       |
                               --------------------
                                     ^
                                     |
                            |-----------------------------|
                      --------------------        --------------------
                      ConcreteDecoratorA          ConcreteDecoratorB
                      + operation()               + operator()
                      --------------------        --------------------
