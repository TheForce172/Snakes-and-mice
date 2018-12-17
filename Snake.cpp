#include "Snake.h"

Snake::Snake(int x, int y, int maxTail) : MoveableGridItem(x, y, SNAKEHEAD), tail_({MoveableGridItem(0,0,SNAKETAIL), MoveableGridItem(0,0,SNAKETAIL), MoveableGridItem(0,0,SNAKETAIL)})
{
	position_at_random();
	//setPrivateMember(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	// make the pointer safe before the snake spots the mouse
	p_mouse_ = nullptr;
}

Snake::~Snake()
{
}

bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: The mouse needs to exist 
	assert(p_mouse != nullptr);
	p_mouse_ = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);
	moveTail(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse_ != nullptr);

	// assume snake only move when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (get_x() < p_mouse_->get_x())          // if snake on left of mouse
		dx = 1;                          // snake should move right
	else if (get_x() > p_mouse_->get_x())     // if snake on left of mouse
		dx = -1;						 // snake should move left

	if (get_y() < p_mouse_->get_y())          // if snake is above mouse
		dy = 1;                          // snake should move down
	else if (get_y() > p_mouse_->get_y())     // if snake is below mouse
		dy = -1;						 // snake should move up
}

void Snake::moveTail(int snake_dx, int snake_dy)
{
	if (tail_.size() == 1)
	{
		tail_.at(0).set_position(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
	}

	else if (tail_.size() == 2)
	{
		tail_.at(1).set_position(tail_.at(0).get_x(), tail_.at(0).get_y()); //set second tail piece to first tail pieces previous position
		tail_.at(0).set_position(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
	}

	else if (tail_.size() == 3)
	{
		tail_.at(2).set_position(tail_.at(1).get_x(), tail_.at(1).get_y());//set third tail piece to second tail pieces previous position
		tail_.at(1).set_position(tail_.at(0).get_x(), tail_.at(0).get_y()); //set second tail piece to first tail pieces previous position
		tail_.at(0).set_position(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
	}
}

char Snake::getTailSymbol() const
{
	return tail_.at(0).get_symbol();
}

bool Snake::gridAtTail(int row, int col) const
{
	bool success = false;
	for (int i = 0; i < tail_.size(); i++)
	{
		if (row == tail_.at(i).get_y() && col == tail_.at(i).get_x())
		{
			success = true;
		}
	}
	return success;
}

void Snake::reset() {
	position_at_random();
	for (int i = 0; i < tail_.size; i++) {
		tail_[i].set_position(get_x(), get_y());
	}
}