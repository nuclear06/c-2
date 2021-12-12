#pragma once
#include "snake.h"
#include "VALUE.h"
extern bool FLAG;

extern char area[WIDE][LONG];
void judge(snake* _snake)
{
	//ø’vector≤∂◊Ω
	try
	{
		if (_snake->x.empty()) throw 0;
		if (_snake->y.empty()) throw "BUG";
	}catch(int)
	{
		std::cerr << "x is empty" << std::endl;
		exit(1);
	}catch(const char*)
	{
		std::cerr << "y is empty" << std::endl;
		exit(1);
	}catch(...)
	{
		cerr << "catch unknown bug";
		exit(1);
	}
	const auto x=_snake->x.back();
	const auto y=_snake->y.back();
	//±ﬂΩÁ≈–∂œ
	if(x==0||x>=LONG-1||y==0||y==WIDE-1)
	{
		FLAG = false;
		return;
	}
	//◊‘ …≈–∂œ+’œ∞≠≈–∂œ
	if(area[y][x]==BODY||area[y][x]==HEAD||area[y][x]==OBSTACLE)
	{
		FLAG = false;
		system("pause");
	}
	

}