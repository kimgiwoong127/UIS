#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Mob.h"

using namespace std;

// �÷��̾� �� ó�� �Լ�
void playerTurn(Player& player, Mob& mob) {
    int choice;
    cout << "\nPlayer�� �ൿ�� �����ϼ���:\n";
    cout << "1. ����\n";
    cout << "2. ���\n";
    cout << "3. ȸ��\n";
    cout << "4. ȸ��\n";
    cout << "����: ";
    cin >> choice;

    // �÷��̾��� �ൿ ó��
    switch (choice) {
    case 1:  // ����
        player.act1();  // ���� ����
        cout << "�÷��̾ ������ �õ��մϴ�!\n";
        mob.hp -= player.gAttack1();  // �÷��̾ ����
        cout << "���Ͱ� " << player.gAttack1() << " �������� �Ծ����ϴ�. ���� ü��: " << mob.hp << "\n";
        break;
    case 2:  // ���
        player.setState(3);  // ��� ���� ����
        cout << "�÷��̾ �� �õ��մϴ�!\n";
        break;
    case 3: {  // ȸ��
        player.setState(4);  // ȸ�� ���� ����
        cout << "�÷��̾ ȸ�Ǹ� �õ��մϴ�!\n";
        int actualEvadeChance = (rand() % 31) + 20;  // 20%~50% ȸ�� Ȯ��
        int evadeChance = rand() % 100 + 1;
        if (evadeChance <= actualEvadeChance) {
            cout << "�÷��̾ ȸ�ǿ� �����߽��ϴ�! ȸ�� Ȯ��: " << actualEvadeChance << "%\n";
        }
        else {
            cout << "�÷��̾ ȸ�ǿ� �����߽��ϴ�.\n";
        }
        break;
    }
    case 4:  // ȸ��
        player.setState(5);  // ȸ�� ���� ����
        player.hp += player.gHeal();  // �÷��̾� ü�� ȸ��
        if (player.hp > player.maxhp) player.hp = player.maxhp;
        cout << "�÷��̾��� ü���� " << player.hp << "�� ȸ���Ǿ����ϴ�.\n";
        break;
    default:
        cout << "�߸��� �����Դϴ�.\n";
        break;
    }
}

// ���� �� ó�� �Լ�
void monsterTurn(Player& player, Mob& mob) {
    int action = rand() % 2;  // ���Ͱ� �������� ������� ����(�ӽ÷� �ϴ� �����Լ� ó���Ͽ���)

    if (action == 0) {
        cout << "���Ͱ� ������ �õ��մϴ�!\n";
        if (player.myState() == 4) {  // �÷��̾ ȸ�� ���¸� ȸ�� Ȯ��
            int evadeChance = rand() % 100 + 1;
            if (evadeChance <= player.gAvoid()) {
                cout << "�÷��̾ ������ ������ ȸ���߽��ϴ�!\n";
                return;  // ȸ�� ����, ���� ���� ��ȿ
            }
        }
        player.hp -= mob.gAttack1();
        cout << "�÷��̾ " << mob.gAttack1() << " �������� �Ծ����ϴ�. �÷��̾� ü��: " << player.hp << "\n";
    }
    else {
        cout << "���Ͱ� �� �õ��մϴ�!\n";
        mob.turn2(player);
    }
}

// �ӵ� ��� �� ���� ���� �Լ�
void determineTurnOrder(Player& player, Mob& mob) {
    player.setSpeed((rand() % 31) + 20);  // �ӵ��� 20~50 ������ ����
    mob.setSpeed((rand() % 31) + 20);     // �ӵ��� 20~50 ������ ����

    cout << "�÷��̾� �ӵ�: " << player.gSpeed() << " | ���� �ӵ�: " << mob.gSpeed() << "\n";
    if (player.gSpeed() >= mob.gSpeed()) {
        cout << "�÷��̾ ���� �ൿ�մϴ�!\n";
        playerTurn(player, mob);  // �÷��̾� ��
        if (mob.hp > 0) {
            monsterTurn(player, mob);  // ���� ��
        }
    }
    else {
        cout << "���Ͱ� ���� �ൿ�մϴ�!\n";
        monsterTurn(player, mob);  // ���� ��
        if (player.hp > 0) {
            playerTurn(player, mob);  // �÷��̾� ��
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // ���� �õ� �ʱ�ȭ

    // Player ��ü �� Mob ��ü ����
    Player player(30, 40, 100, 15, 20, 25, 25);
    Mob mob(25, 35, 120, 10, 15, 20, 15);

    // ���� ����
    while (player.hp > 0 && mob.hp > 0) {
        determineTurnOrder(player, mob);  // �ӵ��� ���� �� ���� ����

        // �¸� ���� üũ
        if (mob.hp <= 0) {
            cout << "�÷��̾ �¸��߽��ϴ�!\n";
            break;
        }

        if (player.hp <= 0) {
            cout << "�÷��̾ �й��߽��ϴ�...\n";
            break;
        }
    }

    return 0;
}
