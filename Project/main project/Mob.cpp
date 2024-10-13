#include "Mob.h"

Mob::Mob(int a, int b, int h, int av, int d, int he,int spd) {
	mob = State(a, b, h, av, d, he,spd);
}

void Mob::turn1(Player& player) {
	player.act2();
	srand(static_cast<unsigned int>(time(0)));
	int exhp = player.gHP();
	int choose = rand() % 100;
	int Bayes[3] = {0,0,0};
	bool a = false;

	for (int i = 0; i < 3; i++) {
		Bayes[i] = ((((float)attack1W[i] / (attack1W[i] + attack1L[i])) * ((float)attack1W[i] / (attack1W[i] + attack2W[i])))
			/ ((float)(attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[i] + attack2L[i]))) * 100;
		cout << Bayes[i] << endl;
	}

	switch (player.PlayerState()) {
	case 3:
		if (choose < Bayes[0]) {//방어
			if (player.gDefense() < mob.gAttack1()) {
				player.sHP(player.gHP()-(mob.gAttack1() - player.gDefense()));
				cout << "적이 공격을 하여 " << mob.gAttack1() - player.gDefense() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "적이 공격을 했지만 방어로 인해 피해를 입지 않았습니다." << endl;
			}
			a = true;
		}
		else {
			if (player.gDefense() < mob.gAttack2()) {
				player.sHP(player.gHP() - (mob.gAttack2() - player.gDefense()));
				cout << "적이 공격을 하여 " << mob.gAttack2() - player.gDefense() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "적이 공격을 했지만 방어로 인해 피해를 입지 않았습니다." << endl;
			}
		}

		if (exhp - player.gHP() >= 10) {
			if (a) {
				this->attack1L[0]++;
			}
			else {
				this->attack2L[0]++;
			}
		}
		else {
			if (a) {
				this->attack1W[0]++;
			}
			else {
				this->attack2W[0]++;
			}
		}
		break;
	case 4:
		if (choose < Bayes[1]) {//회피
			if ((rand() % 100) >= player.gAvoid()) {
				player.sHP(player.gHP() - (mob.gAttack1()));
				cout << "회피에 실패했습니다... " << mob.gAttack1() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "회피에 성공했습니다! 피해를 입지 않습니다." << endl;
			}
			a = true;
		}
		else {
			if ((rand() % 100) >= player.gAvoid()) {
				player.sHP(player.gHP() - (mob.gAttack2()));
				cout << "회피에 실패했습니다... " << mob.gAttack2() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "회피에 성공했습니다! 피해를 입지 않습니다." << endl;
			}
		}

		if (exhp - player.gHP() >= 10) {
			if (a) {
				this->attack1L[1]++;
			}
			else {
				this->attack2L[1]++;
			}
		}
		else {
			if (a) {
				this->attack1W[1]++;
			}
			else {
				this->attack2W[1]++;
			}
		}

		break;
	case 5:
		if (choose <= Bayes[2]) {//회복
			if (player.gHP() + player.gHeal() < player.max()) {
				player.sHP(player.gHP() +player.gHeal());
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.gHeal() << endl;
			}
			else {
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.max() - player.gHP() << endl;
				player.sHP(player.max());
			}
			a = true;
			player.sHP(player.gHP() - (mob.gAttack1()));
			cout << "이어서 적이 공격합니다. 플레이어의 체력 -" << mob.gAttack1() << endl;
		}
		else {
			if (player.gHP() + player.gHeal() < player.max()) {
				player.sHP(player.gHP() + player.gHeal());
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.gHeal() << endl;
			}
			else {
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.max() - player.gHP() << endl;
				player.sHP(player.max());
			}
			player.sHP(player.gHP() - (mob.gAttack2()));
			cout << "이어서 적이 공격합니다. 플레이어의 체력 -" << mob.gAttack2() << endl;
		}

		if (exhp - player.gHP() >= 10) {
			if (a) {
				this->attack1L[2]++;
			}
			else {
				this->attack2L[2]++;
			}
		}
		else {
			if (a) {
				this->attack1W[2]++;
			}
			else {
				this->attack2W[2]++;
			}
		}
		break;
	default:
		break;
	}
}

