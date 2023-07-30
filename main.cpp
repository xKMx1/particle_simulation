#include "particle.h"

#define PI 3.14159265

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particle Simulation");
  sf::Texture texture;
  sf::Clock frameClock;

  Particle part1(30.f, sf::Vector2i(WIDTH, HEIGHT) / 2);
  part1.setVelocity(sf::Vector2f(5.f, 1.f));

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

    part1.update(frameClock.restart().asSeconds(), WIDTH, HEIGHT, 100.f);

    part1.render(&window);
    window.display();
  }
  return 0;
}