#include "Nut.h"

Nut::Nut(int x, int y) : MoveableGridItem(x, y, NUT)
{
	//disappear();
	//int x = 8;
	//int y = 9;
	setPrivateMember(x, y);
}

bool Nut::has_been_collected() const
{
	return collected_;
}

void Nut::disappear() {

}

void Nut::reset() {
	collected_ = false;
	set_position(8, 9);
}