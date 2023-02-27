#include <iostream>
 
using namespace std;
 
struct node
{
	int data;
	node *pre, *next;
};
 
class dll
{
public:
	dll()
	{
		head = NULL;
	}
	void createNode(int val)
	{
		node *tmp = new node;
		if(head == NULL)
		{
			head = tmp;
			tmp->data = val;
			tmp->next = tmp->pre = tmp;
		}
		else
		{
			tmp->pre = head->pre;
			tmp->next = head;
			tmp->data = val;
			(head->pre)->next = tmp;
			head->pre = tmp;
		}
	}
	void push(int val)
	{
		node *tmp = new node;
		tmp->data = val;
		tmp->next = head;
		tmp->pre = head->pre;
		(head->pre)->next = tmp;
		head->pre = tmp;
		head = tmp;
	}
 
	void displayS()
	{
		node *tmp = new node;
		tmp = head;
		while(1)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
			if(tmp == head)	break;
		}
		puts("");
	}
	void displayE()
	{
		node *tmp = new node;
		tmp = head->pre;
		while(1)
		{
			cout << tmp->data << " ";
			tmp = tmp->pre;
			if(tmp == head->pre)	break;
		}
		puts("");
	}
private:
	node *head;
};
 
int main()
{
	dll l;
	l.createNode(30);
	l.createNode(40);
	l.push(20);
	l.push(10);
	l.displayS();
	l.displayE();
	return 0;
}
