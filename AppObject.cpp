#include "AppObject.h"

AppObject::AppObject(sf::Font* font){
    button.initButton(font);
}

void AppObject::createNewParticle() {
    float temp_radius {30.f};
    sf::Vector2i temp_position {30, 30};

    Particle particle = Particle{temp_radius, temp_position};
    particle.setVelocity(sf::Vector2f(5.f, 1.f));

    particleList.push_back(particle);
}

void AppObject::updateState(float dt, int screenWidth, int screenHeight,
                            float particleSpeed) {
    for(auto &i: particleList){
        i.update(dt, screenWidth, screenHeight, particleSpeed);
    }
}

void AppObject::render(sf::RenderTarget *target) {
    for(auto &i: particleList){
        i.render(target);
    }
    button.render(target);
}