// MemberControl.cpp

#include <iostream>
using namespace std;

#include "MemberControl.h"
#include "WBLibrary.h"
#include "wblist.h"

// 1. ���� ȹ��	2. ���尴ü����	3. ����	4. ������
void MemberControl::InsertMember() {
	string name = WBLibrary::InputString("�̸�");
	string phone = WBLibrary::InputString("��ȭ��ȣ");

	Member* member = new Member(name, phone);

	members.rear_insert(member);

	cout << "����Ǿ����ϴ�." << endl;
}

void MemberControl::PrintAllMember() {
	cout << "[���尳��] " << members.getsize() << endl;

	WBList<Member*>::node* cur = members.gethead();
	while (cur != NULL)
	{
		Member* pmem = cur->data;
		pmem->Print();
		cur = cur->next;
	}
	printf("\n");
}

// 1. �˻�Ű ȹ�� 2. �˻� ���� 3. 1ã���� ��� 3. 2 ��ã���� ���
void MemberControl::SelectMember() {
	string name = WBLibrary::InputString("�̸�");
	
	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		Member *pmember = ret->data;
		pmember->Println();
	}
	else {
		cout << "����" << endl;
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

// 1. �˻�Ű ȹ�� 2. �˻����� 3. 1ã���� ���� 3. 2��ã���� ���
void MemberControl::DeleteMember() {
	string name = WBLibrary::InputString("�̸�");

	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		members.cur_delete(ret);
		cout << "���� ����" << endl;
	}
	else {
		cout << "����" << endl;
	}
}

// 1. �˻�Ű ȹ�� 2. �˻����� 3. 1ã����[��ȭ��ȣ�Է�][����]	3. 2��ã���� ���
void MemberControl::UpdateMember() {
	string name = WBLibrary::InputString("�̸�");

	WBList<Member*>::node* ret = NameToNode(name);

	if (ret != NULL) {
		string phone = WBLibrary::InputString("������ ��ȭ��ȣ");
		Member *pmember = ret->data;
		pmember->SetPhone(phone);
		
		cout << "��ȭ��ȣ ���� ����" << endl;
	}
	else {
		cout << "����" << endl;
	}
}