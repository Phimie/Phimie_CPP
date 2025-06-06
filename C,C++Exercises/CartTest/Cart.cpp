#include <iostream>
#include <string>
#include <fstream>

class Student
{
public:
    Student() : m_Age(18) {}
    Student(int age) : m_Age(18)
    {
        this->m_Age = age;
    }

public:
    int m_Age;
};

void writeFile()
{
    std::ofstream ofs("信息.txt", std::ios::out | std::ios::binary);
    if (!ofs.is_open())
    {
        std::cerr << "文件打开失败!" << std::endl;
        return;
    }
    Student s1(18);
    ofs.write(reinterpret_cast<char *>(&s1), sizeof(Student));
    ofs.close();
}

void readFile()
{
    std::ifstream ifs("信息.txt", std::ios::in | std::ios::binary);
    if (!ifs.is_open())
    {
        std::cerr << "文件打开失败!" << std::endl;
        return;
    }

    Student temp_s;
    ifs.read(reinterpret_cast<char *>(&temp_s), sizeof(Student));
    std::cout << "年龄:" << temp_s.m_Age << std::endl;
    ifs.close();
}
int main()
{
    writeFile();
    readFile();

    system("pause");
    return 0;
}