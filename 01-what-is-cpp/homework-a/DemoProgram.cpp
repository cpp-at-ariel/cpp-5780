/**
 * Demo program for Gimatriya calculation.
 * 
 * Date: 2020-02
 */

#include "Gimatriya.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::gimatriya("תשפ") << endl;   // should print 780
	cout << ariel::gimatriya("תש\"פ") << endl;   // should print 780
	cout << ariel::gimatriya("א") << endl;   // should print 1
	cout << ariel::gimatriya("'א") << endl;   // should print 1
	try {
		cout << ariel::gimatriya("abc") << endl;   // should throw an exception
	} catch (exception ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "abc is not a Hebrew string"
	}
}
