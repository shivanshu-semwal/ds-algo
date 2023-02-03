#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct btreenode {
  int data;
  struct btreenode* leftchild;
  struct btreenode* rightchild;
} btreenode;

/*
 * Insert a node in the binary tree
 */
void insert(btreenode**, int);

/*
 * Inorder traversal - LDR (left-data-right)
 */
void inorder(btreenode*);

/*
 * Preorder traversal - DRL (data-left-right)
 */
void preorder(btreenode*);

/*
 * Postorder traversal - LRD (left-right-data)
 */
void postorder(btreenode*);

/*
 * Prints the tree vertical
 */
void printTreeV(btreenode*);

/*
 * Print tree hotizontal
 */
void printTreeH(btreenode*);

/*
 * Delete a node from binary tree
 */
void delete(btreenode**, int);

/*
 * search an node with given data
 * return the address of the node found else NULL
 * address of parent
 * and whether the node is found or node
 * search(&root, element_to_search, &parent)
 */
btreenode* search(btreenode**, int, btreenode**);

void insert(btreenode** sr, int num) {
  if (*sr == NULL) {
    *sr = malloc(sizeof(btreenode));
    (*sr)->data = num;
    (*sr)->leftchild = NULL;
    (*sr)->rightchild = NULL;
    return;
  } //
  else {
    // use recursion
    if (num < (*sr)->data) {
      insert(&((*sr)->leftchild), num);
    } //
    else {
      insert(&((*sr)->rightchild), num);
    }
  }
  return;
}

void inorder(btreenode* sr) {
  if (sr != NULL) {
    inorder(sr->leftchild);
    printf("%d ", sr->data);
    inorder(sr->rightchild);
  } else {
    // printf("NULL ");
  }
}

void preorder(btreenode* sr) {
  // pre-order means visit root first the laft right
  if (sr != NULL) {
    printf("%d ", sr->data);
    postorder(sr->leftchild);
    preorder(sr->rightchild);
  } else {
    // printf("NULL ");
  }
}

void postorder(btreenode* sr) {
  // post-order means visit root last
  if (sr != NULL) {
    postorder(sr->leftchild);
    postorder(sr->rightchild);
    printf("%d ", sr->data);
  } else {
    // printf("NULL");
  }
}

void printTree1(btreenode* root, int space) {
  // base case
  if (root == NULL) {
    space += COUNT;
    for (int i = COUNT; i < space; i++)
      printf(" ");
    printf("(~)\n");
    return;
  }
  space += COUNT;

  printTree1(root->rightchild, space);
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("(%d)\n", root->data);
  printTree1(root->leftchild, space);
}

void printTreeV(btreenode* root) {
  printTree1(root, 3);
}

void printTree2(btreenode* tree, int* di, char* depth) {
  printf("(%d)\n", tree->data);
  if (!tree)
    return;
  if (tree->leftchild) {
    printf("%s x--", depth);
    // _push('|', di, depth);
    depth[(*di)++] = ' ';
    depth[(*di)++] = '|'; //
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' ';
    depth[(*di)] = 0;

    printTree2(tree->leftchild, di, depth);
    // _pop(di, depth);
    depth[*di -= 4] = 0;
  } else {
    printf("%s x--", depth);
    // _push('|', di, depth);
    depth[(*di)++] = ' ';
    depth[(*di)++] = '|'; //
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' ';
    depth[(*di)] = 0;
    printf("(NULL)\n");
    // printTree2(tree->leftchild, di, depth);
    // _pop(di, depth);
    depth[*di -= 4] = 0;
  }
  if (tree->rightchild) {
    printf("%s +--", depth);
    // _push(' ', di, depth);
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' '; //
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' ';
    depth[(*di)] = 0;
    printTree2(tree->rightchild, di, depth);
    // _pop(di, depth);
    depth[*di -= 4] = 0;
  } else {
    printf("%s +--", depth);
    // _push(' ', di, depth);
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' '; //
    depth[(*di)++] = ' ';
    depth[(*di)++] = ' ';
    depth[(*di)] = 0;
    printf("(NULL)\n");
    // printTree2(tree->rightchild, di, depth);
    // _pop(di, depth);
    depth[*di -= 4] = 0;
  }
}

void printTreeH(btreenode* tree) {
  int di = 0;
  char depth[2016] = {0};
  printTree2(tree, &di, depth);
}

btreenode* search(btreenode** root, int num, btreenode** par) {
  btreenode* q;
  q = *root;
  *par = NULL;

  while (q != NULL) {
    if (q->data == num) {
      return q;
    }
    if (q->data > num) {
      *par = q;
      q = q->leftchild;
    } else {
      *par = q;
      q = q->rightchild;
    }
  }
}

void delete(btreenode** root, int num) {
  btreenode *parent, *x, *xsucc;

  // if the tree is empty
  if (*root == NULL) {
    fprintf(stdin, "(warming) Empty tree\n.");
    return;
  }

  parent = x = NULL;

  // call function to search the node
  x = search(root, num, &parent);

  if (x == NULL) {
    printf("Element not found.\n");
    return;
  }

  // if the node to be deleted has two children
  if (x->leftchild != NULL && x->rightchild != NULL) {
    btreenode* par = x;
    xsucc = x->rightchild;

    while (xsucc->leftchild != NULL) {
      par = xsucc;
      xsucc = xsucc->leftchild;
    }

    if (xsucc == x->rightchild) {
      if (parent->leftchild == x) {
        parent->leftchild = xsucc;
      } else {
        parent->rightchild = xsucc;
      }
      xsucc->leftchild = x->leftchild;
      free(x);
      return;
    } else {
      x->data = xsucc->data; // copying the data
      if (xsucc->rightchild != NULL) {
        par->leftchild = xsucc->rightchild;
      } else {
        par->leftchild = NULL;
      }
      free(xsucc);
      return;
    }
  }

  // if the node to be deleted has no child
  if (x->leftchild == NULL && x->rightchild == NULL) {
    if (parent->rightchild == x) {
      parent->rightchild = NULL;
    } else {
      parent->leftchild = NULL;
    }
    free(x);
    return;
  }

  // if node to deleted has only right child
  if (x->leftchild == NULL && x->rightchild != NULL) {
    if (parent->leftchild == x) {
      parent->leftchild = x->rightchild;
    } else {
      parent->rightchild = x->rightchild;
    }
    free(x);
    return;
  }

  // if the node to deleted has only left child
  if (x->leftchild != NULL && x->rightchild == NULL) {
    if (parent->rightchild == x) {
      parent->rightchild = x->leftchild;
    } else {
      parent->leftchild = x->leftchild;
    }
    free(x);
  }
}

int main() {
  btreenode* root = NULL;
  insert(&root, 10);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 6);
  insert(&root, 5);
  insert(&root, 4);
  printTreeH(root);
  printTreeV(root);
  printf("\nInorder: ");
  inorder(root);
  printf("\nPreorder: ");
  preorder(root);
  printf("\nPostorder: ");
  postorder(root);

  root = NULL;
  int a[] = {11, 9, 13, 8, 10, 12, 14, 15, 7};
  for (int i = 0; i <= 8; i++) {
    insert(&root, a[i]);
  }
  printTreeH(root);
  printf("delete 10\n");
  delete (&root, 10);
  printTreeH(root);
  printf("delete 14\n");
  delete (&root, 14);
  printTreeH(root);
  printf("delete 8\n");
  delete (&root, 8);
  printTreeH(root);
  printf("delete 13\n");
  delete (&root, 13);
  printTreeH(root);

  return 0;
}