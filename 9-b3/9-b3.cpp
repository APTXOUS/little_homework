/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class TString {
private:
	char *content;		//指向字符串的指针
	int   len;			//字符串的长度，不含尾零
public:
	TString(char *s = NULL);
	~TString();
	char *get_content();
	/* 根据需要补充其它的成员函数的定义 */
	TString(const TString &);
	void set(char *);
	void set(TString &);
	int length();
};

TString::TString(char *s)
{
	if (s == NULL || strlen(s) == 0) {
		content = NULL;
		len = 0;
	}
	else {
		len = strlen(s);
		content = new char[len + 1];
		strcpy(content, s);
	}
}

TString::~TString()
{
	if (content)
		delete content;
}

char *TString::get_content()
{
	if (content == NULL)
		return "<NULL>";
	else
		return content;
}

/* 在此给出其它成员函数的体外实现部分 */
TString::TString(const TString &s)
{
	if (s.content == NULL || strlen(s.content) == 0) {
		content = NULL;
		len = 0;
	}
	else {
		len = strlen(s.content);
		content = new char[len + 1];
		strcpy(content, s.content);
	}
}
void TString::set(char *target)
{
	if (target == NULL || strlen(target) == 0) {
		content = NULL;
		len = 0;
	}
	else {
		len = strlen(target);
		if (content)
			delete content;
		content = new char[len + 1];
		strcpy(content, target);
	}
}
void TString::set(TString &target)
{
	if (target.content == NULL || strlen(target.content) == 0) {
		content = NULL;
		len = 0;
	}
	else {
		len = strlen(target.content);
		if (content)
			delete content;
		content = new char[len + 1];
		strcpy(content, target.content);
	}
}
int TString::length()
{
	return len;
}

/* main函数不准动 */
int main()
{
	if (1) {
		TString s1;                  //s1为NULL
		TString s2("teststr2");      //s2为"teststr2"
		TString s3 = "teststr3";       //s3为"teststr3"
		TString s4 = NULL;             //s4为NULL
		TString s5 = "";               //s5为NULL

		cout << "定义对象并初始化测试(NULL及字符串常量初始化)" << endl;

		cout << "s1应该是<NULL>，  实际输出：" << s1.get_content() << endl;
		cout << "s2应该是teststr2，实际输出：" << s2.get_content() << endl;
		cout << "s3应该是teststr3，实际输出：" << s3.get_content() << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4.get_content() << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5.get_content() << endl;

		cout << endl << "任意键继续..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "teststr1";
		char *str1 = "teststr2";
		char  str2[] = "teststr3";
		char *str3 = NULL;
		char  str4[] = "";
		TString s1 = s0, s2 = str1, s3 = str2, s4 = str3, s5 = str4;

		cout << "定义对象并初始化测试(TString对象及字符指针、字符数组)" << endl;

		cout << "s1应该是teststr1，实际输出：" << s1.get_content() << endl;
		cout << "s2应该是teststr2，实际输出：" << s2.get_content() << endl;
		cout << "s3应该是teststr3，实际输出：" << s3.get_content() << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4.get_content() << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5.get_content() << endl;

		cout << endl << "任意键继续..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "hello";
		char    str1[] = "tong\0\0\0\0";
		char   *str2 = "ji";
		char   *str3 = NULL;
		char   *str4 = "";

		cout << "通过set函数将字符串赋值给对象的测试" << endl;

		cout << "s0应为hello， 实际输出：" << s0.get_content() << endl;

		s0.set(str1);
		cout << "s0应为tong，  实际输出：" << s0.get_content() << endl;

		s0.set(str2);
		cout << "s0应为ji，    实际输出：" << s0.get_content() << endl;

		s0.set(str3);
		cout << "s0应为<NULL>，实际输出：" << s0.get_content() << endl;

		s0.set(str4);
		cout << "s0应为<NULL>，实际输出：" << s0.get_content() << endl;

		s0.set(strcat(str1, str2));
		cout << "s0应为tongji，实际输出：" << s0.get_content() << endl;

		s0.set(strcpy(str1, str2));
		cout << "s0应为ji，    实际输出：" << s0.get_content() << endl;

		cout << endl << "任意键继续..." << endl;
		getchar();
	}

	if (1) {
		TString s0 = "hello";
		TString s1 = "tongji";
		TString s2;
		TString s3(s2);

		cout << "通过set函数将一个对象的字符串赋值给另一个对象的测试" << endl;

		cout << "s0应为hello， 实际输出：" << s0.get_content() << endl;

		s0.set(s1);
		cout << "s0应为tongji，实际输出：" << s0.get_content() << endl;

		s0.set(s2);
		cout << "s0应为<NULL>，实际输出：" << s0.get_content() << endl;

		s0.set(s3);
		cout << "s0应为<NULL>，实际输出：" << s0.get_content() << endl;

		cout << endl << "任意键继续..." << endl;
		getchar();
	}

	if (1) {
		TString s1 = "hello";
		TString s2;
		char str1[] = "tong\0\0\0\0";
		char *str2 = "ji";

		cout << "求长度测试(length()函数)" << endl;

		cout << "s1为hello， 长度应为5，实际：" << s1.length() << endl;
		cout << "s2为<NULL>，长度应为0，实际：" << s2.length() << endl;

		s2.set(strcat(str1, str2));
		cout << "s2为tongji，长度应为6，实际：" << s2.length() << endl;

		cout << endl << "任意键继续..." << endl;
		getchar();
	}

	return 0;
}
