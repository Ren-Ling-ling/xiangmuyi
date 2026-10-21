#include"book.h"
#include"magazine.h"
#include"eresource.h"
#include"student.h"
#include"teacher.h"
#include"library.h"
#include <iostream>
using namespace std;
int main() {
     library lib;
    lib.addResource(new book("三国演义", "9780306406157", "人民文学出版社", 69.9, 300));
    lib.addResource(new magazine("读者", "读者出版社", 10.0, 5, "月刊"));
    lib.addResource(new eresource("c++教程", "人民邮电出版社", 20.0, "http://xxx.com", "pdf"));
    cout << "所有资源" << endl;
    lib.showall();      

    student s("张三", "20258967", "计算机学院", 2);
    teacher t("李老师", "T1001", "计算机学院", 5);

    cout << "\n张三借阅 " << endl;
    lib.borrow("三国演义", s);    // 成功
    lib.borrow("c++教程", s);     // 成功（电子资源可借）
    lib.borrow("读者", s);        // 超过上限（已借2本）
    s.show();

    cout << "\n 归还 " << endl;
    lib.returnRes("三国演义", s);  // 成功
    s.show();

    cout << "\n删除《读者》 " << endl;
    lib.remove("读者");

    cout << "\n剩余资源 " << endl;
    lib.showall();

    return 0;   
}