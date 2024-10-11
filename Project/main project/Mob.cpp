#include "Mob.h"

Mob::Mob(int a, int b, int h, int av, int d, int he) {
	mob = State(a, b, h, av, d, he);
}

void Mob::turn1(State player) {
	int exhp = player.hp;
	srand((unsigned)time(0));
	int choose = rand() % 100;
	int Bayes[3] = {};
	bool a = false;

	for (int i = 0; i < 3; i++) {
		Bayes[i] = (((attack1W[i] / (attack1W[i] + attack1L[i])) * (attack1W[i] / (attack1W[i] + attack2W[i])))
			/ ((attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[0] + attack2L[0]))) * 100;
	}

	switch (player.myState()) {
	case 3:
		if (choose < Bayes[0]) {//방어
			if (player.gDefense() < mob.gAttack1()) {
				player.hp -= mob.gAttack1() - player.gDefense();
				cout << "적이 공격을 하여 " << mob.gAttack1() - player.gDefense() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "적이 공격을 했지만 방어로 인해 피해를 입지 않았습니다." << endl;
			}
			a = true;
		}
		else {
			if (player.gDefense() < mob.gAttack2()) {
				player.hp -= mob.gAttack2() - player.gDefense();
				cout << "적이 공격을 하여 " << mob.gAttack2() - player.gDefense() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "적이 공격을 했지만 방어로 인해 피해를 입지 않았습니다." << endl;
			}
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[0]++;
			}
			else {
				attack2L[0]++;
			}
		}
		else {
			if (a) {
				attack1W[0]++;
			}
			else {
				attack2W[0]++;
			}
		}
		cout << Bayes[0] << endl;
		break;
	case 4:
		if (choose < Bayes[1]) {//회피
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp -= mob.gAttack1();
				cout << "회피에 실패했습니다... " << mob.gAttack1() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "회피에 성공했습니다! 피해를 입지 않습니다." << endl;
			}
			a = true;
		}
		else {
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp -= mob.gAttack2();
				cout << "회피에 실패했습니다... " << mob.gAttack2() << "만큼의 피해를 입었습니다." << endl;
			}
			else {
				cout << "회피에 성공했습니다! 피해를 입지 않습니다." << endl;
			}
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[1]++;
			}
			else {
				attack2L[1]++;
			}
		}
		else {
			if (a) {
				attack1W[1]++;
			}
			else {
				attack2W[1]++;
			}
		}
		cout << Bayes[1] << endl;
		break;
	case 5:
		if (choose <= Bayes[2]) {//회복
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.gHeal() << endl;
			}
			else {
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.maxhp - player.hp << endl;
				player.hp = player.maxhp;
			}
			a = true;
			player.hp -= mob.gAttack1();
			cout << "이어서 적이 공격합니다. 플레이어의 체력 -" << mob.gAttack1() << endl;
		}
		else {
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.gHeal() << endl;
			}
			else {
				cout << "회복을 사용합니다. 플레이어의 체력 +" << player.maxhp - player.hp << endl;
				player.hp = player.maxhp;
			}
			player.hp -= mob.gAttack2();
			cout << "이어서 적이 공격합니다. 플레이어의 체력 -" << mob.gAttack2() << endl;
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[2]++;
			}
			else {
				attack2L[2]++;
			}
		}
		else {
			if (a) {
				attack1W[2]++;
			}
			else {
				attack2W[2]++;
			}
		}
		cout << Bayes[2] << endl;
		break;
	default:
		break;
	}
}

void Mob::turn2(State player) {
	int exhp = mob.hp;
	srand((unsigned)time(0));
	int choose = rand() % 100;
	int Bayes1[2] = {};
	int Bayes2[2] = {};
	bool a = false;
	bool b = false;
	//1은 방어 성공률 2는 회피 성공률 식은 기존과 동일
	for (int i = 0; i < 3; i++) {
		Bayes1[i] = (((DefW[i] / (DefW[i] + DefL[i])) * (DefW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		Bayes2[i] = (((AvoW[i] / (AvoW[i] + AvoL[i])) * (AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
	}

	switch (player.myState()) {
	case 1:
		if (choose <= Bayes1[0]) {
			if (mob.gDefense() < player.gAttack1()) {
				mob.hp -= player.gAttack1() - mob.gDefense();
				cout << "적이 공격을 방어하여 피해가 줄어듭니다. " << player.gAttack1() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 방어하여 피해를 입히지 못했습니다." << endl;
			}
			a = true;
		}
		else if (choose <= Bayes1[0] + Bayes2[0] && choose > Bayes1[0]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.hp -= player.gAttack1();
				cout << "적이 회피에 실패했습니다! " << player.gAttack1() << "만큼의 피해를 줍니다." << endl;
			}
			else {
				cout << "적이 공격을 회피하였습니다." << endl;
			}
			b = true;
		}
		else {
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
				cout << "적이 회복을 합니다. 적의 체력 +" << mob.gHeal() << endl;
			}
			else {
				cout << "적이 회복을 합니다. 적의 체력 +" << mob.maxhp - mob.hp << endl;
				mob.hp = mob.maxhp;
			}
			mob.hp -= player.gAttack1();
			cout << "기회를 놓치지 않고 공격을 합니다. 적의 체력 -" << player.gAttack1() << endl;
		}

		if (exhp - mob.hp >= 10) {
			if (a) {
				DefW[0]++;
			}
			else if (b) {
				AvoW[0]++;
			}
			else {
				HealW[0]++;
			}
		}
		else {
			if (a) {
				DefL[0]++;
			}
			else if (b) {
				AvoL[0]++;
			}
			else {
				HealL[0]++;
			}
		}
		cout << Bayes1[0] << " " << Bayes2[0] << endl;
		break;
	case 2:
		if (choose <= Bayes1[1]) {
			if (mob.gDefense() < player.gAttack2()) {
				mob.hp -= player.gAttack2() - mob.gDefense();
				cout << "적이 공격을 방어하여 피해가 줄어듭니다. " << player.gAttack2() - mob.gDefense() << "만큼의 피해를 입혔습니다." << endl;
			}
			else {
				cout << "적이 공격을 방어하여 피해를 입히지 못했습니다." << endl;
			}
			a = true;
		}
		else if (choose <= Bayes1[1] + Bayes2[1] && choose > Bayes1[1]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				cout << "적이 회피에 실패했습니다! " << player.gAttack2() << "만큼의 피해를 줍니다." << endl;
			}
			else {
				cout << "적이 공격을 회피하였습니다." << endl;
			}
			b = true;
		}
		else {
			mob.hp - player.gAttack2();
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
				cout << "적이 회복을 합니다. 적의 체력 +" << mob.gHeal() << endl;
			}
			else {
				cout << "적이 회복을 합니다. 적의 체력 +" << mob.maxhp - mob.hp << endl;
				mob.hp = mob.maxhp;
			}
			mob.hp -= player.gAttack2();
			cout << "기회를 놓치지 않고 공격을 합니다. 적의 체력 -" << player.gAttack2() << endl;
		}

		if (exhp - mob.hp >= 10) {
			if (a) {
				DefW[1]++;
			}
			else if (b) {
				AvoW[1]++;
			}
			else {
				HealW[1]++;
			}
		}
		else {
			if (a) {
				DefL[1]++;
			}
			else if (b) {
				AvoL[1]++;
			}
			else {
				HealL[1]++;
			}
		}
		cout << Bayes1[1] << " " << Bayes2[1] << endl;
		break;
	default:
		break;
	}
}