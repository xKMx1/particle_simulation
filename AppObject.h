#pragma once
#include <vector>
#include "particle.h"
#include "Button.h"
#include <iostream>

class AppObject {
private:
    Button button{};
    std::vector<Particle> particleList {};
    sf::CircleShape listOfPoints[144];
public:
    AppObject(sf::Font* font);
    void createNewParticle();
    void scanForCollision();
    void listenForButton(bool clickEvent, sf::Vector2i mousePos);
    void updateState(float dt, int screenWidth, int screenHeight,
                     float particleSpeed);
    void render(sf::RenderTarget *target);
};
