#include<iostream>
using namespace std;
//각 행동을 번호로 간단하게 판단함 더 좋은 방법 있으면 알려주세요
class State {
private:
	int attack1;
	int attack2;
	int avoid;
	int defense;
	int heal;
	int state = 0;
public:
	int hp;//hp는 계속 유동적으로 바뀔거 같아서 일단 public에 뒀음
	State() {};
	State(int a, int b,int h,int av,int d,int he);//몹, 플레이어 각각 설정
	void Idle();
	int gAttack1();//추후 관계를 위해 get제작함
	int gAttack2();
	int gAvoid();
	int gDefense();
	int gHeal();
	void Attack1();
	void Attack2();
	void Avoid();
	void Defense();
	void Heal();//행동
	int myState();
};

State::State(int a, int b,int h,int av,int d,int he){//순서대로 강공, 약공, 체력, 회피율, 방어, 회복
	attack1 = a;
  	attack2 = b;
	hp = h;
	avoid = av;
	defense = d;
	heal = he;
}

void State::Idle(){
	state=0;
}

int State::gAttack1() {
	return attack1;
}

int State::gAttack2() {
	return attack2;
}

int State::gAvoid() {
	return avoid;
}

int State::gDefense() {
	return defense;
}

int State::gHeal() {
	return heal;
}

void State::Attack1() {
	state =1;
}

void State::Attack2() {
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

int State::myState(){
	return state;
}
//추후 각 관계는 몹에서 구현