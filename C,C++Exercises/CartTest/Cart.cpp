// 购物系统:
/*
实现功能:
1.菜单
2.展示所有商品信息
3.增删商品
4.购物车功能,包括查看购物车和清空购物车
5.结算
6.退出
*/
#include <iostream>
#include <string>
#include <fstream>

class Goods
{
public:
    void get_goods_infomation(const std::string &line) // 字符串处理
    {
        size_t pos = 0; // 从头开始找
        m_Id = line.substr(0, line.find(",", pos));
        pos = m_Id.length() + 1; // 跳过第一个逗号

        m_Name = line.substr(pos, line.find(",", pos) - pos);
        pos = m_Name.length() + 1;

        m_Price = stoi(line.substr(pos, line.find(",", pos) - pos));
        pos = std::to_string(m_Price).length() + 1;

        m_Quantity = stoi(line.substr(pos)); // 只传一个pos,默认为剪到末尾
    }

    std::string toString() const
    {
        return m_Id + "," + m_Name + "," + std::to_string(m_Price) + "," + std::to_string(m_Quantity);
    }

    void change_goods_quantity()
    {
        // 更新商品数量
        std::ifstream tempifs("goods.txt");
        std::ofstream tempofs("temp.txt");
        bool found = false;
        std::string line;
        while (std::getline(tempifs, line))
        {
            if (line.substr(0, line.find(',')) == m_Id)
            {
                m_Quantity -= 1;
                if (m_Quantity > 0)
                {
                    tempofs << m_Id << "," << m_Name << "," << m_Quantity << "," << m_Price << "\n";
                }
                else
                {
                    std::cout << "商品已售空!请明天再来吧!" << std::endl;
                    break;
                }
                found = true;
            }
            else
            {
                std::cout << "剩余商品数量:" << std::endl;
                tempofs << line << "\n";
            }
        }
        tempifs.close();
        tempofs.close();

        if (found)
        {
            std::remove("goods.txt");
            std::rename("temp.txt", "goods.txt");
        }
    }

private:
    std::string m_Id;
    std::string m_Name;
    int m_Price;
    int m_Quantity;
};

class ShoppingSystem
{
public:
    void showMenu()
    {
        std::cout << "===== 购物系统菜单 =====" << std::endl;
        std::cout << "1. 展示所有商品信息" << std::endl;
        std::cout << "2. 增加商品" << std::endl;
        std::cout << "3. 添加到购物车" << std::endl;
        std::cout << "4. 查看购物车" << std::endl;
        std::cout << "5. 清空购物车" << std::endl;
        std::cout << "6. 结算" << std::endl;
        std::cout << "7. 退出" << std::endl;
        std::cout << "========================" << std::endl;
    }

    void display_goods()
    {
        std::ifstream ifs("goods.txt", std::ios::in);
        if (!ifs.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::string line;
        std::cout << "===== 商品信息 =====" << std::endl;
        while (std::getline(ifs, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "=========================" << std::endl;
        ifs.close();
    }

    void add_goods()
    {
        std::ofstream ofs("goods.txt", std::ios::app);
        if (!ofs.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::string id, name;
        int price, quantity;

        std::cout << "请输入商品ID：";
        std::cin >> id;
        std::cout << "请输入商品名称：";
        std::cin >> name;
        std::cout << "请输入商品价格：";
        std::cin >> price;
        std::cout << "请输入商品数量：";
        std::cin >> quantity;

        ofs << id << "," << name << "," << price << "," << quantity << "\n"; // 追加商品信息
        ofs.close();
        std::cout << "商品添加成功！" << std::endl;
    }

    void add_cart()
    {
        std::string id;
        std::cout << "请输入要添加到购物车的商品ID：";
        std::cin >> id;

        std::ifstream ifs("goods.txt", std::ios::in);
        if (!ifs.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::ofstream ofs("cart.txt", std::ios::app);
        if (!ofs.is_open())
        {
            std::cerr << "无法打开购物车文件!" << std::endl;
            return;
        }

        std::string line;
        bool found = false;
        while (std::getline(ifs, line))
        {
            if (line.substr(0, line.find(',')) == id)
            {
                ofs << line << "\n";
                found = true;
                break;
            }
        }

        ifs.close();
        ofs.close();

        if (found)
        {
            std::cout << "商品已添加到购物车！" << std::endl;
        }
        else
        {
            std::cout << "未找到商品！" << std::endl;
        }
    }

    void view_cart()
    {
        std::ifstream ifs("cart.txt", std::ios::in);
        if (!ifs.is_open())
        {
            std::cerr << "无法打开购物车文件!" << std::endl;
            return;
        }

        std::string line;
        std::cout << "===== 购物车信息 =====" << std::endl;
        while (std::getline(ifs, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "=====================" << std::endl;
        ifs.close();
    }

    void clearCart()
    {
        std::ofstream file("cart.txt", std::ios::trunc); // 使用trunc清空cart.txt
        if (!file.is_open())
        {
            std::cerr << "无法打开购物车文件!" << std::endl;
            return;
        }
        file.close();
        std::cout << "购物车已清空！" << std::endl;
    }

    void checkout()
    {
        std::ifstream ifs("cart.txt");
        if (!ifs.is_open())
        {
            std::cerr << "无法打开购物车文件!" << std::endl;
            return;
        }

        std::ofstream outFile("products.txt", std::ios::out | std::ios::trunc);
        if (!outFile.is_open())
        {
            std::cerr << "无法打开商品文件!" << std::endl;
            return;
        }

        std::string line;
        double total = 0.0;
        std::cout << "===== 结算信息 =====" << std::endl;
        while (std::getline(ifs, line))
        {

            std::cout << "总金额：$" << total << std::endl;
            std::cout << "=====================" << std::endl;

            // 清空购物车
            std::ofstream cartFile("cart.txt", std::ios::trunc);
            cartFile.close();
        }
    }
};

int main()
{
    ShoppingSystem shoppingsystem;
    int choice;

    while (true)
    {
        shoppingsystem.showMenu();
        std::cout << "请输入您的选择：";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            shoppingsystem.display_goods();
            break;
        case 2:
            shoppingsystem.add_goods();
            break;
        case 3:
            shoppingsystem.add_cart();
        case 4:
            shoppingsystem.view_cart();
        case 5:
            shoppingsystem.clearCart();
        case 6:
            shoppingsystem.checkout();
        case 7:
            std::cout << "购物系统退出成功!" << std::endl;
            break;
        }
    }

    system("pause");
    return 0;
}