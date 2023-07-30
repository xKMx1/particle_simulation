#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Particle {
public:
  Particle(float radius, sf::Vector2f pos);
  void render(sf::RenderTarget *target);
  void resolveColision();
  void update(float dt);
  void detectColision();

private:
  sf::CircleShape m_shape;
  sf::Vector2f m_position;
  sf::Vector2f m_velocity;
  sf::Vector2f m_acceleration;
};