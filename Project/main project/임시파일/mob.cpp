#include "Mob.h"
#include <iostream>

// 몹 설정 생성자
Mob::Mob(int a, int b, int h, int av, int d, int he, int spd) : State(a, b, h, d, av, he, spd) {}

// 몬스터 공격 턴
void Mob::turn1(State player) {
    // 아직
}

// 몬스터 방어 턴
void Mob::turn2(State player) {
    // 작성못함
}

// 플레이어의 행동 데이터를 기록하는 함수
void Mob::updatePlayerAction(int action) {
    // action: 플레이어가 선택한 행동 (1. 공격, 2. 방어, 3. 회피 등)
    switch (action) {
    case 1:
        cout << "플레이어가 공격을 시도했습니다. 행동 기록 업데이트.\n";
        attack1W[0]++;
        break;
    case 2:
        cout << "플레이어가 방어를 시도했습니다. 행동 기록 업데이트.\n";
        DefW[0]++;
        break;
    case 3:
        cout << "플레이어가 회피를 시도했습니다. 행동 기록 업데이트.\n";
        AvoW[0]++;
        break;
    case 4:
        cout << "플레이어가 회복을 시도했습니다. 행동 기록 업데이트.\n";
        HealW[0]++;
        break;
    default:
        cout << "알 수 없는 행동입니다.\n";
        break;
    }
}