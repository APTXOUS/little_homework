/*1650254 ÓÈÒ¢Òú ¼ÆËã»úÒ»°à*/
#include<iostream>
using namespace std;
class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	void set_time(void);
	void show_time(void);
};
void Time::set_time() {
	cin >> hour;
	cin >> minute;
	cin >> sec;
}
void Time::show_time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}
int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	//system("pause");
	return 0;
}

