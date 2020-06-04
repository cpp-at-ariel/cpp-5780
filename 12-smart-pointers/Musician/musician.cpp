#include <iostream>
#include "musician.h"

using namespace std;

const int Musician::M_MAX_CONCURRENTLY_PLAYING (5);
int Musician::m_currentPlayingMusicians (0);

Musician::Musician () //throw()
{
	cout << "Hello, I am a new musician!" << endl;
}

Musician::~Musician ()
{
	cout << "Another musician is deleted..." << endl;
}

void Musician::play() const //throw (TooNoisy)
{
	if (++m_currentPlayingMusicians > M_MAX_CONCURRENTLY_PLAYING)
		throw TooNoisy (m_currentPlayingMusicians);		
}