void Mob::turn2(Player& player) {
	player.act1();
	int exhp = gHP();
	srand(static_cast<unsigned int>(time(0)));
	int choose = rand() % 100;
	int Bayes1[2] = {0,0};
	int Bayes2[2] = {0,0};
	bool a = false;
	bool b = false;
	//1은 방어 성공률 2는 회피 성공률 식은 기존과 동일

	for (int i = 0; i < 2; i++) {
		Bayes1[i] = ((((float)DefW[i] / (DefW[i] + DefL[i])) * ((float)DefW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		Bayes2[i] = ((((float)AvoW[i] / (AvoW[i] + AvoL[i])) * ((float)AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
	}

	switch (player.PlayerState()) {
	case 1:
		if (choose <= Bayes1[0]) {
			if (gDefense() < player.gAttack1()) {
				sHP(gHP()-(player.gAttack1()- gDefense()));
				cout << "적이 공격을 방어하여 피해가 줄어듭니다. " << player.gAttack1() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 방어하여 피해를 입히지 못했습니다." << endl;
			}
			a = true;
		}
		else if (choose <= Bayes1[0] + Bayes2[0] && choose > Bayes1[0]) {
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - player.gAttack1());
				cout << "적이 회피에 실패했습니다! " << player.gAttack1() << "만큼의 피해를 줍니다." << endl;
			}
			else {
				cout << "적이 공격을 회피하였습니다." << endl;
			}
			b = true;
		}
		else {

			if (gHP() + gHeal() < max()) {
				sHP(gHP() + gHeal());
				cout << "적이 회복을 합니다. 적의 체력 +" << gHeal() << endl;
			}
			else {
				cout << "적이 회복을 합니다. 적의 체력 +" << max() - gHP() << endl;
				sHP(max());
			}
			sHP(gHP() - player.gAttack1());
			cout << "기회를 놓치지 않고 공격을 합니다. 적의 체력 -" << player.gAttack1() << endl;
		}

		if (exhp - mob.hp < 10) {
			if (a) {
				this->DefW[0]++;
			}
			else if (b) {
				this->AvoW[0]++;
			}
			else {
				this->HealW[0]++;
			}
		}
		else {
			if (a) {
				this->DefL[0]++;
			}
			else if (b) {
				this->AvoL[0]++;
			}
			else {
				this->HealL[0]++;
			}
		}
		break;
	case 2:
		if (choose <= Bayes1[1]) {
			if (gDefense() < player.gAttack2()) {
				sHP(gHP() - (player.gAttack2() - gDefense()));
				cout << "적이 공격을 방어하여 피해가 줄어듭니다. " << player.gAttack2() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 방어하여 피해를 입히지 못했습니다." << endl;
			}
			a = true;
		}
		else if (choose <= Bayes1[1] + Bayes2[1] && choose > Bayes1[1]) {
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - player.gAttack2());
				cout << "적이 회피에 실패했습니다! " << player.gAttack2() << "만큼의 피해를 줍니다." << endl;
			}
			else {
				cout << "적이 공격을 회피하였습니다." << endl;
			}
			b = true;
		}
		else {
			if ((gHP() + gHeal()) < max()) {
				sHP(gHP() + gHeal());
				cout << "적이 회복을 합니다. 적의 체력 +" << gHeal() << endl;
			}
			else {
				cout << "적이 회복을 합니다. 적의 체력 +" << max() - gHP() << endl;
				sHP(max());
			}
			sHP(gHP() - player.gAttack2());
			cout << "기회를 놓치지 않고 공격을 합니다. 적의 체력 -" << player.gAttack2() << endl;
		}

		if (exhp - mob.hp < 10) {
			if (a) {
				this->DefW[1]++;
			}
			else if (b) {
				this->AvoW[1]++;
			}
			else {
				this->HealW[1]++;
			}
		}
		else {
			if (a) {
				this->DefL[1]++;
			}
			else if (b) {
				this->AvoL[1]++;
			}
			else {
				this->HealL[1]++;
			}
		}
		break;
	default:
		break;
	}
}

void Mob::ShowBayesP1(Player& player) {
	player.act2();
	srand(static_cast<unsigned int>(time(0)));
	int exhp = player.gHP();
	int choose = rand() % 100;
	int Bayes[3] = { 0,0,0 };
	bool a = false;

	for (int i = 0; i < 3; i++) {
		Bayes[i] = ((((float)attack1W[i] / (attack1W[i] + attack1L[i])) * ((float)attack1W[i] / (attack1W[i] + attack2W[i])))
			/ ((float)(attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[i] + attack2L[i]))) * 100;
	}

	cout << endl << "방어 시 베이즈 정리에 따른 확률" << endl
		<< "강공격 성공률: " << Bayes[0] << " 약공격 성공률: " << 100 - Bayes[0] << endl << endl;
	cout << "회피 시 베이즈 정리에 따른 확률" << endl
		<< "강공격 성공률: " << Bayes[1] << " 약공격 성공률: " << 100 - Bayes[1] << endl << endl;
	cout << "회복 시 베이즈 정리에 따른 확률" << endl
		<< "강공격 성공률: " << Bayes[2] << " 약공격 성공률: " << 100 - Bayes[2] << endl << endl;

	switch (player.PlayerState()) {
	case 3:
		if (choose < Bayes[0]) {//방어
			if (player.gDefense() < mob.gAttack1()) {
				player.sHP(player.gHP() - (mob.gAttack1() - player.gDefense()));
			}
			a = true;
		}
		else {
			if (player.gDefense() < mob.gAttack2()) {
				player.sHP(player.gHP() - (mob.gAttack2() - player.gDefense()));
			}
		}

		if (exhp - player.gHP() < 10) {
			if (a) {
				this->attack1L[0]++;
				cout << "방어시 강공격 실패" << endl;
			}
			else {
				this->attack2L[0]++;
				cout << "방어시 약공격 실패" << endl;
			}
		}
		else {
			if (a) {
				this->attack1W[0]++;
				cout << "방어시 강공격 성공" << endl;
			}
			else {
				this->attack2W[0]++;
				cout << "방어시 약공격 성공" << endl;
			}
		}
		break;
	case 4:
		if (choose < Bayes[1]) {//회피
			if ((rand() % 100) >= player.gAvoid()) {
				player.sHP(player.gHP() - (mob.gAttack1()));
			}
			a = true;
		}
		else {
			if ((rand() % 100) >= player.gAvoid()) {
				player.sHP(player.gHP() - (mob.gAttack2()));
			}
		}

		if (exhp - player.gHP() < 10) {
			if (a) {
				this->attack1L[1]++;
				cout << "회피시 강공격 실패" << endl;
			}
			else {
				this->attack2L[1]++;
				cout << "회피시 약공격 실패" << endl;
			}
		}
		else {
			if (a) {
				this->attack1W[1]++;
				cout << "회피시 강공격 성공" << endl;
			}
			else {
				this->attack2W[1]++;
				cout << "회피시 약공격 성공" << endl;
			}
		}

		break;
	case 5:
		if (choose <= Bayes[2]) {//회복
			if (player.gHP() + player.gHeal() < player.max()) {
				player.sHP(player.gHP() + player.gHeal());
			}
			else {
				player.sHP(player.max());
			}
			a = true;
			player.sHP(player.gHP() - (mob.gAttack1()));
		}
		else {
			if (player.gHP() + player.gHeal() < player.max()) {
				player.sHP(player.gHP() + player.gHeal());
			}
			else {
				player.sHP(player.max());
			}
			player.sHP(player.gHP() - (mob.gAttack2()));
		}

		if (exhp - player.gHP() < 10) {
			if (a) {
				this->attack1L[2]++;
				cout << "회복시 강공격 실패" << endl;
			}
			else {
				this->attack2L[2]++;
				cout << "회복시 약공격 실패" << endl;
			}
		}
		else {
			if (a) {
				this->attack1W[2]++;
				cout << "회복시 강공격 성공" << endl;
			}
			else {
				this->attack2W[2]++;
				cout << "회복시 약공격 성공" << endl;
			}
		}
		break;
	default:
		break;
	}
}

void Mob::ShowBayesP2(Player& player) {
	player.act1();
	int exhp = gHP();
	srand(static_cast<unsigned int>(time(0)));
	int choose = rand() % 100;
	int Bayes1[2] = { 0,0 };
	int Bayes2[2] = { 0,0 };
	bool a = false;
	bool b = false;
	//1은 방어 성공률 2는 회피 성공률 식은 기존과 동일

	for (int i = 0; i < 2; i++) {
		Bayes1[i] = ((((float)DefW[i] / (DefW[i] + DefL[i])) * ((float)DefW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		Bayes2[i] = ((((float)AvoW[i] / (AvoW[i] + AvoL[i])) * ((float)AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((float)(DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
	}

	cout << endl << "강공격 시 베이즈 정리에 따른 확률" << endl
		<< "방어 성공률: " << Bayes1[0] << " 회피 성공률: " << Bayes2[0] << " 회복 성공률: " << 100 - Bayes1[0] - Bayes2[0] << endl << endl;
	cout << "약공격 시 베이즈 정리에 따른 확률" << endl
		<< "방어 성공률: " << Bayes1[1] << " 회피 성공률: " << Bayes2[1] << " 회복 성공률: " << 100 - Bayes1[1] - Bayes2[1] << endl << endl;

	switch (player.PlayerState()) {
	case 1:
		if (choose <= Bayes1[0]) {
			if (gDefense() < player.gAttack1()) {
				sHP(gHP() - (player.gAttack1() - gDefense()));
			}
			a = true;
		}
		else if (choose <= Bayes1[0] + Bayes2[0] && choose > Bayes1[0]) {
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - player.gAttack1());
			}
			b = true;
		}
		else {

			if (gHP() + gHeal() < max()) {
				sHP(gHP() + gHeal());
			}
			else {
				sHP(max());
			}
			sHP(gHP() - player.gAttack1());
		}

		if (exhp - mob.hp < 10) {
			if (a) {
				this->DefW[0]++;
				cout << "강공격시 방어 성공"<<endl;
			}
			else if (b) {
				this->AvoW[0]++;
				cout << "강공격시 회피 성공" << endl;
			}
			else {
				this->HealW[0]++;
				cout << "강공격시 회복 성공" << endl;
			}
		}
		else {
			if (a) {
				this->DefL[0]++;
				cout << "강공격시 방어 실패" << endl;
			}
			else if (b) {
				this->AvoL[0]++;
				cout << "강공격시 회피 실패" << endl;
			}
			else {
				this->HealL[0]++;
				cout << "강공격시 회복 실패" << endl;
			}
		}
		break;
	case 2:
		if (choose <= Bayes1[1]) {
			if (gDefense() < player.gAttack2()) {
				sHP(gHP() - (player.gAttack2() - gDefense()));
			}
			a = true;
		}
		else if (choose <= Bayes1[1] + Bayes2[1] && choose > Bayes1[1]) {
			if ((rand() % 100) >= gAvoid()) {
				sHP(gHP() - player.gAttack2());
			}
			b = true;
		}
		else {
			if ((gHP() + gHeal()) < max()) {
				sHP(gHP() + gHeal());
			}
			else {
				sHP(max());
			}
			sHP(gHP() - player.gAttack2());
		}

		if (exhp - mob.hp < 10) {
			if (a) {
				this->DefW[1]++;
				cout << "약공격시 방어 성공" << endl;
			}
			else if (b) {
				this->AvoW[1]++;
				cout << "약공격시 회피 성공" << endl;
			}
			else {
				this->HealW[1]++;
				cout << "약공격시 회복 성공" << endl;
			}
		}
		else {
			if (a) {
				this->DefL[1]++;
				cout << "약공격시 방어 실패" << endl;
			}
			else if (b) {
				this->AvoL[1]++;
				cout << "약공격시 회피 실패" << endl;
			}
			else {
				this->HealL[1]++;
				cout << "약공격시 회복 실패" << endl;
			}
		}
		break;
	default:
		break;
	}
}