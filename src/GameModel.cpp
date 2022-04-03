#include "GameModel.h"
#include "iostream"
#include <algorithm>
#include <random>

GameModel::GameModel() : _elements(SIZE) { init(); }

void GameModel::init() {
    for (uint32_t i = 0; i < SIZE; i++) {
        _elements[i] = i + 1;
    }
    reset();
}

void GameModel::move() {
    if (_state == STATE::IN_PROGRESS) {
        if (_i < _elements.size() - 1) {
            if (_j < _elements.size() - 1 - _i) {
                if (_elements[_j] > _elements[_j + 1]) {
                    std::swap(_elements[_j], _elements[_j + 1]);
                }
                ++_j;
            } else {
                ++_i;
                _j = 0;
            }
        } else {
            reset();
        }
    }
}

void GameModel::randomize() {
    if (_state == STATE::ON_PAUSE) {
        std::shuffle(_elements.begin(), _elements.end(), std::mt19937(std::random_device()()));
    }
}
