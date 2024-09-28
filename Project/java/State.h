#include<iostream>
using namespace std;
//각 행동을 번호로 간단하게 판단함 더 좋은 방법 있으면 알려주세요
class State {
protected:
	int hp;
	int attack1;
	int attack2;
	int avoid;
	int defense;
	int heal;
	int state = 0;
public:
	void setAttack(int a, int b);
	void setHp(int h);
	void setAvoid(int av);
	void setDefense(int d);
	void setHeal(int he);//몹, 플레이어 각각 설정
	void Idle();
	void Attack();
	void Hp();
	void Avoid();
	void Defense();
	void Heal();//행동
};

void State::setAttack(int a, int b) {
	attack1 = a;
  	attack2 = b;
}

void State::setHp(int h) {
	hp = h;
}

void State::setAvoid(int av) {
	avoid = av;
}

void State::setDefense(int d) {
	defense = d;
}

void State::setHeal(int he) {
	heal = he;
}

void State::Attack() {
	state =1;
}

void State::Hp(){
	state =2;
}
void State::Avoid(){
	state =3;
}
void State::Defense(){
	state =4;
}
void State::Heal(){
	state =5;
}
//추후 각 관계는 몹에서 구현