#!make -f

CPP=clang++-9 -std=c++2a

run: test
	./$^

test: TestMain.o Reporters.o Test.o Gimatriya.o
	$(CPP) $^ -o test

%.o: %.cpp Gimatriya.hpp
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o test
