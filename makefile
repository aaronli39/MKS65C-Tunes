compile: library.o linked_list.o test.o
	gcc test.o linked_list.o library.o

run:
	./a.out

library.o: library.c library.h
	gcc -c library.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

test.o: test.c
	gcc -c test.c

clean:
	-rm -rf *.o a.out
