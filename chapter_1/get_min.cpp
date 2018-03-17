#include<iostream>  
using  namespace std;
#include <stack>  
#include <cassert>  

//����һ��  һ������ջ��������ջΪ�գ�ֱ�ӽ�Ԫ�������ջ���������ջ����Ԫ�أ���ѹ���Ԫ�غ͸���ջ��Ԫ�رȽϣ�  
//ѹ�������н�С���Ǹ�Ԫ��ʹ�ø���ջ����ά��ջ��Ԫ��Ϊ��Сֵ��  
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

//�������� һ������ջ��������ջΪ�գ�ֱ�ӽ�Ԫ�������ջ���������ջ����Ԫ�أ���ѹ���Ԫ�غ͸���ջ��Ԫ�رȽϣ�  
//���ѹ���Ԫ��С�ڵ��ڸ���ջ��Ԫ�أ��߽����Ԫ���븨��ջ�������޲�������ջ��ʱ���ж�Ҫ��ջ��Ԫ���Ƿ���ڸ���  
//ջ��Ԫ�أ�����ǣ�Ҳ������ջ��Ԫ�س�ջ�������޲�����  
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
	//s.Push(5);  
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