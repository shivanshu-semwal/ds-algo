#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure for double-linked list
 */
typedef struct dnode {
  int data;
  struct dnode* prev;
  struct dnode* next;
} dnode;

/*
 * At node at the end
 */
void d_append(dnode**, int);

/*
 * Add node at the end of the beginning of double-linked list
 */
void d_addatbeg(dnode**, int);

/*
 * Add a node after  certai element
 * d_addafter(&front, location, data)
 */
void d_addafter(dnode**, int, int);

/*
 * Display the contents of the double-linked list
 */
void d_display(dnode*);

/*
 * Count the number of elemetns in the linked list
 */
int d_count(dnode*);

/*
 * Delete a node with given data
 */
int d_delete(dnode**, int);

/*
 * Delete a node at beginning
 */
int d_delete_beg(dnode**);

/*
 * Delete a node at end
 */
int d_delete_end(dnode**);

void d_append(dnode** s, int data) {
  // if the list is empty
  if (*s == NULL) {
    *s = malloc(sizeof(dnode));
    (*s)->prev = NULL;
    (*s)->next = NULL;
    (*s)->data = data;
  } else {
    dnode* q = *s;
    while (q->next != NULL) {
      q = q->next;
    }
    // add the node
    dnode* temp = malloc(sizeof(dnode));
    temp->next = NULL;
    temp->data = data;
    temp->prev = q;
    q->next = temp;
  }
}

void d_addatbeg(dnode** s, int data) {
  dnode* temp = malloc(sizeof(dnode));
  temp->data = data;
  temp->prev = NULL;
  temp->next = *s;
  (*s)->prev = temp;
  *s = temp;
}

void d_addafter(dnode** s, int loc, int data) {
  dnode* temp = *s;
  for (int i = 0; i < loc; i++) {
    temp = temp->next;
    if (temp == NULL) {
      fprintf(stderr, "warning: less elements\n");
      return;
    }
  }
  // insert new node
  dnode* new = malloc(sizeof(dnode));
  new->data = data;
  new->next = temp->next;
  new->prev = temp;

  temp->next = new;
}

void d_display(dnode* s) {
  while (s != NULL) {
    printf("%d<->", s->data);
    s = s->next;
  }
  printf("NULL\n");
}

int d_count(dnode* d) {
  int count = 0;
  while (d != NULL) {
    count++;
    d = d->next;
  }
  return count;
}

int d_delete(dnode** front, int data) {
  dnode* temp = *front;
  while (temp != NULL) {
    if (temp->data == data) {
      // if first node is to be deleted
      if (temp == *front) {
        *front = temp->next;
        (*front)->prev = NULL;
        free(temp);
      } else if (temp->next == NULL) {
        // node to be deleted is the last node
        (temp->prev)->next = NULL;
      } else {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        free(temp);
      }
    }
    temp = temp->next;
  }
  fprintf(stderr, "Element not found.\n");
}

int d_delete_beg(dnode** front) {
  dnode* temp = *front;
  *front = temp->next;
  (*front)->prev = NULL;
  int data = temp->data;
  free(temp);
  return data;
}

int d_delete_end(dnode** front) {
  dnode* temp = *front;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  int data = temp->data;
  // if node to delete is the first one
  if (temp == *front) {
    *front = NULL;
  } else {
    (temp->prev)->next = NULL;
  }
  free(temp);
  return data;
}

int main() {
  dnode* a = NULL;
  d_append(&a, 1);
  d_append(&a, 2);
  d_append(&a, 3);
  d_append(&a, 4);
  d_display(a);
  printf("Number of elements %d\n", d_count(a));
  d_delete_beg(&a);
  d_delete_beg(&a);
  d_delete_beg(&a);
  d_display(a);
  d_addatbeg(&a, 12);
  d_addafter(&a, 1, 12);
  d_display(a);
  return 0;
}