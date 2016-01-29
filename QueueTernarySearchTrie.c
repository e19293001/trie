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
  if (q == NULL) {
    return 0;
  }
  else {
    return 1 + tstqSize(q->next);
  }
  //return (*q == NULL) ? 0 : 1 + tstqSize((*q)->next);
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

tstqueue* tstqPopfront(tstqueue **q) {
  tstqueue* ret;
  ret = *q;
  (*q) = (*q)->next;
  ret->next = NULL;
  return ret;
}

tstqueue* tstqPopback(tstqueue **q) {
  tstqueue* ret;
  tstqueue* tail;
  tstqueue* prevtail;
  tstqueue* prev1tail;

  ret = NULL;
  printf("[ tstqPopback ] (*q)->item->item: %c (*q)->item->data: %0d\n", (*q)->item->item, (*q)->item->data);
  if (*q != NULL) {
    if ((*q)->next != NULL) {
      tail = *q;
      printf("[ tstqPopback ] tail->item->item: %c tail->item->data: %0d\n", tail->item->item, tail->item->data);
      prevtail = NULL;
      //    while (tail != NULL && tail->next != NULL) {
      while (tail != NULL) {
        prev1tail = prevtail;
        prevtail = tail;
        tail = tail->next;
      }
      if (prev1tail != NULL) {
        prev1tail->next = NULL;
      }
      ret = prevtail;
    }
    else {
      ret = *q;
      *q = NULL;
    }
  }
  else {
    printf("[ tstqPopback ] *q is empty\n");
  }

  printf("[ tstqPopback ] ret->item->item: %c ret->item->data: %0d\n", ret->item->item, ret->item->data);

  return ret;
}

tstqueue* tstqPushback(tstqueue *q, tstrie *t) {
  tstqueue* ret;
  tstqueue* tail;
  tstqueue* prevtail;

  ret = tstqNew((char)NULL, 0);
  tstCopy(t, &ret->item);

  tail = q;
  prevtail = NULL;
  while (tail != NULL) {
    prevtail = tail;
    tail = tail->next;
  }
  tail = prevtail;
  tail->next = ret;
  ret = q;

  printf("[ tstqPushback start ]\n");
  tstqDump(ret);
  printf("[ tstqPushback end ]\n");

  return ret;
}

tstqueue* tstqPushfront(tstqueue *q, tstrie *t) {
  tstqueue* ret;
  ret = tstqNew((char)NULL, 0);
  tstCopy(t,&ret->item);

  ret->next = q;

  return ret;
}

void tstqDump(tstqueue *q) {
  printf("[ tstqDump ] ");
  if (q != NULL) {
    printf("[%c:%0d]", q->item->item, q->item->data);
    q = q->next;
  }
  else {
    printf("[ tstqDump ] *q is empty.\n");
  }
  while (q != NULL) {
    printf("->[%c:%0d]", q->item->item, q->item->data);
    q = q->next;
  }
  printf("\n");
}

