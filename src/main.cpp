#include"book.h"
#include"magazine.h"
#include"eresource.h"
#include"student.h"
#include"teacher.h"
#include <iostream>
using namespace std;
int main() {
    book b("三国演义", "9780306406157", "人民文学出版社", 69.9, 300);
   magazine m("读者","读者出版社",10.0,5,"月刊");
   eresource e("c++教程","人民出版社",20.0,"http://xxx.com","pdf");
      // 图书入库
    student s("张三", "20258967", "计算机学院",2);   // 张三最多可借 2 本
    teacher t("李老师","T1001","计算机学院",5);
    cout << "图书信息" << endl;      // 显示图书与借阅人信息
    b.show();
    m.show();
    e.show();
    cout<<"用户信息"<<endl;
    s.show();
    t.show();
    cout << "ISBN 校验 " << endl;
    cout << "《三国演义》ISBN：" << (b.isvalidisbn() ? "合法" :"不合法") << endl;
   cout<<"类型兼容测试"<<endl;
    resource*r=&b;
    r->show();
    return 0;
}
