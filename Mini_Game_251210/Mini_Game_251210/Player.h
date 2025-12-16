#pragma once
#include "Global.h"
#include <cstdlib> 
#include <ctime> 

class Player
{
public:
	Player(int x, int y);
	~Player() {}
	
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	void SetHp(int HP);
	int GetHp();
	void SetAttack(bool attack);
	bool GetAttack();
	void SetEvade(bool evade);
	bool GetEvade();
	void SetDead(bool dead);
	bool GetDead();

	void Move(char command);
	void Attack();
	void Damage();
	void Evade();

	void BeginUpdate();
	void Update(char command);
	void EndUpdate();
private:
	int posX;
	int posY;
	int hp;
	Movement gMovement;
	bool isAttack;
	bool isEvade;
	bool isDead;
};

