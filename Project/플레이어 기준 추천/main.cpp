#include "State.h"
#include "Mob.h"
#include "Player.h"

using namespace std;

void determineTurnOrder(Player& player, Mob& mob) {
    player.setSpeed((rand() % 31) + 20);
    mob.setSpeed((rand() % 31) + 20); 

    cout << "플레이어 속도: " << player.gSpeed() << " | 몬스터 속도: " << mob.gSpeed() << endl;
    if (player.gSpeed() >= mob.gSpeed()) {
        cout << "플레이어가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;

        player.turn2(mob);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (mob.gHP() > 0) {
            player.turn1(mob);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
    else {
        cout << "몬스터가 먼저 행동합니다!" << endl;
        cout << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        player.turn1(mob);
        cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        if (player.gHP() > 0) {
            player.turn2(mob);
            cout << endl << "플레이어 체력: " << player.gHP() << " 적의 체력: " << mob.gHP() << endl << endl;;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // 랜덤 시드 초기화

    // Player 객체 및 Mob 객체 생성
    Player player(40, 30, 99999, 15, 20, 25, 25);
    Mob mob(35, 25, 99999, 10, 15, 20, 15);
    int i = 1;
    // 전투 시작
    while (true) {
        cout <<"----------------------"<< i << "번째 턴------------------------" << endl<<endl;
        determineTurnOrder(player, mob);  // 속도에 따라 턴 순서 결정

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