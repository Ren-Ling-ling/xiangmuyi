#include "student.h"
#include <iostream>
using namespace std;

student::student(string name, string id, int maxbook) {
    this->name = name;
    this->id = id;
    this->maxbook = maxbook;
    this->borrowcount = 0;  // 构造函数：初始化学生信息，已借数量为 0
}

bool student::borrow(book& b) {
    if (!b.Getavailable()) {
        cout << "借书失败：该书已被借出" << endl;
        return false;
    }                                                                //若图书已被借出，失败
    if (borrowcount >= maxbook) {
        cout << "借书失败：借书数量已到上限" << endl;
        return false;
    }
    b.borrowbook();
    borrowcount++;
    borrowedBooks.push_back(b.Getname());
    cout << name << "成功借阅《" << b.Getname() << "》" << endl;
    return true;
}                                                                  //借书成功：更新图书与学生的状态

bool student::returnbook(book& b) {
    if (b.Getavailable()) {
        cout << "还书失败：该书并未借出" << endl;
        return false;
    }
    b.returnbook();
    borrowcount--;
    for (int i = 0; i < (int)borrowedBooks.size(); i++) { 
        if (borrowedBooks[i] == b.Getname()) {
           borrowedBooks.erase(borrowedBooks.begin() + i);
            break;                                                   // 从借阅列表中删除该书
        }
    }
    cout << name << "成功还书《" << b.Getname() << "》" << endl;
    return true;
}                                                                     // 还书成功：更新图书与学生的状态

void student::showinfo() {
    cout << "姓名：" << name << " 学号：" << id
         << " 已借：" << borrowcount << " 最大借书量：" << maxbook << endl;
}  // 输出学生信息

string student::Getname() { return name; }
string student::Getid() { return id; }
int student::Getborrowcount() { return borrowcount; }
int student::Getmaxbook() { return maxbook; }
