#include "State.h"

using namespace std;

class Mob :public State{

public:
	State mob;
	Mob();
	Mob(int at, int av, int def, int rec, int hp);
	void actchoose();
	
};


Mob::Mob(int at, int av, int def, int rec, int hp) {
	mob = State(at, av, def, rec, hp);
}

Mob::Mob() {
	State(10, 10, 10, 10, 100);
}



void Mob::actchoose() {
	string pl;
	cout << "a1 : 약공, a2 : 강공, av : 회피, d : 방어, h : 힐" << endl;
	pl = mob.checkstate();
	if (pl == "a1")
	{
		int dm = mob.Attack1();
		State target = select(Player::player);
		target.takedamage(dm);
	}
	else if (pl == "a2")
	{
		int dm = mob.Attack2();
		State target = select(Player::player);
		target.takedamage(dm);
	}
	else if (pl == "av")
	{
		mob.Avoid();
	}
	else if (pl == "d")
	{
		mob.Defense();
	}
	else if (pl == "h")
	{
		mob.Heal();
	}

}

