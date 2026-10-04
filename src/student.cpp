#include "student.h"
#include <iostream>
using namespace std;

student::student(string name, string id, int maxbook) {
    this->name = name;
    this->id = id;
    this->maxbook = maxbook;
    this->borrowcount = 0;
}

bool student::borrow(book& b) {
    if (!b.Getavailable()) {
        cout << "借书失败：该书已被借出" << endl;
        return false;
    }
    if (borrowcount >= maxbook) {
        cout << "借书失败：借书数量已到上限" << endl;
        return false;
    }
    b.borrowbook();
    borrowcount++;
    cout << name << "成功借阅《" << b.Getname() << "》" << endl;
    return true;
}

bool student::returnbook(book& b) {
    if (b.Getavailable()) {
        cout << "还书失败：该书并未借出" << endl;
        return false;
    }
    b.returnbook();
    borrowcount--;
    cout << name << "成功还书《" << b.Getname() << "》" << endl;
    return true;
}

void student::showinfo() {
    cout << "姓名：" << name << " 学号：" << id
         << " 已借：" << borrowcount << " 最大借书量：" << maxbook << endl;
}

string student::Getname() { return name; }
string student::Getid() { return id; }
int student::Getborrowcount() { return borrowcount; }
int student::Getmaxbook() { return maxbook; }
