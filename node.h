#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
  char data;
  struct node* left;
  struct node* middle;
  struct node* right;
} tstNode;

struct node* newRoot();

void delNode(struct node* todel);
struct node* addNode(struct node* todel, char data, int x);
