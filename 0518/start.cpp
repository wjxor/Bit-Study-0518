// start.cpp

#include <iostream>
using namespace std;
#include "MemberControl.h"
#include <conio.h>

int main() {
	MemberControl con;
	
	while (true) {
		system("cls");
		con.PrintAllMember();
		cout << "---------------------------------------------" << endl;
		cout << "[1]���� [2]�˻� [3]���� [4]���� [5]����" << endl;
		cout << "---------------------------------------------" << endl;

		switch (_getch()) {
		case '1':con.InsertMember(); break;
		case '2':con.SelectMember(); break;
		case '3':con.UpdateMember(); break;
		case '4':con.DeleteMember(); break;
		case '5': return 0;
		}

		system("pause");
	}
	
	return 0;
}