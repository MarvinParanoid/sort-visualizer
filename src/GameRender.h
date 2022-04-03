#ifndef GAMERENDER_H
#define GAMERENDER_H

#include "GameModel.h"
#include <SFML/Graphics.hpp>

class GameRender : public sf::Drawable, public sf::Transformable {
  private:
    static constexpr uint32_t SCREEN_WIDTH = 800;
    static constexpr uint32_t SCREEN_HEIGHT = 600;
    static constexpr uint32_t TITLE_HEIGHT = 40;
    static constexpr uint32_t MARGIN = 10;
    static constexpr uint32_t FIELD_WIDTH = SCREEN_WIDTH - MARGIN * 2;
    static constexpr uint32_t FIELD_HEIGHT = SCREEN_HEIGHT - TITLE_HEIGHT - MARGIN;
    static constexpr uint32_t THICKNESS = 2;
    static constexpr uint32_t TEXT_HINT_SIZE = 18;
    static constexpr uint32_t TEXT_BLOCK_SIZE = 50;

    GameModel &_game;
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Text _text;

  public:
    explicit GameRender(GameModel &game);
    sf::RenderWindow &window() { return _window; };
    bool init();
    void render();

  public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // GAMERENDER_H
