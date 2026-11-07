#include "resource.h"
#include<iostream>
using namespace std;
resource::resource(){
    name="";
    publisher="";
    price=0;
    available=true;
}
resource::resource(string name,string publisher,double price){
    this->name=name;
    this->publisher=publisher;
    this->price=price;
    available=true;
}
bool resource::borrow(){
    if(!available)return false;
    available=false;
    return true;
}
void resource::returnItem(){
    available=true;
}
resource::~resource(){}
string resource::Getname(){return name;}
string resource::Getpublisher(){return publisher;}
double resource::Getprice(){return price;}
bool resource::Getavailable(){return available;}
int resource::getborrowdays(){return 0;}
double resource::calfine(int daysBorrowed){return 0;}
void resource::setborrower(const string& who)
{
    borrower=who;
}
void resource::restorestate(bool avail,const string&who){
    available=avail;
    borrower=who;
}
string resource::Getborrower(){
    return borrower;
}