By defining a skeleton of an algorithm in an operation(in the abstract base class), deferring some steps to subclasses, the Template Method lets subclasses redefine certain steps of that algorithm without changing the algorithm's structure.

- In the template pattern, parts of program which are well defined like an algorithm are defined as a concrete method in the base class. The specifics of implementation are left to the derived classes by making these methods as abstract in the base class.
- The method which implements the algorithm is also refered as template method and the class which implements this methods as the template class.
