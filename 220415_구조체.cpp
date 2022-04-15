/*
 미궁 탈출 게임 업데이트
 사용할 수 있는 모든 요소에 구조체를 활용해서 소스코드를 개선.
 tile : 지형 정보를 넣고 ( 숲 , 늪 , 평지 )
 player : 피로도를 넣고
 플레이어가 어느 지형에 있는지. 플레이어의 피로도가 얼마인지 (숲-1,늪-3,평지0)
 표시되도록 수정해봅시다.

*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct tile {

	char forest = 'F'; // 숲
	char swamp = 'S'; // 늪
	char yard = 'Y'; // 평지

};

struct player {

	string name;
	int stamina = 0;
	char player_symbol = 'P';
	int player_x;
	int player_y;
};


int main()
{
	srand(time(NULL));

	
	tile start_tile;
	player sena;
	
	sena.name = "sena";
	sena.stamina = 20;
	sena.player_x = rand() % 10;
	sena.player_y = rand() % 10;

	int tile_rand; // 첫 타일 깔때 필요
		
	char start_buf = 0;
	char end_buf = 0;

	char field[10][10] = { 0 }; // 맵

	//int player_x = rand() % 10;
	//int player_y = rand() % 10;

	int end_x = rand() % 10;
	int end_y = rand() % 10;

	char move;

	// 첫 타일 깔기
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			tile_rand = rand() % 3;

			if (tile_rand == 0) // 0 이면 숲
				field[i][j] = (int)start_tile.forest;
			else if (tile_rand == 1) // 1이면 늪
				field[i][j] = (int)start_tile.swamp;
			else // 2 면 평지
				field[i][j] = (int)start_tile.yard;
		}

	start_buf = field[sena.player_x][sena.player_y]; // 처음 플레이어의 x와 y값 저장

	field[sena.player_x][sena.player_y] = sena.player_symbol;
	field[end_x][end_y] = 'E';



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << field[i][j];
		cout << endl;
	}


	while (1)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << field[i][j];
			cout << endl;
		}

		cout << "__________________________________________________" << endl;
		cout << "플레이어 : " << sena.name << "		남은 스테미나 : " << sena.stamina << endl;


		move = _getch();
		switch (move)
		{
		case 'a':
			if (sena.player_y != 0)
			{
				end_buf = field[sena.player_x][sena.player_y - 1]; // end_buf 에다가 P가 곧 두어질 곳의 값 저장
				field[sena.player_x][sena.player_y - 1] = sena.player_symbol;   // 가야하는 곳을 P로 덮어씀
				field[sena.player_x][sena.player_y] = start_buf; // 이전 P가 있었던 곳에 start_buf(이전값) 을 넣음
				start_buf = end_buf; // 현재 P가 있는 위치의 값을 start에 복사
				sena.player_y = sena.player_y - 1;


				if (end_buf == start_tile.forest) // 숲을 만났을때 
					sena.stamina = sena.stamina - 1;
				else if (end_buf == start_tile.swamp) // 늪을 만났을때
					sena.stamina = sena.stamina - 3;
				else // 평지를 만났을때
					;

			}
			else
				field[sena.player_x][sena.player_y] = sena.player_symbol;

			break;
		case 'd':
			if (sena.player_y != 9)
			{

				end_buf = field[sena.player_x][sena.player_y + 1]; // end_buf 에다가 P가 곧 두어질 곳의 값 저장
				field[sena.player_x][sena.player_y + 1] = sena.player_symbol;   // 가야하는 곳을 P로 덮어씀
				field[sena.player_x][sena.player_y] = start_buf; // 이전 P가 있었던 곳에 start_buf(이전값) 을 넣음
				start_buf = end_buf; // 현재 P가 있는 위치의 값을 start에 복사
				sena.player_y = sena.player_y + 1;

				if (end_buf == start_tile.forest)
					sena.stamina = sena.stamina - 1;
				else if (end_buf == start_tile.swamp)
					sena.stamina = sena.stamina - 3;
				else
					;

			}
			else
				field[sena.player_x][sena.player_y] = sena.player_symbol;

			break;
		case 'w':
			if (sena.player_x != 0)
			{
				end_buf = field[sena.player_x-1][sena.player_y ]; // end_buf 에다가 P가 곧 두어질 곳의 값 저장
				field[sena.player_x-1][sena.player_y ] = sena.player_symbol;   // 가야하는 곳을 P로 덮어씀
				field[sena.player_x][sena.player_y] = start_buf; // 이전 P가 있었던 곳에 start_buf(이전값) 을 넣음
				start_buf = end_buf; // 현재 P가 있는 위치의 값을 start에 복사
				sena.player_x = sena.player_x - 1;

				if (end_buf == start_tile.forest)
					sena.stamina = sena.stamina - 1;
				else if (end_buf == start_tile.swamp)
					sena.stamina = sena.stamina - 3;
				else
					;

			}
			else
				field[sena.player_x][sena.player_y] = sena.player_symbol;

			break;
		case 's':
			if (sena.player_x != 9)
			{

				end_buf = field[sena.player_x +1][sena.player_y]; // end_buf 에다가 P가 곧 두어질 곳의 값 저장
				field[sena.player_x+1][sena.player_y] = sena.player_symbol;   // 가야하는 곳을 P로 덮어씀
				field[sena.player_x][sena.player_y] = start_buf; // 이전 P가 있었던 곳에 start_buf(이전값) 을 넣음
				start_buf = end_buf; // 현재 P가 있는 위치의 값을 start에 복사
				sena.player_y = sena.player_y + 1;


				if (end_buf == start_tile.forest)
					sena.stamina = sena.stamina - 1;
				else if (end_buf == start_tile.swamp)
					sena.stamina = sena.stamina - 3;
				else
					;


			}
			else
				field[sena.player_x][sena.player_y] = sena.player_symbol;
			break;

		default:
			break;
		}

		if (field[end_x][end_y] == sena.player_symbol)
		{
			system("cls"); // 탈출시 출력 1
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
					cout << field[i][j];
				cout << endl;
			}

			cout << "탈출에 성공했습니다!" << endl;
			break;
		}

		if (sena.stamina < 0)
		{
			system("cls");
			cout << "stamina : 0 , 당신은 탈출에 실패했습니다.";
			break;
		}

	}

}