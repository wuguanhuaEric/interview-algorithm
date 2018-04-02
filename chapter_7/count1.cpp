#include <iostream>
#include <cstdlib>

using namespace std;

int count1(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 0x1;
		n >>= 1;
	}

	return count;
}

int count2(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1);
		++count;
	}

	return count;
}

int count3(int n)
{
	int count = 0;
	while (n)
	{
		n -= (n & (~n + 1));
		++count;
	}

	return count;
}

int main(void)
{
	cout << count1(5) << endl;
	cout << count2(5) << endl;
	cout << count3(5) << endl;

	system("pause");
	return 0;
}