#include "unitTestNode.h"

void TestNewRoot() {
  int debugThis = 0;
#define _debug_TestNewRoot if (debugThis)
  struct node* root;

  _debug_TestNewRoot printf("[ TestNewRoot ] start.\n");
  root = newRoot();
  assert(root->left == NULL);
  assert(root->middle == NULL);
  assert(root->right == NULL);
  delNode(root);
  _debug_TestNewRoot printf("[ TestNewRoot ] finsih.\n");
}

void TestLeftNode() {
  int debugThis = 0;
#define _debug_TestLeftNode if (debugThis)
  struct node* root;

  _debug_TestLeftNode printf("[ TestLeftNode ] start.\n");
  root = newRoot();
  root = addNode(root, 'c', 0);
  
  delNode(root);
  _debug_TestLeftNode printf("[ TestLeftNode ] finish.\n");
}

void TestRightNode() {
  int debugThis = 0;
#define _debug_TestRightNode if (debugThis)
  struct node* root;

  _debug_TestRightNode printf("[ TestRightNode ] start.\n");
  root = newRoot();
  root = addNode(root, 'c', 1);
  
  delNode(root);
  _debug_TestRightNode printf("[ TestRightNode ] finish.\n");
}

void TestMiddleNode() {
  int debugThis = 0;
#define _debug_TestMiddleNode if (debugThis)
  struct node* root;

  _debug_TestMiddleNode printf("[ TestMiddleNode ] start.\n");
  root = newRoot();
  root = addNode(root, 'c', 2);
  
  delNode(root);
  _debug_TestMiddleNode printf("[ TestMiddleNode ] finish.\n");
}

void TestWithAllBranchNode() {
  int debugThis = 1;
#define _debug_TestWithAllBranchNode if (debugThis)
  struct node* root;

  _debug_TestWithAllBranchNode printf("[ TestWithAllBranchNode ] start.\n");
  root = newRoot();
  root = addNode(root, 'a', 0); // add to left
  root = addNode(root, 'b', 1); // add to middle
  root = addNode(root, 'c', 2); // add to right
  root = addNode(root, 's', 0); // add to left
  
  delNode(root);
  _debug_TestWithAllBranchNode printf("[ TestWithAllBranchNode ] finish.\n");
}

