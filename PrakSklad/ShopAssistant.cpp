#include "ShopAssistant.h"

OrderInfo::OrderInfo()
{
}

OrderInfo::OrderInfo(Requests q, int wTime)
{
	setProduct(q.getProduct());
	setCost(q.getCost());
	waitTime = wTime;
}

int OrderInfo::getWaitTime()
{
	return waitTime;
}

void OrderInfo::setWaitTime(int waitTime_)
{
	waitTime = waitTime_;
}

ProductPack Requests::getProduct()
{
	return prod;
}

void Requests::setProduct(ProductPack PP)
{
	prod = PP;
}

int Requests::getCost()
{
	return cost;
}

void Requests::setCost(int cost_)
{
	cost = cost_;
}
