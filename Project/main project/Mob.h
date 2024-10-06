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
		if (choose < Bayes[2]) {//회복
			player.hp - mob.gAttack1();
			a = true;
		}
		else {
			player.hp - mob.gAttack2();
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