#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Character.h"
#include "Shop.h"
#include "Inventory.h"

using namespace std;

// Text RPG에서 GameManager는 단 하나만 존재해야 하므로 싱글톤 사용
class GameManager
{
private:
	// 정적 멤버 변수로 싱글톤 인스턴스를 저장
	static GameManager* instance;

	GameManager()
	{
	};

	~GameManager()
	{
	};

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager) = delete;


public:
	// 싱글톤 인스턴스 접근 메서드
	static GameManager* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}

	// 상점 방문
	void visitShop(Character* player)
	{
		Shop shop;
		shop.displayItems();

		int choice;
		cout << "아이템 구매 : 1 , 아이템 판매 : 2 >> ";
		cin >> choice;

		if (choice == 1)
		{
			int index;
			cout << "몇 번 아이템을 구매하시겠습니까? >> ";
			cin >> index;
			shop.buyItem(index, player);
		}
		else if (choice == 2)
		{
			int index;
			cout << "몇 번 아이템을 판매하시겠습니까? >> ";
			cin >> index;
			shop.sellItem(index, player);
		}
		else
		{
			cout << "부적절한 입력입니다." << endl;
		}
	}

	// 인벤토리 표시
	void displayInventory(Inventory inventory)
	{
		Inventory inventory;
		cout << "======현재 소지한 아이템======" << endl;
		inventory.listItem();
		cout << "==============================." << endl;
	}

};

#endif // !GAMEMANAGER_H_