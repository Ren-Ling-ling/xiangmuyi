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
    void resource::show(){
        cout<<"名称："<<name<<"出版社："<<publisher<<"价格："<<price<<"状态："<<(available?"在馆":"不在馆")<<endl;
    }
void resource::borrowbook(){available=false;}
void resource::returnbook(){available=true;}
string resource::Getname(){return name;}
string resource::Getpublisher(){return publisher;}
double resource::Getprice(){return price;}
bool resource::Getavailable(){return available;}