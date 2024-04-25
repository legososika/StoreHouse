#pragma once
#include "ITimeController.h"
#include "ShopAssistant.h"
#include <vector>
#include "Storage.h"

class Manager {
public:
	Manager(Storage* st);

	Storage* storage;

	int ParseRequest(std::string name, int waitTime);
	int getMoney();
	void setMoney(int money);
	int getRequestsCount();
	OrderInfo getRequestByIndex(int index);
private:
	int money = 0;
	int requestsCount = 0;
	OrderInfo requests[1000];

};
class Provider : public ITimeController
{
public:
	Provider(Storage* st, Manager* man);

	Storage* storage;
	Manager* manager;

	void ParseRequests(std::string name, int count);
	int getOrdersCount();
	void setOrdersCount(int orderCount_);
	OrderInfo getOrderByIndex(int index);
    void newDay() override;
private:
	int ordersCount = 0;
	OrderInfo orders[1000];
};