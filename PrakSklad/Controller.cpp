#include "Controller.h"
#include <random>
#include <iostream>
void Provider::ParseRequests(std::string name, int count)
{

	OrderInfo request;

	for (int i = 0; i < storage->getFillCount(); i++) {
		if (storage->getCellByIndex(i).product.getName() == name) {
			ProductPack PP = storage->getCellByIndex(i).product;
			PP.setCount(count);
			PP.setExpDate(PP.getMaxExpDate());
			
			request.setProduct(PP);
			request.setWaitTime(1);

			break;
		}
	}
	orders[ordersCount] = request;
	orders[ordersCount].setCost(count * request.getProduct().getPrice());
	ordersCount++;
}

int Provider::getOrdersCount()
{
	return ordersCount;
}

void Provider::setOrdersCount(int ordersCount_)
{
	ordersCount = ordersCount_;
}

OrderInfo Provider::getOrderByIndex(int index)
{
	return orders[index];
}

void Provider::newDay()
{
	for (int i = 0; i < ordersCount; i++) {
		orders[i].setWaitTime(orders[i].getWaitTime() - 1);
		if (orders[i].getWaitTime() == 0) {
			storage->AddProductToStorage(orders[i].getProduct(), orders[i].getProduct().getCount());

			manager->setMoney(manager->getMoney()-orders[i].getCost());

			std::cout << '\n' << "BUY " << orders[i].getProduct().getName() << " count " << orders[i].getProduct().getCount() << " price " << orders[i].getProduct().getCount() << '\n';
		}
	}
}

Provider::Provider(Storage* st, Manager* man)
{
	storage = st;
	manager = man;
}

Manager::Manager(Storage* st)
{
	storage = st;
}

int Manager::ParseRequest(std::string name, int count)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<> dis(0, 3);
	if (dis(rng) != 0) {
		int selectIndex = 0;
		int maxCount = -1;
		for (int i = 0; i < storage->getFillCount(); i++) {
			if (storage->getCellByIndex(i).product.getName() == name) {
				if (storage->getCellByIndex(i).product.getCount() >= maxCount) {
					maxCount = storage->getCellByIndex(i).product.getCount();
					selectIndex = i;
				}
			}
		}
				int currentCount = storage->getCellByIndex(selectIndex).product.getCount();
				if (currentCount - count >= 30) {
					return 0; // прин заказ
				}
				if (currentCount - count > 0 && currentCount - count < 30) {
					return 1; // прин но заказ 50 мандаринов
				}
				if (currentCount - count <= 0) {
					return 2;
				}
			}
	return 9999;
}

int Manager::getMoney()
{
	return money;
}

void Manager::setMoney(int money_)
{
	money = money_;
}

int Manager::getRequestsCount()
{
	return requestsCount;
}

OrderInfo Manager::getRequestByIndex(int index)
{
	return requests[index];
}
