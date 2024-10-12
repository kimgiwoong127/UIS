#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Mob.h"

using namespace std;

// 플레이어 턴 처리 함수
void playerTurn(Player& player, Mob& mob) {
    int choice;
    cout << "\nPlayer의 행동을 선택하세요:\n";
    cout << "1. 공격\n";
    cout << "2. 방어\n";
    cout << "3. 회피\n";
    cout << "4. 회복\n";
    cout << "선택: ";
    cin >> choice;

    // 플레이어의 행동 처리
    switch (choice) {
    case 1:  // 공격
        player.act1();  // 공격 실행
        cout << "플레이어가 공격을 시도합니다!\n";
        mob.hp -= player.gAttack1();  // 플레이어가 공격
        cout << "몬스터가 " << player.gAttack1() << " 데미지를 입었습니다. 몬스터 체력: " << mob.hp << "\n";
        break;
    case 2:  // 방어
        player.setState(3);  // 방어 상태 설정
        cout << "플레이어가 방어를 시도합니다!\n";
        break;
    case 3: {  // 회피
        player.setState(4);  // 회피 상태 설정
        cout << "플레이어가 회피를 시도합니다!\n";
        int actualEvadeChance = (rand() % 31) + 20;  // 20%~50% 회피 확률
        int evadeChance = rand() % 100 + 1;
        if (evadeChance <= actualEvadeChance) {
            cout << "플레이어가 회피에 성공했습니다! 회피 확률: " << actualEvadeChance << "%\n";
        }
        else {
            cout << "플레이어가 회피에 실패했습니다.\n";
        }
        break;
    }
    case 4:  // 회복
        player.setState(5);  // 회복 상태 설정
        player.hp += player.gHeal();  // 플레이어 체력 회복
        if (player.hp > player.maxhp) player.hp = player.maxhp;
        cout << "플레이어의 체력이 " << player.hp << "로 회복되었습니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다.\n";
        break;
    }
}

// 몬스터 턴 처리 함수
void monsterTurn(Player& player, Mob& mob) {
    int action = rand() % 2;  // 몬스터가 공격할지 방어할지 결정(임시로 일단 랜덤함수 처리하였음)

    if (action == 0) {
        cout << "몬스터가 공격을 시도합니다!\n";
        if (player.myState() == 4) {  // 플레이어가 회피 상태면 회피 확인
            int evadeChance = rand() % 100 + 1;
            if (evadeChance <= player.gAvoid()) {
                cout << "플레이어가 몬스터의 공격을 회피했습니다!\n";
                return;  // 회피 성공, 몬스터 공격 무효
            }
        }
        player.hp -= mob.gAttack1();
        cout << "플레이어가 " << mob.gAttack1() << " 데미지를 입었습니다. 플레이어 체력: " << player.hp << "\n";
    }
    else {
        cout << "몬스터가 방어를 시도합니다!\n";
        mob.turn2(player);
    }
}

// 속도 기반 턴 순서 결정 함수
void determineTurnOrder(Player& player, Mob& mob) {
    player.setSpeed((rand() % 31) + 20);  // 속도를 20~50 범위로 설정
    mob.setSpeed((rand() % 31) + 20);     // 속도를 20~50 범위로 설정

    cout << "플레이어 속도: " << player.gSpeed() << " | 몬스터 속도: " << mob.gSpeed() << "\n";
    if (player.gSpeed() >= mob.gSpeed()) {
        cout << "플레이어가 먼저 행동합니다!\n";
        playerTurn(player, mob);  // 플레이어 턴
        if (mob.hp > 0) {
            monsterTurn(player, mob);  // 몬스터 턴
        }
    }
    else {
        cout << "몬스터가 먼저 행동합니다!\n";
        monsterTurn(player, mob);  // 몬스터 턴
        if (player.hp > 0) {
            playerTurn(player, mob);  // 플레이어 턴
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // 랜덤 시드 초기화

    // Player 객체 및 Mob 객체 생성
    Player player(30, 40, 100, 15, 20, 25, 25);
    Mob mob(25, 35, 120, 10, 15, 20, 15);

    // 전투 시작
    while (player.hp > 0 && mob.hp > 0) {
        determineTurnOrder(player, mob);  // 속도에 따라 턴 순서 결정

        // 승리 조건 체크
        if (mob.hp <= 0) {
            cout << "플레이어가 승리했습니다!\n";
            break;
        }

        if (player.hp <= 0) {
            cout << "플레이어가 패배했습니다...\n";
            break;
        }
    }

    return 0;
}