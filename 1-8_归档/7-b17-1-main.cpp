/*1650254 ��Ң�� �����һ��*/
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
		cout << "����int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "��" << fname << "��д��[" << temp << "]��"<<endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << group_add(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		cout << "����int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "��" << fname << "��д��[" << temp << "]��" << endl;
		cout << "��������ֵӦ���ǣ� 1    ʵ���ǣ�" << group_add(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "�����Ǹ�������";
		cout << "����int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "��" << fname << "��д��[" << temp << "]��" << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << group_add(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "�����Ǹ���";
		cout << "����int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "��" << fname << "��д��[" << temp << "]��" << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << group_add(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "�����Ǹ������Ӱ�";
		cout << "����int group_add(fstream &fp, const char *group_name);" << endl;
		cout << "��" << fname << "��д��[" << temp << "]��" << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << group_add(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		int i = 1;
		cout << "����int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "��" << fname << "��[" << temp << "]�������� "<< temp1<<" �� ֵΪ "<<i<< endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << item_add(infile, temp,temp1,&i,TYPE_INT) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		char i[] = "�����ܵģ������ڵ�";
		cout << "����int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "��" << fname << "��[" << temp << "]�������� " << temp1 << " �� ֵΪ " << i << endl;
		cout << "��������ֵӦ���ǣ� 1    ʵ���ǣ�" << item_add(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���Ҹ߳�";
		int i = 1;
		cout << "����int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "��" << fname << "��[" << temp << "]�������� " << temp1 << " �� ֵΪ " << i << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << item_add(infile, temp, temp1, &i, TYPE_INT) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		char i[] = "�����ܵģ������ڵ�";
		cout << "����int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "��" << fname << "��[" << temp << "]���и��� " << temp1 << " �� ֵΪ " << i << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << item_update(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		char i[] = "���ܵİɣ����ڵİ�";
		cout << "����int item_get_value(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);" << endl;
		cout << "��" << fname << "��[" << temp << "]������ȡ " << temp1 << " ��" << endl;
		cout << "iԭ��ֵΪ��" << i<<endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << item_get_value(infile, temp, temp1, &i, TYPE_STRING) << endl;
		cout << "iĿǰֵΪ��" << i << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		cout << "����int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "��" << fname << "��[" << temp << "]����ɾ�� " << temp1 << " ��" << endl;
		cout << "��������ֵӦ���ǣ� 0    ʵ���ǣ�" << item_del(infile, temp, temp1) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		char temp1[] = "���벻�Ҹ߳�";
		cout << "����int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "��" << fname << "��[" << temp << "]����ɾ�� " << temp1 << " ��" << endl;
		cout << "��������ֵӦ���ǣ�1    ʵ���ǣ�" << item_del(infile, temp, temp1) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	if (1)
	{
		char temp[] = "test";
		cout << "����int item_del(fstream &fp, const char *group_name, const char *item_name);" << endl;
		cout << "��" << fname << "��[" << temp << "]��ɾ��"<< endl;
		cout << "��������ֵӦ���ǣ�0    ʵ���ǣ�" << group_del(infile, temp) << endl;
		cout << "�ļ�����Ϊ��" << endl;
		group_show(infile);
		getchar();
		cout << endl;
	}
	cout << "������ϣ�" << endl;
	return 0;
}