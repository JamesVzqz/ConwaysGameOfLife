#ifndef RPENT_H
#define RPENT_H

#include "life.h" //This will make sure to include life.h (protected by include guards) if we don't state it in main.cpp

class RPent : public Life {
public:

	// Constructor/destructor
	RPent(int r, int c);
	~RPent();
};

#endif // !RPENT_H



