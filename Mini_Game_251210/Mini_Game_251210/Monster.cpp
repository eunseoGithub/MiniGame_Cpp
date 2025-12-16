#include "Monster.h"
Monster::Monster(int x,int y)
{
	posX = x;
	posY = y;
	hp = 3;
	isAttack = false;
	isDead = false;
}
Monster::~Monster()
{

}
void Monster::SetX(int x)
{
	posX = x;
}
int Monster::GetX()
{
	return posX;
}
void Monster::SetY(int y)
{
	posY = y;
}
int Monster::GetY()
{
	return posY;
}
void Monster::SetHp(int HP)
{
	hp = HP;
}
int Monster::GetHp()
{
	return hp;
}
void Monster::SetAttack(bool attack)
{
	isAttack = attack;
}
bool Monster::GetAttack()
{
	return isAttack;
}

void Monster::SetDead(bool dead)
{
	isDead = dead;
}
bool Monster::GetDead()
{
	return isDead;
}

void Monster::Move()
{
	int randomNum = rand() % 4;
	switch (randomNum)
	{
	case 0:
		if (posY <= 0)
		{
			break;
		}
		else
		{
			posX += gMovement.movement[0][0];
			posY += gMovement.movement[0][1];
			return;
		}
		break;
	case 1:
		if (posX <= 0)
		{
			break;
		}
		else
		{
			posX += gMovement.movement[2][0];
			posY += gMovement.movement[2][1];
			return;
		}
		break;
	case 2: 
		if (posY >= 19)
		{
			break;
		}
		else
		{
			posX += gMovement.movement[1][0];
			posY += gMovement.movement[1][1];
			return;
		}
		break;
	case 3:
		if (posX >= 19)
		{
			break;
		}
		else
		{
			posX += gMovement.movement[3][0];
			posY += gMovement.movement[3][1];
			return;
		}
		break;
	}
	cout << "몬스터가 벽에 도달해서 움직이지 못합니다." << endl;
}
void Monster::Attack()
{
	isAttack = true;
	cout << "몬스터가 공격을 시도했습니다!!" << endl;
}
void Monster::Damage()
{
	hp--;
	cout << "몬스터가 데미지 입었습니다. : " << hp << endl;
}

void Monster::BeginUpdate()
{
	if (hp <= 0)
		isDead = true;
}
void Monster::Update()
{
	if (isDead)
		return;
	int randNum = -1;
	randNum = rand() % 2;
	if (randNum == 0)
	{
		Move();
	}
	else
	{
		Attack();
	}
}
void Monster::EndUpdate()
{
	isAttack = false;
}