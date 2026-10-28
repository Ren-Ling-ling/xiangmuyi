#include "book.h"
#include "magazine.h"
#include "eresource.h"
#include "student.h"
#include "teacher.h"
#include "library.h"
#include <iostream>
using namespace std;

int main() {
    library lib;
    lib.addResource(new book("三国演义", "9780306406157", "人民文学出版社", 69.9, 300));
    lib.addResource(new magazine("读者", "读者出版社", 10.0, 5, "月刊"));
    lib.addResource(new eresource("c++教程", "人民邮电出版社", 20.0, "http://xxx.com", "pdf"));

    // 用户用 new 创建，交给 Library 管理
    student* ps = new student("张三", "20258967", "计算机学院", 2);
    teacher* pt = new teacher("李老师", "T1001", "计算机学院", 5);
    lib.adduser(ps);
    lib.adduser(pt);

    cout << "所有资源" << endl;
    lib.showall();          // printAll(resources)
    cout << "所有用户" << endl;
    lib.showusers();        // printAll(users) 

    cout << "\n张三借阅" << endl;
    lib.borrow("三国演义", *ps);   
    lib.borrow("c++教程", *ps);
    lib.borrow("读者", *ps);
    ps->show();

    cout << "\n归还" << endl;
    lib.returnRes("三国演义", *ps);
    ps->show();

    cout << "\n删除《读者》" << endl;
    lib.remove("读者");

    cout << "\n剩余资源" << endl;
    lib.showall();

    cout << "\n保存到文件" << endl;
    lib.savetoFile("resources.txt");

    cout << "\n逾期罚款测试" << endl;
    student* ps2 = new student("李四", "20250001", "计算机学院", 5);
    lib.adduser(ps2);
    lib.borrow("三国演义", *ps2);
    ps2->simulateborrowdays("三国演义", 40);
    lib.returnRes("三国演义", *ps2);
    ps2->show();
    cout << "\n----- 读取文件测试 -----" << endl;
    library lib2;                       
    lib2.loadFromFile("resources.txt");  // 从文件读回
    lib2.showall();                      // 显示还原的资源
    return 0;   
}