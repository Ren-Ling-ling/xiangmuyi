#ifndef book_h
#define book_h

#include<string>
using namespace std;
class book{
    private:
    string name;
    string isbn;
    string publisher;
    double price;
    int page;
    bool available;
    public:
    book();
    book(string name,string isbn,string publisher,double price,int page);
    void show();
    void borrowbook();
    void returnbook();
    string Getname();
    string Getpublisher();
    double Getprice();
    bool Getavailable();
    int Getpage();
bool isvalidisbn()const;
};
#endif