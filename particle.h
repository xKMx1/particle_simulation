#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Particle {
public:
  Particle(float radius, sf::Vector2i pos);
  void render(sf::RenderTarget *target);
  void update(float dt, const int screenWidth, const int screenHeight,
              const float particleSpeed);
  void handleColision(int screenWidth, int screenHeight);
  void setVelocity(sf::Vector2f vel);

private:
  sf::CircleShape m_shape;
  sf::Vector2f m_position;
  sf::Vector2f m_velocity;
  sf::Vector2f m_acceleration;
};