#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class State {
private:
	string attack1="a1";
	string attack2="a2";
	string avoid="av";
	string defense="d";
	string heal="h";
	string nothing = "n";
	string state = nothing;  //서로 명령 오가는 체계
public:
	int Shp;//캐릭터의 스탯들
	int Sav;
	int Sat;
	int Sdef;
	int Srec;
	State() {};
	State(int at, int av, int def, int rec, int hp);//몹, 플레이어의 스탯 설정
	int Idle();
	int Attack1();
	int Attack2();
	void takedamage(int deal);
	void Avoid();
	void Defense();
	void Heal();//행동
	string myState();
	State select(State target);
	string checkstate(State target);
};

State::State(int at, int av, int def, int rec, int hp) {//순서대로 공격력, 회피율, 방어력, 회복량, 체력
	Sat = at;
	Sav = av;
	Sdef = def;
	Srec = rec;
	Shp = hp;
}

string State::checkstate(State target) { //일단 몹만 플레이어 행동 따오도록 작성 중
	if (target.myState() == "a1")
	{
		return "av";
	}
	else if (target.myState() == "a2")
	{
		return "d";
	}
	else if (target.myState() == "av" || target.myState() == "d")
	{
		if (this->Shp < 50)
		{
			return "h";
		}
		else
		{
			return "a1";
		}

	}
	else if (target.myState() == "h" || target.myState() == "n")
	{
		if (this->Shp < 50)
		{
			return "h";
		}
		else
		{
			return "a2";
		}

	}
}

int State::Idle() {
	state = "n";
	return 0;
}

State State::select(State target) {
	return target;
}

int State::Attack1() {
	state = attack1;
	return Sat;
}

int State::Attack2() {
	state = attack2;
	return Sat * 2;
}

void State::takedamage(int deal) {
	if (state == "n" || state=="h")
	{
		Shp = Shp - deal;
	}
	else if(state == "d")
	{
		Shp = Shp - (deal - Sdef);
	}
	else
	{
		Shp = Shp;
	}
	
}

void State::Avoid() {
	srand(time(NULL));
	int number = rand() % 100 + 1;
	if (number < Sav)
	{
		state = avoid;
	}
	else
	{
		state = nothing;
	}
}
void State::Defense() {
	state = defense;
}
void State::Heal() {
	state = heal;
	Shp = Shp + Srec;
}

string State::myState() {
	return state;
}

