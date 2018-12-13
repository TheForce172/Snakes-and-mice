#ifndef GridItemH
#define GridItemH

class GridItem 
{
public:
	GridItem(char symbol);
	char get_symbol() const;

private:
	char symbol;
};


#endif