#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Particle {
public:
  Particle(float radius, sf::Vector2i pos, int index);
  void render(sf::RenderTarget *target);
  void update(float dt, int screenWidth, int screenHeight,
              float particleSpeed);
  void handleCollision(int screenWidth, int screenHeight);
  sf::Vector2i determinePositionSquare();
  void setVelocity(sf::Vector2f vel);
  int getIndex();
  sf::Vector2f getPosition();
  float getRadius();

private:
  int m_index{};
  sf::CircleShape m_shape {};
  sf::Vector2f m_position {};
  sf::Vector2f m_velocity {};
  sf::Vector2f m_acceleration {};
};