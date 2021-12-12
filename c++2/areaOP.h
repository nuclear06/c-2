#pragma once
#include<iostream>

#include "FOOD.h"
#include "snake.h"
#include "VALUE.h"
using namespace std;
extern char area[WIDE][LONG];

inline void area_initialization()
{
	for (int row = 0; row < WIDE; row++)
	{
		for (int list = 0; list < LONG; list++)
		{
			if (row == 0 || row == WIDE - 1)
			{
				area[0][list] = '_';
				area[WIDE - 1][list] = '-';
			}
			else
			{
				area[row][list] = ' ';
			}
		}
		area[row][0] = '|';
		area[row][LONG - 1] = '|';
	}
}

inline void area_print()
{
	for (auto& row : area)
	{
		for (auto list : row) cout << list;
		cout << endl;
	}
}

inline void area_redraw(snake* _snake)
{
	auto const x = *_snake->x.begin();
	auto const y = *_snake->y.begin();
	auto const x1 = _snake->x.back();
	auto const y1 = _snake->y.back();
	if (area[y1][x1] == _FOOD)		//用于食物判断
	{
		area[y1][x1] = HEAD;
		area[y][x] = BODY;
	}
	else {
		area[y1][x1] = HEAD;
		area[y][x] = ' ';
		if (_snake->x.size() > 2)
		{
			auto const x2 = *(_snake->x.end() - 2);
			auto const y2 = *(_snake->y.end() - 2);
			area[y2][x2] = BODY;
		}
		_snake->x.erase(_snake->x.begin());
		_snake->y.erase(_snake->y.begin());
	}
}