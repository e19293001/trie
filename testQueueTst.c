#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "QueueTernarySearchTrie.h"

void Test0000QueueTst();

int main() {
  
  Test0000QueueTst();

  return 0;
}


void Test0000QueueTst() {
  tstqueue *qhead;
  tstrie *tst;

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
