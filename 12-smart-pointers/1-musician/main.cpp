#include <iostream>
#include <vector>
#include "musician.hpp"
#include "SharedPointer.hpp"
#include "UniquePointer.hpp"


using namespace std;


// Play music with C-style pointers
void playMusic1 (int numMusicians) {
	vector<Musician*> band (numMusicians);
	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician;								

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();	
		
	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	

	for (int i = 0; i < numMusicians; ++i)
		delete band[i];
}

// Play music with Java-style finally block - does not work in C++
#if Java
void playMusic2 (int numMusicians) {
	vector<Musician*> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician;								

	try {            
		for (int i = 0; i < numMusicians; ++i)
			band[i]->play();	
		
		cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
	} finally {      
		for (int i = 0; i < numMusicians; ++i)
			delete band[i];
	}
}
#endif

// Play music with smart pointers
void playMusic3 (int numMusicians) {
	vector<Musician*> band (numMusicians);

	for (int i = 0; i < numMusicians; ++i)
		band[i] = new Musician;								

	for (int i = 0; i < numMusicians; ++i)
		band[i]->play();	
	
	cout << endl << endl << "All musicians in band are playing!" << endl << endl;	
}



int main () {
	int numMusicans = 7;
	try	{
		playMusic1(numMusicans);
	} catch (TooNoisy& noisy) {
		cout << endl << endl << "It is too noisy here! " << noisy.getNumMusicians() << " musicians are playing concurrently! Stop Playing!" << endl << endl;
	}
}
