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
	int Bayesforturn1[3] = {};
	int Bayesforturn2d[2] = {};
	int Bayesforturn2av[2] = {};
public:
	State mob;
	Mob() {};
	Mob(int a, int b, int h, int av, int d, int he);
	void turn1(State player);
	void turn2(State player);
	int autoselect(State player);
};

Mob::Mob(int a, int b, int h, int av, int d, int he) {
	mob = State(a, b, h, av, d, he);
}

void Mob::turn1(State player) {
	int exhp = player.hp;
	srand((unsigned)time(0));
	int choose = rand() % 100;
	bool a = false;
	int ego = autoselect(player);
	for (int i = 0; i < 3; i++) {
		Bayesforturn1[i] = (((attack1W[i] / (attack1W[i] + attack1L[i])) * (attack1W[i] / (attack1W[i] + attack2W[i])))
			/ ((attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[0] + attack2L[0]))) * 100;
	}

	switch (player.myState()) {
	case 3:
		if (choose < Bayesforturn1[ego]) {//���
			if (player.gDefense() < mob.gAttack1()) {
				player.hp -= mob.gAttack1() - player.gDefense();
				cout << "���� ������ �Ͽ� " << mob.gAttack1() - player.gDefense() << "��ŭ�� ���ظ� �Ծ����ϴ�." << endl;
			}
			else {
				cout << "���� ������ ������ ���� ���� ���ظ� ���� �ʾҽ��ϴ�." << endl;
			}
			a = true;
		}
		else {
			if (player.gDefense() < mob.gAttack2()) {
				player.hp -= mob.gAttack2() - player.gDefense();
				cout << "���� ������ �Ͽ� " << mob.gAttack2() - player.gDefense() << "��ŭ�� ���ظ� �Ծ����ϴ�." << endl;
			}
			else {
				cout << "���� ������ ������ ���� ���� ���ظ� ���� �ʾҽ��ϴ�." << endl;
			}
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[ego]++;
			}
			else {
				attack2L[ego]++;
			}
		}
		else {
			if (a) {
				attack1W[ego]++;
			}
			else {
				attack2W[ego]++;
			}
		}
		cout << Bayesforturn1[ego] << endl;
		break;
	case 4:
		if (choose < Bayesforturn1[ego]) {//ȸ��
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp -= mob.gAttack1();
				cout << "ȸ�ǿ� �����߽��ϴ�... " << mob.gAttack1() << "��ŭ�� ���ظ� �Ծ����ϴ�." << endl;
			}
			else {
				cout << "ȸ�ǿ� �����߽��ϴ�! ���ظ� ���� �ʽ��ϴ�." << endl;
			}
			a = true;
		}
		else {
			if ((rand() % 100) >= player.gAvoid()) {
				player.hp -= mob.gAttack2();
				cout << "ȸ�ǿ� �����߽��ϴ�... " << mob.gAttack2() << "��ŭ�� ���ظ� �Ծ����ϴ�." << endl;
			}
			else {
				cout << "ȸ�ǿ� �����߽��ϴ�! ���ظ� ���� �ʽ��ϴ�." << endl;
			}
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[ego]++;
			}
			else {
				attack2L[ego]++;
			}
		}
		else {
			if (a) {
				attack1W[ego]++;
			}
			else {
				attack2W[ego]++;
			}
		}
		cout << Bayesforturn1[ego] << endl;
		break;
	case 5:
		if (choose <= Bayesforturn1[ego]) {//ȸ��
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
				cout << "ȸ���� ����մϴ�. �÷��̾��� ü�� +" << player.gHeal() << endl;
			}
			else {
				cout << "ȸ���� ����մϴ�. �÷��̾��� ü�� +" << player.maxhp - player.hp << endl;
				player.hp = player.maxhp;
			}
			a = true;
			player.hp -= mob.gAttack1();
			cout << "�̾ ���� �����մϴ�. �÷��̾��� ü�� -" << mob.gAttack1() << endl;
		}
		else {
			if (player.hp + player.gHeal() < player.maxhp) {
				player.hp += player.gHeal();
				cout << "ȸ���� ����մϴ�. �÷��̾��� ü�� +" << player.gHeal() << endl;
			}
			else {
				cout << "ȸ���� ����մϴ�. �÷��̾��� ü�� +" << player.maxhp - player.hp << endl;
				player.hp = player.maxhp;
			}
			player.hp -= mob.gAttack2();
			cout << "�̾ ���� �����մϴ�. �÷��̾��� ü�� -" << mob.gAttack2() << endl;
		}

		if (exhp - player.hp >= 10) {
			if (a) {
				attack1L[ego]++;
			}
			else {
				attack2L[ego]++;
			}
		}
		else {
			if (a) {
				attack1W[ego]++;
			}
			else {
				attack2W[ego]++;
			}
		}
		cout << Bayesforturn1[ego] << endl;
		break;
	default:
		break;
	}
}

