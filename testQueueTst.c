#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "QueueTernarySearchTrie.h"

void Test0000QueueTst();
void Test0001QueueTst();
void Test0002QueueTst();
void Test0003QueueTst();
void Test0004QueueTst();
tstrie* Test0000MakePattern_01();
  
int main() {
  Test0000QueueTst(); // test tstqPushfront
  Test0001QueueTst(); // test tstqPushback
  Test0002QueueTst(); // test tstqPopfront
  Test0003QueueTst(); // test tstqPopback

  Test0004QueueTst(); // test tstqSize

  return 0;
}

void Test0000QueueTst() {
  tstqueue *qhead = NULL;
  tstrie *tst;

  printf("[ -- Test0000QueueTst ]\n");
  printf("create tst value: a\n");
  tst = tstNew('a', 0);
  printf("push front tst to qhead\n");
  qhead = tstqPushfront(qhead, tst);

  tstDelete(tst);

  tst = Test0000MakePattern_01();
  qhead = tstqPushfront(qhead, tst);
  tstDelete(tst);

//  tstDumpGraphical(qhead->item);
  tstDump(qhead->item);
  tstqDump(qhead);
  tstqDelete(qhead);
}

void Test0001QueueTst() { // test tstqPushback
  tstqueue *qhead = NULL;
  tstrie *tst;

  printf("[ -- Test0001QueueTst ]\n");
  printf("create tst value: a\n");
  tst = tstNew('a', 0);
  printf("push back tst to qhead\n");
  qhead = tstqPushback(qhead, tst);

  tstDelete(tst);

  tst = tstNew('s', 1);
//  tst = Test0000MakePattern_01();
//  qhead = tstqPushfront(qhead, tst);
  qhead = tstqPushback(qhead, tst);
  
  printf("dumping start\n");
  tstqDump(qhead);
  printf("dumping end\n");

  tstqDelete(qhead);
  tstDelete(tst);
}

void Test0003QueueTst() {
  tstqueue *qhead = NULL;
  tstrie *tst;
  tstqueue *tstqRet;

  printf("[ -- Test0003QueueTst ]\n");
  tst = tstNew('a', 0);
  qhead = tstqPushback(qhead, tst);
//  tstqDump(qhead);
//  tstDelete(tst);

// --------------------
  tst->item = 'c';
  tst->data = 9;
//  tst = tstNew('c', 9);
  qhead = tstqPushback(qhead, tst);
//  tstqDump(qhead);
// --------------------


  tst->item = 'd';
  tst->data = 7;
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);
  tstDelete(tst);



  printf("starting to pop\n");
  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDump(tstqRet);
  tstqDelete(tstqRet);
  
  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  if (tstqRet != NULL) tstqDelete(tstqRet);


  tstqRet = tstqPopback(&qhead);
  if (tstqRet != NULL) tstqDelete(tstqRet);

  tstqDump(qhead);
  tstqDelete(qhead);
}

void Test0002QueueTst() {
  tstqueue *qhead;
  tstrie *tst;
  tstqueue *tstqRet;

  printf("[ -- Test0002QueueTst ]\n");
  qhead = tstqNew('s', 8);
  tstqDump(qhead);

  tst = tstNew('a', 0);
  qhead = tstqPushfront(qhead, tst);
  tstqDump(qhead);

  tst->item = 'c';
  tst->data = 9;
  qhead = tstqPushfront(qhead, tst);
  tstqDump(qhead);

  printf("testing tqtqPopfront\n");
  tstqRet = tstqPopfront(&qhead);
  tstqDump(tstqRet);
  tstqDump(qhead);

  tstqDelete(tstqRet);
  tstqDelete(qhead);
  tstDelete(tst);
}

void Test0004QueueTst() {
  tstqueue *qhead;
  tstrie *tst;
  tstqueue *tstqRet;

  printf("[ -- Test0004QueueTst ]\n");
  qhead = tstqNew('s', 8);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));

  tst = tstNew('a', 0);
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));
  
  tst->item = 'c';
  tst->data = 9;
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));

  tst->item = 'd';
  tst->data = 7;
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));

  printf("starting to pop\n");
  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  printf("size: %0d\n", tstqSize(qhead));
  tstqDelete(tstqRet);

  tstqDelete(qhead);
  tstDelete(tst);
}

tstrie* Test0000MakePattern_01() {
  tstrie *ret;
  ret = tstNew('s', 0); // she

  ret->middle = tstNew('h', 0);
  ret->middle->middle = tstNew('e', 0); 
  ret->middle->middle->middle = tstNew('l', 0); // shells
  ret->middle->middle->middle->middle = tstNew('l', 0);
  ret->middle->middle->middle->middle->middle = tstNew('s', 0);

  ret->middle->left = tstNew('e', 0); // sells
  ret->middle->left->middle = tstNew('l', 0);
  ret->middle->left->middle->middle = tstNew('l', 0);
  ret->middle->left->middle->middle->middle = tstNew('s', 0);

  ret->middle->left->middle->left = tstNew('a', 0); // sea

  ret->left = tstNew('b', 0); // by
  ret->left->middle = tstNew('y', 0); // by

  ret->right = tstNew('t', 0); // the
  ret->right->middle = tstNew('h', 0);
  ret->right->middle->middle = tstNew('e', 0);

  ret->middle->middle->right = tstNew('o', 0); // shore
  ret->middle->middle->right->middle = tstNew('r', 0);
  ret->middle->middle->right->middle->middle = tstNew('e', 0);
  
  return ret;
}
