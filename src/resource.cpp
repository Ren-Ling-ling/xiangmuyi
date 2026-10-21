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