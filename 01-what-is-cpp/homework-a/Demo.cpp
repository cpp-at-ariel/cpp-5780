/**
 * Demo program for Gimatriya calculation
 */

#include "Gimatriya.h"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << gimatriya("תשפ") << endl;   // should print 780
	cout << gimatriya("תש\"פ") << endl;   // should print 780
	cout << gimatriya("א") << endl;   // should print 1
	cout << gimatriya("'א") << endl;   // should print 1
	try {
		cout << gimatriya("abc") << endl;   // should throw an exception
	catch (exception ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "abc is not a Hebrew string"
	}
}
