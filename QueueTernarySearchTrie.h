#include "TernarySearchTrie.h"

typedef struct tstqueue {
  tstrie *item;
  struct tstqueue *next;
} tstqueue;

tstqueue* tstqNew(char key, int value);

int tstqSize(tstqueue *q);

// insert

void tstqDelete(tstqueue *q);

tstqueue* tstqPopfront(tstqueue **q);

tstqueue* tstqPopback(tstqueue **q);

tstqueue* tstqPushfront(tstqueue *q, tstrie *t);

tstqueue* tstqPushback(tstqueue *q, tstrie *t);

void tstqDump(tstqueue *q);
