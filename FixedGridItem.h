#ifndef FixedGridItem
#define FixedGridItemH
#include "GridItem.h"

class FixedGridItem : public GridItem {

public:
	bool is_at_position(int x, int y) const;	
	int get_x() const;
	int get_y() const;

private:
	int x;
	int y;
};
#endif
