/*
	실습.
	A~Z 키 중에 하나를 정답으로 설정한다.
	유저는 한 개의 키를 입력해서 설정된 값으로 맞춘다.
	유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
	틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오버.

	+) 틀릴 때마다 정답 알파벳이 입력된 알파벳 앞에 있는지. 뒤에 있는지 힌트를 준다.

	+) 입력된 값이 대소문자 구분없이 처리 될 수 있도록 수정해보자.

*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{

	int answer; // 답
	int my_num; // 입력한 값
	int i = 0;

	srand(time(NULL));
	answer = rand() % (122 - 97) + 97;

	cout << "정답 입력하시오 : " << endl;
	cout << answer << endl;

	for (i = 0; i < 5; i++)
	{
		my_num = _getch();

		if ((answer == my_num) || (answer-32) ==my_num)
		{
			cout << "승리" << endl;
			break;
		}

		if((my_num<91)&&(64<my_num)) // 입력한 수가 대문자 일때
			if ((answer - 32) < my_num) 
				cout << "입력한 값보다 답이 앞에 있습니다" << endl;
			else
				cout << "입력한 값보다 답이 뒤에 있습니다" << endl;
		else if ((my_num <123)&&(96<my_num)) // 입력한 수가 소문자 일때
			if(answer < my_num)
				cout << "입력한 값보다 답이 앞에 있습니다" << endl;
			else
				cout << "입력한 값보다 답이 뒤에 있습니다" << endl;

		else
			cout << "알파벳을 입력하세요" << endl;
	}

	if(i==5)
		cout << "게임오버" << endl;

}

