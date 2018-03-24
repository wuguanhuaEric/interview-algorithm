#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

void printCommonList(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL || head2 == NULL)
		return;
	ListNode *p = head1, *q = head2;
	while (p && q)
	{
		if (p->val < q->val)
		{
			p = p->next;
		}
		else if (p->val > q->val)
		{
			q = q->next;
		}
		else
		{
			cout << p->val << "\t";
			p = p->next;
			q = q->next;
		}
	}
}

ListNode* createLinkedList(int arr[], int n){
	if (n == 0) return NULL;

	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++){
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int b[] = { 3, 4, 5, 7 };
	ListNode* head1 = createLinkedList(a, 6);
	ListNode* head2 = createLinkedList(b, 3);
	printCommonList(head1, head2);
	
	system("pause");
	return 0;
}
