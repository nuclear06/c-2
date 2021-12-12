#pragma once
#include <random>
using namespace std;

inline int my_random(int max)
{
	std::random_device rd;
	default_random_engine rand(rd());
	uniform_int_distribution<> pos{ 1,max };
	return pos(rand);
}
	