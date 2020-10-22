The Observer Pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

Problem
    In one place or many places in the application we need to be aware about a system event or an application state change. We'd like to have a standard way of subscribing to listening for system events and a standard way of notifying the interested parties. The notification should be automated after an interested party subscribed to the system event or application state change. There also should be a way to unsubscribe.
Forces
    Observers and observables probably should be represented by objects. The observer objects will be notified by the observable objects.
Solution
    After subscribing the listening objects will be notified by a way of method call.


Observer pattern has a very important position with MVC development.
