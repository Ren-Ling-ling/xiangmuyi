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
cout << "杂志名称:" << name << " 出版社:" << publisher << " 价格:" << price << " 状态:" << (available ? "在馆" : "不在馆")<< " 期号:" << issue << " 出版周期:" << period << endl;
}
void magazine::writetoFile(ofstream&out){
   out << "杂志," << name << ",期号:" << issue << ",出版周期:" << period << endl;
}
int magazine::getborrowdays() { return 15; }

double magazine::calfine(int daysBorrowed) {
    if (daysBorrowed > 15) return (daysBorrowed - 15) * 0.3;
    return 0;
}
