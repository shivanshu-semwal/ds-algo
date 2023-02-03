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
 * Add element to the queue
 * addq( &front_pointer, &rear_pointer, data)
 */
void addq(node**, node**, int);

/*
 * Delete element from the queue
 * Returns the element removed
 * delq( &front_pointer, &rear_pointer);
 */
int delq(node**, node**);

/*
 * Displays the content of the queue
 * displayq( front_pointer )
 */
void displayq(node*);

/*
 * Count the number of elements in the queue
 * countq(front_pointer)
 */
int countq(node*);

void addq(node** front, node** rear, int data) {
  node* temp = malloc(sizeof(node));
  temp->data = data;
  temp->link = NULL;

  // if the queue is empty
  if (*front == NULL) {
    *front = temp;
  } else {
    (*rear)->link = temp;
  }
  *rear = temp;
}

int delq(node** front, node** rear) {
  node* temp;
  int data;

  // if queue is empty
  if (*front == NULL) {
    fprintf(stderr, "warning: queue is empty");
    return -1;
  } else {
    temp = *front;
    *front = (*front)->link;

    data = temp->data;
    free(temp);
    return data;
  }
}

void displayq(node* front) {
  while (front != NULL) {
    printf("%d->", front->data);
    front = front->link;
  }
  printf("NULL\n");
}

int countq(node* front) {
  int count;
  while (front != NULL) {
    front = front->link;
    count++;
  }
  return count;
}
int main() {
  node *front, *rear;
  front = rear = NULL;

  addq(&front, &rear, 1);
  addq(&front, &rear, 2);
  addq(&front, &rear, 3);
  addq(&front, &rear, 4);
  addq(&front, &rear, 5);
  displayq(front);
  printf("Elements count %d\n", countq(front));
  printf("Enement removed: %d\n", delq(&front, &rear));
  printf("Enement removed: %d\n", delq(&front, &rear));
  printf("Enement removed: %d\n", delq(&front, &rear));
  printf("Enement removed: %d\n", delq(&front, &rear));
  printf("Enement removed: %d\n", delq(&front, &rear));
  displayq(front);
  return 0;
}