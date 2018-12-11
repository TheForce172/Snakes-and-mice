#ifndef FixedGridItemH
#define FixedGridItemH
#include "GridItem.h"

class FixedGridItem : public GridItem {


	FixedGridItem(int x, int y);
public:
	bool is_at_position(int x, int y) const;	
	int get_x() const;
	int get_y() const;

private:
	int x, y;
};
#endif
