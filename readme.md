# How to make

* first write a `hello.c`, then

	```bash
	$ make hello
	$ ./hello
	```
	to debug and test

* Makefile basic format

	```bash
	edit : main.o abc.o
		cc -o edit main.o abc.o

	main.o : main.c def.h
		cc -c main.c
	abc.o : abc.c def.h
		cc -c abc.c

	clean :
		rm main.o abc.o
	.PHONY : edit clean
	```

	then

	```
	$ make
	$ make clean	
	```
