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
	int GetPotion();
	void SetPotion(int potion);

private:
	int posX;
	int posY;
	int potion;
};

