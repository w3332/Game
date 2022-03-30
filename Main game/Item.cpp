#include "Item.h"

//

string Item::RandomItem()
{
	int a = rand() % AllItems.size();
	return AllItems[a];
}
