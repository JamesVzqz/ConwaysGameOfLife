#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "game.h"
#include "world.h"
#include "globals.h"

///////////////////////////////////////////////////////////////////////////
// Game Implemention
///////////////////////////////////////////////////////////////////////////

Game::Game(Life** life, int numLife) {

	m_steps = 0;
	m_automate = false;
	m_world = new World();

	if (life != nullptr) {
		for (int i = 0; i < numLife; i++) {
			if (life[i] != nullptr) {
				bool success = m_world->init(life[i]);
				if (!success) {
					std::cout << "Failed to add life to the world" << std::endl;
				}
			}

		}
	}

}
Game::~Game() {
	delete m_world;
}

void Game::gameLoop() {
	while (true) {
		m_world->print();

		if (!m_automate) {
			std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";

			std::string action;
			std::getline(std::cin, action);

			switch (action[0])
			{

			default:
				std::cout << '\a' << std::endl;  // beep
				continue;
			case 'q':
				std::cout << "Quitting Game." << std::endl;
				return;
			case 's':

				continue;
			case ' ':

				break;
			case 'a':
				m_automate = true;
				break;

			}
		}
		else {
			if (m_steps >= MAX_STEPS) {
				std::cout << "Reached max steps, quitting." << std::endl;
				return;
			}
			delay(300);
		}
		m_steps++;
		m_world->update();
	}
}

void Game::report() {
	std::string msg1 = "\nAnswer 1: It is caused due to include guards missing in some header files or they are not placed correctly causing duplicate header inclusions."; // Answer 1
	std::string msg2 = "\nAnswer 2: The function main() is defining the variable w of class World, it is missing the world header file to compile. In case it compiles is because game.h is including world.h."; // Answer 2
	std::string msg3 = "\nAnswer 3: The function main() is defining the variable l of class Life, it won't compile unless the main.cpp includes the life header file. Additionally the clearScreen() function uses the class World so it is expected to include the world header file as well to compile. If it compiles is because game.h is including both world.h and life.h."; // Answer 3
	std::cout << msg1 << std::endl;
	std::cout << msg2 << std::endl;
	std::cout << msg3 << std::endl;
}


void Game::delay(int ms) const {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
