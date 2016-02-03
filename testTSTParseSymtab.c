#include "testTSTParseSymtab.h"

void Test0000Parser() {
  TokenManager* tm;
  Token tok;
  tm = TokenManagerNew("tst/testpattern_tokenmanager.txt");
  //TokenManagerGetNextToken(&tm);
//  while (tok.kind != _EOF) {
    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);
//  }

    tok = TokenManagerGetNextToken(&tm);
  printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);

  TokenManagerDelete(tm);
}
