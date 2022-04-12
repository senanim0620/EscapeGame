/*
	실습 4. 구구단 출력

*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
//	for (int i = 1;i < 10;i++)
//		cout << "2 *" << i << "=" << 2*i <<endl;			

	/*
	for (int j = 2;j < 10;j++)
	{
		for (int i = 1; i < 10;i++)
		{
			cout << j << "*" << i << "=" << j * i << endl;

		}
		cout << "____________________" << endl;
	}
	*/
/*
	for (int i = 1;i < 10;i++) 
	{
		cout << "2 *" << i << "=" << 2 * i;
		cout << "	3 *" << i << "=" << 3 * i;
		cout << "	4 *" << i << "=" << 4 * i<< endl;

	}
	
	cout << "____________________" << endl;
	
	for (int i = 1;i < 10;i++)
	{
		cout << "5 *" << i << "=" << 5 * i;
		cout << "	6 *" << i << "=" << 6 * i;
		cout << "	7 *" << i << "=" << 7 * i << endl;

	}

	cout << "____________________" << endl;

	for (int i = 1;i < 10;i++)
	{
		cout << "8*" << i << "=" << 8* i;
		cout << "	9*" << i << "=" << 9 * i << endl;
		
	}
*/
/*
	for (int j = 2;j< 10;j=j+3)
	{
		for (int i = 1;i < 10;i++)
		{
			cout << j << "*" << i << "=" << j * i << "		";
			cout << (j + 1) << "*" << i << "=" << (j + 1) * i << "		";

			if (j + 2 != 10)
				cout << (j + 2) << "*" << i << "=" << (j + 2) * i << endl;
			else
				cout << endl;
		}

		if (j % 3 == 2)
			cout<<"___________________" << endl;
	}
	*/

	for (int j = 2;j < 10;j = j + 3)
	{
		for (int i = 1;i < 10;i++)
		{
			for (int k = 0;k < 3; k++)
			{
				if (j + k == 10)
					break;

				else
					cout << (j + k) << "*" << i << "=" << (j + k) * i << "		";
			
			}
			cout << endl;
		}

		if (j % 3 == 2)
			cout << "___________________" << endl;
	}




}
