#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::RectangleShape m_shape{};
    sf::Text m_text{};
public:
    Button(sf::Font font);
    void render(sf::RenderTarget *target);
};