#include "testTSTParseSymtab.h"

void Test0000Parser() {
  TokenManager* tm;
  tm = TokenManagerNew("tst/testpattern_tokenmanager.txt");
  //TokenManagerGetNextToken(&tm);
  TokenManagerDelete(tm);
}
