#include <iostream>
#include <cstdlib>

using namespace std;

void SwapTwoNums(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void SwapTwoNums2(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main(void)
{ 
	int a1 = 1, b1 = 2;
	int a2 = 3, b2 = 4;
	SwapTwoNums(a1, b1);
	cout << a1 << "\t" << b1 << endl;
	SwapTwoNums2(a2, b2);
	cout << a2 << "\t" << b2 << endl;

	system("pause");
	return 0;
}