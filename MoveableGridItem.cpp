#include "MoveAbleGridItem.h" 

MoveableGridItem::MoveableGridItem(int x, int y, const char symbol) : GridItem(symbol), x_(x), y_(y)
{}
	int MoveableGridItem::get_x() const
	{
		return x_;
	}

	int MoveableGridItem::get_y() const
	{
		return y_;
	}

	const bool MoveableGridItem::is_at_position(const int x, const int y) const
	{
		return (x == x_) && (y == y_);
	}

	void MoveableGridItem::reset_position(int x, int y) {

	}

	void MoveableGridItem::update_position(const int dx, const int dy) {
		x_ += dx;
		y_ += dy;
	}

	void MoveableGridItem::position_at_random() {
		x_ = rng_.get_random_value(SIZE);
		y_ = rng_.get_random_value(SIZE);
	}

	void MoveableGridItem::set_position(const int x, const int y) {
		x_ = x;
		y_ = y;
	}

	void MoveableGridItem::setPrivateMember(const int dx, const int dy) {
		x_ = dx;
		y_ = dy;
	}

