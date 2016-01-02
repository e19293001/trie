#include "node.h"

struct node* newRoot() {
  struct node* ret;
  ret = (struct node*) malloc (sizeof(struct node));
  ret->left = NULL;
  ret->right = NULL;
  ret->middle = NULL;
  ret->data = -1;
  return ret;
}

struct node* newNode(char x) {
  struct node* ret;
  ret = (struct node*) malloc (sizeof(struct node));
  ret->left = NULL;
  ret->right = NULL;
  ret->middle = NULL;
  ret->data = x;
  return ret;
}

int nodeIsNull(struct node* nd) {
  if (nd->left == NULL &&
      nd->right == NULL &&
      nd->middle == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

void delNode(struct node* todel) {
  int debugThis = 0;
#define _debug_delNode if (debugThis)
  
  if (todel->data == -1) {
    _debug_delNode printf("[ delNode ] start -1.\n");
  }
  else {
    _debug_delNode printf("[ delNode ] start char: %c\n", todel->data);
  }
  if (todel->left != NULL) {
    _debug_delNode printf("[ delNode ] left is not NULL. going to left passing [%c] \n", todel->left->data);
    delNode(todel->left);
    todel->left = NULL;
  }
  else {
    _debug_delNode printf("[ delNode ] todel->left is NULL.\n");
  }

  if (todel->middle != NULL) {
    _debug_delNode printf("[ delNode ] middle is not NULL. going to middle [%c] \n", todel->middle->data);
    delNode(todel->middle);
    todel->middle = NULL;
  }
  else {
    _debug_delNode printf("[ delNode ] todel->middle is NULL.\n");
  }

  if (todel->right != NULL) {
    _debug_delNode printf("[ delNode ] right is not NULL. going to right [%c] \n", todel->right->data);
    delNode(todel->right);
    todel->right = NULL;
  }
  else {
    _debug_delNode printf("[ delNode ] todel->right is NULL.\n");
  }

  if (nodeIsNull(todel)) {
    _debug_delNode printf("[ delNode ] todel is NULL. todel->data: %c freeing\n", todel->data);
    free(todel);
  }
  else {
    _debug_delNode printf("[ delNode ] todel is NOT NULL. todel->data: %c\n", todel->data);
  }    

  _debug_delNode printf("[ delNode ] finish.\n");
}

struct node* addNode(struct node* nd, char data, int x) {
  int debugThis = 1;
#define _debug_addNode if (debugThis)

  struct node* ret = nd;
  struct node* nw;

  if (x == 0) { // add to left
    _debug_addNode printf("[ addNode ] adding left with [%c]\n", data);
    if (nd->left == NULL) {
      nw = newNode(data);
      ret->left = nw;
      _debug_addNode printf("[ addNode ] ret now contains [%c]\n", ret->left->data);
    }
    else {
      addNode(nd->left, data, x);
    }
  }
  else if (x == 1) { // add to right
    _debug_addNode printf("[ addNode ] adding right with [%c]\n", data);
    nw = newNode(data);
    ret->right = nw;
  }
  else if (x == 2) { // add to middle
    _debug_addNode printf("[ addNode ] adding middle with [%c]\n", data);
    nw = newNode(data);
    ret->middle = nw;
  }
  else {
    _debug_addNode printf("error: invalid value for x\n");
    exit(-1);
  }

  return ret;
}
