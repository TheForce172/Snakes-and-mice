#include "Nut.h"

Nut::Nut() : symbol_(NUT), x_(8), y_(9)
{
	//disappear();
	//int x = 8;
	//int y = 9;
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

bool Nut::has_been_collected(int x, int y) const
{
	return true;
}