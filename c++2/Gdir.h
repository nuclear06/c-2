#pragma once
#include <iostream>
#include<conio.h>
#include "snake.h"
#include "VALUE.h"
/**
 * bug 1
 * direct_get()��������ͨ������������ʵ�����ƶ������෴���ƶ�
 * ԭ����¼�����ݱ��޸ĵ������ѭ��δ���㣬δ�ƶ�ʱ�ͽ�����
 *
 */
void direct_get(snake* _snake, double zeta)
{
	const auto now1 = clock();
	char temp2 = _snake->direct;					//���ڻ���temp
	while (clock() - now1 < REFRESHTIME - zeta)		//����1.�������� 2.�ӳ�ʱ��
	{
		const auto now2 = clock();
		while (clock() - now2 < WAITTIME && _kbhit())
		{
			 const char temp = static_cast<char>(_getch());
			/* char temp1 = '\0';
			 if (_kbhit())   temp1 = static_cast<char>(_getch()); */
			const char dir = _snake->direct;
			const unsigned int length = _snake->x.size();
			switch (temp)
			{
			case'W':
				if (dir != 's' || length == 1)temp2 = 'w';
				break;
			case'w':
				if (dir != 's' || length == 1)temp2 = temp;
				break;
			case'A':
				if (dir != 'd' || length == 1)temp2 = 'a';
				break;
			case'a':
				if (dir != 'd' || length == 1)temp2 = temp;
				break;
			case'S':
				if (dir != 'w' || length == 1)temp2 = 's';
				break;
			case's':
				if (dir != 'w' || length == 1)temp2 = temp;
				break;
			case'D':
				if (dir != 'a' || length == 1)temp2 = 'd';
				break;
			case'd':
				if (dir != 'a' || length == 1)temp2 = temp;
				break;

				/*case'W':
				case'A':
				case'S':
				case'D':�Ժ���ʵ��   ��ʵ��*/


				//case -32:
 		//		switch (temp1)
			//	{
			//	case 72:		//w
			//		if (dir != 's' || length == 1) {
			//			temp2 = 'w';
			//			temp = 'w';
			//		}
			//		else
			//		{
			//			temp2 = _snake->direct;
			//		}
			//		break;
			//	case 80:	//s
			//		if (dir != 'w' || length == 1) {
			//			temp2 = 's';
			//			temp = 's';
			//		}
			//		else
			//		{
			//			temp2 = _snake->direct;
			//		}
			//		break;
			//	case 77:	//d
			//		if (dir != 'a' || length == 1) {
			//			temp2 = 'd';
			//			temp = 'd';
			//		}
			//		else
			//		{
			//			temp2 = _snake->direct;
			//		}
			//		break;
			//	case 75:	//a
			//		if (dir != 'd' || length == 1) {
			//			temp2 = 'a';
			//			temp = 'a';
			//		}
			//		else
			//		{
			//			temp2 = _snake->direct;
			//		}

			//		break;
			//	default:
			//		break;
			//	}
			//	break;
			default:
				cerr << "��Ч���� ";
				/*exit(1);*/
				break;
			}
			std::cout << temp << ' ';			//��ӡ���յ��İ���
		}
	}
	_snake->direct = temp2;
}
