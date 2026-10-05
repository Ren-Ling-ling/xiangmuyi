#ifndef student_h
#define student_h

#include <string>
#include <vector>
#include "book.h"
using namespace std;

class student {
private:
    string name;
    string id;
    int borrowcount;
    int maxbook;
    vector<string> borrowedBooks;          //已借书名列表
public:
    student(string name="", string id="", int maxbook=5);
    bool borrow(book& b);
    bool returnbook(book& b);
    void showinfo();
    string Getname();
    string Getid();
    int Getborrowcount();
    int Getmaxbook();
};

#endif
