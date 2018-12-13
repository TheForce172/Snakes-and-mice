#include "MoveAbleGridItem.h" 

MoveableGridItem::MoveableGridItem(int x, int y, const char symbol):GridItem(symbol)
{}
	int MoveableGridItem::get_x() const
	{
		return x;
	}

	int MoveableGridItem::get_y() const
	{
		return y;
	}

	const bool MoveableGridItem::is_at_position(const int x, const int y) const
	{
		return (x == x) && (y == y);
	}

	void MoveableGridItem::reset_position(int x, int y) {

	}

	void MoveableGridItem::update_position(int dx, int dy) {
		x += dx;
		y += dy;
	}

	void MoveableGridItem::position_at_random() {
		x = rng_.get_random_value(SIZE);
		y = rng_.get_random_value(SIZE);
	}



