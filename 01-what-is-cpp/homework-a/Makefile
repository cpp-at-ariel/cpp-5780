#!make -f

CPP=clang++-9 -std=c++2a

run: test
	./$^

demo: DemoProgram.o Gimatriya.o
	$(CPP) $^ -o demo

our_test: TestMain.o Reporters.o DemoTest.o Gimatriya.o
	$(CPP) $^ -o our_test

your_test: TestMain.o Reporters.o Test.o Gimatriya.o
	$(CPP) $^ -o your_test

%.o: %.cpp Gimatriya.hpp
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o demo our_test your_test
