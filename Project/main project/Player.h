#ifndef PLAYER_H
#define PLAYER_H

#include "State.h"
using namespace std;

class Player{
private:
	State player;
public:
	Player(int a, int b, int h, int av, int d, int he,int spd);
	void act1();
	void act2();
	void setSpeed(int spd) { player.setSpeed(spd); }
	int gHP() { return player.hp; }
	int max() { return player.maxhp; }
	int gSpeed() { return player.gSpeed(); }
	void StateChange(int a) { player.setState(a); };
	int PlayerState() const { return player.myState(); };
	int gAttack1() const { return player.gAttack1(); };
	int gAttack2() const { return player.gAttack2(); };
	int gAvoid() const { return player.gAvoid(); };
	int gDefense() const { return player.gDefense(); };
	int gHeal() const { return player.gHeal(); };
	void sHP(int a) { player.hp = a; };
};
#endif