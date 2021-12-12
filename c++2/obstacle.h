#pragma once
#include "MY_random.h"
#include "VALUE.h"
struct obstacle;
struct f_obstacle;

using namespace std;

void crate_obstacle(obstacle* obt);

extern char area[WIDE][LONG];
struct f_obstacle
{
	int x = 0, y = 0;
	char direct{};
	int extend_num = 0;
	int extend_num_max = 0;

	bool f_f_flag = true;

	double i = 0;

	void extend();
	bool expand_judge(int x, int y);
	void start(int x, int y);
	f_obstacle(int _x, int _y, char _direct)
	{
		x = _x;
		y = _y;
		direct = _direct;
		if (OBSTACLE_EXTEND_DISTANCE == 0) extend_num_max = 65535;
		else extend_num_max = OBSTACLE_EXTEND_DISTANCE;
	}
	f_obstacle()
		= default;
};
struct obstacle
{
	double time_distance = 0;
	bool time_dis_flag = true;
	f_obstacle f_ob_arr[OBSTACLE_NUM][4];
	bool obt_flag = true;//障碍是否生成结束
	int obstacle_num = 0;//记录障碍数量
	int _x[OBSTACLE_NUM] = { 0 };//障碍坐标
	int _y[OBSTACLE_NUM] = { 0 };//障碍坐标
	int judgement[OBSTACLE_NUM] = { 0 };//每个障碍创建后的时间记录
	void add();
	void start(int x, int y);
	void judge();
	void f_add();
	void X_expand_judge();
};

void crate_obstacle(obstacle* obt)
{
	if (my_random(OBSTACLE_PROBALITY) == 1)
	{
		const int x = my_random(LONG - 2);
		const int y = my_random(WIDE - 2);
		if (area[y][x] == HEAD || area[y][x] == BODY)
		{
			crate_obstacle(obt);
		}
		else
		{
			obt->start(x, y);
		}
	}
}



void obstacle::start(int x, int y)
{
	area[y][x] = '!';
	_x[obstacle_num] = x;
	_y[obstacle_num] = y;
	f_ob_arr[obstacle_num][0] = f_obstacle(x, y, 'w');
	f_ob_arr[obstacle_num][1] = f_obstacle(x, y, 'a');
	f_ob_arr[obstacle_num][2] = f_obstacle(x, y, 's');
	f_ob_arr[obstacle_num][3] = f_obstacle(x, y, 'd');
	++obstacle_num;
	time_dis_flag = false;
}
void obstacle::add()
{
	++time_distance;
	for (int i = 0; (i <= obstacle_num) && (judgement[OBSTACLE_NUM - 1] < OBSTACLE_TIME); i++)
	{
		++judgement[i];
	}
}
void obstacle::judge()
{
	for (int i = 0; judgement[i] >= OBSTACLE_TIME && i < obstacle_num; i++)
	{
		area[_y[i]][_x[i]] = OBSTACLE;
	}
	if (judgement[OBSTACLE_NUM - 1] > OBSTACLE_TIME) obt_flag = false;
	if (time_distance > OBSTACLE_DISTANCE_TIME) {
		time_dis_flag = true;
		time_distance = 0;
	}
}

void obstacle::f_add()
{
	for (int _i = 0; _i < obstacle_num; ++_i)
	{
		if (f_ob_arr[_i][0].f_f_flag && f_ob_arr[_i][0].i <= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)++f_ob_arr[_i][0].i;
		if (f_ob_arr[_i][1].f_f_flag && f_ob_arr[_i][1].i <= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)++f_ob_arr[_i][1].i;
		if (f_ob_arr[_i][2].f_f_flag && f_ob_arr[_i][2].i <= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)++f_ob_arr[_i][2].i;
		if (f_ob_arr[_i][3].f_f_flag && f_ob_arr[_i][3].i <= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)++f_ob_arr[_i][3].i;
	}
}
inline void obstacle::X_expand_judge()
{
	for (int _i = 0; _i < obstacle_num; ++_i)
	{
		if (f_ob_arr[_i][0].f_f_flag && f_ob_arr[_i][0].i >= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)
			f_ob_arr[_i][0].extend();
		if (f_ob_arr[_i][1].f_f_flag && f_ob_arr[_i][1].i >= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)
			f_ob_arr[_i][1].extend();
		if (f_ob_arr[_i][2].f_f_flag && f_ob_arr[_i][2].i >= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)
			f_ob_arr[_i][2].extend();
		if (f_ob_arr[_i][3].f_f_flag && f_ob_arr[_i][3].i >= static_cast<double>(OBSTACLE_EXTEND_TIME) + OBSTACLE_TIME)
			f_ob_arr[_i][3].extend();

	}
}
void f_obstacle::extend()
{
	if (my_random(OBSTACLE_EXTEND_POSSIBILITY))
	{
		i = 0;
		switch (direct)
		{
		case'w':
			if (expand_judge(x, y - 1))
			{
				--y;
				area[y][x] = OBSTACLE;
				++extend_num;
			}
			break;
		case'a':
			if (expand_judge(x - 1, y))
			{
				--x;
				area[y][x] = OBSTACLE;
				++extend_num;
			}
			break;
		case's':
			if (expand_judge(x, y + 1))
			{
				++y;
				area[y][x] = OBSTACLE;
				++extend_num;
			}
			break;
		case'd':
			if (expand_judge(x + 1, y))
			{
				++x;
				area[y][x] = OBSTACLE;
				++extend_num;
			}
			break;
		default:
			cerr << "ERROR";
			exit(1);


		}
		if (extend_num >= extend_num_max)f_f_flag = false;
	}
}

bool f_obstacle::expand_judge(int x, int y)
{
	if (area[y][x] == '|' || area[y][x] == '_' || area[y][x] == '-')
	{

		f_f_flag = false;
		return false;
	}
	else if (area[y][x] == HEAD || area[y][x] == BODY)
	{
		return false;
	}
	else return true;
}

