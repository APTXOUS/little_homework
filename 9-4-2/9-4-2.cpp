/* 1650254 尤尧寅 计算机一班*/
#include <iostream>
using namespace std;

class student {
private:
	int num;
	float score;
public:
	void display();  //输出学号和成绩
	void get(void);  //键盘输入学号和成绩
					 //类中不允许再添加任何数据成员和成员函数
};

/* 在此给出类成员函数的体外实现 */
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
	/* 【注意：】函数中不允许再定义任何类型的变量(包括全局变量) */
	student *p, s[5];

	/* 键盘输入5个人的学号及成绩
	【要求：】必须给出明确的输入提示，例如“请输入第**个人学号和成绩” */
	p = s;
	cout << "请输入第1个人学号和成绩(学号和成绩用空格隔开)" << endl;
	p->get();
	cout << "请输入第2个人学号和成绩(学号和成绩用空格隔开)" << endl;
	(p + 1)->get();
	cout << "请输入第3个人学号和成绩(学号和成绩用空格隔开)" << endl;
	(p + 2)->get();
	cout << "请输入第4个人学号和成绩(学号和成绩用空格隔开)" << endl;
	(p + 3)->get();
	cout << "请输入第5个人学号和成绩(学号和成绩用空格隔开)" << endl;
	(p + 4)->get();

	/* 输出第1、3、5个人的信息 */
	p->display();
	(p + 2)->display();
	(p + 4)->display();
	system("pause");
	return 0;
}