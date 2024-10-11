#include "Player.h"

void Player::act1() {
	int pl;
	cin >> pl;
	switch (pl) {
	case 1:
		player.Attack1();
		break;
	case 2:
		player.Attack2();
		break;
	default:
		break;
	}
}

void Player::act2() {
	int pl;
	cin >> pl;
	switch (pl) {
	case 1:
		player.Defense();
		break;
	case 2:
		player.Avoid();
		break;
	case 3:
		player.Heal();
		break;
	default:
		break;
	}
}