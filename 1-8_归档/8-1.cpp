/*1650254 尤尧寅 计算机一班 */
#include<iostream>
using namespace std;
class Time
{

	//原：void set_time(void);
	//原：void show_time(void);
public://原：缺参
	int hour;
	int minute;
	int sec;
};
Time t;
void set_time(void)//原:int set_time(void)
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}
void show_time(void)//原:int show_time(void)
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
int main()
{
	set_time();
	show_time();
	return 0;
}
