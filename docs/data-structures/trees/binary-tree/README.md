# Binary Trees

Binary trees are tress in which each node can have atmost two child.

```
  *
 / \
L   R
```

## Traversal

Tree traversal in binary tree refers to the order in which access the root node, left tree and right tree.
The name of the order defines how we access the root node, and rest we always access left tree first than
right tree.

### Pre-order

- pre means root first than left and right

### Post-order

- post means root last, first left than right

### In-order

- first left than root and than right

## Representation

Binary Trees can be represented in two basic ways:

### With Self Referential Structures

```cpp
struct Node{
    int val;
    Node *left;
    Node *right
}
```

### With a array

- in this representation, child node of ith element is at $2*i + 1$ and $2*i + 2$ position

## Types

- Binary heap
- Binary search tree
