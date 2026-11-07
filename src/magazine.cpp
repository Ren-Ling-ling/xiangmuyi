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
cout << "杂志名称:" << name << " 出版社:" << publisher << " 价格:" << price << " 状态:" << (available ? "在馆" : "不在馆")<< " 期号:" << issue << " 出版周期:" << period ;
if (!borrower.empty()) cout << " 借阅人:" << borrower;
cout<< endl;
}
int magazine::getborrowdays() { return 15; }

double magazine::calfine(int daysBorrowed) {
    if (daysBorrowed > 15) return (daysBorrowed - 15) * 0.3;
    return 0;
}
void magazine::writetoFile(ofstream&out){
     out << "杂志," << name << "," << publisher << "," << price << "," << issue << "," << period << "," << (available ? 1 : 0) << "," << borrower << endl;
}