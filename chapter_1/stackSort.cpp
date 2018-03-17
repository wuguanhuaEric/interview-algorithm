#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

void stackSort(stack<int> &stk)
{
	if (stk.empty())
	{
		return;
	}
	stack<int> help;
	while (!stk.empty())
	{
		int cur = stk.top();
		stk.pop();
		while (!help.empty() && help.top() < cur)
		{
			stk.push(help.top());
			help.pop();
		}
		help.push(cur);
	}
	swap(stk, stack<int>());
	while (!help.empty())
	{
		stk.push(help.top());
		help.pop();
	}
}


int main(void)
{
	stack<int>  stk;
	stk.push(3);
	stk.push(5);
	stk.push(8);
	stk.push(9);
	stk.push(7);
	stk.push(1);
	stk.push(2);
	stk.push(6);
	
	stackSort(stk);
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();
	}

	system("pause");
	return 0;
}
