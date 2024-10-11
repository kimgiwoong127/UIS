#include "State.h"

State::State(int a, int b, int h, int av, int d, int he) {
	attack1 = a;
	attack2 = b;
	hp = h;
	avoid = av;
	defense = d;
	heal = he;
	maxhp = hp;
}

void State::Idle() {
	state = 0;
}

int State::gAttack1() {
	return attack1;
}

int State::gAttack2() {
	return attack2;
}

int State::gAvoid() {
	return avoid;
}

int State::gDefense() {
	return defense;
}

int State::gHeal() {
	return heal;
}

void State::Attack1() {
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

int State::myState() {
	return state;
}