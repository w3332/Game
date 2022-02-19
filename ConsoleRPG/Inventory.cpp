#include "Inventory.h"



Inventory::Inventory()
{
	this->capacity = 10;
	this->numOfItems = 0;
	this->itemArr = new Item*[capacity];
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::expand()
{
	this->capacity *= 2; //double the size of cap

	Item **tempArr = new Item*[this->capacity]; //new temporary array with doubled cap

	//copy to temparr
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}

	//delete old array
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr; //perm array gets bigger array

	this->initialiaze(this->numOfItems);
}

void Inventory::initialiaze(const int from)
{
	for (size_t i = from; i < capacity; i++)
	{
		//nullify pointers
		this->itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item &item)
{
	if (this->numOfItems >= capacity)
	{
		expand(); //expand inv
	}

	this->itemArr[this->numOfItems++] = new Item(item);
}

void Inventory::removeItem(int index)
{

}