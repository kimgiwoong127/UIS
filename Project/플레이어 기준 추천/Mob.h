#ifndef MOB_H
#define MOB_H

#include "State.h"
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Mob {
private:
	State mob;
public:
	Mob() {};
	Mob(int a, int b, int h, int av, int d, int he, int spd);
	int gHP() { return mob.hp; };
	int max() { return mob.maxhp; }
	void act1();
	void act2();
	void setSpeed(int spd) { mob.setSpeed(spd); }
	void StateChange(int a) { mob.setState(a); };
	int PlayerState() const { return mob.myState(); };
	int gSpeed() { return mob.gSpeed(); }
	int gAttack1() const { return mob.gAttack1(); };
	int gAttack2() const { return mob.gAttack2(); };
	int gAvoid() const { return mob.gAvoid(); };
	int gDefense() const { return mob.gDefense(); };
	int gHeal() const { return mob.gHeal(); };
	void sHP(int a) { mob.hp = a; };
};
#endif