#include <iostream>
using namespace std;
double n(double);
int main()
{
	double m;
	cout << "Please enter a Celsius value:";
	cin >>m;
	double outcome = n(m);
	cout << m << " degrees Celsius is " << outcome << " degrees Fahrenheit.";
	return 0;
}
double n(double m)
{
	return m * 1.8 + 32;
}

