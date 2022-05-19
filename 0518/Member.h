// member.h

#pragma once

class Member {
private:
	string name;	//이름
	string phone;	//전화번호
	struct tm date;//가입일시

public:
	Member(string name, string phone);

public:
	string GetName() const;
	void SetPhone(string phone);

private:
	string GetDay() const;
	string GetTime() const;

public:
	void Print() const;
	void Println() const;
};

