#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

// State Ŭ���� (�⺻������ �÷��̾�� ���Ͱ� ���)
class State {
private:
    int attack1;
    int attack2;
    int defense;
    int avoid; // ȸ�� Ȯ��
    int heal;
    int state; // ���� ����
    int speed; // �ӵ� �߰�

public:
    int hp;    // ���� ü��
    int maxhp; // �ִ� ü��

    // �⺻ ������ �� �Ű����� ������
    State() : attack1(0), attack2(0), defense(0), avoid(0), heal(0), state(0), hp(0), maxhp(0), speed(0) {} // �⺻ �����ڿ��� ��� ���� �ʱ�ȭ
    State(int a1, int a2, int h, int d, int av, int he, int spd);

    // �ൿ getter �޼���
    int gAttack1();
    int gAttack2();
    int gDefense();
    int gAvoid(); // ȸ�� Ȯ�� ��ȯ
    int gSpeed(); // �ӵ� ��ȯ
    int gHeal();

    // ���� ���� �� ��ȸ
    void setState(int s);
    int myState();  // ���� ���� ��ȯ
    void setSpeed(int spd); // �ӵ� ����
};

#endif
