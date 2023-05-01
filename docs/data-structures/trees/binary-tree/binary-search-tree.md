# Binary Search Tree

Binary Search Trees are used for creating search trees.

A binary search tree:

- is a binary tree
- for each node
    - its left child value is less than its value
    - its right child value is more than its value

## Traversal

This is same as a binary tree, but some new features emerges.
Inorder traversal of a bst give a sorted list. (this fact will be used in many problems).
Converse is also true, if inorder traversal give sorted list, it is bst.

## Searching

Searching in binary tree is same as binary search.
You start with the root node and then compare, there are three
possibilities either it will be the target no., or less target no,
or greater than target no.

After checking each node, you only have to look a one of it's child tree.

And if the tree is balanced, then the time complexity of searching will be same
as binary search.

## Inserting

To insert a element, you again search for the node, and
when you reach one of the leaves or one level above it,
you will place it so it satisfies the BST condition.

## Deletion

First search for the node.
Now three conditions arise:

- 0 child - just remove the node
- 1 child - put that child node in it's place
- 2 child
    - now think about what will the new tree should have
    - it's inorder traversal should still give a sorted list
    - so this node should be replace with it's inorder successor, otherwise it will not give sorted
      list and so it will also not be a bst.

You can solve this using two ways, use double pointers so you can manipulate addresses.
And other easier way, use recursion to do the job.

```cpp
Node *deleteNode(Node *root, int key){
    if(root == nullptr) return nullptr;
    if(key == root->value){
        if(root->left == nullptr && root->right == nullptr) // no child
            return nullptr;
        else if(root->left == nullptr) { // one child
            Node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == nullptr){ // one child
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else { // inorder successor, both child
            Node *temp = root->right;
            while(temp->left!=nullptr) temp = temp->left;
            root->value= temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    else if(key < root->value) root->left = deleteNode(root->left, key);
    else root->left = deleteNode(root->left, key);
}
```

## Balanced Binary Search Tree

Normal BST without balancing are rarely used.
A unbalance bst will have a linear time complexity for searching.

### Types

- AVL Tree
- Red-Black Tree

## Sample Implementation of a Binary tree

```c
{{ include_file('binary-trees.c') }}
```
