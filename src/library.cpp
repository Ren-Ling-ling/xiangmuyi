#include"library.h"
#include"utility.h"
#include "book.h"
#include "magazine.h"
#include "eresource.h"
#include "student.h"
#include"teacher.h"
#include"admin.h"
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
           try{
            stringstream ss(line);
            string type,name,pub,priceStr;
            getline(ss,type,',');
            getline(ss,name,',');
            getline(ss,pub,',');
            getline(ss,priceStr,',');
            double price=stod(priceStr);
        if(type=="图书"){
                string isbn,pageStr,availStr,bwr;
                 getline(ss,isbn,',');
                  getline(ss,pageStr,',');
                  getline(ss,availStr,',');
                  getline(ss,bwr,',');
                  book*p=new book(name,isbn,pub,price,stoi(pageStr));
                  p->restorestate(stoi(availStr)!=0,bwr);
                  resources.push_back(p);
                }
        else if(type=="杂志"){
                string issueStr,period,availStr,bwr;
                 getline(ss,issueStr,',');
                  getline(ss,period,',');
                  getline(ss,availStr,',');
                  getline(ss,bwr,',');
                  magazine*p=new magazine(name,pub,price,stoi(issueStr),period);
                p->restorestate(stoi(availStr)!=0,bwr);
                resources.push_back(p);          
        }
         else if(type=="电子资源"){
                string url,format,availStr,bwr;
                 getline(ss,url,',');
                  getline(ss,format,',');
                   getline(ss,availStr,',');
                  getline(ss,bwr,',');
                  eresource*p=new eresource(name,pub,price,url,format);
                 p->restorestate(stoi(availStr)!=0,bwr);
                 resources.push_back(p);
    }
}
    catch(...){
        cout<<"跳过格式错误的一行："<<line<<endl;
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
    user*u=users[i];
    out<<u->Getrolename()<<","<<u->Getname()<<","<<u->GetuserId()<<","<<u->Getdepartment()<<","<<u->Getmaxbook();
vector<borrowRecord>recs=users[i]->Getrecord();
    out<<','<<recs.size();
for(int j=0;j<(int)recs.size();j++){
    out<<","<<recs[j].name<<","<<recs[j].borrowtime<<","<<recs[j].borrowDays;
vector<borrowRecord>recs=u->Getrecord();
out<<","<<recs.size();
for(int j=0;i<(int)recs.size();j++)
out<<","<<recs[j].name<<","<<recs[j].borrowtime<<","<<recs[j].borrowDays;
out<<endl;
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
       try{

       stringstream ss(line);
        string type,name,id,dept,maxStr,cntStr;
        getline(ss,type,',');
          getline(ss,name,',');
            getline(ss,id,',');
              getline(ss,dept,',');
                getline(ss,maxStr,',');
                int maxbook=stoi(maxStr);
                user*u=nullptr;
         if (type == "学生")      u = new student(name, id, dept, maxbook);
            else if (type == "教师") u = new teacher(name, id, dept, maxbook);
                else if(type=="管理员") u=new admin(name,id,dept,maxbook);
        if (u != nullptr) {
                getline(ss, cntStr, ',');
                int cnt = stoi(cntStr);
                vector<borrowRecord> recs;
                for (int i = 0; i < cnt; i++) {
                    string rname, tstr,dstr;
                    getline(ss, rname, ',');
                    getline(ss, tstr, ',');
                    getline(ss,dstr,',');
                    borrowRecord rec;
                    rec.name = rname;
                    rec.borrowtime = (time_t)stoll(tstr);
                    rec.borrowDays=stoi(dstr);
                    recs.push_back(rec);
                }
                u->restoreborrow(recs);
                users.push_back(u);
            }
    }
    catch(...){
        cout<<"跳过格式错误的一行："<<line<<endl;
    }
}
    in.close();
    cout << "已从文件读取用户" << endl;
}
user* library::login(const string&id){
    for(int i=0;i<(int)users.size();i++){
        if(users[i]->GetuserId()==id) return users[i];
    }
    return nullptr;
}
bool library::hasusers(){return !users.empty();}
bool library::hasResources(){return!resources.empty();}
void library::removeuser(user*u){
    for(int i=0;i<(int)users.size();i++){
           if(users[i]==u){
            delete users[i];
            users.erase(users.begin()+i);
            return;
           }
    }
}
int library::admincount(){
    int c=0;
    for(int i=0;i<(int)users.size();i++){
        if(users[i]->Getrolename()=="管理员")c++;
    }
      return c;
}