#include <iostream>
#include <new>
#include <array>
#include "musician.h"


using namespace std;

template<typename T>
class UniquePointer {
	T* ptr = nullptr;

public:
	UniquePointer()=default;

	// Convert from C pointer:
	UniquePointer(T* t): ptr(t) {} 

	// Behave like C pointer:
	T* operator->(){
		return ptr;
	}
	T& operator*(){
		return *ptr;
	}

	// Do not allow to duplicate:
	UniquePointer(UniquePointer const& other) = delete;
	UniquePointer& operator=(UniquePointer const& other) = delete;

	// Delete when out of scope:
	~UniquePointer(){ 
		if (ptr) delete ptr; 
	}

	// Move constructor and operator=:
	UniquePointer(UniquePointer&& other){
		*this=move(other);
	}
	void operator=(UniquePointer&& other){
		ptr=other.ptr;
		other.ptr=nullptr;
	}
};




//
//template<typename T>
//struct UniquePointer{
//
//	struct Ret{
//		T* ptr=nullptr;
//		int rc=0;
//	};
//
//	Ret* ret = new Ret;
//
//	UniquePointer()=default;
//	UniquePointer(T* t){ret -> ptr=t; ret->rc++;};
//	auto operator->(){
//		return ret->ptr;
//	}
//	UniquePointer(UniquePointer const& other){ret->ptr = other.ret->ptr; ret->rc++ ;};
//	UniquePointer& operator=(UniquePointer const& other) {ret->ptr = other.ret->ptr; ret->rc++ ;};
//
//	~UniquePointer(){
//		ret -> rc--;
//		if(ret -> rc == 0)
//			delete ret->ptr;
//	}
//	UniquePointer(UniquePointer&& other){
//		*this=move(other);
//	}
//	void operator=(UniquePointer&& other){
//
//		ret->ptr=other.ret->ptr;
//	}
//
//};


const static int MAX_MUSICIANS = 20;

void playMusic (int numMusicians) // throw (TooNoisy)
{	
	Musician* band [MAX_MUSICIANS];
	//UniquePointer<Musician> band [MAX_MUSICIANS];

	for (int i = 0; i < numMusicians; ++i)
			band[i] = new Musician;								

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();	
	
	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	

	for (int i = 0; i < numMusicians; ++i)
		delete band[i];
}


int main () {
	int numMusicans = 7;
	try	{
		playMusic(numMusicans);
	} catch (TooNoisy& noisy) {
		cout << endl << endl << "It is too noisy here! " << noisy.getNumMusicians() << " musicians are playing concurrently! Stop Playing!" << endl << endl;
	}
}
