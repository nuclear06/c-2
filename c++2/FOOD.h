#pragma once
#include"VALUE.h"
#include<ctime>
#include<random>

#include "MY_random.h"
#include "snake.h"
using namespace std;
extern char area[WIDE][LONG];

void crate_food()
{
	if (my_random(FOOD_PROBALITY) == 1)
	{
		const int x = my_random(LONG - 2);
		const int y = my_random(WIDE-2);
		if (area[y][x] == BODY || area[y][x] == HEAD)
		{
			crate_food();
		}
		else
		{
			area[y][x] = _FOOD;
		}
	}

}
