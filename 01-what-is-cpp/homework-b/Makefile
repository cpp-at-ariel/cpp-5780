#!make -f

CPP=clang++-9 -std=c++2a

run: test
	./$^

test: TestRunner.o Test1.o Test2.o Gimatriya.o
	$(CPP) $^ -o test

%.o: %.cpp Gimatriya.hpp
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o test
