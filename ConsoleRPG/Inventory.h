#ifndef INVENTORY_h
#define INVENTORY_h

#include "item.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	//functions
	void addItem(const Item &item);
	void removeItem(int index);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < numOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << std::endl;
		}
	}

private:
	int capacity;
	int numOfItems;
	Item **itemArr;
	//functions
	void expand();
	void initialiaze(const int from);
};

#endif