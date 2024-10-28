#include <iostream>

using namespace std;

typedef bool(*FuncPtr)(struct Item*);

struct Item
{
	int itemId;
	int price;
	int type;
};

struct FindResult
{
	bool result;
	int index;
};

struct FindByPrice
{
	bool operator()(Item* item)
	{
		if (item->type == compareNum)
		{
			return true;
		}
		return false;
	}
	int compareNum;
};

struct FindByTypeNPrice
{
	bool operator()(Item* item)
	{
		if (item->type == compareType && item->price == comparePrice)
		{
			return true;
		}
		return false;
	}
	int compareType;
	int comparePrice;
};

struct FindByPriceNId
{
	bool operator()(Item* item)
	{
		if (item->price == comparePrice && item->itemId == compareId)
		{
			return true;
		}
		return false;
	}
	int comparePrice;
	int compareId;
};

struct FindByAll
{
	bool operator()(Item* item)
	{
		if (item->price == comparePrice && item->itemId == compareId && item->type == compareType)
		{
			return true;
		}
		return false;
	}
	int compareType;
	int comparePrice;
	int compareId;
};

template <typename T>
FindResult FindCheckAll(Item* item[], int size, T functor)
{
	FindResult result;
	result.index = -1;
	result.result = false;
	for (int i = 0; i < size; i++)
	{
		//callable 이면 통과
		if (functor(item[i]))
		{
			result.index = i;
			result.result = true;
			return result;
		}

	}
	return result;
}


bool Func_Price(Item* item)
{
	if (item->price == 3000)
		return true;
	return false;
}

bool Func_Type(Item* item)
{
	if (item->type == 3)
	{
		return true;
	}
	return false;
}


int main()
{
	Item* items[10] = { nullptr };

	for (int i = 0; i < 10; i++)
	{
		items[i] = new Item();
		items[i]->itemId = i;
		items[i]->price = (10 - i) * 500;
		items[i]->type = (10 - i);
	}

	FindByPrice findItem;
	findItem.compareNum = 2500;

	//type 8 & price 4000. get Index
	FindByTypeNPrice ftp1;
	ftp1.compareType = 8;
	ftp1.comparePrice = 4000;

	//price 2000 & itemid 6. get Index
	FindByPriceNId ftp2;
	ftp2.compareId = 6;
	ftp2.comparePrice = 2000;

	//itemId 3 & price 3000 & type 6. get Index
	FindByAll ftp3;
	ftp3.compareType = 6;
	ftp3.compareId = 3;
	ftp3.comparePrice = 3000;

	cout << FindCheckAll(items, 10, ftp1).index << endl;
	cout << FindCheckAll(items, 10, ftp2).index << endl;
	cout << FindCheckAll(items, 10, ftp3).index << endl;


	cout << FindCheckAll<FuncPtr>(items, 10, &Func_Price).index << endl;

	return 0;
}