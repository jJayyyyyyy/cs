arctan : main.o atan.o
	cc -o arctan main.o atan.o -lm

main.o : main.c atan.h
	cc -c main.c
atan.o : atan.c atan.h
	cc -c atan.c

clean :
	rm main.o atan.o

.PHONY: arctan clean
