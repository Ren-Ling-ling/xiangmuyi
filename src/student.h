#ifndef student_h
#define student_h

#include <string>
#include "user.h"
using namespace std;

class student :public user {
private:
    string id;     
public:
   student();
   student(string name,string id,string department,int maxbook);
    void show()override;
    string Getid();
};

#endif
