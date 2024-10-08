#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

// State 클래스 (기본적으로 플레이어와 몬스터가 상속)
class State {
private:
    int attack1;
    int attack2;
    int defense;
    int avoid; // 회피 확률
    int heal;
    int state; // 상태 저장
    int speed; // 속도 추가

public:
    int hp;    // 현재 체력
    int maxhp; // 최대 체력

    // 기본 생성자 및 매개변수 생성자
    State() : attack1(0), attack2(0), defense(0), avoid(0), heal(0), state(0), hp(0), maxhp(0), speed(0) {} // 기본 생성자에서 멤버 변수 초기화
    State(int a1, int a2, int h, int d, int av, int he, int spd);

    // 행동 getter 메서드
    int gAttack1();
    int gAttack2();
    int gDefense();
    int gAvoid(); // 회피 확률 반환
    int gSpeed(); // 속도 반환
    int gHeal();

    // 상태 설정 및 조회
    void setState(int s);
    int myState();  // 현재 상태 반환
    void setSpeed(int spd); // 속도 설정
};

#endif
