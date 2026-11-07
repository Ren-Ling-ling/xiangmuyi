#include"admin.h"
#include<iostream>
using namespace std;
admin::admin():user(){adminid="";}
admin::admin(string name,string adminid,string department,int maxbook):user(name,department,maxbook){
    this->adminid=adminid;
}
void admin::show(){
    user::show();
    cout<<"管理员编号："<<adminid<<endl;

}
string admin::Getadminid(){
return adminid;
}
string admin::GetuserId(){return adminid;}
string admin::Getrolename(){return "管理员";}
