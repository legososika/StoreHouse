#pragma once
#include "ProductInfo.h"
#include "StartSettings.h"
#include "ITimeController.h"
#include <vector>
class Cell {
public:
	ProductPack product;
};
class Storage : ITimeController
{
public:
	void AddProductToStorage(ProductPack prod, int count);
	int RemoveProductFromStorage(std::string name, int count);
	int fillStorage(int prodCount, std::vector<ProductInfo> info, bool isStandart);   
	void newDay() override;
	Cell getCellByIndex(int index);
	int getFillCount();
	void setFillCount(int fillCount_);
private:
	Cell cells[1000];
	int fillCount = 0;
	
};

