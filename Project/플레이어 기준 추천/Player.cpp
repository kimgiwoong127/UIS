#include "Player.h"

Player::Player(int a, int b, int h, int av, int d, int he,int spd) {
	player = State(a, b, h, av, d, he,spd);
}

int Player::Select(int turn) {
	int input;
	cout << endl << "행동을 선택해주세요." << endl << endl;
	switch (turn) {
	case 1:
		cout << "1. 강공격" << endl << "2. 약공격";
		break;
	case 2:
		cout << "1. 방어" << endl << "2. 회피" << endl << "3. 회복";
		break;
	default:
		break;
	}
	cout << endl << "선택 : ";
	cin >> input;
	return input;
}

void Player::turn1(Mob& mob) {
	mob.act2();
	srand(static_cast<unsigned int>(time(0)));
	int exhp = mob.gHP();
	int Bayes[3] = {0,0,0};
	string Recommand[3];

	for (int i = 0; i < 3; i++) {
		Bayes[i] = ((((float)attack1W[i] / (attack1W[i] + attack1L[i])) * ((float)attack1W[i] / (attack1W[i] + attack2W[i])))
			/ ((float)(attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[i] + attack2L[i]))) * 100;
		
		if (Bayes[i] >=  100-Bayes[i]) {
			Recommand[i] = "추천 선택 : 강공격 (성공 확률 : " + to_string(Bayes[i]) + "%)";
		}
		else {
			Recommand[i] = "추천 선택 : 약공격 (성공 확률 : " + to_string(100-Bayes[i]) + "%)";
		}
	}

	switch (mob.PlayerState()) {
	case 3:
		cout << Recommand[0] << endl;
		switch (Select(1)) {
		case 1:
			if (mob.gDefense() < gAttack1()) {
				mob.sHP(mob.gHP() - (gAttack1() - mob.gDefense()));
				cout << "방어 중인 적을 공격합니다. " << gAttack1() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 완벽히 방어했습니다." << endl;
			}
			
			if (exhp - mob.gHP() < 10) {
				this->attack1L[0]++;
			}
			else {
				this->attack1W[0]++;
			}
			break;
		case 2:
			if (mob.gDefense() < gAttack1()) {
				mob.sHP(mob.gHP() - (gAttack1() - mob.gDefense()));
				cout << "방어 중인 적을 공격합니다.  " << gAttack2() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 완벽히 방어했습니다." << endl;
			}

			if (exhp - mob.gHP() < 10) {
				this->attack2L[0]++;
			}
			else {
				this->attack2W[0]++;
			}
			break;
		default:
			break;
		}
		break;
	case 4:
		cout << Recommand[1] << endl;
		switch (Select(1)) {
		case 1:
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.sHP(mob.gHP() - gAttack1());
				cout << "적이 회피에 실패했습니다!" << gAttack1() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 회피에 성공했습니다... 피해를 입지 않습니다." << endl;
			}

			if (exhp - mob.gHP() <10) {
				this->attack1L[1]++;
			}
			else {
				this->attack1W[1]++;
			}
			break;
		case 2:
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.sHP(mob.gHP() - gAttack2());
				cout << "적이 회피에 실패했습니다!" << gAttack2() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 회피에 성공했습니다... 피해를 입지 않습니다." << endl;
			}

			if (exhp - mob.gHP() < 10) {
				this->attack2L[1]++;
			}
			else {
				this->attack2W[1]++;
			}
			break;
		default:
			break;
		}
		break;
	case 5:
		cout << Recommand[2] << endl;
		switch (Select(1)) {
		case 1:
			if (mob.gHP() + mob.gHeal() < mob.max()) {
				mob.sHP(mob.gHP() + mob.gHeal());
				cout << "적이 회복을 사용합니다. 적의 체력 +" << mob.gHeal() << endl;
			}
			else {
				cout << "적이 회복을 사용합니다. 적의 체력 +" << mob.max() - mob.gHP() << endl;
				mob.sHP(mob.max());
			}
			mob.sHP(mob.gHP() - (gAttack1()));
			cout << "틈을 노려 적을 공격합니다. 적의 체력 -" << gAttack1() << endl;

			if (exhp - mob.gHP() < 10) {
				this->attack1L[2]++;
			}
			else {
				this->attack1W[2]++;
			}
			break;
		case 2:
			if (mob.gHP() + mob.gHeal() < mob.max()) {
				mob.sHP(mob.gHP() + mob.gHeal());
				cout << "적이 회복을 사용합니다. 적의 체력 +" << mob.gHeal() << endl;
			}
			else {
				cout << "적이 회복을 사용합니다. 적의 체력 +" << mob.max() - mob.gHP() << endl;
				mob.sHP(mob.max());
			}
			mob.sHP(mob.gHP() - (gAttack2()));
			cout << "틈을 노려 적을 공격합니다. 적의 체력 -" << gAttack2() << endl;

			if (exhp - mob.gHP() < 10) {
				this->attack2L[2]++;
			}
			else {
				this->attack2W[2]++;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Player::turn2(Mob& mob) {
	mob.act1();
	int exhp = gHP();
	int Bayes1[2] = { 0,0 };
	int Bayes2[2] = { 0,0 };
	string Recommand[2];
	//1은 방어 성공률 2는 회피 성공률 식은 기존과 동일

	for (int i = 0; i < 2; i++) {
		Bayes1[i] = ((((float)DefW[i] / (DefW[i] + DefL[i])) * ((float)DefW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		Bayes2[i] = ((((float)AvoW[i] / (AvoW[i] + AvoL[i])) * ((float)AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		if (Bayes1[i] >= Bayes2[i] && Bayes1[i] >= (99 - Bayes2[i] - Bayes1[i])) {
			Recommand[i] = "추천 선택 : 방어 (성공 확률 : " + to_string(Bayes1[i]) + "%)";
		}
		else if (Bayes2[i] >= (99 - Bayes2[i] - Bayes1[i])) {
			Recommand[i] = "추천 선택 : 회피 (성공 확률 : " + to_string(Bayes2[i]) + "%)";
		}
		else {
			Recommand[i] = "추천 선택 : 회복 (성공 확률 : " + to_string(99 - Bayes2[i] + Bayes1[i]) + "%)";
		}
	}

	switch (mob.PlayerState()) {
	case 1:
		cout << Recommand[0] << endl;
		switch (Select(2)) {
		case 1:
			if (gDefense() < mob.gAttack1()) {
				sHP(gHP() - (mob.gAttack1() - gDefense()));
				cout << "공격을 방어하여 피해가 줄어듭니다. " << mob.gAttack1() - gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "공격을 완벽하게 막아냈습니다." << endl;
			}
			if (exhp - gHP() >= 10) {
				this->DefL[0]++;
			}
			else {
				this->DefW[0]++;
			}
			break;
		case 2:
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - mob.gAttack1());
				cout << "회피에 실패했습니다..." << mob.gAttack1() << "만큼의 피해를 입습니다." << endl;
			}
			else {
				cout << "공격을 회피하였습니다!" << endl;
			}

			if (exhp - gHP() >= 10) {
				this->AvoL[0]++;
			}
			else {
				this->AvoW[0]++;
			}
			break;
		case 3:
			if (gHP() + gHeal() < max()) {
				sHP(gHP() + gHeal());
				cout << "회복을 합니다. 체력 +" << gHeal() << endl;
			}
			else {
				cout << "회복을 합니다. 체력 +" << max() - gHP() << endl;
				sHP(max());
			}
			sHP(gHP() - mob.gAttack1());
			cout << "적이 빈틈을 놓치지 않고 공격해옵니다. 체력-" << mob.gAttack1() << endl;

			if (exhp - gHP() >= 10) {
				this->HealL[0]++;
			}
			else {
				this->HealW[0]++;
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		cout << Recommand[1] << endl;
		switch (Select(2)) {
		case 1:
			if (gDefense() < mob.gAttack2()) {
				sHP(gHP() - (mob.gAttack2() - gDefense()));
				cout << "공격을 방어하여 피해가 줄어듭니다. " << mob.gAttack2() - gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "공격을 완벽하게 막아냈습니다." << endl;
			}

			if (exhp - gHP() >= 10) {
				this->DefL[1]++;
			}
			else {
				this->DefW[1]++;
			}
			break;
		case 2:
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - mob.gAttack2());
				cout << "회피에 실패했습니다..." << mob.gAttack2() << "만큼의 피해를 입습니다." << endl;
			}
			else {
				cout << "공격을 회피하였습니다!" << endl;
			}

			if (exhp - gHP() >= 10) {
				this->AvoL[1]++;
			}
			else {
				this->AvoW[1]++;
			}
			break;
		case 3:
			if (gHP() + gHeal() < max()) {
				sHP(gHP() + gHeal());
				cout << "회복을 합니다. 체력 +" << gHeal() << endl;
			}
			else {
				cout << "회복을 합니다. 체력 +" << max() - gHP() << endl;
				sHP(max());
			}
			sHP(gHP() - mob.gAttack1());
			cout << "적이 빈틈을 놓치지 않고 공격해옵니다. 체력-" << mob.gAttack2() << endl;

			if (exhp - gHP() >= 10) {
				this->HealL[1]++;
			}
			else {
				this->HealW[1]++;
			}
			break;
		default:
			break;
		}
		break;
	}
}