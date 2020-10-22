Command pattern is an Object behavioral pattern that decouples sender and receiver by encapsulating a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undo-able operations. It can also be thought as an object oriented equivalent of call back method.
Call Back: It is a function that is registered to be called at later point of time based on user actions.

[Wiki]
the command pattern is a behavioral design pattern in which an object is used to represent and encapsulate all the information needed to call a method at a later time. This information includes the method name, the object that owns the method and values for the method parameters.

Four terms always associated with the command pattern are command, receiver, invoker and client. A concrete command object has a receiver object and invokes a method of the receiver in a way that is specific to that receiver's class. The receiver then does the work. A concrete command object is separately passed to an invoker object, which invokes the command, and optionally does bookkeeping about the command execution. Any concrete command object can be passed to the same invoker object. Both an invoker object and several concrete command objects are held by a client object. The client contains the decision making about which commands to execute at which points. To execute a command, it passes the command object to the invoker object. See example code below.

Using command objects makes it easier to construct general components that need to delegate, sequence or execute method calls at a time of their choosing without the need to know the class of the method or the method parameters. Using an invoker object allows bookkeeping about command executions to be conveniently performed, as well as implementing different modes for commands, which are managed by the invoker object, without the need for the client to be aware of the existence of bookkeeping or modes.

[Uses]
GUI buttons and menu items
In Swing and Borland Delphi programming, an Action is a command object. In addition to the ability to perform the desired command, an Action may have an associated icon, keyboard shortcut, tooltip text, and so on. A toolbar button or menu item component may be completely initialized using only the Action object.
Macro recording
If all user actions are represented by command objects, a program can record a sequence of actions simply by keeping a list of the command objects as they are executed. It can then "play back" the same actions by executing the same command objects again in sequence. If the program embeds a scripting engine, each command object can implement a toScript() method, and user actions can then be easily recorded as scripts.
Mobile Code
Using languages such as Java where code can be streamed/slurped from one location to another via URLClassloaders and Codebases the commands can enable new behavior to be delivered to remote locations (EJB Command, Master Worker)
Multi-level undo
If all user actions in a program are implemented as command objects, the program can keep a stack of the most recently executed commands. When the user wants to undo a command, the program simply pops the most recent command object and executes its undo() method.
Networking
It is possible to send whole command objects across the network to be executed on the other machines, for example player actions in computer games.
Parallel Processing
Where the commands are written as tasks to a shared resource and executed by many threads in parallel (possibly on remote machines -this variant is often referred to as the Master/Worker pattern)
Progress bars
Suppose a program has a sequence of commands that it executes in order. If each command object has a getEstimatedDuration() method, the program can easily estimate the total duration. It can show a progress bar that meaningfully reflects how close the program is to completing all the tasks.
Thread pools
A typical, general-purpose thread pool class might have a public addTask() method that adds a work item to an internal queue of tasks waiting to be done. It maintains a pool of threads that execute commands from the queue. The items in the queue are command objects. Typically these objects implement a common interface such as java.lang.Runnable that allows the thread pool to execute the command even though the thread pool class itself was written without any knowledge of the specific tasks for which it would be used.
Transactional behavior
Similar to undo, a database engine or software installer may keep a list of operations that have been or will be performed. Should one of them fail, all others can be reversed or discarded (usually called rollback). For example, if two database tables that refer to each other must be updated, and the second update fails, the transaction can be rolled back, so that the first table does not now contain an invalid reference.
Wizards
Often a wizard presents several pages of configuration for a single action that happens only when the user clicks the "Finish" button on the last page. In these cases, a natural way to separate user interface code from application code is to implement the wizard using a command object. The command object is created when the wizard is first displayed. Each wizard page stores its GUI changes in the command object, so the object is populated as the user progresses. "Finish" simply triggers a call to execute(). This way, the command class contains no user interface code.
