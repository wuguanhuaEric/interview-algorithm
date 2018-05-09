#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

int gcd2(int m, int n)
{
	while (n)
	{
		m = n;
		n = m % n;
	}
	return m;
}

int main()
{
	cout << gcd(6, 0) << endl;
	cout << gcd2(6, 0) << endl;

	system("pause");
	return 0;
}