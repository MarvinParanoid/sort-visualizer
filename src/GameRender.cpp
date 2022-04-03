#include "GameRender.h"
#include "AssetsManager.h"
#include <iostream>

GameRender::GameRender(GameModel &game) : _game(game) {
    _font = AssetsManager::instance().getFont("MainFont");
    init();
}

bool GameRender::init() {
    setPosition(MARGIN, TITLE_HEIGHT);
    _window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sort visualizer");
    _window.setFramerateLimit(120);
    _text = sf::Text("F2 - Randomize / F3 - Start / F4 - Pause / Esc - Exit", _font, TEXT_HINT_SIZE);
    _text.setFillColor(sf::Color::Cyan);
    _text.setPosition(MARGIN, MARGIN);
    return true;
}

void GameRender::render() {
    _window.clear();
    _window.draw(*this);
    _window.draw(_text);
    _window.display();
}

void GameRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    sf::RectangleShape shape(sf::Vector2f(FIELD_WIDTH, FIELD_HEIGHT));
    shape.setOutlineThickness(THICKNESS);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    target.draw(shape, states);

    auto& elements = _game.elements();
    uint32_t rowCount = elements.size();
    uint32_t maxValue = _game.maxValue();

    float rowWidth = (FIELD_WIDTH) / static_cast<float>(rowCount);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOutlineThickness(0);
    for (uint32_t i = 0; i < elements.size(); i++) {
        float rowHeight = (FIELD_HEIGHT) / static_cast<float>(maxValue) * static_cast<float>(elements[i]);
        shape.setSize(sf::Vector2f(rowWidth, rowHeight));
        shape.setPosition(i * rowWidth, FIELD_HEIGHT - rowHeight);
        target.draw(shape, states);
    }
}