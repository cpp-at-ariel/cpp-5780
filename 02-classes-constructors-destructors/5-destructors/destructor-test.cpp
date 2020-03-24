/**
 * Demonstrates what happens when an object is destructed twice.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include <iostream>
using namespace std;

class Test {
public:
    int x;
    Test(int x): x(x) {cout<<"c "<<x<< endl;}
    ~Test() {cout<<"d "<<x << endl;}
};

Test f () {
    return Test(99);    
}

void g (Test t) {
}

Test& h() {
    Test t(88);
    return t;
}


int main() {
    cout << "1" << endl;
    Test* plist = new Test(10);
    {
        Test list0(5);
        cout << "in scope" << endl;
    }
    cout << "2" << endl;
    Test t(555);
    t = f();
    cout << "3" << endl;
    g(Test(67));
    cout << "4" << endl;
    cout << h().x << endl;
    Test array[5] {11, 22, 33, 44, 55};
    delete plist;
}
