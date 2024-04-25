//
// Created by А ну да on 12.12.2022.
//
#ifndef PRAKSKLAD_BUTTON_H
#define PRAKSKLAD_BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

sf::Vector2f size = {300, 60};
sf::Vector2f size2 = {150, 30};

class UIElement {
public:
    UIElement(sf::Vector2f pos, sf::Color outline, sf::Color fill, sf::Font* font, std::string text) {
        _rect.setPosition(pos);
        _rect.setOutlineThickness(4);
        _rect.setSize(size);
        _rect.setOutlineColor(outline);
        _rect.setFillColor(fill);
        _text.setFont(*font);
        //_text.setCharacterSize(size.x);
        _text.setPosition({pos.x + 10, pos.y + 5});
        _text.setString(text);
        _text.setFillColor(outline);
        _text.setOutlineColor(outline);
    }
    UIElement(sf::Vector2f pos, sf::Color outline, sf::Color fill, sf::Font* font, std::string text, bool k) {
        _rect.setPosition(pos);
        _rect.setOutlineThickness(4);
        _rect.setSize(size2);
        _rect.setOutlineColor(outline);
        _rect.setFillColor(fill);
        _text.setFont(*font);
        //_text.setCharacterSize(size.x);
        _text.setPosition({pos.x + 2, pos.y});
        _text.setString(text);
        _text.setFillColor(outline);
        _text.setOutlineColor(outline);
        _text.setCharacterSize(20);
    }

    virtual void draw(sf::RenderWindow& window) {
        window.draw(_rect);
        window.draw(_text);
    }

    virtual void setOutlineColor(sf::Color color) {
        _rect.setOutlineColor(color);
        _text.setOutlineColor(color);
        _text.setFillColor(color);
    }

    virtual void setFillColor(sf::Color color) {
        _rect.setFillColor(color);
    }

    virtual bool contains(int x, int y) {
       return _rect.getGlobalBounds().contains(x, y);
    }

    virtual int click() const {
        return 0;
    }

    virtual void setString(std::string string) {
        _text.setString(string);
    }

    virtual int getID() const{
        return -1;
    }

protected:
    sf::RectangleShape _rect;
    sf::Text _text;

    //sf::Color _out, _fill;
};

class Button : public UIElement {
public:
    Button(sf::Vector2f pos,sf::Color outline, sf::Color fill, sf::Font* font, std::string text, int id = 0) :
            UIElement(pos, outline, fill, font, text), _id(id) { }

    Button(sf::Vector2f pos,sf::Color outline, sf::Color fill, sf::Font* font, std::string text, int id, bool k) :
            UIElement(pos, outline, fill, font, text, k), _id(id) { }

    int click() const override{
        return 1;
    }

    int getID() const final{
        return _id;
    }

protected:
    int _id;
};

class TextBox : public Button {
public:
    TextBox(sf::Vector2f pos, sf::Color outline, sf::Color fill, sf::Font* font, int id = 0, int limit = 3) :
    Button(pos, outline, fill, font, "", id), _limit(limit) { }

    TextBox(sf::Vector2f pos, sf::Color outline, sf::Color fill, sf::Font* font, int id, bool k, int limit = 3) :
            Button(pos, outline, fill, font, "", id, k), _limit(limit) { }

    int click() const override {
        return 2;
    }

    virtual void addCharacter(char character) {
        std::string string = _text.getString();
        if (string.size() >= _limit) {
            return;
        }
        string.push_back(character);
        _text.setString(string);
    }

    virtual void removeCharacter() {
        std::string string = _text.getString();
        if (string.size() == 0) {
            return;
        }
        string.pop_back();
        _text.setString(string);
    }

    virtual std::string getString() const {
        return _text.getString();
    }

protected:
    int _limit;
};

class TestElement : public UIElement {
public:

private:

};

#endif //PRAKSKLAD_BUTTON_H
