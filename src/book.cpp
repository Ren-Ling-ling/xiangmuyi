#include"book.h"
#include<iostream>
using namespace std;
book::book(){
    available=true;
}
book::book(string name,string isbn,string publisher,double price,int page){
this->name=name;
this->publisher=publisher;
this->isbn=isbn;
this->price=price;
this->page=page;
available=true;
}
void book::show(){
    cout << "书名:" << name << " 出版社:" << publisher << " ISBN:" << isbn << " 价格:" << price << " 页数:" << page << " 状态:" << (available ? "在馆" : "不在馆") << endl;
}
void book::borrowbook(){
    available=false;
}
void book::returnbook(){
    available=true;
}
string book::Getname(){return name;}
double book::Getprice(){return price;}
bool book::Getavailable(){return available;}