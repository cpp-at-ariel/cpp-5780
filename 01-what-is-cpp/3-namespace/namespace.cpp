#include <iostream>
using namespace std;

#include "namespace.hpp"
using namespace abc;

namespace abc {
	void printx() {
		cout << 5 << endl;
	}
}

int main() {
	printx();
}
