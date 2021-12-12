#pragma once
#include"snake.h"
void normal_move(snake* _snake)
{
	switch (_snake->direct)
	{
	case'w':
		_snake->y.push_back(_snake->y.back()-1);
		_snake->x.push_back(_snake->x.back());
		break;
	case'a':
		_snake->x.push_back(_snake->x.back()-1);
		_snake->y.push_back(_snake->y.back());
		break;
	case's':
		_snake->y.push_back(_snake->y.back()+1);
		_snake->x.push_back(_snake->x.back());
		break;
	case'd':
		_snake->x.push_back(_snake->x.back()+1);
		_snake->y.push_back(_snake->y.back());
		break;
	default:
		/*cout << "THE PROGRAM ERROR!";
		exit(1);*/;
	}
}
