# C_Queue: A simple queue written in C(++)

C_Queue is a simple queue written in C, with the help of templates
from C++, implemented with a singly-linked list. Admittedly, there
are better implementations for a queue, as deque is O(N) with a 
singly-linked list, but I wanted to prototype something quickly.

The driver code in `main` is meant to give an example of how the 
queue's state is manipulated with the various implemented methods.

# TODOS

- ensure initializiation with a known capacity works for all generic types
- port to C, using either an unsafe generics-container implementation or
a safe, generics-container implementation using macros to generate the 
templates
