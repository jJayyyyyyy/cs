circular_queue : main.o queue.o
	cc -ocirculary_queue main.o queue.o

main.o : main.c queue.h
	cc -c main.c
queue.o : main.c queue.h
	cc -c queue.c

clean :
	rm main.o queue.o

.PHONY:circulary_queue clean
