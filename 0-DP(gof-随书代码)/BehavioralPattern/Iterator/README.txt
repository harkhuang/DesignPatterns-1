[WIKI]
In object-oriented programming, the iterator pattern is a design pattern in which an iterator is used to traverse a container and access the container's elements. The iterator pattern decouples algorithms from containers; in some cases, algorithms are necessarily container-specific and thus cannot be decoupled.

For example, the hypothetical algorithm SearchForElement can be implemented generally using a specified type of iterator rather than implementing it as a container-specific algorithm. This allows SearchForElement to be used on any container that supports the required type of iterator.



The 'iterator' design pattern is used liberally within the STL for traversal of various containers. The full understanding of this will liberate a developer to create highly reusable and easily understandable data containers.
The basic idea of the iterator is that it permits the traversal of a container (like a pointer moving across an array). However, to get to the next element of a container, you need not know anything about how the container is constructed. This is the iterators job. By simply using the member functions provided by the iterator, you can move, in the intended order of the container, from the first element to the last element.
Let us start by considering a traditional single dimensional array with a pointer moving from the start to the end. This example assumes knowledge of pointer arithmetic. Note that the use of "it" or "itr," henceforth, is a short version of "iterator."




Intent
01
Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
The C++ and Java standard library abstraction that makes it possible to decouple collection classes and algorithms.
Promote to “full object status” the traversal of a collection.
Polymorphic traversal
Problem
02
Need to “abstract” the traversal of wildly different data structures so that algorithms can be defined that are capable of interfacing with each transparently.

Discussion
03
“An aggregate object such as a list should give you a way to access its elements without exposing its internal structure. Moreover, you might want to traverse the list in different ways, depending on what you need to accomplish. But you probably don’t want to bloat the List interface with operations for different traversals, even if you could anticipate the ones you’ll require. You might also need to have more than one traversal pending on the same list.” And, providing a uniform interface for traversing many types of aggregate objects (i.e. polymorphic iteration) might be valuable.

04
The Iterator pattern lets you do all this. The key idea is to take the responsibility for access and traversal out of the aggregate object and put it into an Iterator object that defines a standard traversal protocol.

05
The Iterator abstraction is fundamental to an emerging technology called “generic programming”. This strategy seeks to explicitly separate the notion of “algorithm” from that of “data structure”. The motivation is to: promote component-based development, boost productivity, and reduce configuration management.

06
As an example, if you wanted to support four data structures (array, binary tree, linked list, and hash table) and three algorithms (sort, find, and merge), a traditional approach would require four times three permutations to develop and maintain. Whereas, a generic programming approach would only require four plus three configuration items.

Structure
07
The Client uses the Collection class’ public interface directly. But access to the Collection’s elements is encapsulated behind the additional level of abstraction called Iterator. Each Collection derived class knows which Iterator derived class to create and return. After that, the Client relies on the interface defined in the Iterator base class.
