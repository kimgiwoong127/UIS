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
	string state = nothing;  //���� ��� ������ ü��
public:
	int Shp;//ĳ������ ���ȵ�
	int Sav;
	int Sat;
	int Sdef;
	int Srec;
	State() {};
	State(int at, int av, int def, int rec, int hp);//��, �÷��̾��� ���� ����
	int Idle();
	int Attack1();
	int Attack2();
	void takedamage(int deal);
	void Avoid();
	void Defense();
	void Heal();//�ൿ
	string myState();
	State select(State target);
	string checkstate(State target);
};

State::State(int at, int av, int def, int rec, int hp) {//������� ���ݷ�, ȸ����, ����, ȸ����, ü��
	Sat = at;
	Sav = av;
	Sdef = def;
	Srec = rec;
	Shp = hp;
}

string State::checkstate(State target) { //�ϴ� ���� �÷��̾� �ൿ �������� �ۼ� ��
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

