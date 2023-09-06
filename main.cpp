#include "particle.h"
#include "AppObject.h"

#define PI 3.14159265

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particle Simulation");
  sf::Texture texture;
  sf::Clock frameClock;

  sf::Font fontForButton;
  if (!fontForButton.loadFromFile("font/font.otf")) {
    std::cout << "Font error " << std::endl;
  }

  AppObject game(&fontForButton);
  game.createNewParticle();

  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event{};

    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      }
    }
    window.clear(sf::Color(255, 255, 255));

    game.updateState(frameClock.restart().asSeconds(), WIDTH, HEIGHT, 100.f);
    game.render(&window);

    window.display();
  }
  return 0;
}