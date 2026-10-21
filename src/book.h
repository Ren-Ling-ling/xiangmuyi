#ifndef book_h
#define book_h

#include<string>
#include"resource.h"
using namespace std;
class book:public resource{
    private:
    string isbn;
    int page;
    public:
    book();
    book(string name,string isbn,string publisher,double price,int page);
    void show()override;
    int Getpage();
bool isvalidisbn()const;
};
#endif