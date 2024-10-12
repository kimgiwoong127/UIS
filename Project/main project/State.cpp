#include "State.h"

State::State(int a, int b, int h, int av, int d, int he, int spd) {  
	attack1 = a; 
	attack2 = b;
	hp = h; 
	avoid = av; 
	defense = d;
	heal = he; 
	maxhp = h; 
	state = 0;
	speed = spd;
}

//void State::Idle() {
	//state = 0;
//}

int State::gAttack1() const {
	return this->attack1;
}

int State::gAttack2() const{
	return this->attack2;
}

int State::gAvoid() const {
	return this->avoid;
}

int State::gDefense() const {
	return this->defense;
}

int State::gHeal() const {
	return this->heal;
}

/*void State::Attack1() {
	state = 1;
}

void State::Attack2() {
	state = 2;
}

void State::Avoid() {
	state = 3;
}
void State::Defense() {
	state = 4;
}
void State::Heal() {
	state = 5;
}
*/

void State::setSpeed(int spd) { speed = spd; }

int State::gSpeed() { return this->speed; }