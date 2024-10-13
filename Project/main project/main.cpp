#include "State.h"
#include "Mob.h"
#include "Player.h"

using namespace std;

void monsterTurn(Player player, Mob mob,int turn) {
    if (turn == 1) {
        cout << "몬스터가 공격을 시도합니다!" << endl;
    }else{
        cout << "몬스터가 수비를 시도합니다!" << endl;
    }
}

void determineTurnOrder(Player& player, Mob& mob) {
    player.setSpeed((rand() % 31) + 20);
    mob.setSpeed((rand() % 31) + 20); 

    cout << "플레이어 속도: " << player.gSpeed() << " | 몬스터 속도: " << mob.gSpeed() << endl;
    if (player.gSpeed() >= mob.gSpeed()) {
        cout << "플레이어가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;

        monsterTurn(player, mob,2);
        mob.turn2(player);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (mob.gHP() > 0) {
            monsterTurn(player, mob,1);  // 몬스터 턴
            mob.turn1(player);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
    else {
        cout << "몬스터가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        monsterTurn(player, mob,1);
        mob.turn1(player);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (player.gHP() > 0) {
            monsterTurn(player, mob,2);  // 몬스터 턴
            mob.turn2(player);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
}

void determineTurnOrderB(Player& player, Mob& mob) {
    player.setSpeed((rand() % 31) + 20);
    mob.setSpeed((rand() % 31) + 20);

    cout << "플레이어 속도: " << player.gSpeed() << " | 몬스터 속도: " << mob.gSpeed() << endl;
    if (player.gSpeed() >= mob.gSpeed()) {
        cout << "플레이어가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;

        monsterTurn(player, mob, 2);
        mob.ShowBayesP2(player);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (mob.gHP() > 0) {
            monsterTurn(player, mob, 1);  // 몬스터 턴
            mob.ShowBayesP1(player);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
    else {
        cout << "몬스터가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        monsterTurn(player, mob, 1);
        mob.ShowBayesP1(player);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (player.gHP() > 0) {
            monsterTurn(player, mob, 2);  // 몬스터 턴
            mob.ShowBayesP2(player);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // 랜덤 시드 초기화

    // Player 객체 및 Mob 객체 생성
    Player player(40, 30, 100, 15, 20, 25, 25);
    Mob mob(35, 25, 120, 10, 15, 20, 15);
    int i = 1;
    // 전투 시작
    while (true) {
        cout <<"----------------------"<< i << "번째 턴------------------------" << endl<<endl;
        //determineTurnOrder(player, mob);  // 속도에 따라 턴 순서 결정
        determineTurnOrderB(player, mob); // 이건 베이즈 확률 출력

        if (mob.gHP() <= 0) {
            cout << "플레이어가 승리했습니다!" << endl;
            break;
        }

        if (player.gHP() <= 0) {
            cout << "플레이어가 패배했습니다..." << endl;
            break;
        }
        i++;
    }

    return 0;
}