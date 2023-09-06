#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::RectangleShape m_shape{};
    sf::Text m_text{};
public:
    Button() = default;
    void initButton(sf::Font* font);
    bool buttonClicked(bool clickEvent, sf::Vector2i mousePosition);
    void render(sf::RenderTarget *target);
};