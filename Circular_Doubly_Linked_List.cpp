#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node* prev;
	struct node* next;
}*head=NULL;
int count()
{
	if (!head)
		return 0;
	int count1 = 0;
	struct node* temp = head;
	do
	{
		count1++;
		temp = temp->next;
	} while (temp != head);
	return count1;
}
void insert(int pos, int data)
{
	if (pos<0 || pos>count())
		return;
	if (pos == 0)
	{
		if (!head)
		{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->data = data;
			head = temp;
			head->next = head->prev = head;
		}
		else
		{
			struct node* temp = head->prev;
			struct node* t = (struct node*)malloc(sizeof(struct node));
			t->data = data;
			t->prev = t->next = NULL;
			t->next = head;
			head->prev = t;
			head = t;
			head ->prev = temp;
			temp->next = head;
			
		}

	}
	else if (pos > 0)
	{
		int count = 0;
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		struct node* t = head;
		while (count != pos - 1)
		{
			t = t->next;
			count++;
		}
		temp->next = t->next;
		if (t->next) {
			t->next->prev = temp;
			t->next = temp;
		}
		temp->prev = t;
	}
}
void display()
{
	struct node* t = head;
	if (!head)
		return;
	do
	{
		cout << t->data<<" ";
		t = t->next;
	} while (t != head);
	cout << endl;
}
void Delete(int pos)
{
	if (pos < 0 || pos>count())
		return;
	if (pos == 0)
	{
		struct node* temp = head->prev,*t;
		t = head;
		head = head->next;
		temp->next = head;
		head->prev = temp;
		free(t);
	}
	else if (pos > 0)
	{
		int count = 0;
		struct node* temp = head;
		while (count != pos - 1)
		{
			temp = temp->next;
			count++;
		}
		struct node* t = temp->next->next,*temp1=temp->next;
		t->prev = temp;
		temp->next = t;
		free(temp1);
	}

}


		int main()
		{
			insert(0, 11);
			insert(0, 22);
			insert(0, 33);
			display();
			Delete(0);
			display();
			
		}

