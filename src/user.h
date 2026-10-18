#ifndef user_h
#define user_h
#include<string>
#include<vector>
#include"resource.h"
using namespace std;
class user{
    string name;
    string department;
    int maxbook;
    int borrowcount;
    vector<string>borrowedBooks;


public:
user();
user(string name,string department,int maxbook);
bool borrowbook(resource&r);
bool returnbook(resource&r);
void show();
string Getname();
string Getdepartment();
int Getmaxbook();
int Getborrowcount();
};
#endif