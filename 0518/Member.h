// member.h

#pragma once

class Member {
private:
	string name;	//�̸�
	string phone;	//��ȭ��ȣ
	struct tm date;//�����Ͻ�

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

