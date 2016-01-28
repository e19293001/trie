OUT=tst
MAIN=main
#TEST=testTsTrie
TEST=testQueueTst
COPTS=-g -Wall
OBJDIR=obj

all: mkdirs bin/$(TEST)
	./bin/$(TEST)

mkdirs:
	mkdir -p bin $(OBJDIR)

comp: $(OBJDIR)/tst.o $(OBJDIR)/main.o $(OBJDIR)/node.o
	gcc $^ -o bin/$(OUT) $(COPTS)

run:
	./$(OUT)

$(OBJDIR)/TernarySearchTrie.o: TernarySearchTrie.c TernarySearchTrie.h
	gcc -c $< -o $@ $(COPTS)

$(OBJDIR)/QueueTernarySearchTrie.o: QueueTernarySearchTrie.c QueueTernarySearchTrie.h
	gcc -c $< -o $@ $(COPTS)

#$(OBJDIR)/testTsTrie.o: testTsTrie.c 
#	gcc -c $< -o $@ $(COPTS)

# obj/tst.o: tst.c tst.h
# 	gcc -c $< -o $@ $(COPTS)
# 
# obj/main.o: main.c 
# 	gcc -c $< -o $@ $(COPTS)
# 
# obj/node.o: node.c node.h
# 	gcc -c $< -o $@ $(COPTS)
# 
# obj/unitTestNode.o: unitTestNode.c unitTestNode.h
# 	gcc -c $< -o $@ $(COPTS)

clean:
	rm -fr *.o
	rm -fr bin obj 

$(OBJDIR)/$(TEST).o: $(TEST).c
	gcc -c $< -o $@ $(COPTS)

bin/$(TEST): $(OBJDIR)/$(TEST).o $(OBJDIR)/TernarySearchTrie.o $(OBJDIR)/QueueTernarySearchTrie.o
	gcc $^ -o $@ $(COPTS)

val: mkdirs bin/$(TEST)
	valgrind --leak-check=full -v ./bin/$(TEST)
