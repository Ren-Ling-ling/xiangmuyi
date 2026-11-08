#ifndef teacher_h
#define teacher_h
#include<string>
#include"user.h"
using namespace std;
class teacher:public user {
private:
string workid;
public:
teacher();
teacher(string name,string workid,string department,int maxbook);
void show()override;
string Getworkid();
string GetuserId()override;
string Getrolename()override;
static constexpr int MAXBOOK=10;
};
#endif