#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
}*head=NULL;
int count()
{
	struct node* temp = head;
	int count1 = 0;
	if (!head)
		return 0;
	do
	{
		count1++;
		temp = temp->next;
	} while (temp != head);
	return count1;
}
void insert(int pos, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if (pos<0 || pos>count())
		return;
	if (pos == 0)
	{
		if (!head)
		{
			head = temp;
			head->next = head;
		
		}
		else
		{
			struct node* t = head;
			while (t->next != head)
				t = t->next;
			temp->next = head;
			t->next =temp;
			head = temp;
		}
	}
	else if(pos>0)
	{
		int count1 = 0;
		struct node* t = head;
		while (count1 != pos - 1)
		{
			count1++;
			t = t->next;
		}
		temp->next = t->next;
		t->next = temp; 
		
	}
}
void display()
{
	struct node* temp = head;
	do
	{
		cout << temp->data<<" ";
		temp = temp->next;
	
	} while (temp != head);
	
}
void delete_node(int pos)
{
	if (pos<0 || pos>count())
		return;
	if (!head)
		return;
	if (pos == 0)
	{
		struct node* temp = head;
		do
		{
			temp = temp->next;
		} while (temp->next != head);
		struct node* t = head;
		head = head->next;
		temp->next = head;
		free(t);
	}
	else
	{
		struct node* t = head;
		int count = 0;
		while (count != pos - 1)
		{
			count++;
			t = t->next;
		}
		struct node* temp = t->next;
		t->next = temp->next;
		free(temp);
	}


	}

		int main()
		{
			insert(0, 24);
			insert(1, 54);
			display();
			delete_node(0);
			display();
		}

