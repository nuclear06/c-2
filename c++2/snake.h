#pragma once
#include<iostream>
#include<vector>
#include "VALUE.h"
struct snake
{
	char direct = 'd';
	std::vector<int> x = { 1 };
	std::vector<int> y = { static_cast<int>((WIDE) / 2) };
};
