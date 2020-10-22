A facade is an object that provides a simplified interface to a larger body of code, such as a class library. A facade can:
+ make a software library easier to use, understand and test, since the facade has convenient methods for common tasks;
+ make the library more readable, for the same reason;
+ reduce dependencies of outside code on the inner workings of a library, since most code uses the facade, thus allowing more flexibility in developing the system;
+ wrap a poorly designed collection of APIs with a single well-designed API (as per task needs).


The Facade Pattern hides the complexities of the system by providing an interface to the client from where the client can access the system on an unified interface. Facade defines a higher-level interface that makes the subsystem easier to use. For instance making one class method perform a complex process by calling several other classes.
