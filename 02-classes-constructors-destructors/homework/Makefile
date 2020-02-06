#!make -f

CPP=clang++-5.0 -std=c++17

demo: Demo.o FamilyTree.o
	$(CPP) $^ -o demo

test: Test.o FamilyTree.o
	$(CPP) $^ -o test

%.o: %.cpp
	$(CPP) --compile $< -o $@

Test.o: badkan.hpp FamilyTree.hpp

Demo.o: FamilyTree.hpp

FamilyTree.hpp: familyTree.h
	cp familyTree.h FamilyTree.hpp

clean:
	rm -f *.o demo test
