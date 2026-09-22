#include"book.h"
#include <iostream>
using namespace std;
int main() {
book b1("三国演义","isbn","人民文学出版社",69.9,300);
b1.show();
b1.borrowbook();
b1.show();
b1.returnbook();
b1.show();
cout<<"书名："<<b1.Getname()<<endl;
cout<<"价格："<<b1.Getprice()<<endl;
cout<<"是否可借"<<b1.Getavailable()<<endl;
    return 0;
}
