#include <iostream>
using namespace std;
double transfer(double);
int main()
{
	double num_lightyears;
	cout << "Enter the number of light years: ";
	cin >> num_lightyears;
	double outcome = transfer(num_lightyears);
	cout << num_lightyears<<" light years " << " = " << outcome << " astronomical units";
	return 0;
}

double transfer(double num_lightyears)
{
	return num_lightyears * 63240;
}