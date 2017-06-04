/*1650254 尤尧寅 计算机一班*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
private:
	char *content;
	int   len;

	/* 根据需要定义所需的成员函数、友元函数等 */
public:
	TString();
	TString(const char *);
	TString(const TString &);
	~TString();
	TString& operator =(const TString &target);
	friend ostream& operator << (ostream &out, TString &a);
	friend istream& operator >> (istream &in, TString &a);
	TString operator +(TString &b);
	TString operator +(const char b[]);
	int length();
	char& operator[](int);
	friend TString operator +(const char b[], TString &a);
	friend bool operator < (TString &a, TString &b);
	friend bool operator > (TString &a, TString &b);
	friend bool operator == (TString &a, TString &b);
	friend bool operator <= (TString &a, TString &b);
	friend bool operator >= (TString &a, TString &b);
	friend bool operator != (TString &a, TString &b);
	friend bool operator < (TString &a, const char * b);
	friend bool operator <= (TString &a, const char * b);
	friend bool operator > (TString &a, const char * b);
	friend bool operator >= (TString &a, const char * b);
	friend bool operator == (TString &a, const char * b);
	friend bool operator != (TString &a, const char * b);
	friend int TStringLen(TString &target);
};

/* 如果有其它全局函数需要声明，写于此处 */
int renew(char **target, int space);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
