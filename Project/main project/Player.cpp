#include "Player.h"

Player::Player(int a, int b, int h, int av, int d, int he, int spd) {
	player = State(a, b, h, av, d, he, spd);
}

void Player::act1() {
	int pl;
	cout << "Player의 공격! 행동을 선택하세요:" << endl;
	cout << "1. 강공격" << endl;
	cout << "2. 약공격" << endl;
	cout << "선택: ";
	cin >> pl;
	switch (pl) {
	case 1:

		StateChange(1);
		break;
	case 2:
		StateChange(2);
		break;
	default:
		break;
	}
}

void Player::act2() {
	int pl;
	cout << "Player의 수비! 행동을 선택하세요:" << endl;
	cout << "1. 방어" << endl;
	cout << "2. 회피" << endl;
	cout << "3. 회복" << endl;
	cout << "선택: ";
	cin >> pl;
	switch (pl) {
	case 1:
		StateChange(3);
		break;
	case 2:
		StateChange(4);
		break;
	case 3:
		StateChange(5);
		break;
	default:
		break;
	}
}