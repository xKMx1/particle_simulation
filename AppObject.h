#pragma once
#include <vector>
#include "particle.h"
#include "Button.h"
#include <iostream>

class AppObject {
private:
    Button button{};
    std::vector<Particle> particleList {};
public:
    AppObject(sf::Font* font);
    void createNewParticle();
    void updateState(float dt, int screenWidth, int screenHeight,
                     float particleSpeed);
    void render(sf::RenderTarget *target);
};
