/**
 * Demonstrates the difference between push_back and emplace
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class T>
class iterable_printer {
	const T& the_iterable;
	public:
	iterable_printer(const T& x): the_iterable(x) {
		cout << "constructor " << endl;
	}
	void print() {
		for (auto item: the_iterable) {
			cout << item << " ";
		}
		cout << endl;
	}
};


int main() {
	throw string("abc");
	vector<string> v1;
	//vector<int> v2(v1.begin(), v1.end());  // static assert

	auto v2 = vector({1,2,3,4});
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout," "));
	cout << endl;

	iterable_printer(vector({1,2,3,4})).print();
}
