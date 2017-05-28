/* 1650254 ��Ң�� ��1*/

#include <iostream>
using namespace std;

/* ������ԭ�Ͷ��岻׼�� */
int   tj_strlen(const char *str);
char *tj_strcat(char *s1, const char *s2);
char *tj_strcpy(char *s1, const char *s2);
char *tj_strncpy(char *s1, const char *s2, const int len);
int   tj_strcmp(const char *s1, const char *s2);
int   tj_strcasecmp(const char *s1, const char *s2);
int   tj_strncmp(const char *s1, const char *s2, const int len);
int   tj_strcasencmp(const char *s1, const char *s2, const int len);
char *tj_strupr(char *str);
char *tj_strlwr(char *str);
int   tj_strchr(const char *str, const char ch);
int   tj_strstr(const char *str, const char *substr);
int   tj_strrchr(const char *str, const char ch);
int   tj_strrstr(const char *str, const char *substr);
char *tj_strrev(char *str);

/* ----- ���������κ���ʽ��ȫ������!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
int tj_strlen(const char *str)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	const char *p1 = str;
	if (str == NULL)
		return 0;
	while (*p1 != '\0')
		p1++;
	return (p1-str) / 1;
}

char *tj_strcat(char *s1, const char *s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	char *p1 = s1;
	int i = tj_strlen(s1);
	if (s1 == NULL)
		return s1;
	if (s2 == NULL)
		return s1;
	s1 += i;
	while (*s2 != '\0')
		*(s1++) = *(s2++);
	*s1 = '\0';
	s1 = p1;
	return s1;
}

char *tj_strcpy(char *s1, const char *s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	char *p1 = s1;
	if (s1 == NULL)
		return s1;
	if (s2 == NULL)
	{
		*s1 = '\0';
		return s1;
	}
	while (*s2 != '\0')
		*(s1++) = *(s2++);
	*s1 = '\0';
	s1 = p1;
	return s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	char *p1 = s1;
	if (s1 == NULL)
		return s1;
	if (s2 == NULL)
		return s1;
	int i = tj_strlen(s2);
	int j = len;
	while (j--&&i--)
		*(s1++) = *(s2++);
	s1 = p1;
	return s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int temp;
	const char *p1 = s1, *p2 = s2;
	if (s1 == NULL && s2 == NULL)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;
	while (1)
		if (*s1 != '\0'&&*s2 != '\0')
		{
			if (*(s1++) != *(s2++))
			{
				s1--;
				s2--;
				break;
			}
		}
		else
			break;
		
	temp = (int)(*(s1) - *(s2));
	s1 = p1;
	s2 = p2;
	return temp; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcasecmp(const char *s1, const char *s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;
	const char *p1 = s1, *p2 = s2;
	int i = 0;
	int temp;
	char temp1;
	char temp2;
	while (1)
	{
		if (*s1!= '\0'&&*s2!= '\0')
		{
			temp1 = *s1;
			temp2 = *s2;
			if (temp1 >= 65 && temp1 <= 90)
				temp1 += 32;
			if (temp2 >= 65 && temp2 <= 90)
				temp2 += 32;
			if (temp1 != temp2)
			{
				temp = (int)(temp1 - temp2);
				break;
			}
			else
			{
				s1++;
				s2++;
			}
		}
		else
		{
			temp = (int)(*s1 - *s2);
			break;
		}
	}
	s1 = p1;
	s2 = p2;
	return temp;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;
	const char *p1 = s1, *p2 = s2;
	int i = 0;
	int temp;
	int len1 = tj_strlen(s1);
	int len2 = tj_strlen(s2);
	while (1)
	{
		if (*s1 != '\0'&&*s2 != '\0'&&i < len - 1)
		{
			if (*s1!= *s2)
				break;
			else
			{
				s1++;
				s2++;
				i++;
			}
		}
		else
			break;
	}
	temp = (int)(*s1 - *s2);
	s1 = p1;
	s2 = p2;
	return temp;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;
	const char *p1 = s1, *p2 = s2;
	int i = 0;
	int len1 = tj_strlen(s1);
	int len2 = tj_strlen(s2);
	int temp;
	char temp1;
	char temp2;
	while (1)
	{
		if (*s1 != '\0'&&*s2 != '\0'&&i < len - 1)
		{
			temp1 = *s1;
			temp2 = *s2;
			if (temp1 >= 65 && temp1 <= 90)
				temp1 += 32;
			if (temp2 >= 65 && temp2 <= 90)
				temp2 += 32;
			if (temp1 != temp2)
			{
				temp = (int)(temp1 - temp2);
				break;
			}
			else
			{
				s1++;
				s2++;
				i++;
			}
		}
		else
		{
			temp1 = *s1;
			temp2 = *s2;
			if (temp1 >= 65 && temp1 <= 90)
				temp1 += 32;
			if (temp2 >= 65 && temp2 <= 90)
				temp2 += 32;
			temp = (int)(temp1 - temp2);
			break;
		}
	}
	s1 = p1;
	s2 = p2;
	return temp;
}

char *tj_strupr(char *str)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL)
		return str;
	char *str1 = str;
	while (*str != '\0')
	{
		if (*str>= 97 && *str<= 122)
		{
			*str = *str - 32;
		}
		str++;
	}
	str = str1;
	return str;
}

char *tj_strlwr(char *str)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL)
		return str;
	char *str1 = str;
	while (*str != '\0')
	{
		if (*str >= 65 && *str<= 90)
		{
			*str = *str + 32;
		}
		str++;
	}
	str = str1;
	return str;
}

int tj_strchr(const char *str, const char ch)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL)
		return 0;
	int i = 0;
	int len = tj_strlen(str);
	while (*str != ch&&i < len - 1)
	{
		str++;
		i++;
	}
	if (i != len - 1)
		return i + 1;
	else
		return 0;
}

int tj_strstr(const char *str, const char *substr)
{
	if (str == NULL)
		return 0;
	int  i = 0,sum = 0;
	while( *str != '\0')
	{
		int temp = tj_strncmp(str, substr, tj_strlen(substr));
		i++;
		if (temp == 0)
		{
			sum += i;
			break;
		}
		str++;
	}
	return sum; 
}

int tj_strrchr(const char *str, const char ch)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL)
		return 0;
	int len = tj_strlen(str);
	int i = len - 1;
	str += i;
	while (*str != ch&&i >= 0)
	{
		str--;
		i--;
	}
	if (i != -1)
		return i + 1;
	else
		return 0;
}

int tj_strrstr(const char *str, const char *substr)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL)
		return 0;
	int len = tj_strlen(str);
	str += tj_strlen(str) - 1;
	int  n = 0, num = 0;
	while( n<len)
	{
		int temp = tj_strncmp(str, substr, tj_strlen(substr));
		n++;
		if (temp == 0)
		{
			num += n;
			break;
		}
		str--;
	}
	if (num == 0)
		return 0;
	return (len + 1 - num);
}

char *tj_strrev(char *str)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (str == NULL || str == "")
		return str;
	int n = tj_strlen(str) - 1;
	char *str1 = str;
	char *str2 = str;
	str2 = str2 + n;
	while (*str != '\0')
	{
		if (str1 >= str2)
			break;
		int temp;
		temp = *str1;
		*str1 = *str2;
		*str2= temp;
		str1++;
		str2--;
	}
	return str;
}
