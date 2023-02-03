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
 * Push element in the stack
 */
void push(node**, int);

/*
 * Pop element from stack and return it
 */
int pop(node**);

/*
 * Displays the stack contents
 */
void display(node*);

/*
 * Count the number of elements in the stack
 */
int count(node*);
void push(node** q, int data) {
  node* temp;
  temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = *q;
  *q = temp;
}

int pop(node** q) {
  int data;
  node* temp;

  // if stack is empty
  if (*q == NULL) {
    fprintf(stderr, "warning: stack underflow");
    return -1;
  } else {
    temp = *q;
    data = temp->data;
    *q = temp->link;
    free(temp);
    return data;
  }
}

void display(node* q) {
  while (q != NULL) {
    printf("%d->", q->data);
    q = q->link;
  }
  printf("NULL\n");
  return;
}

int count(node* q) {
  int count = 0;
  while (q != NULL) {
    count++;
    q = q->link;
  }
  return count;
}

int main() {
  node* top = NULL;
  push(&top, 1);
  push(&top, 2);
  push(&top, 3);
  push(&top, 4);
  display(top);
  printf("no of elements:: %d\n", count(top));
  printf("Popped %d\n", pop(&top));
  printf("Popped %d\n", pop(&top));
  printf("Popped %d\n", pop(&top));
  display(top);
  printf("Popped %d\n", pop(&top));
  return 0;
}