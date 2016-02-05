#ifndef parser_h
#define parser_h

#include "tokenmanager.h"

typedef struct parserData {
  TokenManager *tm;
  Token currentToken;
  Token previousToken;
} parserData;

parserData *_parser;

parserData* ParserNew();
void ParserConsume();
Token ParserGetToken();
void ParserAdvance();
void ParserDelete(parserData *t);
void ParserStart(parserData *t);

void program();
void push();
void pushc();
void pushwc();
void halt();

void consume(int expected);

#endif
