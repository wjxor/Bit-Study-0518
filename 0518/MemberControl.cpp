// MemberControl.cpp

#include <iostream>
using namespace std;

#include "MemberControl.h"
#include "WBLibrary.h"
#include "wblist.h"

// 1. 정보 획득	2. 저장객체생성	3. 저장	4. 결과출력
void MemberControl::InsertMember() {
	string name = WBLibrary::InputString("이름");
	string phone = WBLibrary::InputString("전화번호");

	Member* member = new Member(name, phone);

	members.rear_insert(member);

	cout << "저장되었습니다." << endl;
}

void MemberControl::PrintAllMember() {
	cout << "[저장개수] " << members.getsize() << endl;

	WBList<Member*>::node* cur = members.gethead();
	while (cur != NULL)
	{
		Member* pmem = cur->data;
		pmem->Print();
		cur = cur->next;
	}
	printf("\n");
}

// 1. 검색키 획득 2. 검색 수행 3. 1찾으면 출력 3. 2 못찾으면 출력
void MemberControl::SelectMember() {
	string name = WBLibrary::InputString("이름");
	
	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		Member *pmember = ret->data;
		pmember->Println();
	}
	else {
		cout << "없다" << endl;
	}
}

WBList<Member*>::node* MemberControl::NameToNode(string name) {
	WBList<Member*>::node* cur = members.gethead();
	while (cur != NULL)
	{
		Member* pmember = cur->data;
		if (pmember->GetName() == name)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

// 1. 검색키 획득 2. 검색수행 3. 1찾으면 삭제 3. 2못찾으면 출력
void MemberControl::DeleteMember() {
	string name = WBLibrary::InputString("이름");

	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		members.cur_delete(ret);
		cout << "삭제 성공" << endl;
	}
	else {
		cout << "없다" << endl;
	}
}

// 1. 검색키 획득 2. 검색수행 3. 1찾으면[전화번호입력][수정]	3. 2못찾으면 출력
void MemberControl::UpdateMember() {
	string name = WBLibrary::InputString("이름");

	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		string phone = WBLibrary::InputString("변경할 전화번호");
		Member *pmember = ret->data;
		pmember->SetPhone(phone);
		
		cout << "전화번호 수정 성공" << endl;
	}
	else {
		cout << "없다" << endl;
	}
}