#include "MoveAbleGridItem.h" 

MoveableGridItem::MoveableGridItem(int x, int y) : x(x), y(y) {

}
	int MoveableGridItem::get_x() const
	{
		return x;
	}

	int MoveableGridItem::get_y() const
	{
		return y;
	}

	bool MoveableGridItem::is_at_position(int x, int y) const
	{
		return (x == x) && (y == y);
	}

	void reset_position(int x, int y) {

	}

	void update_position(int dx, int dy) {

	}



