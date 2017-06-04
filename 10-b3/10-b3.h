/*1650254 ��Ң�� �����һ��*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
private:
	char *content;
	int   len;

	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
int renew(char **target, int space);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
