#include"book.h"
#include"student.h"
#include <iostream>
using namespace std;
int main() {
    book b1("三国演义", "9780306406157", "人民文学出版社", 69.9, 300);
    book b2("红楼梦",   "9787020002207", "人民文学出版社", 59.7, 1600);
    book b3("测试书",   "abc123",         "某出版社",       10.0, 100);   // 图书入库
    student s("张三", "20258967", 2);   // 张三最多可借 2 本
    cout << "----- 图书与借阅人信息 -----" << endl;      // 显示图书与借阅人信息
    b1.show();
    b2.show();
    b3.show();
    s.showinfo();
    cout << "\nISBN 校验 " << endl;
    cout << "《三国演义》ISBN：" << (b1.isvalidisbn() ? "合法" : "不合法") << endl;
    cout << "《测试书》ISBN："   << (b3.isvalidisbn() ? "合法" : "不合法") << endl;     // ISBN 合法性校验
    cout << "\n张三借书 " << endl;      // 张三借书
    s.borrow(b1);   // 成功
    s.borrow(b1);   // 已借出，失败
    s.borrow(b2);   // 成功
    s.borrow(b3);   // 超上限，失败
    s.showinfo();
    cout << "\n张三还书" << endl;        // 张三还书
    s.returnbook(b1);   // 成功
    s.returnbook(b3);   // 未借，失败
    s.showinfo();
    b1.show();   // 查看 b1 状态恢复

    return 0;
}
