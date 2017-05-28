/* 计1 1650254 尤尧寅*/

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

int tj_strlen(const char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
    return i; //return值可根据需要修改
}

int tj_strcat(char s1[], const char s2[])
{
	int ins = tj_strlen(s1);
	for (int k = tj_strlen(s1); k <= tj_strlen(s1)+tj_strlen(s2)+1; k++)
	{
		s1[k] = s2[k - ins];
	}

    return 0; //return值可根据需要修改
}

int tj_strcpy(char s1[], const char s2[])
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';

    return 0; //return值可根据需要修改
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	int i = 0;
	while (i<len)
	{
		if (s2[i] == '\0')
			break;
		s1[i] = s2[i];
		i++;
	}
	return 0; //return值可根据需要修改
}

int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int temp;
	while (1)
	{
		if (s1[i]!='\0'&&s2[i]!='\0')
		{
			if (s1[i] != s2[i])
				break;
			else
				i++;
		}
		else
		{
			break;
		}
	}
	temp = (int)(s1[i] - s2[i]);
	return temp; //return值可根据需要修改
}

int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int temp;
	char temp1;
	char temp2;
	while (1)
	{
		if (s1[i] != '\0'&&s2[i] != '\0')
		{
			temp1 = s1[i];
			temp2 = s2[i];
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
				i++;
		}
		else
		{
			temp = (int)(s1[i] - s2[i]);
			break;
		}
	}
	return temp; //return值可根据需要修改
}

int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int temp;
	int len1 = tj_strlen(s1);
	int len2 = tj_strlen(s2);
	while (1)
	{
		if (s1[i] != '\0'&&s2[i] != '\0'&&i < len - 1)
		{
			if (s1[i] != s2[i])
				break;
			else
				i++;
		}
		else
			break;
	}
	temp = (int)(s1[i] - s2[i]);
	return temp; //return值可根据需要修改
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int len1 = tj_strlen(s1);
	int len2 = tj_strlen(s2);
	int temp;
	char temp1;
	char temp2;
	while (1)
	{
		if (s1[i] != '\0'&&s2[i] != '\0'&&i < len-1)
		{
			temp1 = s1[i];
			temp2 = s2[i];
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
				i++;
		}
		else
		{
			temp1 = s1[i];
			temp2 = s2[i];
			if (temp1 >= 65 && temp1 <= 90)
				temp1 += 32;
			if (temp2 >= 65 && temp2 <= 90)
				temp2 += 32;
			temp = (int)(temp1 - temp2);
			break;
		}
	}
	return temp;//return值可根据需要修改
}

int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
    return 0; //return值可根据需要修改
}

int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return 0; //return值可根据需要修改
}

int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int len = tj_strlen(str);
	while (str[i] != ch&&i < len - 1)
	{
		i++;
	}
	if (i != len - 1)
		return i + 1;
	else
		return 0;//return值可根据需要修改
}

int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int j = 0;
	int temp=0;
	while (str[i] != '\0')
	{
		if (str[i] == substr[j])
		{
			if (j == 0)
				temp = i;
			if (substr[j+1]=='\0')
			{
				return temp+1;
			}
			j++;
		}
		else
		{
			if(j!=0)
				i = temp;
			j = 0;
		}
		i++;
	}
	return 0;
}

int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	
	int len = tj_strlen(str);
	int i = len-1;
	while (str[i] != ch&&i >= 0)
	{
		i--;
	}
	if (i != -1)
		return i + 1;
	else
		return 0; //return值可根据需要修改
}

int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len1 = tj_strlen(str);
	int len2 = tj_strlen(substr);
	int i = len1 - 1;
	int j = len2 - 1;
	int temp = len1 - 1;
	while (i!=-1)
	{
		if (str[i] == substr[j])
		{
			if (j == 0 )
				temp = i;
			if (j == len2 - 1)
				temp = i;
			if (j == 0)
			{
				return temp + 1;
			}
			j--;
		}
		else
		{
			if (j != len2-1)
				i = temp;
			j = len2-1;
		}
		i--;
	}
	return 0;//return值可根据需要修改
}

int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int n = tj_strlen(str)-1;
	int i = 0;
	while (str[0]!='\0')
	{
		if (n - i == 0 || n - i == 1)
			break;
		int temp;
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		i++;
		n--;
	}
	
    return 0; //return值可根据需要修改
}
