#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



struct employee;
struct Manager{
	vector<shared_ptr<employee>> employees;
	void ask_for_vacation(){}
	~Manager(){
//		for(auto& emp:employees)
//			emp->manager=nullptr;
		{cout << "manager I'm done \n";};
	}
};

struct employee{

	int id;
	string name;
	weak_ptr<Manager> manager;

	void take_vacation(){
		//if(auto p = manager.lock())
		if(!manager.expired()){
			auto p = manager.lock();
			p -> ask_for_vacation();
		}
	}

	~employee(){cout << "employee I'm done \n";};

};
void add(){

}
struct Stack{

	struct Node{
		int data=8;
		shared_ptr<Node> next;
	};

	shared_ptr<Node> head;

	void push(int data){
		auto temp = make_shared<Node>();
		temp->data=data;
		temp->next = head;
		head = temp;
	}

	struct iterator{
		using iterator_category = std::forward_iterator_tag;
		using value_type = int;
		using difference_type = int;
		using pointer = int*;
		using reference = int&;
		shared_ptr<Node> curr;
		iterator(shared_ptr<Node> a):curr(a){};
		void operator++(){
			curr = curr->next;
		}
		bool operator!=(iterator& o){
			return curr != o.curr;
		}
		int& operator*(){
			return curr->data;
		}
	};

	iterator begin(){
		return head;
	}

	iterator end(){
		return iterator(nullptr);
	}

};


int main(){

	//unordered_set<employee> use;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    for(auto& i : s)
    	cout << i << " ";
    cout << endl;

	unique_ptr<string> ptr;//(new std::string("hello"));
	unique_ptr<string> ptr2 (new std::string("hello"));
	ptr = move(ptr2);
	vector<unique_ptr<string>> v;
	v.push_back(move(ptr));

	shared_ptr<string> p(new std::string("hello"));

	vector<shared_ptr<string>> vs;
	{
		shared_ptr<string> p2;
		p2=p;

	}
	vs.push_back(p);
	p=nullptr;
	vs.clear();

	auto sp = make_shared<string>("hi");

	{
		auto bob=make_shared<Manager>();
		{
			auto kate = make_shared<employee>();
			bob->employees.push_back(kate);
			kate->manager=bob;
		}
	}
}
