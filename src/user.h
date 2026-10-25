#ifndef user_h
#define user_h
#include<string>
#include<vector>
#include <ctime>    
#include"resource.h"
using namespace std;
struct borrowRecord{
    string name;
    time_t borrowtime;
};
class user{
    string name;
    string department;
    int maxbook;
    int borrowcount;
    vector<borrowRecord>borrowedBooks;


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
void simulateborrowdays(const string&rname,int daysago);
};
#endif