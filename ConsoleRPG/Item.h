#ifndef ITEM_h
#define ITEM_h

#include <iostream>
#include <iomanip>
#include <string>

class Item
{
public:
	Item();
	virtual ~Item();

	inline std::string debugPrint() const { return this->name; }


private:
	std::string name;
	int buyValue;
	int sellValue;
};

#endif