/* 1650254 ��Ң�� �����һ��*/
#include <iostream>
using namespace std;

class student {
private:
	int num;
	float score;
public:
	void display();  //���ѧ�źͳɼ�
	void get(void);  //��������ѧ�źͳɼ�
					 //���в�����������κ����ݳ�Ա�ͳ�Ա����
};

/* �ڴ˸������Ա����������ʵ�� */
void student::display(void)
{
	cout << "student " << num << " " << "score: " << score << endl;
}
void student::get(void)
{
	cin >> num;
	cin >> score;
}
int main()
{
	/* ��ע�⣺�������в������ٶ����κ����͵ı���(����ȫ�ֱ���) */
	student *p, s[5];

	/* ��������5���˵�ѧ�ż��ɼ�
	��Ҫ�󣺡����������ȷ��������ʾ�����硰�������**����ѧ�źͳɼ��� */
	p = s;
	cout << "�������1����ѧ�źͳɼ�(ѧ�źͳɼ��ÿո����)" << endl;
	p->get();
	cout << "�������2����ѧ�źͳɼ�(ѧ�źͳɼ��ÿո����)" << endl;
	(p + 1)->get();
	cout << "�������3����ѧ�źͳɼ�(ѧ�źͳɼ��ÿո����)" << endl;
	(p + 2)->get();
	cout << "�������4����ѧ�źͳɼ�(ѧ�źͳɼ��ÿո����)" << endl;
	(p + 3)->get();
	cout << "�������5����ѧ�źͳɼ�(ѧ�źͳɼ��ÿո����)" << endl;
	(p + 4)->get();

	/* �����1��3��5���˵���Ϣ */
	p->display();
	(p + 2)->display();
	(p + 4)->display();
	system("pause");
	return 0;
}