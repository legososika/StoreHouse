#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>

#include "Button.h"
#include "ItemDescription.h"
#include "Controller.h"
#include "ITimeController.h"
#include "ProductInfo.h"
#include "ShopAssistant.h"
#include "Storage.h"
#include "Shop.h"

sf::Font* font;

int action_marker = 0;

sf::Color outline_color = sf::Color::Cyan, fill_color = sf::Color(50, 50, 50, 190),
selected_color = sf::Color::Magenta, lean_over_color = sf::Color::Green, background_color(30, 30, 30);

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<> dis(0, 1000);

inline void MakeOne(std::vector<UIElement*>& uielems, sf::Vector2f pos, int type, int id, std::string string = "",
                      int limit = 3) {
    uielems.push_back(nullptr);
    if (type == 0) {
        *uielems.rbegin() = new UIElement(pos , outline_color, fill_color, font, string);
    }
    if (type == 1) {
        *uielems.rbegin() = new Button(pos , outline_color, fill_color, font, string, id);
    }
    if (type == 2) {
        *uielems.rbegin() = new TextBox(pos , outline_color, fill_color, font, id, limit);
    }
}
inline void MakeOne(std::vector<UIElement*>& uielems, sf::Vector2f pos, bool k, int id, std::string string = "") {
    uielems.push_back(nullptr);
    if (id == -1) {
        *uielems.rbegin() = new UIElement(pos, outline_color, fill_color, font, string, true);
        return;
    }

    *uielems.rbegin() = new TextBox(pos , outline_color, fill_color, font, id, k);
    uielems[uielems.size() - 1]->setString(string);
}

inline void BombText(std::vector<sf::Text>& text, sf::Vector2f pos, std::string string, int size = 50) {
    text.push_back(sf::Text(string, *font));

    text.rbegin()->setString(string);
    text.rbegin()->setFont(*font);
    text.rbegin()->setPosition(pos);
    text.rbegin()->setOutlineColor(outline_color);
    text.rbegin()->setFillColor(outline_color);
    text.rbegin()->setCharacterSize(size);
}

inline void MakeItemDescription(std::vector<ItemDescription>& items, std::string name, int date, int amount,
                                int price) {
    sf::Vector2f ref_point = {20, 100};
    int pos = items.size();
    items.push_back(ItemDescription(name, date, amount, price, ref_point, pos, font, outline_color));
}

inline void MakeItemDescription(std::vector<ItemDescription>& items, bool blank) {
    sf::Vector2f ref_point = {20, 100};
    int pos = items.size();
    items.push_back(ItemDescription(true, ref_point, pos, font, outline_color));
}

void ClearElems(std::vector<UIElement*>& uielems) {
    for (auto elem : uielems) {
        UIElement* to_delete = elem;
        elem = nullptr;
        delete to_delete;
    }
    uielems.clear();
}

void ClearTexts(std::vector<sf::Text>& text) {
    text.clear();
}

void CreateElems1(std::vector<UIElement*>& uielems) {
    MakeOne(uielems, {100, 200}, 0, 0, "Number of days");

    MakeOne(uielems, {100, 400}, 0, 0, "Number of types");

    MakeOne(uielems, {100, 600}, 0, 0, "Number of shops");

    MakeOne(uielems, {600, 200}, 2, 1);

    MakeOne(uielems, {600, 400}, 2, 2);

    MakeOne(uielems, {600, 600}, 2, 3);

    MakeOne(uielems, {360, 850}, 1, 4, "NEXT");

}

void CreateTexts1(std::vector<sf::Text>& text) {
    BombText(text, {280, 70}, "Choose parameters", 50);
}

