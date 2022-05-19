// MemberControl.h

#pragma once
#include "wblist.h"
#include "Member.h"

class MemberControl {
	WBList<Member*> members;
	
private:
	WBList<Member*>::node* NameToNode(string name);


public:
	void InsertMember();
	void PrintAllMember();
	void SelectMember();
	void DeleteMember();
	void UpdateMember();
};