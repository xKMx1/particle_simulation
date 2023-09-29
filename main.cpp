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

  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event{};
    bool buttonSwitch = false;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left) {
          buttonSwitch = true;
        }
        break;
      }
    }
    window.clear(sf::Color(255, 255, 255));
    game.listenForButton(buttonSwitch, sf::Mouse::getPosition(window));
    game.scanForCollision();

    game.updateState(frameClock.restart().asSeconds(), WIDTH, HEIGHT, 100.f);
    game.render(&window);

    window.display();
  }
  return 0;
}