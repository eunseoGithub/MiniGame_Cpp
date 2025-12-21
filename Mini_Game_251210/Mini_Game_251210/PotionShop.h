#pragma once
class PotionShop
{
public:
	PotionShop(int x, int y);

	void DispensePotion();
	void ReturnPotion();
	
	int GetX();
	void SetX(int x);
	int GetY();
	void SetY(int y);

private:
	int posX;
	int posY;
};

