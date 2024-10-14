#ifndef PLAYER_H
#define PLAYER_H

#include "Mob.h"
#include <string>

using namespace std;


class Player{
private:
	int attack1W[3] = { 1,1,1 };
	int attack1L[3] = { 1,1,1 };
	int attack2W[3] = { 1,1,1 };
	int attack2L[3] = { 1,1,1 };

	int DefW[2] = { 1,1 };
	int DefL[2] = { 1,1 };
	int AvoW[2] = { 1,1 };
	int AvoL[2] = { 1,1 };
	int HealW[2] = { 1,1 };
	int HealL[2] = { 1,1 };
	State player;
public:
	Player(int a, int b, int h, int av, int d, int he, int spd);
	void turn1(Mob& m);
	void turn2(Mob& m);
	int Select(int turn);
	void setSpeed(int spd) { player.setSpeed(spd); }
	int gHP() { return player.hp; }
	int max() { return player.maxhp; }
	int gSpeed() { return player.gSpeed(); }
	int gAttack1() const { return player.gAttack1(); };
	int gAttack2() const { return player.gAttack2(); };
	int gAvoid() const { return player.gAvoid(); };
	int gDefense() const { return player.gDefense(); };
	int gHeal() const { return player.gHeal(); };
	void sHP(int a) { player.hp = a; };
};
#endif