#include "Mob.h"
#include <iostream>

// �� ���� ������
Mob::Mob(int a, int b, int h, int av, int d, int he, int spd) : State(a, b, h, d, av, he, spd) {}

// ���� ���� ��
void Mob::turn1(State player) {
    // ����
}

// ���� ��� ��
void Mob::turn2(State player) {
    // �ۼ�����
}

// �÷��̾��� �ൿ �����͸� ����ϴ� �Լ�
void Mob::updatePlayerAction(int action) {
    // action: �÷��̾ ������ �ൿ (1. ����, 2. ���, 3. ȸ�� ��)
    switch (action) {
    case 1:
        cout << "�÷��̾ ������ �õ��߽��ϴ�. �ൿ ��� ������Ʈ.\n";
        attack1W[0]++;
        break;
    case 2:
        cout << "�÷��̾ �� �õ��߽��ϴ�. �ൿ ��� ������Ʈ.\n";
        DefW[0]++;
        break;
    case 3:
        cout << "�÷��̾ ȸ�Ǹ� �õ��߽��ϴ�. �ൿ ��� ������Ʈ.\n";
        AvoW[0]++;
        break;
    case 4:
        cout << "�÷��̾ ȸ���� �õ��߽��ϴ�. �ൿ ��� ������Ʈ.\n";
        HealW[0]++;
        break;
    default:
        cout << "�� �� ���� �ൿ�Դϴ�.\n";
        break;
    }
}
