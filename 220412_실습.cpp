/*
	실습 1. 정수를 하나 입력 받아서 입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다" 출력
			10이하 9초과이면 9보다 큽니다 출력
			9		6		6보다 큽니다	
			그외에는 6보다 작거나 같습니다.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int num;
	cout << "정수 하나를 입력하세요 : ";
	cin >> num;

	if (num>10)
	{
		cout << "입력된 숫자가 10보다 크다";
	}
	else if (num > 9)
	{
		cout << "입력한 숫자가 9보다 크다";
	}
	else if (num > 6)
	{
		cout << "입력한 숫자가 6보다 크다";
	}
	else
	{
		cout << "입력한 숫자가 6보다 작거나 같다.";
	}

}
