
#To run, put this file together with matrixCalculator.h, and matrixCalculator.c
#in the same directory. Run "make". Then the executable
#is "scheme," which just takes a line of input and
#breaks it up into tokens.

mc: matrixCalculator.o
	gcc -o mc matrixCalculator.o

matrixCalculator.o: matrixCalculator.c
	gcc -c matrixCalculator.c
	
clean:
	rm -f *~ *.o *.a

#^^^^^^This space must be a TAB!!.
	