//wblist.h
//���ø� Ŭ���� -> Ŭ������ ����� ���赵
//�����Ϸ��� Ŭ������ ����!
//[���赵�� h���Ͽ� ��Ƶξ�� �Ѵ�.]
#pragma once

template<typename T>
class WBList
{
public:
	class node
	{
	public:
		T data;			//T �� �����ϰڴ�.
		node* prev;
		node* next;

	public:
		node(T _data)
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
	WBList();

public:
	node* gethead() { return head; }
	node* gettail() { return tail; }
	int   getsize() { return size; }

public:
	//----------������----------------------------------
	void front_insert(T value);
	void rear_insert(T value);
	void next_insert(node* cur, T value);

	//---------�������-----------------------------------
	void front_delete();
	void rear_delete();
	void cur_delete(node* cur);

	//���(��ȸ)-------------------------------------------
	/*
	void printall() {
		
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
	*/
	//�˻�...
};


template<typename T>
WBList<T>::WBList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

template<typename T>
void WBList<T>::front_insert(T value)
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

template<typename T>
void WBList<T>::rear_insert(T value)
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

template<typename T>
void WBList<T>::next_insert(node* cur, T value)
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

template<typename T>
void WBList<T>::front_delete()
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

template<typename T>
void WBList<T>::rear_delete()
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

template<typename T>
void WBList<T>::cur_delete(node* cur)
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
