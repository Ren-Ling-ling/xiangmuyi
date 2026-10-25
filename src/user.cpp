#include"user.h"
#include<iostream>
using namespace std;
user::user(){
    name="";
    department="";
    maxbook=5;
    borrowcount=0;
}
user::user(string name,string department,int maxbook){
    this->name=name;
    this->department=department;
    this->maxbook=maxbook;
    this->borrowcount=0;
}
bool user::borrowbook(resource&r){
if(borrowcount>=maxbook){
   cout<<"借阅失败：借阅数量达到上限"<<endl;
   return false;
}
if(!r.borrow()){
        cout<<"借阅失败：该资源已被借出"<<endl;
        return false;
    }
    borrowcount++;
    borrowRecord rec;
    rec.name=r.Getname();
    rec.borrowtime=time(nullptr);
    borrowedBooks.push_back(rec);
    cout << name << "成功借阅《" << r.Getname() << "》" << endl;
    return true;
}
bool user::returnbook(resource&r){
    if(r.Getavailable()){
        cout << "归还失败：该资源并未借出" << endl;
        return false;
    }
    r.returnItem();
    borrowcount--;
    for(int i=0;i<(int)borrowedBooks.size();i++){
        if(borrowedBooks[i].name==r.Getname()){
            time_t now=time(nullptr);
            int days=(int)((now-borrowedBooks[i].borrowtime)/86400);
            double fine=r.calfine(days);
            if(fine>0)
             cout << "逾期！已借 " << days << " 天，罚款 " << fine << " 元" << endl;
             else
              cout << "已借 " << days << " 天，未逾期" << endl;
            borrowedBooks.erase(borrowedBooks.begin()+i);
            break;
        }
    }
     cout << name << "成功归还《" << r.Getname() << "》" << endl;
     return true;
}
void user::show(){
     cout << "姓名:" << name << " 院系:" << department<< " 已借:" << borrowcount << " 最大借阅量:" << maxbook << endl;
}
string user::Getname(){return name;}
string user::Getdepartment(){return department;}
int user::Getmaxbook(){return maxbook;}
int user::Getborrowcount(){return borrowcount;}
void user::simulateborrowdays(const string& rname, int daysAgo) {
    for (int i = 0; i < (int)borrowedBooks.size(); i++) {
        if (borrowedBooks[i].name == rname) {
            borrowedBooks[i].borrowtime = time(nullptr) - (time_t)daysAgo * 86400;
            break;
        }
    }
}