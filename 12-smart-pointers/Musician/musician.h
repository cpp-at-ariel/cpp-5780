#ifndef MUSICIAN_H
#define MUSICIAN_H

#include "tooNoisy.h"

class Musician {
public:
	Musician ();  //throw()	
	~Musician ();
	 
	void play () const; //throw (TooNoisy)

private:		
	static const int M_MAX_CONCURRENTLY_PLAYING;
	static int m_currentPlayingMusicians;
};


#endif // MUSICIAN_H
