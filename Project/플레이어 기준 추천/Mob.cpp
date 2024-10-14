#include "Mob.h"

Mob::Mob(int a, int b, int h, int av, int d, int he, int spd) {
	mob = State(a, b, h, av, d, he, spd);
}

void Mob::act1() {
	int pl = rand()%2;
	switch (pl) {
	case 0:
		StateChange(1);
		cout << "적의 상태 : 약공격 " << endl;
		break;
	case 1:
		StateChange(2);
		cout << "적의 상태 : 강공격 " << endl;
		break;
	default:
		break;
	}
}

void Mob::act2() {
	int pl = rand() % 3;
	switch (pl) {
	case 0:
		StateChange(3);
		cout << "적의 상태 : 방어 " << endl;
		break;
	case 1:
		StateChange(4);
		cout << "적의 상태 : 회피 " << endl;
		break;
	case 2:
		StateChange(5);
		cout << "적의 상태 : 회복 " << endl;
		break;
	default:
		break;
	}
}