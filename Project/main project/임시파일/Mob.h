#ifndef MOB_H
#define MOB_H

#include "State.h"
#include <cstdlib>
#include <ctime>

class Mob : public State {
private:
    int attack1W[3] = { 1, 1, 1 };  // 약공격 성공
    int attack1L[3] = { 1, 1, 1 };  // 약공격 실패
    int attack2W[3] = { 1, 1, 1 };  // 강공격 성공
    int attack2L[3] = { 1, 1, 1 };  // 강공격 실패

    int DefW[2] = { 1, 1 };  // 방어 성공
    int DefL[2] = { 1, 1 };  // 방어 실패
    int AvoW[2] = { 1, 1 };  // 회피 성공
    int AvoL[2] = { 1, 1 };  // 회피 실패
    int HealW[2] = { 1, 1 }; // 회복 성공
    int HealL[2] = { 1, 1 }; // 회복 실패

public:
    Mob() {};
    Mob(int a, int b, int h, int av, int d, int he, int spd);

    void turn1(State player);  // 몬스터 공격 턴
    void turn2(State player);  // 몬스터 방어 턴

    // 플레이어의 행동 데이터를 기록하는 함수
    void updatePlayerAction(int action);
};

#endif  // MOB_H
