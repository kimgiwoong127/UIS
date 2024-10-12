#ifndef MOB_H
#define MOB_H

#include "Player.h"
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Mob {
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
	State mob;
public:
	Mob() {};
	Mob(int a, int b, int h, int av, int d, int he,int spd);
	int gHP() { return mob.hp; };
	int max() { return mob.maxhp; }
	void turn1(Player& p);
	void turn2(Player& p);
	void setSpeed(int spd) { mob.setSpeed(spd); }
	int gSpeed() { return mob.gSpeed(); }
	int gAttack1() const { return mob.gAttack1(); };
	int gAttack2() const { return mob.gAttack2(); };
	int gAvoid() const { return mob.gAvoid(); };
	int gDefense() const { return mob.gDefense(); };
	int gHeal() const { return mob.gHeal(); };
	void sHP(int a) { mob.hp = a; };
};
#endif