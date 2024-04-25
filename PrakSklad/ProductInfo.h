#pragma once
#include "ITimeController.h"
#include <string>
class ProductPack {

public:
    int getCount();
    int getExpDate();
    int getMaxExpDate();
    int getPrice();
    std::string getName();
    void setCount(int count_);
    void setExpDate(int expDate_);
    void setMaxExpDate(int maxExpDate_);
    void setPrice(int price_);
    void setName(std::string name_);

private:
    int count;
    std::string name;
    int expDate;
    int maxExpDate;
    int price = 0;
};

