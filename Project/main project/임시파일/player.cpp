#include "Player.h"
#include <iostream>

// ������ ����
Player::Player(int a, int b, int h, int av, int d, int he, int spd) : State(a, b, h, d, av, he, spd) {}

// ���� �ൿ ó��
void Player::act1() {
    int pl;
    cout << "���� ����� �����ϼ��� (1. �����, 2. ������): ";
    cin >> pl;

    switch (pl) {
    case 1:
        this->setState(1);  // ���¸� ��������� ����
        cout << "�÷��̾ ������� �����߽��ϴ�.\n";
        break;
    case 2:
        this->setState(2);  // ���¸� ���������� ����
        cout << "�÷��̾ �������� �����߽��ϴ�.\n";
        break;
    default:
        cout << "�߸��� �����Դϴ�.\n";
        break;
    }
}
