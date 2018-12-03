#include "Nut.h"

Nut::Nut(int x, int y) : symbol_(NUT), x_(0), y_(0)
{
	disappear();
}

int Nut::get_x() const
{
	return x_;
}

int Nut::get_y() const
{
	return x_;
}

char Nut::get_symbol() const
{
	return symbol_;
}

bool Nut::is_at_position(int x, int y) const
{
	return (x_ == x) && (y_ == y);
}

bool Nut::is_collected(int x, int y) const
{
	return true;
}