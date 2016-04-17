singly_queue : main.o queue.o
	cc -o singly_queue main.o queue.o

main.o : main.c queue.h
	cc -c main.c
queue.o : queue.c queue.h
	cc -c queue.c

clean :
	rm main.o queue.o

.PHONY: singly_queue clean
