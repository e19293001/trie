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
//    printf("[ tstqDelete ] t->item->item: %c t->item->data: %0d\n", t->item->item, t->item->data);
//    printf("[ tstqDelete ] deleting item which has a value of %c\n", t->item->item);
    tstDelete(t->item);
    free(t);
  }
}

tstqueue* tstqPopfront(tstqueue **q) {
  tstqueue* ret = NULL;
//  printf("popping\n");
  if (*q == NULL) {
//    printf("*q is null\n");
    return NULL;
  }
  else  {
//    printf("*q is NOT null\n");
    ret = *q;
    if ((*q)->next == NULL) {
//      printf("(*q)->next is NULL\n");
      (*q) = NULL;
    }
    else {
//      printf("(*q)->next is NOT NULL\n");
      (*q) = (*q)->next;
//      tstqDump(*q);
      ret->next = NULL;
    }
//    printf("dumping start\n");
//    tstqDump(ret);
//    printf("dumping end\n");
  }


  return ret;
}

tstqueue* tstqPopback(tstqueue **q) {
  tstqueue* ret;
  tstqueue* tail;
  tstqueue* prevtail;
  tstqueue* prev1tail;

  if ((*q) == NULL) {
    ret = NULL;
  }
  else {
    if ((*q)->next != NULL) {
      tail = *q;
      prevtail = NULL;
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

  return ret;
}

tstqueue* tstqPushback(tstqueue *q, tstrie *t) {
  tstqueue* ret = NULL;
  tstqueue* tail;
  tstqueue* prevtail;

  ret = malloc(sizeof(tstqueue));
  ret->next = NULL;

  if (q != NULL) {
    tstCopy(t,&ret->item);
    //ret = q;
    tail = q;
    prevtail = NULL;
    while (tail != NULL) {
      prevtail = tail;
      tail = tail->next;
    }
    tail = prevtail;
    tail->next = ret;
    ret = q;
//    tstqDump(ret);
  }
  else {
//    printf("[ tstqPushfront ] q is NULL\n");
    //ret->item = NULL;
    tstCopy(t,&ret->item);
    ret->next = NULL;
//    printf("[ tstqPushfront ] done copying\n");
  }

  return ret;
}

tstqueue* tstqPushfront(tstqueue *q, tstrie *t) {
  tstqueue* ret = NULL;
//  printf("[ tstqPushfront ] \n");
  ret = malloc(sizeof(tstqueue));
  
  if (q != NULL) {
    //ret = tstqNew('\0', 0);
    tstCopy(t,&ret->item);
    ret->next = q;
  }
  else {
//    printf("[ tstqPushfront ] q is NULL\n");
    //ret->item = NULL;
    tstCopy(t,&ret->item);
    ret->next = NULL;
//    printf("[ tstqPushfront ] done copying\n");
  }
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
    if (q->item == NULL) {
      printf("[ tstqDump ] q->item is NULL\n");
    }
    else {
      printf("->[%c:%0d]", q->item->item, q->item->data);
      q = q->next;
    }
  }
  printf("\n");
}

