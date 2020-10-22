[Background]
  Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.

Usually a program is made up of a large number of classes. So the logic and computation is distributed among these classes. However, as more classes are developed in a program, especially during maintenance and/or refactoring, the problem of communication between these classes may become more complex. This makes the program harder to read and maintain. Furthermore, it can become difficult to change the program, since any change may affect code in several other classes.
With the mediator pattern, communication between objects is encapsulated with a mediator object. Objects no longer communicate directly with each other, but instead communicate through the mediator. This reduces the dependencies between communicating objects, thereby lowering the coupling.

[Definition]
  The essence of the Mediator Pattern is to "Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.[1]

[Participants]
+ Mediator - defines the interface for communication between Colleague objects
+ ConcreteMediator - implements the Mediator interface and coordinates communication between Colleague objects. It is aware of all the Colleagues and their purpose with regards to inter communication.
+ ConcreteColleague - communicates with other Colleagues through its Mediator

[Description]
  Every Colleague maitains a Mediator, when interaction is needed among ConcreteColleague instances, ConcreteMediator is used. Then ConcreteColleague instances do not need to include references each other, they may not even know each other, resulting a better maintenance or refactoring.
