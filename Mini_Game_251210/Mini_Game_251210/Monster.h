#pragma once
#include "Global.h"
#include <cstdlib> 
#include <ctime> 
class Monster
{
public:
	Monster(int x, int y);
	~Monster();

	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	void SetHp(int HP);
	int GetHp();
	void SetAttack(bool attack);
	bool GetAttack();
	void SetDead(bool dead);
	bool GetDead();

	void Move();
	void Attack();
	void Damage();

	void BeginUpdate();
	void Update();
	void EndUpdate();

private:
	int posX;
	int posY;
	int hp;
	Movement gMovement;
	bool isAttack;
	bool isDead;
};

