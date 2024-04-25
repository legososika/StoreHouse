//
// Created by А ну да on 18.12.2022.
//

#ifndef PRAKSKLAD_ITEMDESCRIPTION_H
#define PRAKSKLAD_ITEMDESCRIPTION_H

#include <SFML/Graphics.hpp>
#include <string>

class ItemDescription {
public:
    ItemDescription(std::string& name, int date, int amount, int price, sf::Vector2f ref_point, int pos, sf::Font* font,
                    sf::Color color) {
        int space_v = 30;
        _name.setFont(*font);
        _name.setString(name);
        _name.setPosition(ref_point.x + 1, ref_point.y + pos * space_v);
        _name.setFillColor(color);
        _name.setCharacterSize(25);

        _date.setFont(*font);
        _date.setString(std::to_string(date));
        _date.setPosition(ref_point.x + 300, ref_point.y + pos * space_v);
        _date.setFillColor(color);
        _date.setCharacterSize(25);

        _amount.setFont(*font);
        _amount.setString(std::to_string(amount));
        _amount.setPosition(ref_point.x + 500, ref_point.y + pos * space_v);
        _amount.setFillColor(color);
        _amount.setCharacterSize(25);

        _price.setFont(*font);
        _price.setString(std::to_string(price));
        _price.setPosition(ref_point.x + 750, ref_point.y + pos * space_v);
        _price.setFillColor(color);
        _price.setCharacterSize(25);
    }

    ItemDescription(bool blank, sf::Vector2f ref_point, int pos, sf::Font* font, sf::Color color) {
        int space_v = 30;
        _name.setFont(*font);
        _name.setString("NAME");
        _name.setPosition(ref_point.x + 1, ref_point.y + pos * space_v);
        _name.setFillColor(color);
        _name.setCharacterSize(25);

        _date.setFont(*font);
        _date.setString("EXP DATE");
        _date.setPosition(ref_point.x + 300, ref_point.y + pos * space_v);
        _date.setFillColor(color);
        _date.setCharacterSize(25);

        _amount.setFont(*font);
        _amount.setString("AMOUNT");
        _amount.setPosition(ref_point.x + 500, ref_point.y + pos * space_v);
        _amount.setFillColor(color);
        _amount.setCharacterSize(25);

        _price.setFont(*font);
        _price.setString("PRICE");
        _price.setPosition(ref_point.x + 750, ref_point.y + pos * space_v);
        _price.setFillColor(color);
        _price.setCharacterSize(25);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(_name);
        window.draw(_date);
        window.draw(_amount);
        window.draw(_price);
    }

    void setAmount(int amount) {
        _amount.setString(std::to_string(amount));
    }
private:
    sf::Text _name, _date, _amount, _price;
};

#endif //PRAKSKLAD_ITEMDESCRIPTION_H
