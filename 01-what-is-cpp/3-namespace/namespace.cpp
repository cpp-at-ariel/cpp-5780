#include <iostream>
using namespace std;

namespace def{
	int y = 789;
};

namespace abc{
	int x = 123;
	void printx() { std::cout << x << std::endl; }
	namespace xyz {
		int w = 5;
	}
};

namespace def{
	int x = 456;
	void printx() { std::cout << x << std::endl; }
};



//using namespace abc; 
//using namespace def; 
int main() {
	abc::printx();
	def::printx();
	std::cout << def::x << " "<< def::y << std::endl;
//	printx();
	//std::cout << abc::xyz::w << std::endl;
}
