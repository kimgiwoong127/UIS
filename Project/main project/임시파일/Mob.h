#ifndef MOB_H
#define MOB_H

#include "State.h"
#include <cstdlib>
#include <ctime>

class Mob : public State {
private:
    int attack1W[3] = { 1, 1, 1 };  // ����� ����
    int attack1L[3] = { 1, 1, 1 };  // ����� ����
    int attack2W[3] = { 1, 1, 1 };  // ������ ����
    int attack2L[3] = { 1, 1, 1 };  // ������ ����

    int DefW[2] = { 1, 1 };  // ��� ����
    int DefL[2] = { 1, 1 };  // ��� ����
    int AvoW[2] = { 1, 1 };  // ȸ�� ����
    int AvoL[2] = { 1, 1 };  // ȸ�� ����
    int HealW[2] = { 1, 1 }; // ȸ�� ����
    int HealL[2] = { 1, 1 }; // ȸ�� ����

public:
    Mob() {};
    Mob(int a, int b, int h, int av, int d, int he, int spd);

    void turn1(State player);  // ���� ���� ��
    void turn2(State player);  // ���� ��� ��

    // �÷��̾��� �ൿ �����͸� ����ϴ� �Լ�
    void updatePlayerAction(int action);
};

#endif  // MOB_H
