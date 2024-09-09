#include <iostream>
using namespace std;
void First(void);
void Second(void);
int main()
{
	First();
	First();
	Second();
	Second();
	return 0;
}
void First()
{
	cout << "Three blind mice" << endl;
}
void Second()
{
	cout << "See how they run" << endl;
}