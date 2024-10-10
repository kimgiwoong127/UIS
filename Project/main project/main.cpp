#include "State.h"
#include <cstdlib> 
#include <ctime>   
#include <iostream>

using namespace std;

class Mob :public State {
private:
    int attack1W[3] = { 1,1,1 };
    int attack1L[3] = { 1,1,1 };
    int attack2W[3] = { 1,1,1 };
    int attack2L[3] = { 1,1,1 };

    int DefW[2] = { 1,1 };
    int DefL[2] = { 1,1 };
    int AvoW[2] = { 1,1 };
    int AvoL[2] = { 1,1 };
    int HealW[2] = { 1,1 };
    int HealL[2] = { 1,1 };
public:
    State mob;
    Mob() {};
    Mob(int a, int b, int h, int av, int d, int he);
    void turn1(State player);
    void turn2(State player);
};

Mob::Mob(int a, int b, int h, int av, int d, int he) {
    mob = State(a, b, h, av, d, he);
}

void Mob::turn1(State player) {
    int exhp = player.hp;
    srand((unsigned)time(0));
    int choose = rand() % 100;
    int Bayes[3] = {};
    bool a = false;

    for (int i = 0; i < 3; i++) {
        Bayes[i] = (((attack1W[i] / (attack1W[i] + attack1L[i])) * (attack1W[i] / (attack1W[i] + attack2W[i])))
            / ((attack1W[i] + attack2W[i]) / (attack1W[i] + attack2W[i] + attack1L[0] + attack2L[0]))) * 100;
        cout << "Bayes[" << i << "] = " << Bayes[i] << endl; // Debugging output
    }

    switch (player.myState()) {
    case 3:
        if (choose < Bayes[0]) {
            if (player.gDefense() < mob.gAttack1()) {
                player.hp -= mob.gAttack1() - player.gDefense();
            }
            a = true;
        }
        else {
            if (player.gDefense() < mob.gAttack2()) {
                player.hp -= mob.gAttack2() - player.gDefense();
            }
            cout << "약공격" << endl;
        }

        if (exhp - player.hp >= 10) {
            if (a) {
                attack1L[0]++;
                cout << "Attack1L[0] incremented: " << attack1L[0] << endl; // Debugging output
            }
            else {
                attack2L[0]++;
                cout << "Attack2L[0] incremented: " << attack2L[0] << endl; // Debugging output
            }
        }
        else {
            if (a) {
                attack1W[0]++;
                cout << "Attack1W[0] incremented: " << attack1W[0] << endl; // Debugging output
            }
            else {
                attack2W[0]++;
                cout << "Attack2W[0] incremented: " << attack2W[0] << endl; // Debugging output
            }
        }

        break;
    case 4:
        if (choose < Bayes[1]) {
            if ((rand() % 100) >= player.gAvoid()) {
                player.hp -= mob.gAttack1();
            }
            a = true;
        }
        else {
            if ((rand() % 100) >= player.gAvoid()) {
                player.hp -= mob.gAttack2();
            }
        }

        if (exhp - player.hp >= 10) {
            if (a) {
                attack1L[1]++;
                cout << "Attack1L[1] incremented: " << attack1L[1] << endl; // Debugging output
            }
            else {
                attack2L[1]++;
                cout << "Attack2L[1] incremented: " << attack2L[1] << endl; // Debugging output
            }
        }
        else {
            if (a) {
                attack1W[1]++;
                cout << "Attack1W[1] incremented: " << attack1W[1] << endl; // Debugging output
            }
            else {
                attack2W[1]++;
                cout << "Attack2W[1] incremented: " << attack2W[1] << endl; // Debugging output
            }
        }

        break;
    case 5:
        if (choose <= Bayes[2]) {
            player.hp -= mob.gAttack1();
            if (player.hp + player.gHeal() < player.maxhp) {
                player.hp += player.gHeal();
            }
            else {
                player.hp = player.maxhp;
            }
            a = true;
        }
        else {
            player.hp -= mob.gAttack2();
            if (player.hp + player.gHeal() < player.maxhp) {
                player.hp += player.gHeal();
            }
            else {
                player.hp = player.maxhp;
            }
        }

        if (exhp - player.hp >= 10) {
            if (a) {
                attack1L[2]++;
                cout << "Attack1L[2] incremented: " << attack1L[2] << endl; // Debugging output
            }
            else {
                attack2L[2]++;
                cout << "Attack2L[2] incremented: " << attack2L[2] << endl; // Debugging output
            }
        }
        else {
            if (a) {
                attack1W[2]++;
                cout << "Attack1W[2] incremented: " << attack1W[2] << endl; // Debugging output
            }
            else {
                attack2W[2]++;
                cout << "Attack2W[2] incremented: " << attack2W[2] << endl; // Debugging output
            }
        }
        break;
    default:
        break;
    }
}

void Mob::turn2(State player) {
    // You can apply similar debugging logic here for the defense and avoidance values
}
