#include"magazine.h"
#include<iostream>
using namespace std;
magazine::magazine():resource(){
    issue=0;
    period="";
}
magazine::magazine(string name,string publisher,double price,int issue,string period):resource(name,publisher,price)
{
    this->issue=issue;
    this->period=period;
}
void magazine::show(){
resource::show();
cout<<"期号："<<issue<<"出版周期"<<period<<endl;
}