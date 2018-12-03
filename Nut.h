#ifndef NutH
#define NutH
#include "Constants.h"
class Nut
{

	private:
	// data members		
	int  x_, y_;
	char symbol_;
	bool collected;

	public:
	// constructor
	Nut(int x, int y);

	// assessors
	bool is_collected(int x, int y) const;
	bool is_at_position(int x, int y) const;

	// mutator
	void disappear();

	// getter
	int get_x() const;
	int get_y() const;
	char get_symbol() const;


};

#endif