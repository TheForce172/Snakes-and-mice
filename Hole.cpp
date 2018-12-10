#include "Hole.h"
Hole::Hole() : symbol_(HOLE)
{
}

Hole::Hole(int x, int y) : symbol_(HOLE), x_(x), y_(y)
{
}
void Hole::operator=(const Hole& rhs) {
	x_ = rhs.x_;
	y_ = rhs.y_;
}


int Hole::get_x() const
{
	return x_;
}

int Hole::get_y() const
{
	return y_;
}

char Hole::get_symbol() const
{
	return symbol_;
}

bool Hole::is_at_position(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}