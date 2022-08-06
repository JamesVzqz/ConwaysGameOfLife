#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "rpent.h"
#include "glider.h"
#include "tub.h"
#include "world.h"
#include "game.h"

///////////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////////

int main() {

	Life **population = new Life*[3];

	population[0] = new Glider(4, 4); 
	population[1] = new RPent(14, 14);
	population[2] = new Tub(2, 15);
	int numLife = 3;

	// Create the game
	Game g(population, numLife);

	// Run the game
	g.gameLoop();

	// Report
	g.report();

	// Clean up
	delete population[0];
	delete population[1];
	delete population[2];
	delete[] population;

}




#ifdef _MSC_VER  // DO NOT BREAK APART THE CONTROL MACROS
//  Microsoft Visual C++
#include <windows.h>

void World::clearScreen() const {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // DO NOT BREAK APART THE CONTROL MACROS
// not Microsoft Visual C++, so assume UNIX interface
#include <iostream>
#include <cstring>
#include <cstdlib>

void World::clearScreen() const {  // will just write a newline in an Xcode output window

	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
		std::cout << std::endl;
	else {
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		std::cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << std::flush;
	}
}

#endif // DO NOT BREAK APART THE CONTROL MACROS

