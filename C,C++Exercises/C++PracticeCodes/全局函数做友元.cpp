///////////////////全局函数做友元
#include <iostream>

class Student
{
public:
};

void test01()
{
    Student s1;
}

int main()
{
    test01();
    return 0;
}