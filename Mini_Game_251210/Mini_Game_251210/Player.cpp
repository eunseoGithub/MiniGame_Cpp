#include "Player.h"

Player::Player(int x, int y)
{
	posX = x;
	posY = y;
	hp = 20;
	isAttack = false;
	isEvade = false;
	isDead = false;
}

void Player::SetX(int x)
{
	posX = x;
}
int Player::GetX()
{
	return posX;
}
void Player::SetY(int y)
{
	posY = y;
}
int Player::GetY()
{
	return posY;
}
void Player::SetHp(int HP)
{
	hp = HP;
}
int Player::GetHp()
{
	return hp;
}

void Player::SetAttack(bool attack)
{
	isAttack = attack;
}
bool Player::GetAttack()
{
	return isAttack;
}

void Player::SetEvade(bool evade)
{
	isEvade = evade;
}
bool Player::GetEvade()
{
	return isEvade;
}

void Player::SetDead(bool dead)
{
	isDead = dead;
}
bool Player::GetDead()
{
	return isDead;
}

void Player::Move(char command)
{
	switch (command)
	{
	case 'w':
	case 'W':
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
	case 'a':
	case 'A':
		if (posX <=0)
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
	case 's':
	case 'S':
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
	case 'd':
	case 'D':
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
	cout << "벽에 도달해서 움직이지 못합니다." << endl;
}
void Player::Attack()
{
	isAttack = true;
	cout << "플레이어가 공격을 시도했습니다!!" << endl;
}
void Player::Damage()
{
	hp--;
	cout << "플레이어가 데미지 입었습니다. : " << hp << endl;
}
void Player::Evade()
{
	int randomNum = rand() % 10;
	if (randomNum < 2)
	{
		isEvade = true;
		cout << "플레이어가 회피했습니다." << endl;
	}
	else
	{
		cout << "플레이어가 회피를 실패했습니다." << endl;
	}
}

void Player::BeginUpdate()
{
	if (hp <= 0)
		isDead = true;
}

void Player::Update(char command)
{
	if (command != NULL)
	{
		if (command != 'F' && command != 'f')
		{
			Move(command);
		}
		else
		{
			Attack();
		}
	}
}

void Player::EndUpdate()
{
	isEvade = false;
	isAttack = false;
}