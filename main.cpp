#include "particle.h"

#define PI 3.14159265

int main() {
  sf::RenderWindow window(sf::VideoMode(1200, 700), "Particle Simulation");
  sf::Texture texture;
  sf::Clock frameClock;

  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      }
    }

    window.clear(sf::Color(255, 255, 255));

    window.display();
  }
  return 0;
}