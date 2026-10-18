#include"teacher.h"
#include<iostream>
using namespace std;
teacher::teacher():user(){
    workid="";
}
teacher::teacher(string name,string workid,string department,int maxbook):user(name,department,maxbook){
    this->workid=workid;
}
void teacher::show(){
    user::show();
    cout<<"工号："<<workid<<endl;
}
string teacher::Getworkid(){return workid;}