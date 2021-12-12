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
bool FLAG = true;//���ڱ�־��Ϸ�Ƿ����
char enter = ' ';//��������û���ʱ������

int main()
{
	area_initialization();									//��ʼ��
	snake START_snake;										//
	statistic player_sta;									//
	obstacle player_obs;									//�ṹ�嶨����
	while (FLAG)											//
	{
		auto now = clock();
		double zeta = 0;
		if(_SPEED)zeta=player_sta.zeta_speed();

		while (FLAG&&(clock() - now < REFRESHTIME - zeta))			//ˢ�µ�ͼ��ʱ��ѭ�������ڸĳ����ӵ��ٶȣ�
		{	
			direct_get(&START_snake, zeta);					//��ȡ�ƶ�����
			system("cls");
			normal_move(&START_snake);						//�����ƶ�
			judge(&START_snake);							//ʤ���ж�
			area_redraw(&START_snake);						//�ػ��ͼ

			area_print();									//��ӡ��ǰ���

			crate_food();									//ʳ���������
															//�Ե�ʳ��ĺ����ж��ڣ�area_redraw(snake* _snake))��
			
			if(player_obs.time_dis_flag&&player_obs.obstacle_num < OBSTACLE_NUM)
				crate_obstacle(&player_obs);				//�����ϰ���
			if(player_obs.obt_flag)
			{
				player_obs.add();							//�ϰ������ж�ֵ+1
				player_obs.judge();							//�ϰ������ж�
			}
			//�ϰ���չ��ش���
			if (OBSTACLE_EXTEND) {
				player_obs.f_add();
				player_obs.X_expand_judge();
			}
			//---------------------------------------
			if (_SPEED)
			{
			if (zeta < static_cast<double>(REFRESHTIME) - MINUS) ++player_sta.i;	//�ٶ��ж�ֵ+1
				player_sta.visual_speed();					//�ٶȿ��ӻ�
			}												
			cout << endl << "Input:";						//���������������·
		}
	}
	cout << endl << 
			"***************************" << endl;
	cout << "------===GAME OVER===------" << endl;
	cout << "***************************" << endl;
	cout << "Your score is:" << START_snake.x.size() << endl;
	//return 0;
}
