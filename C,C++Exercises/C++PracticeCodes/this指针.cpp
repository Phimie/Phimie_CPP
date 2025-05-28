// this指针

#include <iostream>

class Student
{
public:
    int S_A;
};

void test01()
{
    Student s1;
}
int main()
{
    std::cout << "案例一:" << std::endl;
    test01();

    return 0;
}