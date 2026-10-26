#include"library.h"
#include"utility.h"
#include<iostream>
using namespace std;
library::library(){}
library::~library(){
    for(int i=0;i<(int)resources.size();i++){
      delete resources[i];
    }
    for(int i=0;i<(int)users.size();i++){
      delete users[i];
      }
      users.clear();
    }

void library::addResource(resource*r){
    resources.push_back(r);
}
void library::adduser(user*u){
    users.push_back(u);
}
void library::showusers(){
    printAll(users);
}
void library::showall(){
    printAll(resources);
}
resource*library::find(const string& name){
    for(int i=0;i<(int)resources.size();i++){
    if(resources[i]->Getname()==name)
{
    return resources[i];
}
}
return nullptr;
}
void library::borrow(const string&name,user&u){
    resource*r=find(name);
    if(r==nullptr){
         cout << "借阅失败：找不到资源《" << name << "》" << endl;
         return;
    }
    u.borrowbook(*r);
}
void library::returnRes(const string&name,user&u){
    resource*r=find(name);
    if(r==nullptr){
         cout << "归还失败：找不到资源《" << name << "》" << endl;
         return;
    }
    u.returnbook(*r);
}
void library::remove(const string &name){
    for(int i=0;i<(int)resources.size();i++){
        if(resources[i]->Getname()==name){
            delete resources[i];
            resources.erase(resources.begin()+i);
            cout << "已删除资源《" << name << "》" << endl;
            return;
        }
    }
    cout << "删除失败：找不到资源《" << name << "》" << endl;
}
void library::savetoFile(const string&filename){
    ofstream out(filename);
    if (!out){
        cout << "文件打开失败！" << endl;
        return;
    }
    for(int i=0;i<(int)resources.size();i++){
        resources[i]->writetoFile(out);
    }
out.close();
cout << "已保存到文件：" << filename << endl;
    }