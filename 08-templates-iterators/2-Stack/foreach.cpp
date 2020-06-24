#include "Stk.hpp"

#include <string>
#include <iostream>
using namespace std;



int main() {
	Stk<string>  strStk;
	strStk.push("world!");
	strStk.push("Hello");

	// string  strStk[2] {"Hello","world!"};
	for (const string& val: strStk) {
		cout << val.size() << " ";
		cout << val << endl;
	}
	return 0;
}
