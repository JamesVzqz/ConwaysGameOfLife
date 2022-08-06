#ifndef TUB_H
#define TUB_H

#include "life.h" //This will make sure to include life.h (protected by include guards) if we don't state it in main.cpp

class Tub : public Life {
public:
	// Constructor/destructor
	Tub(int r, int c);
	~Tub();
};


#endif // !TUB_H

