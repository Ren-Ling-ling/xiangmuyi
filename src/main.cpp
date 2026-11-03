#include "book.h"
#include "magazine.h"
#include "eresource.h"
#include "student.h"
#include "teacher.h"
#include "library.h"
#include <iostream>
using namespace std;
int readInt(){
    int x;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"输入失效，请输入数字：";
    }
    return x;
}
int main() {
    library lib;

    // 启动：自动加载 
    lib.loadUsers("users.txt");
    if (!lib.hasusers()) {
        lib.adduser(new student("张三", "20258967", "计算机学院", 2));
        lib.adduser(new teacher("李老师", "T1001", "计算机学院", 5));
        lib.saveUsers("users.txt");
    }

    lib.loadFromFile("resources.txt");
    if (!lib.hasResources()) {
        lib.addResource(new book("三国演义", "9780306406157", "人民文学出版社", 69.9, 300));
        lib.addResource(new magazine("读者", "读者出版社", 10.0, 5, "月刊"));
        lib.addResource(new eresource("c++教程", "人民邮电出版社", 20.0, "http://xxx.com", "pdf"));
        lib.savetoFile("resources.txt");
    }

    //强制登录 
    user* current = nullptr;
    while (current == nullptr) {
        string id;
        cout << "请输入学号/工号登录（输入 0 退出）：";
        cin >> id;
        if (id == "0") { cout << "已退出。" << endl; return 0; }
        current = lib.login(id);
        if (current == nullptr)
            cout << "用户不存在，登录失败，请重试。" << endl;
        else
            cout << "登录成功，欢迎 " << current->Getname() << "！" << endl;
    }

    // 主菜单 
    int choice;
    while (true) { cout<<"\n图书馆借阅管理系统 " << endl;
        cout << "当前用户：" << current->Getname() << endl;
        cout << "1. 显示所有资源" << endl;
        cout << "2. 显示所有用户" << endl;
        cout << "3. 按名称查找资源" << endl;
        cout << "4. 按类型筛选资源" << endl;
        cout << "5. 借书" << endl;
        cout << "6. 还书" << endl;
        cout << "7. 查看我的借阅记录" << endl;
        cout << "8. 删除资源" << endl;
        cout << "9. 保存到文件（手动）" << endl;
        cout << "10. 从文件读取（手动）" << endl;
        cout << "11. 切换用户（重新登录）" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择：";
        int choice=readInt();

        if (choice == 0) {
            // 退出前自动保存
            lib.saveUsers("users.txt");
            lib.savetoFile("resources.txt");
            cout << "已自动保存，再见！" << endl;
            break;
        }

        if (choice == 1) {
            lib.showall();
        } else if (choice == 2) {
            lib.showusers();
        } else if (choice == 3) {
            string name;
            cout << "输入资源名称："; cin >> name;
            lib.showByname(name);
        } else if (choice == 4) {
            int t;
            cout << "选类型（1图书 2杂志 3电子资源）："; cin >> t;
            lib.showBytype(t);
        } else if (choice == 5) {
            string name;
            cout << "输入要借的资源名："; cin >> name;
            lib.borrow(name, *current);
        } else if (choice == 6) {
            string name;
            cout << "输入要还的资源名："; cin >> name;
            lib.returnRes(name, *current);
        } else if (choice == 7) {
            current->showRecords();
        } else if (choice == 8) {
            string name;
            cout << "输入要删除的资源名："; cin >> name;
            lib.remove(name);
        } else if (choice == 9) {
            lib.savetoFile("resources.txt");
            lib.saveUsers("users.txt");
        } else if (choice == 10) {
            lib.loadFromFile("resources.txt");
            lib.loadUsers("users.txt");
        } else if (choice == 11) {
            string id;
            cout << "重新登录，输入学号/工号："; cin >> id;
            user* u = lib.login(id);
            if (u != nullptr) { current = u; cout << "已切换为：" << current->Getname() << endl; }
            else cout << "用户不存在，切换失败" << endl;
        } else {
            cout << "无效选择，请重新输入" << endl;
        }
    }

    return 0;
}