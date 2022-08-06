#ifndef GAME_H
#define	GAME_H

class Life;
class World;

class Game {
public:
	// Constructor/destructor
	Game(Life** life, int numLife);
	~Game();
	void report();

	void gameLoop();
private:
	void delay(int ms) const;
	World* m_world;
	int m_steps;
	bool m_automate;
};


#endif // !GAME_H