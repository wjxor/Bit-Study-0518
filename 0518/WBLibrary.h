// WBLibrary.h
#pragma once

class WBLibrary {
public:
	// 입력받는 기능
	// static : 클래스멤버 -> 클래스이름으로 사용 가능
	static string InputString(string msg);
	static int InputNumber(string msg);
};