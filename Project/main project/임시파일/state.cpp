#include "State.h"

// 매개변수 생성자 정의
State::State(int a1, int a2, int h, int d, int av, int he, int spd) : attack1(a1), attack2(a2), defense(d), avoid(av), heal(he), hp(h), maxhp(h), state(0), speed(spd) {}

// 행동 getter 메서드 정의
int State::gAttack1() { return attack1; }
int State::gAttack2() { return attack2; }
int State::gDefense() { return defense; }
int State::gAvoid() { return avoid; }
int State::gHeal() { return heal; }
int State::gSpeed() { return speed; }

// 상태 설정 및 조회 메서드 정의
void State::setState(int s) { state = s; }
int State::myState() { return state; }
void State::setSpeed(int spd) { speed = spd; }