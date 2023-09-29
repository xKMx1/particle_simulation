#include "AppObject.h"

AppObject::AppObject(sf::Font* font){
    button.initButton(font);

    int count = 0;
    for(int i = 0; i < 16; i++){                   // we make grid of points 80px80p apart
        for(int j = 0; j < 9; j++){
            std::cout << count << " - (" << i*80 << ", " << j*80 << ") "; 
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

    Particle particle = Particle{temp_radius, temp_position};
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