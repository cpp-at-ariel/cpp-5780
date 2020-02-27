#!make -f

CPP=clang++-9 -std=c++2a

run: demo
	./$^

demo: Demo.o Gimatriya.o
	$(CPP) $^ -o demo

test: TestCounter.o Test.o Gimatriya.o
	$(CPP) $^ -o test

%.o: %.cpp Gimatriya.hpp
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o demo test
