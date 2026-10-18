#include "student.h"
#include <iostream>
using namespace std;

student::student():user(){
    id="";
}
student::student(string name, string id,string department, int maxbook) :user(name,department,maxbook){
   
    this->id = id;
}                      // 还书成功：更新图书与学生的状态

void student::show() {
    user::show();
    cout << "学号："<<id<< endl;
}  // 输出学生学号信息
string student::Getid() { return id; }
