linked_list : main.o list.o
	cc -o linked_list main.o list.o

main.o : main.c list.h
	cc -c main.c
list.o :list.c list.h
	cc -c list.c

clean :
	rm main.o list.o

.PHONY: linked_list clean
