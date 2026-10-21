#ifndef library_h
#define library_h
#include<vector>
#include<string>
#include"resource.h"
#include"user.h"
using namespace std;
class library{
private:
vector<resource*> resources;
public:
library();
~library();
void addResource(resource*r);
void showall();
void borrow(const string& name, user& u);
resource*find(const string&name);
void returnRes(const string&name,user&u);
void remove(const string&name);
};
#endif
