compile: test.o linked_list.o library.o
	gcc test.o

run:
	./a.out

library.o:
	gcc -c library.c

linked_list.o:
	gcc -c linked_list.c

test.o:
	gcc -c test.o

clean:
	@rm -rf *.o a.out 
