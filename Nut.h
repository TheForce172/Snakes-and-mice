#ifndef NutH
#define NutH

#include "Constants.h"


class Nut{
public:
	// constructor
	Nut();
	
	int get_x() const;
	int get_y() const;

	char get_symbol() const;

	bool has_been_collected(int x, int y) const;
	bool is_at_position(int x, int y) const;

	void disappear();

	

private:
	// data members		
	int  x_, y_;
	char symbol_;
	bool collected;

	

	

};

#endif