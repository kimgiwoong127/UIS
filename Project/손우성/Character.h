#ifndef CHARACTER_H
#define CHARACTER_H

#include "State.h"
#include <memory>

using namespace std;

class Character {
public:
    Character(int hp) : hp(hp) {}

    void changeState(unique_ptr<State> newState) {
        if (currentState) {
            currentState->exit();
        }
        currentState = move(newState);
        currentState->enter();
    }

    void update() {
        if (currentState) {
            currentState->update();
        }
    }

    int getHP() const { return hp; }
    void setHP(int newHP) { hp = newHP; }
    unique_ptr<State>& getState() { return currentState; }

private:
    int hp;
    unique_ptr<State> currentState;
};

#endif
