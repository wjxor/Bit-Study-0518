//03_���߿��Ḯ��Ʈ(C�ڵ�).cpp
#include <stdio.h>
#include <malloc.h>

typedef struct node node;
struct node
{
	int data;			//int�� �����ϰڴ�.
	struct node* prev;
	struct node* next;
};

typedef struct wblist wblist;
struct wblist
{
	node* head;		//[�ʼ�] ù��° ����� �ּ�
	node* tail;		//      ������ ����� �ּ�
	int size;		//[�ɼ�] ���� ����
};

void mylist_init(wblist* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

//----------������----------------------------------
//1. ��� ����  2.��� �ʱ�ȭ  3.����
void mylist_front_insert(wblist* plist, int value)
{
	node* newnode = (node*)malloc(sizeof(node));//#include <malloc.h>

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	//����ִ� ����
	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->next = plist->head;
		plist->head->prev = newnode;
		plist->head = newnode;
	}
	plist->size++;
}

void mylist_rear_insert(wblist* plist, int value)
{
	node* newnode = (node*)malloc(sizeof(node));//#include <malloc.h>

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	plist->size++;
}

void mylist_next_insert(wblist* plist, node* cur, int value)
{
	node* newnode = (node*)malloc(sizeof(node));//#include <malloc.h>

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	//cur�� ���������(��������������� [������� �ʴ°��] ����)
	if (cur == plist->tail)
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	else //���� ��� ����
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	plist->size++;
}
//-----------------------------------------------------

//1. ������ ��� ã��  2. �帧���� ������ ��带 ����  3. ������ ���free
void mylist_front_delete(wblist* plist)
{
	if (plist->head == NULL)
		return;

	node* del = plist->head;
	//��尡 �ϳ��϶�
	if (plist->head->next == NULL)
	{
		plist->tail = plist->head = NULL;
	}
	else
	{
		plist->head = plist->head->next;
		plist->head->prev = NULL;
	}
	free(del);

	plist->size--;
}

void mylist_rear_delete(wblist* plist)
{
	if (plist->head == NULL)
		return;

	node* del = plist->tail;
	//��尡 �ϳ��϶�
	if (plist->head->next == NULL)
	{
		plist->tail = plist->head = NULL;
	}
	else
	{
		plist->tail = plist->tail->prev;
		plist->tail->next = NULL;
	}
	free(del);

	plist->size--;
}

void mylist_cur_delete(wblist* plist, node* cur)
{
	//ù��° ����� ���
	if (cur == plist->head) {
		return mylist_front_delete(plist);
	}
	//������ ����� ���
	else if (cur == plist->tail) {
		return mylist_rear_delete(plist);
	}
	//�߰� ���
	else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		plist->size--;
	}
}

//���(��ȸ)-------------------------------
void mylist_printall(const wblist* plist) {
	printf("[���尳�� : %d] ", plist->size);

	node* cur = plist->head;
	while (cur != NULL)
	{
		int value = cur->data;
		printf("%d -> ", value);
		cur = cur->next;
	}
	printf("\n");
}

void mylist_printall1(const wblist* plist) {
	printf("[���尳�� : %d] ", plist->size);

	node* cur = plist->tail;	//<---
	while (cur != NULL)
	{
		int value = cur->data;
		printf("%d -> ", value);
		cur = cur->prev;		//<---
	}
	printf("\n");
}
//-------------------------------------------------

//�˻�
node* mylist_select(const wblist* plist, int findvalue)
{
	node* cur = plist->head;
	while (cur != NULL)
	{
		int value = cur->data;
		if (value == findvalue)
			return cur;

		cur = cur->next;
	}
	return NULL;
}


int main()
{
	wblist list;

	mylist_init(&list);

	//10 11 12
	for (int i = 10; i <= 12; i++)
		mylist_rear_insert(&list, i); //mylist_front_insert(&list, i); 

	mylist_printall(&list);
	mylist_printall1(&list);

	//next_insert
	//10 11 12 13 
	mylist_next_insert(&list, list.head->next->next, 13);
	mylist_printall(&list);
	mylist_printall1(&list);

	//next_insert
	//10 11 20 12 13 
	mylist_next_insert(&list, list.head->next, 20);
	mylist_printall(&list);
	mylist_printall1(&list);

	printf("select\n");
	node* cur = mylist_select(&list, 22);
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
	mylist_printall1(&list);



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
	mylist_cur_delete(&list, list.head);
	mylist_printall(&list);
	mylist_printall1(&list);

	//������ ��� ����
	//11 20 12 [13]
	mylist_cur_delete(&list, list.head->next->next->next);
	mylist_printall(&list);
	mylist_printall1(&list);

	//�߰� ��� ����
	//11 [20] 12
	mylist_cur_delete(&list, list.head->next);
	mylist_printall(&list);
	mylist_printall1(&list);

	return 0;
}