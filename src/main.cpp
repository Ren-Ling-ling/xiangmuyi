#include"book.h"
#include"student.h"
#include <iostream>
using namespace std;
int main() {
book b1("三国演义","9780306406157","人民文学出版社",69.9,300);
book b2("测试","abc123","出版社",10.0,100);
student s("张三","20258967",5);
cout<<"b1的isbn:"<<(b1.isvalidisbn()?"合法":"不合法")<<endl;
cout<<"b2的isbn:"<<(b2.isvalidisbn()?"合法":"不合法")<<endl;
cout<<"初始状态"<<endl;
b1.show();
s.showinfo();
cout<<"借书"<<endl;
s.borrow(b1);
b1.show();
s.showinfo();
cout<<"还书"<<endl;
s.returnbook(b1);
b1.show();
s.showinfo();

    return 0;
}
