/**
 * Examples of automatic tests for the exercise on family trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "FamilyTree.hpp"

int main() {
	familyTree tree;

	tree.addNew("adam", 'm');
	tree.addNew("hava", 'f', 'w', "adam");
	tree.addNew("shem", 'm', 'c', "adam");
	tree.addNew("ham", 'm', 'c', "hava");
	tree.addNew("yefet", 'm', 's', "ham");
	tree.addNew("kar", 'f', 'w', "ham");
	tree.addNew("posher", 'm', 'c', "ham");

	tree.find("adam", "posher");

	badkan::TestCase testcase;
	testcase.setname("My tests")
		.CHECK_OUTPUT(tree.findRelation("posher", 'g'), "adam")
		.CHECK_OUTPUT(tree.findRelation("posher", 'u'), "hava")
		.CHECK_OUTPUT(tree.find("ham", "posher"), "father")
		.CHECK_OUTPUT(tree.find("adam", "hava"), "husband")
		.CHECK_OUTPUT(tree.find("adam", "posher"), "grandfather")
		.print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;

	return 0;
}