void Mob::turn2(State player) {
	int exhp = mob.hp;
	srand((unsigned)time(0));
	int choose = rand() % 100;
	bool a = false;
	bool b = false;
	int ego = autoselect(player);
	//1�� ��� ������ 2�� ȸ�� ������ ���� ������ ����
	for (int i = 0; i < 3; i++) {
		Bayesforturn2d[i] = (((DefW[i] / (DefW[i] + DefL[i])) * (DefW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
		Bayesforturn2av[i] = (((AvoW[i] / (AvoW[i] + AvoL[i])) * (AvoW[i] / (DefW[i] + AvoW[i] + HealW[i])))
			/ ((DefW[i] + AvoW[i] + HealW[i]) / (DefW[i] + AvoW[i] + HealW[i] + DefL[i] + AvoL[i] + HealL[i]))) * 100;
	}

	switch (player.myState()) {
	case 1:
		if (choose <= Bayesforturn2d[ego]) {
			if (mob.gDefense() < player.gAttack1()) {
				mob.hp -= player.gAttack1() - mob.gDefense();
				cout << "���� ������ ����Ͽ� ���ذ� �پ��ϴ�. " << player.gAttack1() - mob.gDefense() << "��ŭ�� ���ظ� �������ϴ�." << endl;
			}
			else {
				cout << "���� ������ ����Ͽ� ���ظ� ������ ���߽��ϴ�." << endl;
			}
			a = true;
		}
		else if (choose <= Bayesforturn2d[ego] + Bayesforturn2av[ego] && choose > Bayesforturn2d[ego]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				mob.hp -= player.gAttack1();
				cout << "���� ȸ�ǿ� �����߽��ϴ�! " << player.gAttack1() << "��ŭ�� ���ظ� �ݴϴ�." << endl;
			}
			else {
				cout << "���� ������ ȸ���Ͽ����ϴ�." << endl;
			}
			b = true;
		}
		else {
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
				cout << "���� ȸ���� �մϴ�. ���� ü�� +" << mob.gHeal() << endl;
			}
			else {
				cout << "���� ȸ���� �մϴ�. ���� ü�� +" << mob.maxhp - mob.hp << endl;
				mob.hp = mob.maxhp;
			}
			mob.hp -= player.gAttack1();
			cout << "��ȸ�� ��ġ�� �ʰ� ������ �մϴ�. ���� ü�� -" << player.gAttack1() << endl;
		}

		if (exhp - mob.hp >= 10) {
			if (a) {
				DefW[ego]++;
			}
			else if (b) {
				AvoW[ego]++;
			}
			else {
				HealW[ego]++;
			}
		}
		else {
			if (a) {
				DefL[ego]++;
			}
			else if (b) {
				AvoL[ego]++;
			}
			else {
				HealL[ego]++;
			}
		}
		cout << Bayesforturn2d[ego] << " " << Bayesforturn2av[ego] << endl;
		break;
	case 2:
		if (choose <= Bayesforturn2d[ego]) {
			if (mob.gDefense() < player.gAttack2()) {
				mob.hp -= player.gAttack2() - mob.gDefense();
				cout << "���� ������ ����Ͽ� ���ذ� �پ��ϴ�. " << player.gAttack2() - mob.gDefense() << "��ŭ�� ���ظ� �������ϴ�." << endl;
			}
			else {
				cout << "���� ������ ����Ͽ� ���ظ� ������ ���߽��ϴ�." << endl;
			}
			a = true;
		}
		else if (choose <= Bayesforturn2d[ego] + Bayesforturn2av[ego] && choose > Bayesforturn2d[ego]) {
			if ((rand() % 100) >= mob.gAvoid()) {
				cout << "���� ȸ�ǿ� �����߽��ϴ�! " << player.gAttack2() << "��ŭ�� ���ظ� �ݴϴ�." << endl;
			}
			else {
				cout << "���� ������ ȸ���Ͽ����ϴ�." << endl;
			}
			b = true;
		}
		else {
			mob.hp - player.gAttack2();
			if (mob.hp + mob.gHeal() < mob.maxhp) {
				mob.hp += mob.gHeal();
				cout << "���� ȸ���� �մϴ�. ���� ü�� +" << mob.gHeal() << endl;
			}
			else {
				cout << "���� ȸ���� �մϴ�. ���� ü�� +" << mob.maxhp - mob.hp << endl;
				mob.hp = mob.maxhp;
			}
			mob.hp -= player.gAttack2();
			cout << "��ȸ�� ��ġ�� �ʰ� ������ �մϴ�. ���� ü�� -" << player.gAttack2() << endl;
		}

		if (exhp - mob.hp >= 10) {
			if (a) {
				DefW[ego]++;
			}
			else if (b) {
				AvoW[ego]++;
			}
			else {
				HealW[ego]++;
			}
		}
		else {
			if (a) {
				DefL[ego]++;
			}
			else if (b) {
				AvoL[ego]++;
			}
			else {
				HealL[ego]++;
			}
		}
		cout << Bayesforturn2d[ego] << " " << Bayesforturn2av[ego] << endl;
		break;
	default:
		break;
	}
}

int Mob::autoselect(State player) {
	int select;
	if (player.myState() == 1)
	{
		select = 0;
	}
	else if (player.myState() == 2)
	{
		select = 1;
	}
	else if (player.myState() == 3 || 4 || 5)
	{
		for (int i = 0; i < 2; i++) {
			if (Bayesforturn1[i] < Bayesforturn1[i + 1])
			{
				select = i + 1;
			}
			else
			{
				select = i;
			}
		}
	}
	return select;


}