#pragma once
#include "constants.h"
class Hole
{
public:
	// constructors
	Hole();
	Hole(int x, int y);

	// assessors
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool is_at_position(int x, int y) const;
	void operator=(const Hole& rhs);

private:
	static const int MAXHOLES; // number of holes in underground
							   // data members
	const char symbol_;
	int x_, y_;
};