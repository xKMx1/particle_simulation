#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

float dot(const sf::Vector2f &lv, const sf::Vector2f &rv);
sf::Vector2f getNormalVector(sf::Vector2i point);
sf::Vector2f normalise(sf::Vector2f source);
sf::Vector2f reflect(const sf::Vector2f &velocity, const sf::Vector2f &normal);
