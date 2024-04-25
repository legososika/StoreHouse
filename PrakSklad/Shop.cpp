#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#include <cfenv>
#include "Shop.h"

std::pair<std::string, int> Shop::MakeOrder()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dis(0, 1000);
    std::string name;

    //chosse number of thing
    int countLessExpDate = 0;
    for (int i = 0; i < storage->getFillCount(); i++) {
        ProductPack tempPP = storage->getCellByIndex(i).product;
        if ((double)tempPP.getExpDate() / (double)tempPP.getMaxExpDate() <= 0.5) {
            countLessExpDate+=2;
        }
        else {
            countLessExpDate++;
        }
    }
    countLessExpDate = countOfProductType;
    double temp = 0.5 / (double)countLessExpDate;
    double tempConst1 = fmod((double)dis(rng), 2.22);
    double randomChoise = fmod(tempConst1,0.5);
    int num = (int)(randomChoise / temp);
    int index = 0;
    for (int i = 0; i < storage->getFillCount(); i++) {
        ProductPack tempPP = storage->getCellByIndex(i).product;
        if ((double)tempPP.getExpDate() / (double)tempPP.getMaxExpDate() <= 0.5) {
            if (num == i || num == i + 1) {
                index = i;
                break;
            }
            else {
                i++;
            }
        }
        else {
            if (num == i) {
                index = i;
                break;
            }
        }

    }
    //chosse number of thing    

    if (index == 0) {
        name = "ARBUZ";
    }
    if (index == 1) {
        name = "BANANA";
    }
    if (index == 2) {
        name = "APPLE";
    }
    if (index == 3) {
        name = "ANANAS";
    }
    if (index == 4) {
        name = "ARBUZ1";
    }
    if (index == 5) {
        name = "BANANA1";
    }
    if (index == 6) {
        name = "APPLE1";
    }
    if (index == 7) {
        name = "ANANAS1";
    }
    if (index == 8) {
        name = "ARBUZ2";
    }
    if (index == 9) {
        name = "BANANA2";
    }
    if (index == 10) {
        name = "APPLE2";
    }
    if (index == 11) {
        name = "ANANAS2";
    }
    if (index == 12) {
        name = "ARBUZ3";
    }
    if (index == 13) {
        name = "BANANA3";
    }
    if (index == 14) {
        name = "APPLE3";
    }
    if (index == 15) {
        name = "ANANAS3";
    }
    if (index == 16) {
        name = "SECRETPRODUCT";
    }
    int count = dis(dev) % 50 + 10;

    return std::make_pair(name, count);
}

int Shop::getCountOfProductType()
{
    return countOfProductType;
}

void Shop::setCountOfProductType(int countOfProductType_)
{
    countOfProductType = countOfProductType_;
}
