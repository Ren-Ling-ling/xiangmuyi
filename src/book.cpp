#include"book.h"
#include<iostream>
using namespace std;
bool book::isvalidisbn()const{
    if(isbn.length()!=13){
        return false;
    }
    for(int i=0;i<13;i++){
        if(isbn[i]<'0'||isbn[i]>'9'){
            return false;
        }
    }
    int sum=0;
    for(int i=0;i<12;i++){
        int dig=isbn[i]-'0';
        if(i%2==0){
            sum+=dig*1;
        }
        else{
            sum+=dig*3;
        }
    }
    int check=(10-sum%10)%10;
    int finally=isbn[12]-'0';
    return check==finally;
}
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
string book::Getpublisher(){return publisher;}
double book::Getprice(){return price;}
bool book::Getavailable(){return available;}
int book::Getpage(){return page;}
