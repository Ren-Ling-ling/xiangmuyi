#include"eresource.h"
#include<iostream>
using namespace std;
eresource::eresource():resource(){
    url="";
    format="";
}
eresource::eresource(string name,string publisher,double price,string url,string format):resource(name,publisher,price)
{
    this->url=url;
    this->format=format;
}
void eresource::show(){
   cout << "电子资源名称:" << name << " 出版社:" << publisher << " 价格:" << price  << " 网址:" << url << " 格式：" << format << endl;

}
bool eresource::borrow(){
    return true;
}
void eresource::returnItem(){
    
}
void eresource::writetoFile(ofstream&out){
    out << "电子资源," <<  name << "," << publisher << "," << price << "," << url << "," << format << endl;
}