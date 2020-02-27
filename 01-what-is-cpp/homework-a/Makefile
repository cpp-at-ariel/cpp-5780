#!make -f

CPP=clang++-9 -std=c++17

demo: Demo.o Gimatriya.o
	$(CPP) $^ -o demo

test: TestMain.o Test.o Gimatriya.o
	$(CPP) $^ -o test

%.o: %.cpp Gimatriya.h
	$(CPP) --compile $< -o $@

clean:
	rm -f *.o demo test
