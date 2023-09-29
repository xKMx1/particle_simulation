#include "particle.h"

Particle::Particle(float radius, sf::Vector2i pos) {
  m_position.x = static_cast<float>(pos.x);
  m_position.y = static_cast<float>(pos.y);

  m_shape.setRadius(radius);
  m_shape.setOrigin(m_shape.getGlobalBounds().width / 2,
                          m_shape.getGlobalBounds().height / 2);
  m_shape.setFillColor(sf::Color::Green);
  m_shape.setPosition(m_position);
}

void Particle::setVelocity(sf::Vector2f vel) { m_velocity = vel; }

void Particle::render(sf::RenderTarget *target) { target->draw(m_shape); }

void Particle::handleCollision(const int screenWidth, const int screenHeight) {
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

sf::Vector2i Particle::determinePositionSquare(){
	int xCoord{};
	int yCoord{};
	bool returnFlagX = 0;
	bool returnFlagY = 0;
	while (true)
	{
		if(m_position.x > (xCoord + 1) * 80){
			xCoord++;
		}
		else {
			returnFlagX = true;
		}

		if(m_position.y > (yCoord + 1) * 80){
			yCoord++;
		}
		else {
			returnFlagY = true;
		}

		if(returnFlagX && returnFlagY){
			return sf::Vector2i(xCoord, yCoord);
		}
	}
	
}

void Particle::update(float dt, const int screenWidth, const int screenHeight,
                      const float particleSpeed) {
  m_velocity += m_acceleration * dt * particleSpeed;
  m_position += m_velocity * dt * particleSpeed;

  m_shape.setPosition(m_position);

  handleCollision(screenWidth, screenHeight);
}
