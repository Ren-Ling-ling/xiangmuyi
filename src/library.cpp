#include"library.h"
#include"utility.h"
#include "book.h"
#include "magazine.h"
#include "eresource.h"
#include "student.h"
#include"teacher.h"
#include<sstream>
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
    void library::loadFromFile(const string&filename){
        ifstream in(filename);
        if(!in){cout<<"文件打开失败！"<<endl;return;}
        string line;
        while(getline(in,line)){
            if(line.empty())continue;
            stringstream ss(line);
            string type,name,pub,priceStr;
            getline(ss,type,',');
            getline(ss,name,',');
            getline(ss,pub,',');
            getline(ss,priceStr,',');
            double price=stod(priceStr);
            if(type=="图书"){
                string isbn,pageStr;
                 getline(ss,isbn,',');
                  getline(ss,pageStr,',');
                  resources.push_back(new book(name,isbn,pub,price,stoi(pageStr)));           
                   }
                              else if(type=="杂志"){
                string issueStr,period;
                 getline(ss,issueStr,',');
                  getline(ss,period,',');
                  resources.push_back(new magazine(name,pub,price,stoi(issueStr),period));           
        }
         else if(type=="电子资源"){
                string url,format;
                 getline(ss,url,',');
                  getline(ss,format,',');
                  resources.push_back(new eresource(name,pub,price,url,format));           
        }
    }
    in.close();
    cout<<"已经从文件读取资源"<<endl;
}
void library::showByname(const string&name){
    resource*r=find(name);
    if(r==nullptr){
         cout << "找不到资源《" << name << "》" << endl;
         return;
    }
    r->show();
}
void library::showBytype(int type){
    for(int i=0;i<(int)resources.size();i++){
        resource*r=resources[i];
        bool match=false;
        if(type==1&&dynamic_cast<book*>(r)) match=true;
else if(type==2&&dynamic_cast<magazine*>(r)) match=true;
else if(type==3&&dynamic_cast<eresource*>(r)) match=true;
     if(match)r->show();
    }
}
void library::saveUsers(const string&filename){
    ofstream out(filename);
    if(!out){cout << "文件打开失败！" << endl; return;}
    for(int i=0;i<(int)users.size();i++){
student*s=dynamic_cast<student*>(users[i]);
teacher*t=dynamic_cast<teacher*>(users[i]);
if(s!=nullptr){
    out << "学生," << s->Getname() << "," << s->Getid() << "," << s->Getdepartment() << "," << s->Getmaxbook() << endl;
}
else if(t!=nullptr){
out << "教师," << t->Getname() << "," << t->Getworkid() << ","<< t->Getdepartment() << "," << t->Getmaxbook() << endl;
}
    }
out.close();
cout << "用户已保存到文件：" << filename << endl;
}
void library::loadUsers(const string&filename){
    ifstream in(filename);
    if(!in){cout << "文件打开失败！" << endl; return;}
    string line;
    while(getline(in,line)){
        if(line.empty())continue;
        stringstream ss(line);
        string type,name,id,dept,maxStr;
        getline(ss,type,',');
          getline(ss,name,',');
            getline(ss,id,',');
              getline(ss,dept,',');
                getline(ss,maxStr,',');
                int maxbook=stoi(maxStr);
                if(type=="学生")users.push_back(new student(name, id, dept, maxbook));
                else if(type=="教师")users.push_back(new teacher(name,id,dept,maxbook));
    }
    in.close();
    cout << "已从文件读取用户" << endl;
}
user* library::login(const string&id){
    for(int i=0;i<(int)users.size();i++){
        student*s=dynamic_cast<student*>(users[i]);
        teacher*t=dynamic_cast<teacher*>(users[i]);
        if(s!=nullptr&&s->Getid()==id) return users[i];
 if(t!=nullptr&&s->Getid()==id) return users[i];
    }
    return nullptr;
}
bool library::hasusers(){return !users.empty();}
bool library::hasResources(){return!resources.empty();}