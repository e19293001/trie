#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "QueueTernarySearchTrie.h"

void Test0000QueueTst();
void Test0001QueueTst();
void Test0002QueueTst();
void Test0003QueueTst();
void Test0004QueueTst();
  
int main() {
  
  Test0000QueueTst(); // test tstqPushfront
  Test0001QueueTst(); // test tstqPushback
  Test0002QueueTst(); // test tstqPopfront
  Test0003QueueTst(); // test tstqPopback
  Test0004QueueTst(); // test tstqSize

  return 0;
}

void Test0000QueueTst() {
  tstqueue *qhead;
  tstrie *tst;

  printf("[ -- Test0000QueueTst ]\n");
  printf("creating queue value: s\n");
  qhead = tstqNew('s', 8);
  printf("create tst value: a\n");
  tst = tstNew('a', 0);
  printf("push front tst to qhead\n");
  qhead = tstqPushfront(qhead, tst);
  printf("qhead->item->item: %c\n", qhead->item->item);

  tstqDump(qhead);
//  printf("qhead->next->item->item: %c", qhead->next->item->item);
  tstqDelete(qhead);
  tstDelete(tst);
}

void Test0001QueueTst() {
  tstqueue *qhead;
  tstrie *tst;

  printf("[ -- Test0001QueueTst ]\n");
  printf("creating queue value: s\n");
  qhead = tstqNew('s', 8);
  printf("create tst value: a\n");
  tst = tstNew('a', 0);
  printf("push back tst to qhead\n");
  qhead = tstqPushback(qhead, tst);
  printf("qhead->item->item: %c\n", qhead->item->item);

  tstqDump(qhead);
//  printf("qhead->next->item->item: %c", qhead->next->item->item);
  tstqDelete(qhead);
  tstDelete(tst);
}

void Test0003QueueTst() {
  tstqueue *qhead;
  tstrie *tst;
  tstqueue *tstqRet;

  printf("[ -- Test0003QueueTst ]\n");
  qhead = tstqNew('s', 8);
  tstqDump(qhead);

  tst = tstNew('a', 0);
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);
  
  tst->item = 'c';
  tst->data = 9;
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);

  tst->item = 'd';
  tst->data = 7;
  qhead = tstqPushback(qhead, tst);
  tstqDump(qhead);

  printf("starting to pop\n");
  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDelete(tstqRet);

  tstqRet = tstqPopback(&qhead);
  tstqDump(qhead);
  tstqDelete(tstqRet);

  tstqDelete(qhead);
  tstDelete(tst);
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

