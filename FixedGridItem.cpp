#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const int x, const int y, char symbol):GridItem(symbol),x_(x),y_(y)
{}

const int FixedGridItem::get_x() {
	return x_;
}

const int FixedGridItem::get_y() {
	return y_;
}

bool FixedGridItem::is_at_position(const int x, const int y) const{
	return (x_ == x) && (y_ == y);
}