/*1650254 尤尧寅 计算机一班*/
#include"7-b17-1.h"
int main()
{
	fstream infile;
	infile.open(fname, ios::in | ios::out | ios::binary|ios::trunc);
	if (!infile.is_open())
		return 1;
	if (1)
	{
		char temp[]= "test";
		cout << "测试int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "在" << fname << "中写入[" << temp << "]项"<<endl;
		cout << "函数返回值应该是： 0    实际是：" << group_add(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		cout << "测试int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "在" << fname << "中写入[" << temp << "]项" << endl;
		cout << "函数返回值应该是： 1    实际是：" << group_add(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "今天是个好日子";
		cout << "测试int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "在" << fname << "中写入[" << temp << "]项" << endl;
		cout << "函数返回值应该是： 0    实际是：" << group_add(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "今天是个好";
		cout << "测试int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "在" << fname << "中写入[" << temp << "]项" << endl;
		cout << "函数返回值应该是： 0    实际是：" << group_add(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "今天是个好日子啊";
		cout << "测试int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "在" << fname << "中写入[" << temp << "]项" << endl;
		cout << "函数返回值应该是： 0    实际是：" << group_add(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		int i = 1;
		cout << "测试int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中增加 "<< temp1<<" 项 值为 "<<i<< endl;
		cout << "函数返回值应该是： 0    实际是：" << item_add(infile, temp,temp1,&i,TYPE_INT) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		char i[] = "不可能的，不存在的";
		cout << "测试int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中增加 " << temp1 << " 项 值为 " << i << endl;
		cout << "函数返回值应该是： 1    实际是：" << item_add(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "不挂高程";
		int i = 1;
		cout << "测试int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中增加 " << temp1 << " 项 值为 " << i << endl;
		cout << "函数返回值应该是： 0    实际是：" << item_add(infile, temp, temp1, &i, TYPE_INT) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		char i[] = "不可能的，不存在的";
		cout << "测试int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中更新 " << temp1 << " 项 值为 " << i << endl;
		cout << "函数返回值应该是： 0    实际是：" << item_update(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		char i[] = "可能的吧，存在的吧";
		cout << "测试int item_get_value(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中提取 " << temp1 << " 项" << endl;
		cout << "i原本值为：" << i<<endl;
		cout << "函数返回值应该是： 0    实际是：" << item_get_value(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "i目前值为：" << i << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		cout << "测试int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中删除 " << temp1 << " 项" << endl;
		cout << "函数返回值应该是： 0    实际是：" << item_del(infile, temp, temp1) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "我想不挂高程";
		cout << "测试int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "在" << fname << "的[" << temp << "]项中删除 " << temp1 << " 项" << endl;
		cout << "函数返回值应该是：1    实际是：" << item_del(infile, temp, temp1) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		cout << "测试int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "将" << fname << "的[" << temp << "]项删除"<< endl;
		cout << "函数返回值应该是：0    实际是：" << group_del(infile, temp) << endl;
		cout << "文件内容为：" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	cout << "测试完毕！" << endl;
	return 0;
}