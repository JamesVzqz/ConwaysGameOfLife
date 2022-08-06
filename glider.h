#ifndef GLIDER_H
#define GLIDER_H

#include "life.h" //This will make sure to include life.h (protected by include guards) if we don't state it in main.cpp

class Glider : public Life {
public:
	// Constructor/destructor
	Glider(int r, int c);
	~Glider();
};

#endif // !GLIDER_H



