#pragma once
#include"VALUE.h"
using namespace std;
struct statistic
{
	double i = 0;				//cpuÆµÂÊ£¨doge
	int w=0;
	int a=0;
	int s=0;
	int d=0;
	double num = WHOLETIME / REFRESHTIME;
	double zeta_speed()
	{
		/*double j = 10;*/
		return i / num * REFRESHTIME;
	}
	void visual_speed()
	{
		cout << "SPEED:";
		int m;
		for( m=1;m<=static_cast<int>(ALL_LEVEL * i/num);++m)
		{
			cout << "=";
		}
		for(int j=ALL_LEVEL-m;j>0;--j)
		{
			cout << "-";
		}
	}
};