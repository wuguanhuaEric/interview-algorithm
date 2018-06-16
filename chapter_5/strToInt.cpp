#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool isValid(string str)
{
	if (str.empty())
		return false;
	else if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
		return false;
	else if (str[0] == '-' && (str.length() == 1 || str[1] == '0'))
		return false;
	else if (str[0] == '0' && str.length() > 1)
		return false;
	else
	{
		for (auto c : str.substr(1))
		{
			if (c < '0' || c > '9')
				return false;
		}
		return true;
	}
}

int convert(const string& str)
{
	if (!isValid(str))
		return false;

	int ret = 0, cur = 0, minQ = INT_MIN / 10, minR = INT_MIN % 10;
	bool flag = str[0] == '-' ? false : true;
	for (auto c : str)
	{
		if (c == '-')
			continue;
		cur = '0' - c;
		if (ret < minQ || (ret == minQ && cur < minR))
			return 0;
		else
			ret = ret * 10 + cur;
	}

	if (flag && ret == INT_MIN)
		return 0;
	return flag ? -ret : ret;
}

int main(void)
{
	cout << convert("124") << endl;
	cout << convert("023") << endl;
	cout << convert("A13") << endl;
	cout << convert("2147483648") << endl;
	cout << convert("-2147483648") << endl;

	system("pause");
	return 0;
}