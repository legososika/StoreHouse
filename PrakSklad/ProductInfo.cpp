#include "ProductInfo.h"

int ProductPack::getCount()
{
    return count;
}

int ProductPack::getExpDate()
{
    return expDate;
}

int ProductPack::getMaxExpDate()
{
    return maxExpDate;
}

int ProductPack::getPrice()
{
    return price;
}

std::string ProductPack::getName()
{
    return name;
}

void ProductPack::setCount(int count_)
{
    count = count_;
}

void ProductPack::setExpDate(int expDate_)
{
    expDate = expDate_;
}

void ProductPack::setMaxExpDate(int maxExpDate_)
{
    maxExpDate = maxExpDate_;
}

void ProductPack::setPrice(int price_)
{
    price = price_;
}

void ProductPack::setName(std::string name_)
{
    name = name_;
}