void CreateElems2(std::vector<UIElement*>& uielems, int k) {
    //MakeOne(uielems, {100, 100}, 0, 0, "Biba");

    MakeOne(uielems, {360, 850}, 1, 5, "START");

    for (int i = 0; i < k; ++i) {

        std::string name, exp_date, price;
        if (i == 0) {
            name = "ARBUZ";
            exp_date = "6";
            price = "75";
        }
        if (i == 1) {
            name = "BANANA";
            exp_date = "8";
            price = "25";
        }
        if (i == 2) {
            name = "APPLE";
            exp_date = "10";
            price = "15";
        }
        if (i == 3) {
            name = "ANANAS";
            exp_date = "8";
            price = "50";
        }
        if (i == 4) {
            name = "CREAM";
            exp_date = "6";
            price = "75";
        }
        if (i == 5) {
            name = "MILK";
            exp_date = "8";
            price = "15";
        }
        if (i == 6) {
            name = "CARDBOARD";
            exp_date = "10";
            price = "25";
        }
        if (i == 7) {
            name = "AMMO";
            exp_date = "8";
            price = "50";
        }
        if (i == 8) {
            name = "AK-47";
            exp_date = "6";
            price = "75";
        }
        if (i == 9) {
            name = "BOMB";
            exp_date = "8";
            price = "15";
        }
        if (i == 10) {
            name = "ROPE";
            exp_date = "10";
            price = "25";
        }
        if (i == 11) {
            name = "STEW";
            exp_date = "8";
            price = "50";
        }
        if (i == 12) {
            name = "BEER";
            exp_date = "6";
            price = "75";
        }
        if (i == 13) {
            name = "WINE";
            exp_date = "8";
            price = "15";
        }
        if (i == 14) {
            name = "VODKA";
            exp_date = "10";
            price = "25";
        }
        if (i == 15) {
            name = "SAKE";
            exp_date = "8";
            price = "50";
        }
        if (i == 16) {
            name = "SECRET PRODUCT";
            exp_date = "12";
            price = "60";
        }

        MakeOne(uielems, {100, static_cast<float>(100 + 40 * i)}, true, -1, name);

        MakeOne(uielems, {400, static_cast<float>(100 + 40 * i)}, true, 40 + i, price);

        MakeOne(uielems, {700, static_cast<float>(100 + 40 * i)}, true, 60 + i, exp_date);
    }
}

void CreateTexts2(std::vector<sf::Text>& text) {
    BombText(text, {100, 10}, "NAME");

    BombText(text, {400, 10}, "PRICE");

    BombText(text, {680, 10}, "EXP DATE");
}

void CreateElems3(std::vector<UIElement*>& uielems) {
    MakeOne(uielems, {100, 850}, 1, 6, "RESTART");

    MakeOne(uielems, {500, 850}, 1, 7, "PAUSE");
}

void CreateTexts3(std::vector<sf::Text>& text) {
    BombText(text, {30, 25}, "DAY ");

    BombText(text, {350, 25}, "PROFIT");

    BombText(text, {150, 25}, "0");

    BombText(text, {530, 25}, "0");
}

void UpdateInfo(std::vector<ItemDescription>& items, Storage& storage, int prok) {

    items.clear();
    MakeItemDescription(items, true);
    int j = 0;
    for (int i = prok; i < storage.getFillCount(); ++i) {
        if (j > 24) {
            break;
        }
        ProductPack products = storage.getCellByIndex(i).product;
        if (products.getExpDate() <= 0 || products.getCount() <= 0) {
            continue;
        }
        MakeItemDescription(items, products.getName(), products.getExpDate(), products.getCount(),
                            products.getPrice());
        ++j;
    }
}

void ProcessMouseMovement(int x, int y, std::vector<UIElement*>& uielems, TextBox*& selected_typebox, bool stop) {
    for (auto a : uielems) {
        int type = -1;
        if (a == selected_typebox) {
            continue;
        }
        a->setOutlineColor(outline_color);
        if (a->contains(x, y) || a->click() == 1 && dynamic_cast<Button*>(a)->getID() == 7 && stop) {
            type = a->click();
        }
        if (type == -1) {
            continue;
        }
        if (type == 0) {
            continue;
        }
        if (type == 1) {
            if (stop && dynamic_cast<Button*>(a)->getID() == 7) {
                a->setOutlineColor(selected_color);
                continue;
            }
        }
        a->setOutlineColor(lean_over_color);
    }
}

