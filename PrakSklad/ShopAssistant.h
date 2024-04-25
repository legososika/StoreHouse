#pragma once
#include "ProductInfo.h"
class Requests
{
public:
	ProductPack getProduct();
	void setProduct(ProductPack PP);
	int getCost();
	void setCost(int cost_);
private:
	ProductPack prod;
	int cost;
};

class OrderInfo : public Requests {
public:
	OrderInfo();
	OrderInfo(Requests q, int wTime);
	int getWaitTime();
	void setWaitTime(int waitTime_);
private:
	int waitTime;
};
