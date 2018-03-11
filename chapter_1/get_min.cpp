#include<iostream>  
using  namespace std;
#include <stack>  
#include <cassert>  

//方法一：  一个辅助栈，如果这个栈为空，直接将元素入这个栈，如果辅助栈中有元素，将压入的元素和辅助栈顶元素比较，  
//压入两者中较小的那个元素使得辅助栈总是维持栈顶元素为最小值。  
//class Stack  
//{  
//public:  
//  void Push(int data)  
//  {  
//      s1.push(data);  
//      if (minstack.empty())  
//      {  
//          minstack.push(data);  
//      }  
//      else  
//      {  
//          int tmp = minstack.top();  
//          int min = data > tmp ? tmp : data;  
//          minstack.push(min);  
//      }  
//  }  
//  
//  void Pop()  
//  {  
//      assert(!s1.empty() && !minstack.empty());  
//  
//      s1.pop();  
//      minstack.pop();  
//  }  
//  
//  int GetMin()  
//  {  
//      assert(!minstack.empty());  
//      return minstack.top();  
//  }  
//  
//  
//private:  
//  stack<int> s1;  
//  stack<int> minstack;  
//  
//};  

//方法二： 一个辅助栈，如果这个栈为空，直接将元素入这个栈，如果辅助栈中有元素，将压入的元素和辅助栈顶元素比较，  
//如果压入的元素小于等于辅助栈顶元素，者将这个元素入辅助栈，否则无操作，出栈的时候判断要出栈的元素是否等于辅助  
//栈顶元素，如果是，也将辅助栈顶元素出栈。否则无操作。  
class Stack
{
public:
	void Push(int data)
	{
		s1.push(data);
		if (minstack.empty())
		{
			minstack.push(data);
		}
		else
		{
			if (data <= minstack.top())
			{
				minstack.push(data);
			}
		}
	}

	void Pop()
	{
		assert(!s1.empty() && !minstack.empty());

		if (s1.top() == minstack.top())
		{
			minstack.pop();
		}
		s1.pop();
	}

	int GetMin()
	{
		assert(!minstack.empty());
		return minstack.top();
	}


private:
	stack<int> s1;
	stack<int> minstack;
};

int main()
{
	Stack s;
	s.Push(36);
	s.Push(15);
	s.Push(95);
	s.Push(50);
	s.Push(53);
	cout << s.GetMin() << endl;
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	cout << s.GetMin() << endl;
	cout << "hello..." << endl;
	system("pause");
	return 0;
}
