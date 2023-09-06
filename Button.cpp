#include "Button.h"

Button::Button(sf::Font font){
    m_shape.setPosition(sf::Vector2f(1000.f, 50.f));
    m_shape.setSize(sf::Vector2f(150.f, 50.f));
    m_shape.setFillColor(sf::Color::Cyan);
    m_shape.setOutlineColor(sf::Color::Black);
    m_shape.setOutlineThickness(1.f);
    
    m_text.setCharacterSize(24);
    m_text.setFont(font);
    m_text.setFillColor(sf::Color::Black);
    m_text.setString("Add particle");
    m_text.setPosition(sf::Vector2f(m_shape.getPosition().x + (m_shape.getSize().x / 2) - (m_text.getGlobalBounds().getSize().x / 2), m_shape.getPosition().y + (m_shape.getSize().y / 2) - (m_text.getGlobalBounds().getSize().y / 2)));
}

void Button::render(sf::RenderTarget *target){
    target->draw(m_shape);
    target->draw(m_text);
}