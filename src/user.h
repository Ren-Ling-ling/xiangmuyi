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
     int borrowDays;
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
virtual void show();
virtual ~user();
string Getname();
string Getdepartment();
virtual string GetuserId()=0;
virtual string Getrolename()=0;
int Getmaxbook();
int Getborrowcount();
void simulateborrowdays(const string&rname,int daysago);
void showRecords();
vector<borrowRecord> Getrecord();
void restoreborrow(const vector<borrowRecord>&recs);
};
#endif