void ProcessClick(int x, int y, std::vector<UIElement*>& uielems, TextBox*& selected_typebox) {
    selected_typebox = nullptr;
    for (auto a : uielems) {
        int type = -1;
        a->setOutlineColor(outline_color);
        if (a->contains(x, y)) {
            type = a->click();
        }
        std::cout << "Click " << type << "\n";
        if (type == -1) {
            continue;
        }
        if (type == 0) {
            continue;
        }
        if (type == 1) {
            a->setOutlineColor(selected_color);
            action_marker = dynamic_cast<Button*>(a)->getID();
        }
        if (type == 2) {
            selected_typebox = dynamic_cast<TextBox*>(a);
            a->setOutlineColor(selected_color);
        }
    }
}

void ProcessText(sf::Event& event, TextBox*& selected_typebox) {
    if (selected_typebox == nullptr) {
        return;
    }
    if (event.text.unicode >= '0' && event.text.unicode <= '9') {
        selected_typebox->addCharacter(event.text.unicode);
    }
}

void DeleteCharacter(TextBox*& selected_typebox) {
    if (selected_typebox == nullptr) {
        return;
    }
    selected_typebox->removeCharacter();
}

bool GetInfo(std::vector<UIElement*>& uielems, int& n, int& k, int& m) {
    std::string s;
    s = dynamic_cast<TextBox*>(uielems[3])->getString();
    if (s == "") {
        return false;
    }
    n = std::stoi(s);
    s = dynamic_cast<TextBox*>(uielems[4])->getString();
    if (s == "") {
        return false;
    }
    k = std::stoi(s);
    s = dynamic_cast<TextBox*>(uielems[5])->getString();
    if (s == "") {
        return false;
    }
    m = std::stoi(s);
    return n && k && m;
}

void GetInfo2(std::vector<UIElement*>& uielems, std::vector<ProductInfo>& info) {
    for (auto elem : uielems) {
        ProductInfo blank;
        if (elem->getID() / 40 == 1) {
            info[elem->getID() - 40].cost = std::stoi(dynamic_cast<TextBox*>(elem)->getString());
        }
        if (elem->getID() / 60 == 1) {
            info[elem->getID() - 60].expDate = std::stoi(dynamic_cast<TextBox*>(elem)->getString());
        }
    }
}

void DayUpdate(std::vector<sf::Text>& text, int& day, int& profit, int& n, int& k, int& m,
               Storage& storage, Manager& manager, Provider& prov, std::vector<Requests>& req,
               std::vector<Shop>& shop) {
    ++day;
    text[2].setString(std::to_string(day));
    text[3].setString(std::to_string(profit));

    prov.newDay();
    storage.newDay();

    std::vector<std::pair<std::string, int>> orders;
    for (int shopInfo = 0; shopInfo < m; shopInfo++) {
        std::pair<std::string, int> orderInfo = shop[shopInfo].MakeOrder();
        std::string name = orderInfo.first;
        int count = orderInfo.second;
        orders.push_back(make_pair(name, count));
    }

    for (int j = 0; j < orders.size(); j++) {
        int state = manager.ParseRequest(orders[j].first,orders[j].second);
        if (state == 0) {
            int money = storage.RemoveProductFromStorage(orders[j].first,orders[j].second);
            manager.setMoney(manager.getMoney()+money);
        }
        if (state == 1) {
            int money = storage.RemoveProductFromStorage(orders[j].first, orders[j].second);
            manager.setMoney(manager.getMoney() + money);
            prov.ParseRequests(orders[j].first, 50);
        }
        if (state == 2) {
            prov.ParseRequests(orders[j].first,75);
        }
    }

    profit = manager.getMoney();
}

