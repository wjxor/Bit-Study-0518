//04_이중연결리스트(C++).cpp
/*
* //중첩클래스 
class wblist
{
	//외부 클래스 전용 클래스
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
		int data;			//int를 저장하겠다.
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
	node* head;		//[필수] 첫번째 노드의 주소
	node* tail;		//      마지막 노드의 주소
	int size;		//[옵션] 저장 개수

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
	//----------저장기능----------------------------------
	void front_insert(int value)
	{
		node* newnode = new node(value);

		//비어있는 상태
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

		//cur가 꼬리노드라면(꼬리연결과정에서 [비어있지 않는경우] 복사)
		if (cur == tail)
		{
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}
		else //노드와 노드 사이
		{
			newnode->prev = cur;
			newnode->next = cur->next;
			cur->next->prev = newnode;
			cur->next = newnode;
		}
		size++;
	}

	//---------삭제기능-----------------------------------
	void front_delete()
	{
		if (head == NULL)
			return;

		node* del = head;
		//노드가 하나일때
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
		//노드가 하나일때
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
		//첫번째 노드일 경우
		if (cur == head) {
			return front_delete();
		}
		//마지막 노드일 경우
		else if (cur == tail) {
			return rear_delete();
		}
		//중간 노드
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			size--;
		}
	}

	//출력(순회)-------------------------------------------
	void printall() {
		printf("[저장개수 : %d] ", size);

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
		printf("[저장개수 : %d] ", size);

		node* cur = tail;	//<---
		while (cur != NULL)
		{
			int value = cur->data;
			printf("%d -> ", value);
			cur = cur->prev;		//<---
		}
		printf("\n");
	}

	//검색...
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

	//첫번째 노드 삭제
	//[10] 11 20 12 13 
	list.cur_delete(list.gethead());
	list.printall();
	list.printall1();

	//마지막 노드 삭제
	//11 20 12 [13]
	list.cur_delete(list.gethead()->next->next->next);
	list.printall();
	list.printall1();

	//중간 노드 삭제
	//11 [20] 12
	list.cur_delete(list.gethead()->next);
	list.printall();
	list.printall1();

	return 0;
}