#include "particle.h"

Particle::Particle(float radius, sf::Vector2i pos) {
  this->m_position.x = pos.x;
  this->m_position.y = pos.y;

  this->m_shape.setRadius(radius);
  this->m_shape.setOrigin(m_shape.getGlobalBounds().width / 2,
                          m_shape.getGlobalBounds().height / 2);
  this->m_shape.setFillColor(sf::Color::Green);
  this->m_shape.setPosition(m_position);
}

void Particle::setVelocity(sf::Vector2f vel) { m_velocity = vel; }

void Particle::render(sf::RenderTarget *target) { target->draw(this->m_shape); }

void Particle::handleColision(const int screenWidth, const int screenHeight) {
  if (m_position.x - m_shape.getRadius() < 0) {
    m_velocity.x *= -1;
  }
  if (m_position.x + m_shape.getRadius() > screenWidth) {
    m_velocity.x *= -1;
  }
  if (m_position.y - m_shape.getRadius() < 0) {
    m_velocity.y *= -1;
  }
  if (m_position.y + m_shape.getRadius() > screenHeight) {
    m_velocity.y *= -1;
  }
}

void Particle::update(float dt, const int screenWidth, const int screenHeight,
                      const float particleSpeed) {
  this->m_velocity += this->m_acceleration * dt * particleSpeed;
  this->m_position += this->m_velocity * dt * particleSpeed;

  this->m_shape.setPosition(m_position);

  this->handleColision(screenWidth, screenHeight);
}
