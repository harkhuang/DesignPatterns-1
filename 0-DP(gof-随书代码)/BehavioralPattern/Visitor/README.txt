The Visitor Pattern will represent an operation to be performed on the elements of an object structure by letting you define a new operation without changing the classes of the elements on which it operates.

the visitor design pattern is a way of separating an algorithm from an object structure on which it operates. A practical result of this separation is the ability to add new operations to existing object structures without modifying those structures. It is one way to easily follow the open/closed principle.

In essence, the visitor allows one to add new virtual functions to a family of classes without modifying the classes themselves; instead, one creates a visitor class that implements all of the appropriate specializations of the virtual function. The visitor takes the instance reference as input, and implements the goal through double dispatch.

[Details]
The visitor pattern requires a programming language that supports "single dispatch" and "method overloading". Under these conditions, consider two objects, each of some class type; one is called the "element", and the other is called the "visitor". An element has an accept() method that can take the visitor as an argument. The accept() method calls a visit() method of the visitor; the element passes itself as an argument to the visit() method. Thus:

+ When the accept() method is called in the program, its implementation is chosen based on both:
  - The dynamic type of the element.
  - The static type of the visitor.
+ When the associated visit() method is called, its implementation is chosen based on both:
  - The dynamic type of the visitor.
  - The static type of the element as known from within the implementation of the accept() method, which is the same as the dynamic type of the element. (As a bonus, if the visitor can't handle an argument of the given element's type, then the compiler will catch the error.)
+ Consequently, the implementation of the visit() method is chosen based on both:
  - The dynamic type of the element.
  - The dynamic type of the visitor.
This effectively implements double dispatch; indeed, because the Lisp language's object system supports multiple dispatch (not just single dispatch), implementing the visitor pattern in Lisp is trivial.
In this way, a single algorithm can be written for traversing a graph of elements, and many different kinds of operations can be performed during that traversal by supplying different kinds of visitors to interact with the elements based on the dynamic types of both the elements and the visitors.
