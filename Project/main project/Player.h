#include "State.h"
using namespace std;
//실시간으로 전투할꺼 일단 보류해두고 공격턴 수비턴으로 나눠서 만들예정.
class Player :public State{
private:
	State player;
public:
	Player(int a, int b, int h, int av, int d, int he);
	void act1(State mob);
	void act2();
};

Player::Player(int a, int b, int h, int av, int d, int he) {
	player = State(a, b, h, av, d, he);
}

void Player::act1(State mob) {
	int pl;
	cin >> pl;
	switch (pl){
		case 1:
			mob.hp-player.gAttack1();
			break;
		case 2:
			mob.hp-player.gAttack2();
			break;
		default:
			break;
	}
}

void Player::act2() {
	int pl;
	cin >> pl;
	switch (pl) {
		case 1:
			player.Defense();//수비턴
			break;
		case 2:
			player.Avoid();
			break;
		case 3:
			player.Heal();
			break;
		default:
			break;
	}
}
/*
수비: State에 들어있는 defense값만큼 체력을 더해뒀다가 공격을 맞고 원래 체력으로 복구.
defense값보다 높은 데미지를 입으면 hp = hp - ((attack1 or attack2) - defense)로 처리.

회피: 0~10의 숫자로 10을 랜덤으로 돌려서 만약 회피보다 값이 높다면 공격 면역.

힐: 그냥 체력힐. 수비랑 밸런스를 위해 값이 더 낮게 설정할 예정.
 */