#include "QueueTernarySearchTrie.h"

tstqueue* tstqNew(char key, int value) {
  tstqueue* ret;
  tstrie* t;

  ret = malloc(sizeof(tstqueue));
  t = tstNew(key,value);
  ret->item = t;
  ret->next = NULL;

  return ret;
}

int tstqSize(tstqueue *q) {
  int ret;

  return ret;
}

void tstqDelete(tstqueue *q) {
  while (q != NULL) {
    tstqueue* t = q;
    q = q->next;
    printf("[ tstqDelete ] t->item->item: %c t->item->data: %0d\n", t->item->item, t->item->data);
    printf("[ tstqDelete ] deleting item which has a value of %c\n", t->item->item);
    tstDelete(t->item);
    free(t);
  }
}

tstqueue* tstqPopfront(tstqueue *q) {
  tstqueue* ret;

  return ret;
}

tstqueue* tstqPopback(tstqueue *q) {
  tstqueue* ret;

  return ret;
}

tstqueue* tstqPushfront(tstqueue *q, tstrie *t) {
  tstqueue* ret;
  ret = tstqNew((char)NULL, 0);
  tstCopy(t,&ret->item);
  printf("[ tstqPushfront ] ret->item->item: %c ret->item->data: %0d\n", ret->item->item, ret->item->data);
  printf("[ tstqPushfront ] t->item: %c t->data: %0d\n", t->item, t->data);
  ret->next = q;
  printf("[ tstqPushfront ] ret->next->item->item: %c ret->next->item->data: %0d\n", ret->next->item->item, ret->next->item->data);

  return ret;
}

void tstqDump(tstqueue *q) {
  printf("[ tstqDump ] ");
  if (q != NULL) {
    printf("%c", q->item->item);
    q = q->next;
  }
  while (q != NULL) {
    printf("->%c", q->item->item);
    q = q->next;
  }
  printf("\n");
}

tstqueue* tstqPushback(tstqueue *q, tstrie *t) {
  tstqueue* ret;

  return ret;
}

