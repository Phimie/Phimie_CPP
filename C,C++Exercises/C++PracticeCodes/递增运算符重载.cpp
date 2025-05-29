// 递增运算符重载
#include <iostream>
#include <string>

class MyInteger
{
    friend std::ostream &operator<<(std::ostream &cout, const MyInteger &myint);

public:
    MyInteger() : m_Num(0)
    {
    }

public:
    // 重载前置++运算符
    MyInteger &operator++()
    {
        m_Num++;
        return *this; // 将自身进行返回
    }
    // 重载后置++运算符
    MyInteger operator++(int) // int 代表占位参数,可以用于区分前置和后置递增
    {                         // 后置递增返回的是一个值而不是引用
        // 先 返回结果
        MyInteger temp = *this;
        // 后 递增
        m_Num++;
        // 最后将记录结果做返回
