#include <iostream>
#include "Character.h"
#include "item"

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) : name(userName), job(characterJob), level(1), maxHelth(200), helth(200), attack(30), experience(0), gold(0), accuracy(100), attackspeed(20), evasion(1), isDead(false), mp(100), maxMp(100)
{
    characterJob->applyJobEffect(attack, maxHelth,attackspeed,evasion,accuracy,maxMp);
    helth = maxHelth;
	mp = maxMp;
}

Character* Character::getInstance(string userName, Job* characterJob) {
    if (instance == nullptr) {
        instance = new Character(userName, characterJob);
    }
    return instance;
}

void Character::displayStatus()
{
    cout << "���� ������ ����" << endl;
    cout << "����: " << level << endl;
    cout << "ü��: " << helth << "/" << maxHelth << endl;
    cout << "����: " << mp << "/" << maxMp << endl;
    cout << "����ġ: " << experience << endl;
    cout << "���ݷ�: " << attack << endl;
    cout << "�������: " << gold << endl;
	cout << "���ݼӵ�: " << attackspeed << endl;
	cout << "���߷�: " << accuracy << endl;
	cout << "ȸ����: " << evasion << endl;
    cout << "����: " << job->getJobName() << endl;
}

void Character::levelUp()
{
    level++;
    maxHelth += level * 20;
    helth = maxHelth;
    attack += level * 5;
    cout << "������!" << name << "�� ������ " << level << "�� �Ǿ����ϴ�!" << endl;
}


void Character::useItem(Item* item)
{
	inventory.useItem(item);
}
void Character::addItemToInventory(Item* item)
{
	inventory.addItem(item);
}
void Character::removeItemFromInventory(Item* item)
{
	inventory.removeItem(item);
}
void Character::displayInventory() {
	inventory.listItem();
}