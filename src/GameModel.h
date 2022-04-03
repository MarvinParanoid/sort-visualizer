#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <cstdint>
#include <vector>

class GameModel {
  private:
    enum class STATE { IN_PROGRESS, ON_PAUSE };
    static constexpr uint32_t SIZE = 100;
    static constexpr uint32_t MAX_VALUE = SIZE * 1.15;

    std::vector<uint32_t> _elements;
    STATE _state = STATE::ON_PAUSE;
    uint32_t _i, _j;

    void reset() {
        _i = 0;
        _j = 0;
        _state = STATE::ON_PAUSE;
    }
    void init();

  public:
    GameModel();
    void randomize();
    void start() { _state = STATE::IN_PROGRESS; }
    void pause() { _state = STATE::ON_PAUSE; }
    void move();
    const std::vector<uint32_t> &elements() const { return _elements; }
    static uint32_t maxValue() { return MAX_VALUE; }
};

#endif // GAMEMODEL_H
