#include "GameController.h"

void GameController::run() {
    sf::Event event;
    while (_render.window().isOpen()) {
        while (_render.window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _render.window().close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    _render.window().close();
                } else if (event.key.code == sf::Keyboard::F2) {
                    _game.randomize();
                } else if (event.key.code == sf::Keyboard::F3) {
                    _game.start();
                } else if (event.key.code == sf::Keyboard::F4) {
                    _game.pause();
                }
            }
        }
        _game.move();
        _render.render();
    }
}