#!make -f

CPP=clang++-9 -std=c++2a

run: your_test
	./$^

demo: DemoProgram.o Gimatriya.o
	$(CPP) $^ -o demo

our_test: TestMain.o Reporters.o DemoTest.o Gimatriya.o
	$(CPP) $^ -o our_test

test: TestMain.o Reporters.o Test.o Gimatriya.o
	$(CPP) $^ -o test

%.o: %.cpp Gimatriya.hpp
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o demo our_test test
