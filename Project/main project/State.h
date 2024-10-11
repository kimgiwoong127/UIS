#ifndef STATE_H
#define STATE_H

#include<iostream>
using namespace std;

class State {
private:
	int attack1;
	int attack2;
	int avoid;
	int defense;
	int heal;
	int state = 0;
public:
	int hp;
	int maxhp;
	State() {};
	State(int a, int b, int h, int av, int d, int he);
	void Idle();
	int gAttack1();
	int gAttack2();
	int gAvoid();
	int gDefense();
	int gHeal();
	void Attack1();
	void Attack2();
	void Avoid();
	void Defense();
	void Heal();
	int myState();
};
#endif