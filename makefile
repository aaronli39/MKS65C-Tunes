run: linked_list.c
	gcc test.c
	
compile:
	./a.out
	
linked_list.c: linked_list.h
	gcc linked_list.c