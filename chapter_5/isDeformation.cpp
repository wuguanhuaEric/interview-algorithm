#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isDeformation1(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	if (len1 != len2)
	{
		return false;
	}

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

bool isDeformation2(string str1, string str2)
{
	if (str1.size() != str2.size())
	{
		return false;
	}

	vector<int> v(256, 0);
	
	for (auto &c : str1)
	{
		++v[c];
	}

	for (auto &c : str2)
	{
		--v[c];
		if (v[c] < 0)
			return false;
	}

	return true;
}

int main()
{
	string s1 = "124", s2 = "241";
	cout << isDeformation1(s1, s2) << endl;
	cout << isDeformation2(s1, s2) << endl;

	system("pause");
	return 0;
}