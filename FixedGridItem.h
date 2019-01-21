#ifndef FixedGridItemH
#define FixedGridItemH
#include "GridItem.h"

class FixedGridItem : public GridItem 
{

public:
	FixedGridItem(int x, int y, char symbol);

	int get_x() const;
	int get_y() const;
	bool is_at_position(const int x, const int y) const;	

private:
	const int x_, y_;
};
#endif
