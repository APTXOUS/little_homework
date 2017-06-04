/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>		//getch()函数要包含此头文件
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "10-b3.h"
using namespace std;

void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/* ----main函数不准动---- */
int main()
{
	if (1) {
		TString s1;                  //s1为NULL
		TString s2("teststr2");      //s2为"teststr2"
		TString s3 = "teststr3";       //s3为"teststr3"
		TString s4 = NULL;             //s4为NULL
		TString s5 = "";               //s5为NULL

		cout << "定义对象并初始化测试(NULL及字符串常量初始化)" << endl;

		cout << "s1应该是<NULL>，  实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s0 = "teststr1";
		char *str1 = "teststr2";
		char  str2[] = "teststr3";
		char *str3 = NULL;
		char  str4[] = "";
		TString s1 = s0, s2 = str1, s3 = str2, s4 = str3, s5 = str4;

		cout << "定义对象并初始化测试(TString对象及字符指针、字符数组)" << endl;

		cout << "s1应该是teststr1，实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;

		wait_for_enter();
	}
	if (1) {
		TString s1;

		cout << "重载cin测试" << endl;

		cout << "请在键盘上输入Hello" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		cout << "请在键盘上输入Hello 123" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("Hello"), s2;

		cout << "赋值操作测试" << endl;

		cout << "s1应该是Hello， 实际输出：" << s1 << endl;

		s2 = s1;
		cout << "s2应该是Hello， 实际输出：" << s2 << endl;

		s1 = "Hi";
		cout << "s1应该是Hi，    实际输出：" << s1 << endl;

		s2 = "";
		cout << "s2应该是<NULL>，实际输出：" << s2 << endl;

		s1 = NULL;
		cout << "s1应该是<NULL>，实际输出：" << s1 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s0, s1("tong"), s2("ji"), s3;

		cout << "连接(+)测试(两个TString类)" << endl;

		s3 = s1 + s2;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = s2 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + s0;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s0 + s2;
		cout << "s3应为ji，    实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s2, s3;

		cout << "连接(+)测试(TString类和字符串常量)" << endl;

		s3 = s1 + "ji";
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = "ji" + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + "";
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1 + NULL;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = "" + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = NULL + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s2 + NULL;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = NULL + s2;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = s2 + "";
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = "" + s2;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s3;
		char *str1 = "ji", *str2 = "", *str3 = NULL;

		cout << "连接(+)测试(TString类和字符指针)" << endl;

		s3 = s1 + str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = str1 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1 + str3;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str3 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s3;
		char str1[] = "ji", str2[] = "";

		cout << "连接(+)测试(TString类和字符数组)" << endl;

		s3 = s1 + str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = str1 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "house", s2 = "horse", s3 = "house", s4 = "", s5 = NULL;

		cout << "比较运算测试(两个TString类)" << endl;

		cout << "串1=" << s1 << " 串2=" << s2 << " > 结果应为1，实际：" << (s1 >  s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " >=结果应为1，实际：" << (s1 >= s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " < 结果应为0，实际：" << (s1 <  s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " <=结果应为0，实际：" << (s1 <= s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " ==结果应为0，实际：" << (s1 == s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " !=结果应为1，实际：" << (s1 != s2) << endl;

		cout << "串1=" << s1 << " 串3=" << s3 << " > 结果应为0，实际：" << (s1 >  s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " >=结果应为1，实际：" << (s1 >= s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " < 结果应为0，实际：" << (s1 <  s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " <=结果应为1，实际：" << (s1 <= s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " ==结果应为1，实际：" << (s1 == s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " !=结果应为0，实际：" << (s1 != s3) << endl;

		cout << "串1=" << s1 << " 串4=" << s4 << " > 结果应为1，实际：" << (s1 >  s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " >=结果应为1，实际：" << (s1 >= s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " < 结果应为0，实际：" << (s1 <  s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " <=结果应为0，实际：" << (s1 <= s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " ==结果应为0，实际：" << (s1 == s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " !=结果应为1，实际：" << (s1 != s4) << endl;

		cout << "串1=" << s1 << " 串5=" << s5 << " > 结果应为1，实际：" << (s1 >  s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " >=结果应为1，实际：" << (s1 >= s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " < 结果应为0，实际：" << (s1 <  s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " <=结果应为0，实际：" << (s1 <= s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " ==结果应为0，实际：" << (s1 == s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " !=结果应为1，实际：" << (s1 != s5) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "house";

		cout << "比较运算测试(TString类和字符串常量)" << endl;

		cout << "串1=" << s1 << " 常量=horse" << " > 结果应为1，实际：" << (s1 >  "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " >=结果应为1，实际：" << (s1 >= "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " < 结果应为0，实际：" << (s1 <  "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " <=结果应为0，实际：" << (s1 <= "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " ==结果应为0，实际：" << (s1 == "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " !=结果应为1，实际：" << (s1 != "horse") << endl;

		cout << "串1=" << s1 << " 常量=house" << " > 结果应为0，实际：" << (s1 >  "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " >=结果应为1，实际：" << (s1 >= "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " < 结果应为0，实际：" << (s1 <  "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " <=结果应为1，实际：" << (s1 <= "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " ==结果应为1，实际：" << (s1 == "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " !=结果应为0，实际：" << (s1 != "house") << endl;

		cout << "串1=" << s1 << " 常量=" << " > 结果应为1，实际：" << (s1 >  "") << endl;
		cout << "串1=" << s1 << " 常量=" << " >=结果应为1，实际：" << (s1 >= "") << endl;
		cout << "串1=" << s1 << " 常量=" << " < 结果应为0，实际：" << (s1 <  "") << endl;
		cout << "串1=" << s1 << " 常量=" << " <=结果应为0，实际：" << (s1 <= "") << endl;
		cout << "串1=" << s1 << " 常量=" << " ==结果应为0，实际：" << (s1 == "") << endl;
		cout << "串1=" << s1 << " 常量=" << " !=结果应为1，实际：" << (s1 != "") << endl;

		cout << "串1=" << s1 << " 常量=<NULL>" << " > 结果应为1，实际：" << (s1 >  NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " >=结果应为1，实际：" << (s1 >= NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " < 结果应为0，实际：" << (s1 <  NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " <=结果应为0，实际：" << (s1 <= NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " ==结果应为0，实际：" << (s1 == NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " !=结果应为1，实际：" << (s1 != NULL) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "house";
		char *str2 = "horse", *str3 = "house", *str4 = "", *str5 = NULL;

		cout << "比较运算测试(TString类和字符指针)" << endl;

		cout << "串1=" << s1 << " 串2=" << str2 << " > 结果应为1，实际：" << (s1 >  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " >=结果应为1，实际：" << (s1 >= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " < 结果应为0，实际：" << (s1 <  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " <=结果应为0，实际：" << (s1 <= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " ==结果应为0，实际：" << (s1 == str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " !=结果应为1，实际：" << (s1 != str2) << endl;

		cout << "串1=" << s1 << " 串3=" << str3 << " > 结果应为0，实际：" << (s1 >  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " >=结果应为1，实际：" << (s1 >= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " < 结果应为0，实际：" << (s1 <  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " <=结果应为1，实际：" << (s1 <= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " ==结果应为1，实际：" << (s1 == str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " !=结果应为0，实际：" << (s1 != str3) << endl;

		cout << "串1=" << s1 << " 串4=" << str4 << " > 结果应为1，实际：" << (s1 >  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " >=结果应为1，实际：" << (s1 >= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " < 结果应为0，实际：" << (s1 <  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " <=结果应为0，实际：" << (s1 <= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " ==结果应为0，实际：" << (s1 == str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " !=结果应为1，实际：" << (s1 != str4) << endl;

		cout << "串1=" << s1 << " 串5=<NULL>" << " > 结果应为1，实际：" << (s1 >  str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " >=结果应为1，实际：" << (s1 >= str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " < 结果应为0，实际：" << (s1 <  str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " <=结果应为0，实际：" << (s1 <= str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " ==结果应为0，实际：" << (s1 == str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " !=结果应为1，实际：" << (s1 != str5) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "house";
		char str2[] = "horse", str3[] = "house", str4[] = "";

		cout << "比较运算测试(TString类和字符指针)" << endl;

		cout << "串1=" << s1 << " 串2=" << str2 << " > 结果应为1，实际：" << (s1 >  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " >=结果应为1，实际：" << (s1 >= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " < 结果应为0，实际：" << (s1 <  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " <=结果应为0，实际：" << (s1 <= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " ==结果应为0，实际：" << (s1 == str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " !=结果应为1，实际：" << (s1 != str2) << endl;

		cout << "串1=" << s1 << " 串3=" << str3 << " > 结果应为0，实际：" << (s1 >  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " >=结果应为1，实际：" << (s1 >= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " < 结果应为0，实际：" << (s1 <  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " <=结果应为1，实际：" << (s1 <= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " ==结果应为1，实际：" << (s1 == str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " !=结果应为0，实际：" << (s1 != str3) << endl;

		cout << "串1=" << s1 << " 串4=" << str4 << " > 结果应为1，实际：" << (s1 >  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " >=结果应为1，实际：" << (s1 >= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " < 结果应为0，实际：" << (s1 <  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " <=结果应为0，实际：" << (s1 <= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " ==结果应为0，实际：" << (s1 == str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " !=结果应为1，实际：" << (s1 != str4) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "tong", s2;

		cout << "求长度测试(length()函数)" << endl;

		cout << "s1为tong，  长度应为4，实际：" << s1.length() << endl;
		cout << "s2为<NULL>，长度应为0，实际：" << s2.length() << endl;
		s2 = s1 + "ji";
		cout << "s2为tongji，长度应为6，实际：" << s2.length() << endl;

		wait_for_enter();
	}
	if (1) {
		TString s1 = "tong", s2;

		cout << "求长度测试(TStringLen()函数)" << endl;

		cout << "s1为tong，  长度应为4，实际：" << TStringLen(s1) << endl;
		cout << "s2为<NULL>，长度应为0，实际：" << TStringLen(s2) << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s1 + (s2 = "ji")) << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s1 + "ji") << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s2 = s1 + "ji") << endl;
		cout << "串为tong，  长度应为4，实际：" << TStringLen(s1 + NULL) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1 = "house";
		TString s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };
		int i, j;
		char ch = 'P';

		cout << "[]运算符测试" << endl;

		cout << "串1是" << s1 << "，依次打印字符的结果是：";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		cout << "串1是" << s1 << "，依次打印字符int值的结果是（有越界）：" << endl;
		for (i = -4; i < s1.length() + 4; i++)
			cout << int(s1[i]) << ' ';
		cout << endl << endl;

		s1[0] = s1[0] - 32;
		cout << "串1是" << s1 << "，依次打印字符的结果是：";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		s1[1] = 'A';
		s1[2] = ch;
		ch += 32;
		s1[3] = ch;
		s1[4] = 'Y';
		cout << "串1是" << s1 << "，依次打印字符的结果是：";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		cout << "串2数组是4个字符串，依次打印字符的结果是：" << endl;
		for (i = 0; i < 4; i++) {
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++)
				cout << s2[i][j] << ' ';
			cout << endl;
		}
		cout << endl;

		cout << "串2数组是4个字符串，首字母大写后依次打印字符的结果是：" << endl;
		for (i = 0; i < 4; i++) {
			s2[i][0] -= 32;
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++)
				cout << s2[i][j] << ' ';
			cout << endl;
		}
		cout << endl;

		wait_for_enter();
	}

	if (1) {
		const int MAX_BYTES = 100 * 1024 * 1024;

		TString s1;
		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		char   *crc_str;

		cout << "内存性能测试(大约需要2-8分钟)，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
		_getch();

		crc_str = new char[MAX_BYTES + 65536]; //申请（100MB+64KB）空间
		if (crc_str == NULL) {
			cout << "无法申请" << MAX_BYTES + 65536 << "字节的校验空间，程序终止，请检查后再次运行" << endl;
			goto END;
		}
		*crc_str = 0; //置为空串

		t_start = GetTickCount(); //取当前系统时间，单位毫秒
		srand((unsigned int)time(0));
		total = 0;
		while (1) {
			len = 32768 + rand() % 32768;

			cout << "s1已有长度：" << s1.length() / (1024.0 * 1024) << " MB字节，本次增加 " << len << " 字节" << endl;
			for (i = 0; i<len; i++)
				temp[i] = ' ' + rand() % 95;	//数组用随机字符填充
			temp[len] = 0;
			total += len;
			s1 = s1 + temp;
			strcat(crc_str, temp);
			if (s1.length() == 0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
				break;
		}
		t_end = GetTickCount();   //取当前系统时间

		cout << "time=" << (t_end - t_start) / 1000.0 << endl;

		if (s1.length() == 0)
			cout << "内存分配到达 " << total / (1024 * 1024) << " MB字节后，内存耗尽" << endl;
		else
			cout << "内存分配到达满100MB，测试结束" << endl;

		if (s1 != crc_str)
			cout << "s1累加验证出错，请检查程序的实现部分" << endl;
		else {
			cout << "    本次测试耗时 " << (t_end - t_start) / 1000.0 << "秒" << endl;
			cout << "    老师的机器运行VS2015编译的程序，大约耗时360-380秒" << endl;
			cout << "    【说明】：只有相同编译器下的运行时间才有可比性" << endl;
			cout << "              老师的机器为Intel(R) Core(TM) i5-4210U CPU @1.70GHz  2.40GHz" << endl;
			cout << "              如果时间相差太大，除CPU的性能差异外，还有可能是算法问题" << endl;

			delete crc_str; //释放校验串

			cout << endl << "打开任务管理器查看程序内存占用情况..." << endl;
			wait_for_enter();
		}
	}
	END:

	system("pause");

	return 0;
}
