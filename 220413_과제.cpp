/*
	10 X10 크기의 맵을 구성한다 2차원 배열
	플레이어는 0 0 에 존재한다
	탈출 지점이 존재한다
	wasd 키입력을 통해 플레이어를 이동시킨다
	탈출지점 0 0 을 제외하고는 랜덤설정
	0이 E에 도달하면 탈출에 성공했습니다 하고 출력후 프로그램 종료


*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));

	char field[10][10];

	int player_x = rand()%10;
	int player_y = rand()%10;
	int end_x = rand() % 10;
	int end_y = rand() % 10;

	char move;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = '#';

	field[player_x][player_y] = 'P';
	field[end_x][end_y] = 'E';



	while (1)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << field[i][j];
			cout << endl;
		}

		move = _getch();
		switch (move)
		{
		case 'a':
			if (player_y != 0) // y값이 0이 아니면
			{
				field[player_x][player_y - 1] = 'P';
				field[player_x][player_y] = '#';
				player_y = player_y - 1;

			}
			break;
		case 'd':
			if (player_y != 10)
			{
				field[player_x][player_y + 1] = 'P';
				field[player_x][player_y] = '#';
				player_y = player_y + 1;
			}
			break;
		case 'w':
			if (player_x != 0)
			{
				field[player_x - 1][player_y] = 'P';
				field[player_x][player_y] = '#';
				player_x = player_x - 1;
			}
			break;
		case 's':
			if (player_x != 10)
			{
				field[player_x + 1][player_y] = 'P';
				field[player_x][player_y] = '#';
				player_x = player_x + 1;
			}
			break;

		default:
			break;
		}

		if (field[end_x][end_y] == 'P')
		{
			cout << "탈출에 성공했습니다!" << endl;
			break;
		}

	}

}

