#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controller.h"
#include "ITimeController.h"
#include "ProductInfo.h"
#include "ShopAssistant.h"
#include "Storage.h"
#include <vector>
#include <random>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
   // window.setKeyRepeatEnabled(false);
    //window.setVerticalSyncEnabled(true);
       
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dis(0, 1000);


    const int K = 10;// колво товаров
    const int M = 3;
    const int N = 7;

    const int timerInfo = 3;
    Storage storage;
    Manager manager(&storage);
    Provider prov(&storage, &manager);
    Shop shop[M+1];
    for (int i = 0; i < M; i++) {
        shop[i].countOfProductType = K;
    }
    std::vector<Requests>req;

    //std::vector<ITimeController*> timer = {new ProductPack(), new Manager(), new Provider()}; 

    while (window.isOpen())
    {
        window.display();
        for (int i = 0; i < N; i++) {
            prov.newDay();
            manager.newDay();

            for (int shopInfo = 0; shopInfo < M; shopInfo++) {
                int k = dis(rng) % 3;
                if (k != 0) {
                    req.push_back(shop[shopInfo].MakeOrder());
                }
            }
            for (int j = 0; j < req.size(); j++) {
                int waitTime = dis(rng) % 3 + 1;
                bool can = manager.ParseRequest(req[j],waitTime);
                if (can) {
                    OrderInfo order;
                    order.prod = req[j].prod;
                    order.countPack = req[j].countPack;
                    order.cost = req[j].cost;
                    order.waitTime = waitTime;
                    manager.requests[manager.requestsCount] = order;
                    manager.requestsCount++;
                    prov.ParseRequests(order);
                }
            }
            req.clear();

            int profit = 0;
            profit = manager.money;
        
        }
    }

    return 0;
}