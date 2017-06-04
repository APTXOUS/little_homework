/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::~TString()
{
	if (content)
	{

		delete content;
		content = NULL;
	}
}
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::TString(const char  *target)
{

	if (target != NULL)
	{
		len = strlen(target);
		if (len != 0)
		{
			content = new(nothrow)char[len + 1];
			if (content == NULL)
				exit(0);
			strcpy(content, target);
		}
		else
			content = NULL;
	}
	else
	{
		len = 0;
		content = NULL;
	}
}
TString::TString(const TString &target)
{

	len = target.len;
	if (target.content == NULL)
		content = NULL;
	else
	{
		content = new(nothrow)char[len + 1];
		if (content == NULL)
			exit(0);
		strcpy(content, target.content);
	}

}
TString& TString::operator =(const TString &target)
{
	if (content)
	{
		delete content;
		content = NULL;
	}
	len = target.len;
	if (target.content == NULL)
		content = NULL;
	else
	{
		content = new(nothrow)char[len + 1];
		if (content == NULL)
			exit(0);
		strcpy(content, target.content);
	}
	return *this;
}

TString TString::operator +(TString &b)
{
	TString temp;
	temp.len = b.len + len;
	temp.content = new(nothrow)char[temp.len + 1];
	if (temp == NULL)
		exit(0);
	temp[0] = 0;
	if(content)
		strcpy(temp.content, content);
	if(b.content)
		strcat(temp.content, b.content);
	return temp;
}
TString TString::operator +(const char b[])
{
	TString temp;
	if (b)
		temp.len = strlen(b) + len;
	else
		temp.len = len;
	if (temp.len > 0)
	{
		temp.content = new(nothrow)char[temp.len + 1];
		if (temp == NULL)
			exit(0);
		temp[0] = 0;
		if (content)
			strcpy(temp.content, content);
		if (b)
			strcat(temp.content, b);
	}
	return temp;
}
int TString::length()
{
	return len;
}
char& TString::operator[](int i)
{
	if (i < len&&i >= 0)
		return content[i];
	else if (i >= len)
		return content[len - 1];
	else if (i <0)
		return content[0];
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
int TStringLen(TString &target)
{
	return target.len;
}
TString operator +(const char b[], TString &a)
{
	TString temp;
	if (b)
		temp.len = strlen(b) + a.len;
	else
		temp.len = a.len;
	if (temp.len > 0)
	{
		temp.content = new(nothrow)char[temp.len + 1];
		if (temp == NULL)
			exit(0);
		temp[0] = 0;
		if (b)
			strcpy(temp.content, b);
		if (a.content)
			strcat(temp.content, a.content);
	}
	return temp;
}
ostream& operator << (ostream &out, TString &a)
{
	if (a.content == NULL)
		out << "<NULL>";
	else
		for (int i = 0; i < a.len; i++)
			out << a.content[i];
	return out;
}
istream& operator >> (istream &in, TString &a)
{
	char temp[1025];
	int space = 0;
	int flag = 0;
	if (a.content)
	{
		delete a.content;
		a.content = NULL;
	}
	while (flag==0)
	{
		for (int i = 0; i < 1024; i++)
		{
			in.get(temp[i]);
			if (temp[i] == ' ' || temp[i] == '\n' || temp[i] == '\r')
			{
				temp[i] = '\0';
				flag = 1;				break;
			}
		}
		if (flag == 0)
		{
			temp[1024] = '\0';
			renew(&a.content, space + 1024 + 1);
			space = space + 1024;
			strcat(a.content, temp);
		}
		else
		{
			int temp_len = strlen(temp);
			renew(&a.content, space + temp_len + 1);
			space = space + temp_len;
			strcat(a.content, temp);
		}
	}
	a.len = space;
	return in;
}
int renew(char ** target,int space)
{
	char *temp;
	temp = new (nothrow)char[space];
	if (temp == NULL)
		exit(0);
	temp[0] = 0;
	if (*target)
	{
		strcpy(temp, *target);
		delete *target;
		*target = NULL;
	}
	*target = temp;
	return 0;
}
bool operator < (TString &a, TString &b)
{
	if (a.content&&b.content)
	{
		if (strcmp(a.content, b.content) < 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b.content)
	{
		return 1;
	}
	else if (a.content&&b.content == NULL)
	{
		return 0;
	}
	else 
		return 0;
}
bool operator > (TString &a, TString &b)
{
	if (a.content&&b.content)
	{
		if (strcmp(a.content, b.content) > 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b.content)
	{
		return 0;
	}
	else if (a.content&&b.content == NULL)
	{
		return 1;
	}
	else
		return 0;
}
bool operator == (TString &a, TString &b)
{
	if (a.content&&b.content)
		return !strcmp(a.content, b.content);
	else if (a.content == NULL&&b.content)
	{
		return 0;
	}
	else if (a.content&&b.content == NULL)
	{
		return 0;
	}
	else
		return 1;
}
bool operator >= (TString &a, TString &b)
{
	if (a.content&&b.content)
	{
		if (strcmp(a.content, b.content) >= 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b.content)
	{
		return 0;
	}
	else if (a.content&&b.content == NULL)
	{
		return 1;
	}
	else
		return 1;
}
bool operator <= (TString &a, TString &b)
{
	if (a.content&&b.content)
	{
		if (strcmp(a.content, b.content) <= 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b.content)
	{
		return 1;
	}
	else if (a.content&&b.content == NULL)
	{
		return 0;
	}
	else
		return 1;
}
bool operator != (TString &a, TString &b)
{
	if (a.content&&b.content)
		return strcmp(a.content, b.content);
	else if (a.content == NULL&&b.content)
	{
		return 1;
	}
	else if (a.content&&b.content == NULL)
	{
		return 1;
	}
	else
		return 0;
}
bool operator < (TString &a, const char * b)
{
	if (a.content&&b)
	{
		if (strcmp(a.content, b) < 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b)
	{
		return 1;
	}
	else if (a.content&&b== NULL)
	{
		return 0;
	}
	else
		return 0;
}
bool operator <= (TString &a, const char * b)
{
	if (a.content&&b)
	{
		if (strcmp(a.content, b) <= 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b)
	{
		return 1;
	}
	else if (a.content&&b == NULL)
	{
		return 0;
	}
	else
		return 1;
}
bool operator > (TString &a, const char * b)
{
	if (a.content&&b)
	{
		if (strcmp(a.content, b) > 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b)
	{
		return 0;
	}
	else if (a.content&&b == NULL)
	{
		return 1;
	}
	else
		return 0;
}
bool operator >= (TString &a, const char * b)
{
	if (a.content&&b)
	{
		if (strcmp(a.content, b) >= 0)
			return 1;
		else
			return 0;
	}
	else if (a.content == NULL&&b)
	{
		return 0;
	}
	else if (a.content&&b == NULL)
	{
		return 1;
	}
	else
		return 1;
}
bool operator ==(TString &a, const char * b)
{
	if (a.content&&b)
		return !strcmp(a.content, b);
	else if (a.content == NULL&&b)
	{
		return 0;
	}
	else if (a.content&&b == NULL)
	{
		return 0;
	}
	else
		return 1;
}
bool operator !=(TString &a, const char * b)
{
	if (a.content&&b)
		return strcmp(a.content, b);
	else if (a.content == NULL&&b)
	{
		return 1;
	}
	else if (a.content&&b == NULL)
	{
		return 1;
	}
	else
		return 0;
}