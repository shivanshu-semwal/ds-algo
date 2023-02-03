#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure for linked list
 */
typedef struct node {
  int data;
  struct node* link;
} node;

/*
 * Add node at the end of the list
 */
void append(node**, int);

/*
 * Add node at the beginning
 */
void addatbeg(node**, int);

/*
 * Add node at a certain position
 */
void addafter(node**, int, int);

/*
 * Delete the node with given data
 */
void delete(node**, int);

/*
 * Display the contents of the linked list
 */
void display(node* q);

/*
 * Count the number of nodes in teh linked list
 */
int count(node* q);

void append(node** q, int data) {
  // append - add node at the end of the linked list
  // create a node
  node* temp;
  temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  // if the linked list is empty
  if (*q == NULL) {
    *q = temp;
  }
  // go to end and add node
  else {
    node* t = *q;
    while (t->link != NULL) {
      t = t->link;
    }
    t->link = temp;
  }
}

void addatbeg(node** q, int data) {
  // addatbeg - add new node at the begginning of the linked list
  // create a node
  node* temp;
  temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  // add node at beginnning
  temp->link = *q;
  *q = temp;
}

void addafter(node** q, int loc, int data) {
  // addafter - add node after a particular location
  //  create a node
  node* temp;
  temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  node* t = *q;
  for (int i = 0; i < loc; i++) {
    t = t->link;
    if (t == NULL) {
      fprintf(stderr, "warning: insertion at position %d but not emough elements.\n", loc);
      return;
    }
  }

  temp->link = t->link;
  t->link = temp;
}

int count(node* q) {
  // count number of nodes present in the linked list
  int c = 0;
  while (q != NULL) {
    q = q->link;
    c++;
  }
  return c;
}

void delete(node** q, int data) {
  node *temp = *q, *previous;
  while (temp != NULL) {
    if (temp->data == data) {
      // if the node to be deleted is the first one
      if (temp == *q) {
        *q = (*q)->link; // or *q = temp->link;
        free(temp);
        return;
      } else {
        previous->link = temp->link;
        free(temp);
        return;
      }
    } else {
      previous = temp;
      temp = temp->link;
    }
  }
  fprintf(stderr, "warning: element with given data not present");
  return;
}

void display(node* q) {
  node* temp = q;
  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->link;
  }
  printf("NULL\n");
}

void merge(node** first, node** second) {
  node* temp = *first;
  while (temp->link != NULL) {
    temp = temp->link;
  }
  temp->link = *second;
}

int main() {
  // some demo
  node* head = NULL;

  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  display(head);
  delete (&head, 1);
  delete (&head, 2);
  delete (&head, 3);
  display(head);

  addatbeg(&head, 32);
  addafter(&head, 0, 44);
  display(head);
  printf("%d", count(head));

  node *first, *second;
  first = second = NULL;

  // adding elemetns to the first list
  append(&first, 1);
  append(&first, 2);
  append(&first, 3);
  display(first);
  // adding to the second element
  append(&second, 4);
  append(&second, 5);
  append(&second, 6);
  append(&second, 7);
  display(second);
  // merging both
  merge(&first, &second);
  display(first);
  return 0;
}