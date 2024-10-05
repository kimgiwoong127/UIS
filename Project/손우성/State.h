#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <memory>

using namespace std;

class State {
public:
    virtual ~State() {}
    virtual void enter() = 0;
    virtual void update() = 0;
    virtual void exit() = 0;
};

class IdleState : public State {
public:
    void enter() override {
        cout << "Entering Idle State\n";
    }
    void update() override {
        cout << "Idle...\n";
    }
    void exit() override {
        cout << "Exiting Idle State\n";
    }
};

class AttackState : public State {
public:
    void enter() override {
        cout << "Entering Attack State\n";
    }
    void update() override {
        cout << "Attacking!\n";
    }
    void exit() override {
        cout << "Exiting Attack State\n";
    }
};

class DodgeState : public State {
public:
    void enter() override {
        cout << "Entering Dodge State\n";
    }
    void update() override {
        cout << "Dodging!\n";
    }
    void exit() override {
        cout << "Exiting Dodge State\n";
    }
};

class HealState : public State {
public:
    void enter() override {
        cout << "Entering Heal State\n";
    }
    void update() override {
        cout << "Healing!\n";
    }
    void exit() override {
        cout << "Exiting Heal State\n";
    }
};

#endif
