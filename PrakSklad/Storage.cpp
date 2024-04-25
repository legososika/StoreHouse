#include "Storage.h"
#include "StartSettings.h"
#include <iostream>
void Storage::AddProductToStorage(ProductPack prod, int count)
{
    cells[fillCount].product = prod;
    cells[fillCount].product.setCount(count);
    fillCount++;
}

int Storage::RemoveProductFromStorage(std::string name, int count)
{
    for (int i = 0; i < fillCount; i++) {
        if (cells[i].product.getName() == name && cells[i].product.getExpDate() > 0 && cells[i].product.getCount() >= count) {
            double price = 1.5 * cells[i].product.getPrice() * count;
            double temp = (0.5 - (0.5 * (double)((double)cells[i].product.getExpDate() / (double)cells[i].product.getMaxExpDate())));
            price -= temp * cells[i].product.getPrice() * count;
            cells[i].product.setCount(cells[i].product.getCount() - count);
            if (price / count < 14) {

            }
            std::cout << '\n' << "SELL "<<cells[i].product.getName() << " count " << count << " price " << price << '\n';

            return (int)price;
        }
    }
    return 0;
}

void Storage::newDay()
{
    for (int i = 0; i < fillCount; i++) {
        if (cells[i].product.getCount() > 0)
            cells[i].product.setExpDate(cells[i].product.getExpDate() - 1);
        if (cells[i].product.getExpDate() <= 0) {
            cells[i].product.setCount(0);
        }
    }
}

Cell Storage::getCellByIndex(int index)
{
    return cells[index];
}

int Storage::getFillCount()
{
    return fillCount;
}

void Storage::setFillCount(int fillCount_)
{
    fillCount = fillCount_;
}

int Storage::fillStorage(int productCount, std::vector<ProductInfo> info, bool isStandart)
{       
    int balance = 0;
    if (isStandart) {
        for (int nameID = 0; nameID < productCount; nameID++) {
            std::string name;
            if (nameID == 0) {
                name = "ARBUZ";
//                cells[nameID].product.setExpDate(6);
//                cells[nameID].product.setPrice(75);
            }
            if (nameID == 1) {
                name = "BANANA";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(25);
            }
            if (nameID == 2) {
                name = "APPLE";
//                cells[nameID].product.setExpDate(10);
//                cells[nameID].product.setPrice(15);
            }
            if (nameID == 3) {
                name = "ANANAS";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(50);
            }
            if (nameID == 4) {
                name = "CREAM";
//                cells[nameID].product.setExpDate(6);
//                cells[nameID].product.setPrice(75);
            }
            if (nameID == 5) {
                name = "MILK";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(15);
            }
            if (nameID == 6) {
                name = "CARDBOARD";
//                cells[nameID].product.setExpDate(10);
//                cells[nameID].product.setPrice(25);
            }
            if (nameID == 7) {
                name = "AMMO";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(50);
            }
            if (nameID == 8) {
                name = "AK-47";
//                cells[nameID].product.setExpDate(6);
//                cells[nameID].product.setPrice(75);
            }
            if (nameID == 9) {
                name = "BOMB";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(15);
            }
            if (nameID == 10) {
                name = "ROPE";
//                cells[nameID].product.setExpDate(10);
//                cells[nameID].product.setPrice(25);
            }
            if (nameID == 11) {
                name = "STEW";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(50);
            }
            if (nameID == 12) {
                name = "BEER";
//                cells[nameID].product.setExpDate(6);
//                cells[nameID].product.setPrice(75);
            }
            if (nameID == 13) {
                name = "WINE";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(15);
            }
            if (nameID == 14) {
                name = "VODKA";
//                cells[nameID].product.setExpDate(10);
//                cells[nameID].product.setPrice(25);
            }
            if (nameID == 15) {
                name = "SAKE";
//                cells[nameID].product.setExpDate(8);
//                cells[nameID].product.setPrice(50);
            }
            if (nameID == 16) {
                name = "SECRET PRODUCT";
//                cells[nameID].product.setExpDate(12);
//                cells[nameID].product.setPrice(60);
            }
            cells[nameID].product.setExpDate(info[nameID].expDate);
            cells[nameID].product.setPrice(info[nameID].cost);
            cells[nameID].product.setCount(100);
            cells[nameID].product.setMaxExpDate(cells[nameID].product.getExpDate());
            cells[nameID].product.setName(name);
            balance += cells[nameID].product.getPrice();
        }
        return balance * 100;
    }
    else {
        for (int nameID = 0; nameID < productCount; nameID++) {
            cells[nameID].product.setName(info[nameID].name);
            cells[nameID].product.setExpDate(info[nameID].expDate);
            cells[nameID].product.setMaxExpDate(info[nameID].expDate);
            cells[nameID].product.setPrice(info[nameID].cost);
            cells[nameID].product.setCount(info[nameID].count);

            balance += cells[nameID].product.getPrice();
        }
    }
    return balance * 100;
}

