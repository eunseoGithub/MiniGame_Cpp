#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Movement
{
	int movement[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
};

struct AttackRange
{
	int range[8][2] = { {0,-1},{1,-1},{-1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1} };
};