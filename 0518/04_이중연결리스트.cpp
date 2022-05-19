//04_���߿��Ḯ��Ʈ(C++).cpp
/*
* //��øŬ���� 
class wblist
{
	//�ܺ� Ŭ���� ���� Ŭ����
	class node {};
};
*/

#include <iostream>
using namespace std;

class wblist
{
	class node
	{
	public:
		int data;			//int�� �����ϰڴ�.
		struct node* prev;
		struct node* next;

	public:
		node(int _data)
		{
			data = _data;
			prev = NULL;
			next = NULL;
		}
	};

private:
	node* head;		//[�ʼ�] ù��° ����� �ּ�
	node* tail;		//      ������ ����� �ּ�
	int size;		//[�ɼ�] ���� ����

public:
	wblist()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
public:
	node* gethead() { return head;  }
	node* gettail() { return tail;  }
	int   getsize() { return size;  }

public:
	//----------������----------------------------------
	void front_insert(int value)
	{
		node* newnode = new node(value);

		//����ִ� ����
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		size++;
	}
	void rear_insert(int value)
	{
		node* newnode = new node(value);

		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}
		size++;
	}
	void next_insert(node* cur, int value)
	{
		node* newnode = new node(value);

		//cur�� ���������(��������������� [������� �ʴ°��] ����)
		if (cur == tail)
		{
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}
		else //���� ��� ����
		{
			newnode->prev = cur;
			newnode->next = cur->next;
			cur->next->prev = newnode;
			cur->next = newnode;
		}
		size++;
	}

	//---------�������-----------------------------------
	void front_delete()
	{
		if (head == NULL)
			return;

		node* del = head;
		//��尡 �ϳ��϶�
		if (head->next == NULL)
		{
			tail = head = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		free(del);
		size--;
	}
	void rear_delete()
	{
		if (head == NULL)
			return;

		node* del = tail;
		//��尡 �ϳ��϶�
		if (head->next == NULL)
		{
			tail = head = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(del);
		size--;
	}
	void cur_delete(node* cur)
	{
		//ù��° ����� ���
		if (cur == head) {
			return front_delete();
		}
		//������ ����� ���
		else if (cur == tail) {
			return rear_delete();
		}
		//�߰� ���
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			size--;
		}
	}

	//���(��ȸ)-------------------------------------------
	void printall() {
		printf("[���尳�� : %d] ", size);

		node* cur = head;
		while (cur != NULL)
		{
			int value = cur->data;
			printf("%d -> ", value);
			cur = cur->next;
		}
		printf("\n");
	}
	void printall1() {
		printf("[���尳�� : %d] ", size);

		node* cur = tail;	//<---
		while (cur != NULL)
		{
			int value = cur->data;
			printf("%d -> ", value);
			cur = cur->prev;		//<---
		}
		printf("\n");
	}

	//�˻�...
};

int main()
{
	wblist list;	

	//10 11 12
	for (int i = 10; i <= 12; i++)
		list.rear_insert(i); //mylist_front_insert(&list, i); 

	list.printall();
	list.printall1();

	//next_insert
	//10 11 12 13 
	list.next_insert(list.gethead()->next->next, 13);
	list.printall();
	list.printall1();

	//next_insert
	//10 11 20 12 13 
	list.next_insert(list.gethead()->next, 20);
	list.printall();
	list.printall1();

	printf("select\n");
	/*node* cur = mylist_select(&list, 22);
	if (cur != NULL)
	{
		printf("ã�� : %d\n", cur->data);
	}
	else
	{
		printf("����\n");
	}

	printf("update\n");
	node* cur1 = mylist_select(&list, 20);
	if (cur1 != NULL)
	{
		cur1->data = 100;
	}
	else
	{
		printf("����\n");
	}
	mylist_printall(&list);
	mylist_printall1(&list);*/



	//delete
	printf("delete\n");
	//for (int i = 0; i < 7; i++)
	//{
	//	mylist_rear_delete(&list); //mylist_front_delete(&list);
	//	mylist_printall(&list);
	//	mylist_printall1(&list);
	//	printf("\n");
	//}

	//ù��° ��� ����
	//[10] 11 20 12 13 
	list.cur_delete(list.gethead());
	list.printall();
	list.printall1();

	//������ ��� ����
	//11 20 12 [13]
	list.cur_delete(list.gethead()->next->next->next);
	list.printall();
	list.printall1();

	//�߰� ��� ����
	//11 [20] 12
	list.cur_delete(list.gethead()->next);
	list.printall();
	list.printall1();

	return 0;
}