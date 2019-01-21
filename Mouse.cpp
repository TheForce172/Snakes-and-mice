#include "Mouse.h"

Mouse::Mouse(int x, int y) : MoveableGridItem(x, y, MOUSE), alive_(true), escaped_(false)
{
	//setPrivateMember(x, y);
	position_in_middle_of_grid();
}

bool Mouse::is_alive() const
{
	return alive_;
}

bool Mouse::has_escaped() const
{
	return escaped_;
}

bool Mouse::has_reached_a_hole(Underground ug) const
{
	if (ug.is_Hole(get_x(),get_y())) {
		return true;
	}

	return false;
}

void Mouse::die()
{
	alive_ = false;
}

void Mouse::escape_into_hole()
{
	escaped_ = true;
}

void Mouse::scamper(const char k, Nut n)
{
	// move mouse in required direction
	// pre: k is an arrow representing the direction in which the mouse moves
	assert(k == LEFT || RIGHT || UP || DOWN);
	// find direction indicated by k
	int mouse_dx, mouse_dy;
	switch (k)
	{
		case LEFT:
			mouse_dx = -1;
			mouse_dy = 0;
			break;
		case RIGHT:
			mouse_dx = +1;
			mouse_dy = 0;
			break;
		case UP:
			mouse_dx = 0;
			mouse_dy = -1;
			break;
		case DOWN:
			mouse_dx = 0;
			mouse_dy = +1;
			break;
	}

	// update mouse coordinates if move is possible
	if (((get_x() + mouse_dx) >= 1) && ((get_x() + mouse_dx) <= SIZE) && ((get_y() + mouse_dy) >= 1) && ((get_y() + mouse_dy) <= SIZE))
	{
		update_position(mouse_dx, mouse_dy);
	}

	
}

void Mouse::position_in_middle_of_grid()
{
	set_position(SIZE / 2, SIZE / 2);
}

bool Mouse::can_collect_nut(Nut n) const {
	return ((n.get_x() == get_x()) && (n.get_y() == get_y()));
}

void Mouse::reset() {
	position_in_middle_of_grid();
	alive_ = true;
	escaped_ = false;
}

void Mouse::tunnel(Underground ug)
{		
	int currentx = get_x();
	int currenty = get_y();
	do {

		int hole = rand() % 3;
		if (ug.is_valid_hole_number(hole)) {
			set_position(ug.get_hole_x(hole), ug.get_hole_y(hole));
		}
	} while (get_x() == currentx && get_y() == currenty);
}
 