int main() {
    font = new sf::Font;
    int prok = 0;
    if (!font->loadFromFile("/Users/Neponel/CLionProjects/PrakSklad/UbuntuMono-Regular.ttf")) {
        std::cout << "Failed loading font";
        throw;
    }
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "window");

    std::vector<UIElement*> uielems;
    std::vector<sf::Text> text_arr;
    std::vector<ItemDescription> items;

    CreateElems1(uielems);
    CreateTexts1(text_arr);

    sf::RectangleShape content_box({960, 700});
    content_box.setFillColor(fill_color);
    content_box.setPosition(20, 100);

    TextBox* selected_typebox = nullptr;

    bool simulation_start = false;
    bool stop = false;

    int n = 0, k = 0, m = 0;
    int day = 0, profit = 0;

    sf::Clock clock;

    Storage storage;
    Manager manager(&storage);
    Provider prov(&storage, &manager);
    std::vector<Shop> shop(m + 1);
    storage.setFillCount(0);
    std::vector<Requests> req;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                ProcessMouseMovement(event.mouseMove.x, event.mouseMove.y, uielems, selected_typebox, stop);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                ProcessClick(event.mouseButton.x, event.mouseButton.y, uielems, selected_typebox);
            }
            if (event.type == sf::Event::TextEntered) {
                ProcessText(event, selected_typebox);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace) {
                DeleteCharacter(selected_typebox);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                if (items.size() - prok > 20) {
                    ++prok;
                    UpdateInfo(items, storage, prok);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                if (prok > 0) {
                    --prok;
                    UpdateInfo(items, storage, prok);
                }
            }
        }

        window.clear(background_color);

        if (simulation_start) {
            window.draw(content_box);
            for (int j = 0; j < items.size(); ++j) {
                if (j >= 23) {
                    break;
                }
                items[j].draw(window);
            }
        }

        for (auto a : uielems) {
            a->draw(window);
        }
        for (auto a : text_arr) {
            window.draw(a);
        }

        window.display();

        if (simulation_start && clock.getElapsedTime().asSeconds() >= 1) {
            clock.restart();
            if (day < n && !stop) {
                DayUpdate(text_arr, day, profit, n, k, m, storage, manager, prov, req,
                          shop);
                UpdateInfo(items, storage, prok);
            }
            if (day >= n) {
                //action_marker = 4;
            }


        }

        if (action_marker == 4) {
            if (!GetInfo(uielems, n, k, m)) {
                action_marker = 0;
            }
            else {
                ClearElems(uielems);
                ClearTexts(text_arr);
                CreateElems2(uielems, k);
                CreateTexts2(text_arr);
                action_marker = 0;
            }
        }
        if (action_marker == 5) {
            std::vector<ProductInfo> info;
            info.resize(k);

            GetInfo2(uielems, info);

            ClearElems(uielems);
            ClearTexts(text_arr);
            CreateElems3(uielems);
            CreateTexts3(text_arr);
            simulation_start = true;

            int startBalance = storage.fillStorage(k, info, true);

            //profit -= startBalance;

            storage.setFillCount(k);

            shop.resize(m + 1);
            for (int i = 0; i < m; ++i) {
                shop[i].setCountOfProductType(k);
                shop[i].storage = &storage;
            }
            UpdateInfo(items, storage, prok);
            clock.restart();

            action_marker = 0;
        }
        if (action_marker == 6) {
            //prok = 0;
            ClearElems(uielems);
            ClearTexts(text_arr);
            CreateElems1(uielems);
            CreateTexts1(text_arr);
            stop = false;
            simulation_start = false;
            day = 0;
            prok = 0;
            //MakeItemDescription(items, "BLANK_ITEM", 1, 1);
            action_marker = 0;
        }
        if (action_marker == 7) {
            stop = !stop;
            action_marker = 0;
        }
    }

    return 0;
}
