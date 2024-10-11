#ifndef MOB_H
#define MOB_H

#include "State.h"
#include <cstdlib> 
#include <ctime>   

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
#endif