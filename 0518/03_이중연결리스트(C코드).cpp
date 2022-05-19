//03_이중연결리스트(C코드).cpp
#include <stdio.h>
#include <malloc.h>

typedef struct node node;
struct node
{
	int data;			//int를 저장하겠다.
	struct node* prev;
	struct node* next;
};

typedef struct wblist wblist;
struct wblist
{
	node* head;		//[필수] 첫번째 노드의 주소
	node* tail;		//      마지막 노드의 주소
	int size;		//[옵션] 저장 개수
};

void mylist_init(wblist* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

//----------저장기능----------------------------------
//1. 노드 생성  2.노드 초기화  3.연결
void mylist_front_insert(wblist* plist, int value)
{
	node* newnode = (node*)malloc(sizeof(node));//#include <malloc.h>

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	//비어있는 상태
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

	//cur가 꼬리노드라면(꼬리연결과정에서 [비어있지 않는경우] 복사)
	if (cur == plist->tail)
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	else //노드와 노드 사이
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	plist->size++;
}
//-----------------------------------------------------

//1. 삭제할 노드 찾기  2. 흐름에서 삭제할 노드를 제거  3. 삭제할 노드free
void mylist_front_delete(wblist* plist)
{
	if (plist->head == NULL)
		return;

	node* del = plist->head;
	//노드가 하나일때
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
	//노드가 하나일때
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
	//첫번째 노드일 경우
	if (cur == plist->head) {
		return mylist_front_delete(plist);
	}
	//마지막 노드일 경우
	else if (cur == plist->tail) {
		return mylist_rear_delete(plist);
	}
	//중간 노드
	else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		plist->size--;
	}
}

//출력(순회)-------------------------------
void mylist_printall(const wblist* plist) {
	printf("[저장개수 : %d] ", plist->size);

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
	printf("[저장개수 : %d] ", plist->size);

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

//검색
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
		printf("찾음 : %d\n", cur->data);
	}
	else
	{
		printf("실패\n");
	}

	printf("update\n");
	node* cur1 = mylist_select(&list, 20);
	if (cur1 != NULL)
	{
		cur1->data = 100;
	}
	else
	{
		printf("실패\n");
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

	//첫번째 노드 삭제
	//[10] 11 20 12 13 
	mylist_cur_delete(&list, list.head);
	mylist_printall(&list);
	mylist_printall1(&list);

	//마지막 노드 삭제
	//11 20 12 [13]
	mylist_cur_delete(&list, list.head->next->next->next);
	mylist_printall(&list);
	mylist_printall1(&list);

	//중간 노드 삭제
	//11 [20] 12
	mylist_cur_delete(&list, list.head->next);
	mylist_printall(&list);
	mylist_printall1(&list);

	return 0;
}