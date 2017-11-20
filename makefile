all: pipe.c
	gcc pipe.c
run: all
	./a.out
clean:
	rm a.out
	rm *~