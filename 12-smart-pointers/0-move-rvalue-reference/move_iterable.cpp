#include <iostream>
#include <vector>
using namespace std;


template<typename Container>
class DummyIterable1 {
	const Container& container;
public:
	DummyIterable1(const Container& the_container): container(the_container) {	}
	auto begin() { return container.begin(); }
	auto end() { return container.end(); }
};

template<typename Container>
class DummyIterable2 {
	const Container container_copy;
	const Container& container_ref;
public:
	DummyIterable2(const Container&  the_container): container_ref (the_container) { cout << "no copy"<<endl;	}
	DummyIterable2(const Container&& the_container): container_copy(the_container), container_ref(container_copy) { cout << "copy"<<endl;	}
	auto begin() { return container_ref.begin(); }
	auto end() { return container_ref.end(); }
};



void demo_iterables() {
	vector<int> v1{1,2,3,4};

	cout << endl << "DummyIterable1: " << endl;
	// DummyIterable on an l-value works:
	for (auto i: DummyIterable1{v1}) {
		cout << i << " ";
	} cout << endl;

	// DummyIterable on an r-value leads to undefined behavior:
	for (auto i: DummyIterable1{vector<int>{1,2,3,4}}) {
		cout << i << " ";
	} cout << endl;

	cout << endl << "DummyIterable2: " << endl;
	// DummyIterable on an l-value works without copying:
	for (auto i: DummyIterable2{v1}) {
		cout << i << " ";
	} cout << endl;

	// DummyIterable on an r-value copies and works too!:
	for (auto i: DummyIterable2{vector<int>{1,2,3,4}}) {
		cout << i << " ";
	} cout << endl;
}

int main() {
	cout << boolalpha;
	demo_iterables();
}
