#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const int x, const int y, char& symbol):GridItem(symbol),x(x),y(y)
{}

const int FixedGridItem::get_x() {
	return x;
}

const int FixedGridItem::get_y() {
	return y;
}

const bool FixedGridItem::is_at_postion(const int x, const int y) {
	return (x == x) && (y == y);
}