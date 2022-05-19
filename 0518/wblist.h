//wblist.h
//템플릿 클래스 -> 클래스를 만드는 설계도
//컴파일러가 클래스를 생성!
//[설계도를 h파일에 모아두어야 한다.]
#pragma once

template<typename T>
class WBList
{
public:
	class node
	{
	public:
		T data;			//T 를 저장하겠다.
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
	node* head;		//[필수] 첫번째 노드의 주소
	node* tail;		//      마지막 노드의 주소
	int size;		//[옵션] 저장 개수

public:
	WBList();

public:
	node* gethead() { return head; }
	node* gettail() { return tail; }
	int   getsize() { return size; }

public:
	//----------저장기능----------------------------------
	void front_insert(T value);
	void rear_insert(T value);
	void next_insert(node* cur, T value);

	//---------삭제기능-----------------------------------
	void front_delete();
	void rear_delete();
	void cur_delete(node* cur);

	//출력(순회)-------------------------------------------
	/*
	void printall() {
		
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
	*/
	//검색...
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

template<typename T>
void WBList<T>::front_delete()
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

template<typename T>
void WBList<T>::rear_delete()
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

template<typename T>
void WBList<T>::cur_delete(node* cur)
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
