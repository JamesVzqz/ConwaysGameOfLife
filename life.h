#ifndef LIFE_H
#define LIFE_H

class World; //QUESTION: does this goes inside the include guards?


class Life {
public:

	int getCol() const; // const member functions cannot modify member variables.
	int getRow() const;
	int getHeight() const;
	int getWidth() const;
	char getFigure(int r, int c) const;

protected:
	int m_col;
	int m_row;
	int m_height;
	int m_width;
	char** m_sprite;
	World* m_world;
};

#endif // !LIFE_H



