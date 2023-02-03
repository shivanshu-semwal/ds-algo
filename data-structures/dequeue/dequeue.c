#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* link;
} node;

/*
 * Add a node at the end of the queue
 */
void addq_at_end(node**, node**, int);

/*
 * Add node at the start of the queue
 */
void addq_at_start(node**, node**, int);

/*
 * Delete element at the end of the queue
 * and return the deleted element
 */
int delq_at_end(node**, node**);

/*
 * Delete element at the start of the queue
 */
int delq_at_start(node**, node**);

/*
 * Displays the content of the queue
 */
void displayq(node*);

/*
 * Count the number of elemnts in the queue
 */
int countq(node*);

void addq_at_end(node** front, node** rear, int data) {
  node* temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  // if queue is empty
  if (*front == NULL) {
    *front = temp;
  } else {
    (*rear)->link = temp;
  }
  *rear = temp;
}

void addq_at_start(node** front, node** rear, int data) {
  node* temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  // if queue is empty
  if (*front == NULL) {
    *front = *rear = temp;
  } else {
    temp->link = *front;
    *front = temp;
  }
}

int delq_at_end(node** front, node** rear) {
  // if queue is empty
  if (*rear == NULL) {
    fprintf(stderr, "warning: dequeue empty.\n");
    return -1;
  } else {
    node *temp, *previous = NULL;
    temp = *front;
    while (temp != *rear) {
      previous = temp;
      temp = temp->link;
    }
    // delete the node
    int data = temp->data;
    free(temp);
    *rear = previous;
    (*rear)->link = NULL;

    // if the queue become empty
    if (*rear == NULL) {
      *front = NULL;
    }
    return data;
  }
}

int delq_at_start(node** front, node** rear) {
  // if queue is empty
  if (*front == NULL) {
    fprintf(stderr, "warning: dequeue empty.\n");
    return -1;
  }
  // delete the node
  node* temp = *front;
  *front = (*front)->link;
  int data = temp->data;
  free(temp);
  if (*front == NULL) {
    *rear = NULL;
  }
  return data;
}

void displayq(node* front) {
  while (front != NULL) {
    printf("%d->", front->data);
    front = front->link;
  }
  printf("NULL\n");
}

int countq(node* front) {
  int count = 0;
  while (front != NULL) {
    count++;
    front = front->link;
  }
  return count;
}

int main() {
  node *front, *rear;
  front = rear = NULL;

  addq_at_end(&front, &rear, 1);
  addq_at_end(&front, &rear, 2);
  addq_at_end(&front, &rear, 3);
  addq_at_end(&front, &rear, 4);
  displayq(front);
  addq_at_start(&front, &rear, 5);
  addq_at_start(&front, &rear, 6);
  addq_at_start(&front, &rear, 7);
  addq_at_start(&front, &rear, 8);
  displayq(front);
  printf("Deleting at end %d\n", delq_at_end(&front, &rear));
  printf("Deleting at end %d\n", delq_at_end(&front, &rear));
  displayq(front);
  printf("Deleting at start %d\n", delq_at_start(&front, &rear));
  printf("Deleting at start %d\n", delq_at_start(&front, &rear));
  displayq(front);
  printf("Number of elements remaining %d\n", countq(front));
  displayq(front);
  return 0;
}