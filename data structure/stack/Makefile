array_stack : main.o stack.o
	cc -o array_stack main.o stack.o

main.o : main.c stack.h
	cc -c main.c
stack.o : stack.h stack.h
	cc -c stack.c

clean :
	rm main.o stack.o
.PHONY: array_stack clean
