#include"book.h"
#include<iostream>
using namespace std;
book::book():resource(){
    isbn="";
    page=0;
}
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
        int dig=isbn[i]-'0';    // 字符转数字：'7'-'0'=7
        if(i%2==0){
            sum+=dig*1;
        }
        else{
            sum+=dig*3;
        }
    }
    int check=(10-sum%10)%10;   // 理论校验位
    int finally=isbn[12]-'0';   // 实际的第 13 位
    return check==finally;
}
book::book(string name,string isbn,string publisher,double price,int page):resource(name,publisher,price)
{   // 重载构造函数：用参数初始化图书信息

this->isbn=isbn;
this->page=page;
available=true;    // 新书默认在馆
}
void book::show(){
    cout << "书名:" << name << " 出版社:" << publisher << " ISBN:" << isbn << " 价格:" << price << " 页数:" << page << " 状态:" << (available ? "在馆" : "不在馆") << endl;
}  // 输出图书信息
int book::Getpage(){return page;}
