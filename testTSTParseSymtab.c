#include "testTSTParseSymtab.h"
#include "parser.h"

void Test0001Parser() { // test parser
  parserData *parser;
  parser = ParserNew();
  printf("testing parser\n");
  ParserStart(parser);
  ParserDelete(parser);
}

void Test0000Parser() {
  TokenManager* tm;
  Token tok;
  tm = TokenManagerNew("tst/testpattern_tokenmanager.txt");
  
  if (isdigit('1')) {
    printf("digit\n");
  }
  else {
    printf("not digit\n");
  }
  
  do {
    tok = TokenManagerGetNextToken(&tm);
    printf("token.image: %s\n", tok.image);
  } while (tok.kind != _EOF);

  printf("tok.kind: %0d token.image: %s\n", tok.kind, tok.image);

  TokenManagerDelete(tm);
}
