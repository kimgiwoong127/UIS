#include "State.h"

using namespace std;

class Mob :public State{

public:
	State mob;
	Mob(){};
	Mob(int a, int b, int h, int av, int d, int he);
	void actchoose(State player);
	
};

Mob::Mob(int a, int b, int h, int av, int d, int he) {
	mob = State(a, b, h, av, d,he);
}

void Mob::actchoose(State player) {
	switch (player.myState()){
		case 1:
			mob.hp-player.gAttack1();
			break;
		case 2:
			mob.hp-player.gAttack2();
			break;
		default:
			break;
		case 3:
			player.Defense();//수비턴
			break;
		case 4:
			player.Avoid();
			break;
		case 5:
			player.Heal();
			break;
	}
}