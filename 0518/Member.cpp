// Member.cpp

#include <iostream>
using namespace std;

#include "Member.h"

Member::Member(string name, string phone) {
	this->name = name;
	this->phone = phone;

	time_t timer = time(NULL);
	localtime_s(&this->date, &timer);
}

string Member::GetName() const {
	return name;
}

void Member::SetPhone(string phone) {
	this->phone = phone;
}

void Member::Print() const {
	cout << name << "\t" << phone << endl;
}

string Member::GetDay() const {
	int year = date.tm_year + 1900;
	int month = date.tm_mon + 1;
	int day = date.tm_mday;

	char temp[50];
	sprintf_s(temp, "%04d-%02d-%02d", year, month, day);
	return temp;
}

string Member::GetTime() const {
	char temp[50];
	sprintf_s(temp, "%02d:%02d:%02d", date.tm_hour, date.tm_min, date.tm_sec);

	return temp;
}

void Member::Println() const {
	cout << "[이름] " << name << endl;
	cout << "[전화번호] " << phone << endl;
	cout << "[날짜] " << GetDay() << endl;
	cout << "[시간] " << GetTime() << endl;

}