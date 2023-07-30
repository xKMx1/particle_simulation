#include "particle.h"

Particle::Particle(float radius, sf::Vector2f pos) {
  this->m_position = pos;

  this->m_shape.setRadius(radius);
  this->m_shape.setOrigin(m_shape.getGlobalBounds().width / 2,
                          m_shape.getGlobalBounds().height / 2);
  this->m_shape.setFillColor(sf::Color::Green);
  this->m_shape.setPosition(m_position);
}

void Particle::render(sf::RenderTarget *target) { target->draw(this->m_shape); }