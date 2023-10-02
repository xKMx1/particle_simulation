#include "AppObject.h"

AppObject::AppObject(sf::Font* font){
    button.initButton(font);

    int count = 0;
    for(int i = 0; i < 16; i++){                   // we make grid of points 80px80p apart
        for(int j = 0; j < 9; j++){
            listOfPoints[count].setPosition(i * 80, j * 80);
            listOfPoints[count].setFillColor(sf::Color::Black);
            listOfPoints[count].setRadius(5.f);
            count++;
        }
        std::cout << '\n';
    }
}

void AppObject::createNewParticle() {
    float temp_radius {30.f};
    sf::Vector2i temp_position {30, 30};

    Particle particle = Particle{temp_radius, temp_position, particleList.size()};
    particle.setVelocity(sf::Vector2f(5.f, 1.f));

    particleList.push_back(particle);
}

void AppObject::listenForButton(bool clickEvent, sf::Vector2i mousePos){
    if(button.buttonClicked(clickEvent, mousePos)){
        createNewParticle();
    }
}

void AppObject::updateState(float dt, int screenWidth, int screenHeight,
                            float particleSpeed) {
    for(auto &i: particleList){
        i.update(dt, screenWidth, screenHeight, particleSpeed);
    }
}

void AppObject::scanForCollision(){
    for(auto &ball : particleList){
        for(auto &target : particleList){
            if(ball.getIndex() != target.getIndex()){
                if(doParticlesOverlap(ball.getPosition(), ball.getRadius(), target.getPosition(), target.getRadius())){
                    
                }
            }
        }
    }
}

bool AppObject::doParticlesOverlap(sf::Vector2f particleOnePos, float particleOneRadius, sf::Vector2f particleTwoPos, float particleTwoRadius){
    return abs(((particleTwoPos.x - particleOnePos.x) * (particleTwoPos.x - particleOnePos.x)) + ((particleTwoPos.y - particleOnePos.y) * (particleTwoPos.y - particleOnePos.y))) < ((particleOneRadius + particleTwoRadius) * (particleOneRadius + particleTwoRadius));
}

void AppObject::render(sf::RenderTarget *target) {
    for(auto &i: particleList){
        i.render(target);
    }
    for(int i =0; i < 144; i++){
        target->draw(listOfPoints[i]);
    }
    button.render(target);
}