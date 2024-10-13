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
	int speed=0;
	int state;
public:
	int hp;
	int maxhp;
	State() {};
	State(int a, int b, int h, int av, int d, int he, int spd);
	int gAttack1() const;
	int gAttack2() const;
	int gAvoid() const;
	int gDefense() const;
	int gHeal() const;
	/*void Attack1();
	void Attack2();
	void Avoid();
	void Defense();
	void Heal();*/
	void setSpeed(int spd); // 속도 설정
	int gSpeed() ;
	void setState(int a) {
		state = a;
	}
	int myState() const {
		return this->state;
	}
};
#endif