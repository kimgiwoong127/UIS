#include "Player.h"
#include <iostream>

// 생성자 구현
Player::Player(int a, int b, int h, int av, int d, int he, int spd) : State(a, b, h, d, av, he, spd) {}

// 공격 행동 처리
void Player::act1() {
    int pl;
    cout << "공격 방법을 선택하세요 (1. 약공격, 2. 강공격): ";
    cin >> pl;

    switch (pl) {
    case 1:
        this->setState(1);  // 상태를 약공격으로 설정
        cout << "플레이어가 약공격을 선택했습니다.\n";
        break;
    case 2:
        this->setState(2);  // 상태를 강공격으로 설정
        cout << "플레이어가 강공격을 선택했습니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다.\n";
        break;
    }
}
