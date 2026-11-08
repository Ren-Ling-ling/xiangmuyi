#ifndef admin_h
#define admin_h
#include<string>
#include"user.h"
using namespace std;
class admin:public user{
    private:
    string adminid;
    public:
    admin();
    admin(string name,string adminid,string department,int maxbook);
    void show()override;
    string Getadminid();
    string GetuserId()override;
    string Getrolename()override;
    static constexpr int MAXBOOK=0;
};
#endif