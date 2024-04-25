#pragma once
#include "ShopAssistant.h"
#include "Controller.h"
class Shop
{
public:
	Storage* storage;
	std::pair<std::string, int> MakeOrder();
	int getCountOfProductType();
	void setCountOfProductType(int countOfProductType_);
private:
	int countOfProductType;
};

