#include "areaOP.h"
#include "Gdir.h"
#include "JUDEG.h"
#include "snake.h"
#include "MOVE.h"
#include "FOOD.h"
#include "statistic.h"
#include "obstacle.h"
using namespace std;
char area[WIDE][LONG];
bool FLAG = true;//用于标志游戏是否结束
char enter = ' ';//用于输出用户此时的输入

int main()
{
	area_initialization();									//初始化
	snake START_snake;										//
	statistic player_sta;									//
	obstacle player_obs;									//结构体定义区
	while (FLAG)											//
	{
		auto now = clock();
		double zeta = 0;
		if(_SPEED)zeta=player_sta.zeta_speed();

		while (FLAG&&(clock() - now < REFRESHTIME - zeta))			//刷新地图的时间循环（后期改成增加的速度）
		{	
			direct_get(&START_snake, zeta);					//获取移动方向
			system("cls");
			normal_move(&START_snake);						//进行移动
			judge(&START_snake);							//胜负判断
			area_redraw(&START_snake);						//重绘地图

			area_print();									//打印当前情况

			crate_food();									//食物随机生成
															//吃到食物的后续判断在（area_redraw(snake* _snake))中
			
			if(player_obs.time_dis_flag&&player_obs.obstacle_num < OBSTACLE_NUM)
				crate_obstacle(&player_obs);				//创建障碍物
			if(player_obs.obt_flag)
			{
				player_obs.add();							//障碍警告判断值+1
				player_obs.judge();							//障碍激活判断
			}
			//障碍拓展相关代码
			if (OBSTACLE_EXTEND) {
				player_obs.f_add();
				player_obs.X_expand_judge();
			}
			//---------------------------------------
			if (_SPEED)
			{
			if (zeta < static_cast<double>(REFRESHTIME) - MINUS) ++player_sta.i;	//速度判断值+1
				player_sta.visual_speed();					//速度可视化
			}												
			cout << endl << "Input:";						//给输出键盘输入铺路
		}
	}
	cout << endl << 
			"***************************" << endl;
	cout << "------===GAME OVER===------" << endl;
	cout << "***************************" << endl;
	cout << "Your score is:" << START_snake.x.size() << endl;
	//return 0;
}
