#include "State.h"
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Mob :public State {
private:
	int attack1W[3] = { 1,1,1 };
	int attack1L[3] = { 1,1,1 };
	int attack2W[3] = { 1,1,1 };
	int attack2L[3] = { 1,1,1 };

	int DefW[2] = { 1,1 };
	int DefL[2] = { 1,1 };
	int AvoW[2] = { 1,1 };
	int AvoL[2] = { 1,1 };
	int HealW[2] = { 1,1 };
	int HealL[2] = { 1,1 };
public:
	State mob;
	Mob() {};
	Mob(int a, int b, int h, int av, int d, int he);
	void turn1(State player);
	//void turn2(State player);방어턴은 나중에
};

Mob::Mob(int a, int b, int h, int av, int d, int he) {
	mob = State(a, b, h, av, d, he);
}

void Mob::turn1(State player) {
	int exhp = player.hp;
	srand((unsigned)time(0));
	int choose = rand() % 100;
	int Bayes[3] = {};
	bool a=false;

	for (int i = 0; i < 3; i++) {
		Bayes[i]=(((attack1W[i] / (attack1W[i] + attack1L[i])) * (attack1W[i] / (attack1W[i] + attack2W[i]))) 
				/((attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[0] + attack2L[0])))*100;
	}

	switch (player.myState()) {
	case 3:
		if (choose < Bayes[0]) {//방어
			if (player.gDefense() < mob.gAttack1()) {
				player.hp -= mob.gAttack1() - player.gDefense();
			}
			a = true;
		}
		else {
			if (player.gDefense() < mob.gAttack2()) {
				player.hp -= mob.gAttack2() - player.gDefense();
			}
			cout << "약공격" << endl;
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

		break;
	case 4:
		if (choose < Bayes[1]) {//회피
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp - mob.gAttack1();
			}
			a = true;
		}
		else {
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp - mob.gAttack2();
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

		break;
	case 5:
		if (choose <= Bayes[2]) {//회복
			player.hp - mob.gAttack1();
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
			}
			else {
				player.hp = player.maxhp;
			}
			a = true;
		}
		else {
			player.hp - mob.gAttack2();
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
			}
			else {
				player.hp = player.maxhp;
			}
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
		Bayes1[i] = (((DefW[i] / (DefW[i] + DefL[i])) * (DefW[i] / (DefW[i] + AvoW[i]+HealW[i])))
			/ ((DefW[i] + AvoW[i]+HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i]+HealL[i]))) * 100;
		Bayes2[i] = (((AvoW[i] / (AvoW[i] + AvoL[i])) * (AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
	}

	switch (player.myState()) {
	case 1:
		if (choose <= Bayes1[0]) {
			if (mob.gDefense() < player.gAttack1()) {
				mob.hp -= player.gAttack1() - mob.gDefense();
			}
			a = true;
		}
		else if (choose <= Bayes1[0] + Bayes2[0]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.hp - player.gAttack1();
			}
			b = true;
		}
		else {
			mob.hp - player.gAttack1();
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
			}
			else {
				mob.hp = mob.maxhp;
			}
		}

		if (exhp - mob.hp >= 10) {
			if (a) {
				DefW[0]++;
			}
			else if(b) {
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

		break;
	case 2:
		if (choose <= Bayes1[0]) {
			if (mob.gDefense() < player.gAttack2()) {
				mob.hp -= player.gAttack2() - mob.gDefense();
			}
			a = true;
		}
		else if (choose <= Bayes1[0] + Bayes2[0]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.hp - player.gAttack2();
			}
			b = true;
		}
		else {
			mob.hp - player.gAttack2();
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
			}
			else {
				mob.hp = mob.maxhp;
			}
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

		break;
	default:
		break;
	}
}
