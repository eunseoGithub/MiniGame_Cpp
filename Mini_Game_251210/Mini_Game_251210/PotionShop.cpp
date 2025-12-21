#include "PotionShop.h"

PotionShop::PotionShop(int x, int y)
{
	posX = x;
	posY = y;
}

void PotionShop::DispensePotion()
{

}
void PotionShop::ReturnPotion()
{

}

int PotionShop::GetX()
{
	return posX;
}
void PotionShop::SetX(int x)
{
	posX = x;
}
int PotionShop::GetY()
{
	return posY;
}
void PotionShop::SetY(int y)
{
	posY = y;
}