#include "Character.h"
#include "ActionStats.h"
#include <cstdlib> 
#include <ctime>   

using namespace std;

void makeDecision(Character& character, ActionStats& stats) {
    string bestAction = stats.getBestAction();
    if (bestAction == "Attack") {
        character.changeState(make_unique<AttackState>());
    } else if (bestAction == "Dodge") {
        character.changeState(make_unique<DodgeState>());
    } else if (character.getHP() <= 20) { // 체력이 낮으면 회복 상태로 전환
        character.changeState(make_unique<HealState>());
    }
}

void determineEnemyAction(Character& enemy, int playerAttackType, int enemyAvoidChance) {
    int enemyActionChance = rand() % 100;
    
    if (playerAttackType == 1) { // 약공격
        if (enemyActionChance < 50) {
            enemy.changeState(make_unique<IdleState>());
            cout << "Enemy chooses to defend weak attack.\n";
        } else {
            cout << "Enemy takes damage from weak attack.\n";
        }
    }
    else if (playerAttackType == 2) { // 강공격
        if (enemyActionChance < 50 + enemyAvoidChance) {
            enemy.changeState(make_unique<DodgeState>());
            cout << "Enemy dodges strong attack!\n";
        } else {
            cout << "Enemy takes heavy damage from strong attack.\n";
        }
    }
}

int main() {
    srand((unsigned)time(0));  // 난수 시드 초기화

    // 캐릭터와 적 생성 (체력, 회피율)
    Character player(100);
    Character enemy(80);
    ActionStats stats;

    // 게임 루프 예시
    int playerAttackType = 1; // 1: 약공격, 2: 강공격
    int enemyAvoidChance = 25; // 적의 회피율

    // 플레이어가 약공격
    player.changeState(make_unique<AttackState>());
    player.update();
    determineEnemyAction(enemy, playerAttackType, enemyAvoidChance);

    // 플레이어가 강공격
    playerAttackType = 2;
    player.changeState(make_unique<AttackState>());
    player.update();
    determineEnemyAction(enemy, playerAttackType, enemyAvoidChance);

    return 0;
}
