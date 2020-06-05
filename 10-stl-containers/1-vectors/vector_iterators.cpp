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


int main() {
	vector<string> v1;
	//vector<int> v2(v1.begin(), v1.end());  // static assert
	vector<int> v2;

	v2 = vector<int>({1,2,3,4});
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout," "));
}
