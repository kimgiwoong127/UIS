#ifndef PLAYER_H
#define PLAYER_H

#include "State.h"

class Player : public State {
public:
    Player(int a, int b, int h, int av, int d, int he, int spd);
    void act1();
    void act2();
};

#endif
