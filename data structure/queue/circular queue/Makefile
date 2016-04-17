doubly_queue : main.o queue.o
	cc -o doubly_queue main.o queue.o

main.o : main.c queue.h
	cc -c main.c
queue.o : main.c queue.h
	cc -c queue.c

clean :
	rm main.o queue.o

.PHONY: doubly_queue clean
