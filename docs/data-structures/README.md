# Data Structures

Some algorithms need data to be structured in certain way
for them to work efficiently. This is what data structures provide.
How the data is arranged in memory is defined by data structures

## Data Structure

- <https://en.wikipedia.org/wiki/Data_structure>

Data structure is data organization, management and storage format
that is usually chosen for efficient access to data.
Data structure is a collection of data values and the
relationship among them and the functions or operations that
can be applied on the data.

## Abstract data type

- <https://en.wikipedia.org/wiki/Abstract_data_type>
- <https://cs.stackexchange.com/questions/6678/what-is-the-difference-between-abstract-and-concrete-data-structures>

Abstract data type are mathematical model of data types.
They define functionality but not how they are implemented.
For e.g. `stack` provide functionality to `pop` and `push` items
but it can be implemented in multiple ways. (using dynamic arrays or linked lists)

**ADT** are present from the *view of a user* and **data types**
from the *point of view of who is going to implement it*.

Here is a small list of ADT's:

- List
    - list is a collections of items, where we can add items and remove items
    - implemented using arrays, using linked list
    - `getElementAt(i)`, `find(i)`, `insert()`, `remove()`
    - list can be implemented using arrays and linked list
- String
    - string is a collection of ordered characters
    - usually same operations as list
    - using arrays, using linked list
- Set
    - set is a collection of unique items
    - `insert()` `remove()` `find()` `size()`
    - using arrays, using linked list, using linked list which are connected in form of a tree
- Map
    - map is a collection of key value pairs
    - `getValue(key)`
    - using hash map
- Graph
    - `addNode()` `addEdge(x, y)` `getChildren()`
    - implemented using adjacency list, adjacency graph
- Tree
    - implemented using (arrays and linked list) or using only linked list, or only using arrays
    - Binary Trees are often used in context of data structures representing nodes with right and left child
- Stack
    - represnets a stack of items, where we can push items and pop items
- Queue
    - represents a queues of items, where we can add items at end of queue and remove items from front of queue

## Outline

- Data Structure
    - Classification:
        - Linear: static, dynamic
        - Non Linear
- Array
    - dynamic array
    - create, insert, delete
- Linked List
    - Types: Single, double, circular
    - Operation: insertion, deletion, searching
- Stack: push, pop
- Queue:
    - Priority Queue
- [Tree](./trees/README.md)
    - Binary Tree
        - Binary Heap
        - Binary search tree
            - avl tree
            - red black tree
            - splay tree
    - Segment tree
    - Trie
    - Binary Indexed Tree
    - suffix array and suffix tree
    - B-Tree
    - k dimensional tree
- [Graph](./graphs/README.md)
- Hashing

## A note about programming language

- Every languages provides some basic type of data structures and data types (primitive data types).
- If you use low level programming language you have to implement the data structures on you own and will have more control over it's execution,
  but you will have to write more code.
