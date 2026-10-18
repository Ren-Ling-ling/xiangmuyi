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
    resource::show();
    cout<<"网址："<<url<<"格式："<<format<<endl;
}