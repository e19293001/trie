OUT=tst
MAIN=main
TEST=testNode
TEST=testTstNode
COPTS=-g

all: mkdirs bin/$(TEST)
	./bin/$(TEST)

mkdirs:
	mkdir -p bin obj

comp: obj/tst.o obj/main.o obj/node.o
	gcc $^ -o bin/$(OUT) $(COPTS)

run:
	./$(OUT)

obj/TernarySearchTrie.o: TernarySearchTrie.c TernarySearchTrie.h
	gcc -c $< -o $@ $(COPTS)

obj/tst.o: tst.c tst.h
	gcc -c $< -o $@ $(COPTS)

obj/main.o: main.c 
	gcc -c $< -o $@ $(COPTS)

obj/node.o: node.c node.h
	gcc -c $< -o $@ $(COPTS)

obj/unitTestNode.o: unitTestNode.c unitTestNode.h
	gcc -c $< -o $@ $(COPTS)

clean:
	rm -fr *.o
	rm -fr bin obj 

obj/$(TEST).o: $(TEST).c
	gcc -c $< -o $@ $(COPTS)

bin/$(TEST): obj/$(TEST).o obj/node.o obj/unitTestNode.o obj/TernarySearchTrie.o
	gcc $^ -o $@ $(COPTS)

val: mkdirs bin/$(TEST)
	valgrind --leak-check=full -v ./bin/$(TEST)
