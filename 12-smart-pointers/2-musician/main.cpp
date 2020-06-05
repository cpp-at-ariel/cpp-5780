#include <iostream>
#include <new>
#include <array>
#include "musician.h"


using namespace std;

template<typename T>
struct smartPointer{

	T* ptr = nullptr;
	smartPointer()=default;
	smartPointer(T* t):ptr(t){};
	auto operator->(){
		return ptr;
	}
	auto operator*(){
		return *ptr;
	}
	smartPointer(smartPointer const& other)=delete;
	smartPointer& operator=(smartPointer const& other) =delete;
	~smartPointer(){delete ptr;}
	smartPointer(smartPointer&& other){
		*this=move(other);
	}
	void operator=(smartPointer&& other){

		ptr=other.ptr;
		other.ptr=nullptr;
	}

};




//
//template<typename T>
//struct smartPointer{
//
//	struct Ret{
//		T* ptr=nullptr;
//		int rc=0;
//	};
//
//	Ret* ret = new Ret;
//
//	smartPointer()=default;
//	smartPointer(T* t){ret -> ptr=t; ret->rc++;};
//	auto operator->(){
//		return ret->ptr;
//	}
//	smartPointer(smartPointer const& other){ret->ptr = other.ret->ptr; ret->rc++ ;};
//	smartPointer& operator=(smartPointer const& other) {ret->ptr = other.ret->ptr; ret->rc++ ;};
//
//	~smartPointer(){
//		ret -> rc--;
//		if(ret -> rc == 0)
//			delete ret->ptr;
//	}
//	smartPointer(smartPointer&& other){
//		*this=move(other);
//	}
//	void operator=(smartPointer&& other){
//
//		ret->ptr=other.ret->ptr;
//	}
//
//};


const static int MAX_MUSICIANS = 20;

void playMusic (int numMusicians) // throw (TooNoisy)
{	
	Musician* band [MAX_MUSICIANS];
	//smartPointer<Musician> band [MAX_MUSICIANS];

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
