/**
 * Demo program for the exercise on family trees.
 * 
 * @author 1 Adam Lev-Ari
 * @author 2 Erel Segal-Halevi
 *
 * @since 2019-12
 */

#include <iostream>
using std::cout, std::endl;

#include "FamilyTree.hpp"

int main() {
  try {
    // constructs an empty tree:
    familyTree tree;

    tree.addNew("adam", 'm');
    tree.addNew("hava", 'f', 'w', "adam");
    tree.addNew("shem", 'm', 'c', "adam");
    tree.addNew("ham", 'm', 'c', "hava");
    tree.addNew("yefet", 'm', 's', "ham");
    tree.addNew("kar", 'f', 'w', "ham");
    tree.addNew("posher", 'm', 'c', "ham");
    //tree.display();

    //"Find relation with relation assign (Father/Mother/Wife/Sibling/Cousin/Uncle/Aunt/Grandparent)"
    tree.findRelation("adam", 'f');
    tree.findRelation("posher", 'u');
    tree.findRelation("posher", 'g');
    tree.findRelation("yefet", 's');

    //finds relation between 2 nodes in the tree
    cout << "\n\nRelations:" << endl;
    cout << tree.find("ham", "posher") << endl;
    cout << tree.find("ham", "kar") << endl;
    cout << tree.find("posher", "shem") << endl;
    cout << tree.find("yefet", "posher") << endl;
    cout << tree.find("adam", "posher") << endl;
    cout << tree.find("posher", "adam") << endl;
  } catch (...) {
    cout << "Caught exception!" << endl;
  }
}


