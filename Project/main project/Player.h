#ifndef PLAYER_H
#define PLAYER_H

#include "State.h"
using namespace std;

class Player :public State {
private:
	State player;
public:
	Player(int a, int b, int h, int av, int d, int he);
	void act1();
	void act2();
};

Player::Player(int a, int b, int h, int av, int d, int he) {
	player = State(a, b, h, av, d, he);
}
#endif