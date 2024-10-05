#include "State.h"

using namespace std;

class Player :public State {

public:
	State player;
	Player();
	Player(int at, int av, int def, int rec, int hp);
	void actchoose();
};

Player::Player(int at, int av, int def, int rec, int hp) {
	player = State(at, av, def,  rec,  hp);
}

Player::Player() {
	player=State(10, 10, 10, 10, 100);
}

void Player::actchoose() {
	string pl;
	cout << "a1 : 약공, a2 : 강공, av : 회피, d : 방어, h : 힐" << endl;
	cin >>pl;
	if (pl == "a1")
	{
		int dm = player.Attack1();
		State target = select(Mob::mob);
		target.takedamage(dm);
	}
	else if (pl == "a2")
	{
		int dm = player.Attack2();
		State target = select(Mob::mob);
		target.takedamage(dm);
	}
	else if (pl == "av")
	{
		player.Avoid();
	}
	else if (pl == "d")
	{
		player.Defense();
	}
	else if (pl == "h")
	{
		player.Heal();
	}

}
