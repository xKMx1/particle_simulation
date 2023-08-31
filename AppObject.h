#pragma once
#include <vector>
#include "particle.h"

class AppObject {
private:
    std::vector<Particle> particleList {};
public:
    AppObject();
    void createNewParticle();
    void updateState(float dt, int screenWidth, int screenHeight,
                     float particleSpeed);
    void render(sf::RenderTarget *target);
};
